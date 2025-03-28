#include "Nautilus/Nautilus.h"

int main(int argc, char* argv[])
{
    nt::Logger::debug("Nautilus API v%d.%d.%d", NT_API_VERSION_MAJOR, NT_API_VERSION_MINOR, NT_API_VERSION_PATCH);

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
    window->initialize(false);

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
    }

    // Destroy window
    nt::Logger::info("Destroying window...");
    window->destroy();

    return NT_EXIT_SUCCESS;
}
