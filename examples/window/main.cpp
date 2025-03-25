#include "Nautilus/Nautilus.h"

#include <iostream>

int main(int argc, char* argv[])
{
    // Window settings
    nt::WindowDesc desc{};
    desc.position.x      = 100;
    desc.position.y      = 100;
    desc.width           = 1024;
    desc.height          = 768;
    desc.title           = "Nautilus Application";
    desc.backgroundColor = NT_COLOR_DEFAULT;

    // Create agents
    nt::WindowPtr window = nt::createWindow(desc);

    if (!window)
        return NT_EXIT_MINOR_ERROR;

    // Initialize
    window->initialize();

    // Main loop
    while (window->pollEvents())
    {
        // Exit condition
        if (nt::Event::isKeyPressed(VK_ESCAPE))
            break;

        // Draw frame
        window->update();
    }

    // Destroy window
    window->destroy();

    return NT_EXIT_SUCCESS;
}