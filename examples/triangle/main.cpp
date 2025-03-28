#include "Nautilus/Nautilus.h"

int main(int argc, char* argv[])
{
    nt::Logger::debug("Nautilus API v%d.%d.%d", NT_API_VERSION_MAJOR, NT_API_VERSION_MINOR, NT_API_VERSION_PATCH);
    nt::Logger::debug("OpenGL API v%d.%d.%d", NT_OPENGL_VERSION_MAJOR, NT_OPENGL_VERSION_MINOR, NT_OPENGL_VERSION_PATCH);

    // Window settings
    nt::WindowDesc desc{};
    desc.position.x      = 100;
    desc.position.y      = 100;
    desc.width           = 1024;
    desc.height          = 768;
    desc.title           = "Nautilus Application";
    desc.backgroundColor = NT_COLOR_WHITE;

    // Create agents
    nt::WindowPtr window = nt::createWindow(desc);

    if (!window)
        return NT_EXIT_MINOR_ERROR;

    // Initialize
    nt::Logger::info("Initializing window...");
    window->initialize();

    // Normal triangle
    nt::Mesh vertices =
    {
        nt::Vertex(nt::Vec3f( 0.0f,  1.0f, 0.0f), nt::Vec2f(0.5f, 1.0f), NT_COLOR_RED).makeReadable(),
        nt::Vertex(nt::Vec3f(-1.0f, -1.0f, 0.0f), nt::Vec2f(0.0f, 0.0f), NT_COLOR_GREEN).makeReadable(),
        nt::Vertex(nt::Vec3f( 1.0f, -1.0f, 0.0f), nt::Vec2f(1.5f, 1.0f), NT_COLOR_BLUE).makeReadable(),
    };

    // Main loop
    while (window->pollEvents())
    {
        // Exit condition
        if (nt::Event::isKeyPressed(VK_ESCAPE))
        {
            nt::Logger::info("Exiting...");
            break;
        }

        // Draw frame
        window->update();
        window->clear(NT_COLOR_WHITE);
        window->frame(vertices);
        window->swapBuffers();
    }

    // Destroy window
    nt::Logger::info("Destroying window...");
    window->destroy();

    return NT_EXIT_SUCCESS;
}
