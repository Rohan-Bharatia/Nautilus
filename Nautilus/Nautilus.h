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

#ifndef _NAUTILUS_H_
    #define _NAUTILUS_H_

#include "Core.h"
#include "Renderer.h"
#include "EntryPoint.h"

#define NT_VERSION_MAJOR 1
#define NT_VERSION_MINOR 0
#define NT_VERSION_PATCH 0
#define NT_VERSION_INT (NT_VERSION_MAJOR * 100 + NT_VERSION_MINOR * 10 + NT_VERSION_PATCH)
#define NT_VERSION_STRING NT_STRINGIFY(NT_VERSION_MAJOR) "." NT_STRINGIFY(NT_VERSION_MINOR) "." NT_STRINGIFY(NT_VERSION_PATCH)
#define NT_VERSION_PRETTY "v" NT_VERSION_STRING
#define NT_VERSION_CHECK(major, minor, patch)                                                    \
    (NT_VERSION_MAJOR > (major) ||                                                               \
    (NT_VERSION_MAJOR == (major) && NT_VERSION_MINOR > (minor)) ||                               \
    (NT_VERSION_MAJOR == (major) && NT_VERSION_MINOR == (minor) && NT_VERSION_PATCH >= (patch)))

#endif // _NAUTILUS_H_
