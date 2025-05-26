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

#ifndef _NT_CORE_EVENT_APPLICATION_EVENT_CPP_
    #define _NT_CORE_EVENT_APPLICATION_EVENT_CPP_

#include "ApplicationEvent.h"

namespace Nt
{
    WindowResizeEvent::WindowResizeEvent(uint32 width, uint32 height) :
        m_width(width), m_height(height)
    {}

    uint32 WindowResizeEvent::GetWidth() const
    {
        return m_width;
    }

    uint32 WindowResizeEvent::GetHeight() const
    {
        return m_height;
    }

    std::string WindowResizeEvent::ToString() const
    {
        std::stringstream ss;
        ss << "WindowResizeEvent: " << m_width << ", " << m_height;
        return ss.str();
    }
} // namespace Nt

#endif // _NT_CORE_EVENT_APPLICATION_EVENT_CPP_