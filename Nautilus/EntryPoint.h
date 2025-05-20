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
    extern Application* CreateApplication(void);
} // namespace Nt

int main(int argc, char* argv[])
{
    auto app = Nt::CreateApplication();
    app->Run();
    NT_SAFE_DELTE(app);
    return 0;
}

#endif // _ENTRY_POINT_H_
