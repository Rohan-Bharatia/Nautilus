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

#ifndef _CORE_H_
    #define _CORE_H_

// Core
#include "Core/Preprocessor.h"
#include "Core/Application.h"
#include "Core/Bits.h"
#include "Core/Logger.h"
#include "Core/Assertion.h"
#include "Core/Endian.h"
#include "Core/Atom.h"
#include "Core/DeviceInfo.h"
#include "Core/Filesystem.h"
#include "Core/Timer.h"

// Math
#include "Core/Angle.h"
#include "Core/Vec2.h"
#include "Core/Vec3.h"
#include "Core/Vec4.h"
#include "Core/Mat3x3.h"
#include "Core/Mat4x4.h"
#include "Core/Ray2.h"
#include "Core/Ray3.h"
#include "Core/Rect.h"
#include "Core/Color.h"
#include "Core/Vertex.h"

// Events
#include "Core/Event.h"
#include "Core/KeyEvent.h"
#include "Core/MouseEvent.h"
#include "Core/ApplicationEvent.h"

// Layers
#include "Core/Layer.h"
#include "Core/LayerStack.h"

#endif // _CORE_H_
