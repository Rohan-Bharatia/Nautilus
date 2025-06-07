#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#pragma once

#ifndef _ENTRY_POINT_H_
    #define _ENTRY_POINT_H_

#include "Core/Application.h"

namespace Nt
{
    extern Application* CreateApplication(int32 argc, char** argv);
} // namespace Nt

#ifdef NT_PLATFORM_WINDOWS
int APIENTRY WinMain(HINSTANCE hinstance, HINSTANCE hinstancePrev, PSTR cmdline, int cmdshow)
{
    try
    {
        auto app = Nt::CreateApplication(NT_STATIC_CAST(Nt::int32, __argc), __argv);
        app->Run();
        NT_SAFE_DELETE(app);
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        Nt::Logger::Critical("Exception: {%s}!", e.what());
        return EXIT_FAILURE;
    }
    catch (...)
    {
        Nt::Logger::Critical("Unknown exception occurred!");
        return EXIT_FAILURE;
    }
    return EXIT_FAILURE;
}
#else // (NOT) NT_PLATFORM_WINDOWS
int main(int argc, char* argv[])
{
    try
    {
        auto app = Nt::CreateApplication(NT_STATIC_CAST(Nt::int32, argc), argv);
        app->Run();
        NT_SAFE_DELETE(app);
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        Nt::Logger::Critical("Exception: {%s}!", e.what());
        return EXIT_FAILURE;
    }
    catch (...)
    {
        Nt::Logger::Critical("Unknown exception occurred!");
        return EXIT_FAILURE;
    }
    return EXIT_FAILURE;
}
#endif // NT_PLATFORM_WINDOWS

#endif // _ENTRY_POINT_H_
