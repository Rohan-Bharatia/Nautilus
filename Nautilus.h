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

#ifndef _NT_NAUTILUS_H_
    #define _NT_NAUTILUS_H_

// Version macros
#define STRINGIFY(x) #x
#define NT_MAKE_VERSION(major, minor, patch) STRINGIFY(major) "." STRINGIFY(minor) "." STRINGIFY(patch)
#define NT_VERSION_MAJOR 1
#define NT_VERSION_MINOR 0
#define NT_VERSION_PATCH 0
#define NT_VERSION_STR NT_MAKE_VERSION(NT_VERSION_MAJOR, NT_VERSION_MINOR, NT_VERSION_PATCH)
#define NT_VERSION_INT (NT_VERSION_MAJOR * 100) + (NT_VERSION_MINOR * 10) + NT_VERSION_PATCH

#endif // _NT_NAUTILUS_H_
