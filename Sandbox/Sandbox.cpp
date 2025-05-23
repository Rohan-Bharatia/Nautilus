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

#ifndef _SANDBOX_CPP_
    #define _SANDBOX_CPP_

#include <Nautilus/Nautilus.h>

class SandboxApplication :
    public Nt::Application
{
public:
    SandboxApplication(Nt::int32 argc, char** argv) :
        Nt::Application(argc, argv)
    {
        Nt::Logger::Info("%f", Nt::GetBatteryLevel());
    }

    ~SandboxApplication(void)
    {}
};

Nt::Application* Nt::CreateApplication(Nt::int32 argc, char** argv)
{
    return new SandboxApplication(argc, argv);
}

#endif // _SANDBOX_CPP_
