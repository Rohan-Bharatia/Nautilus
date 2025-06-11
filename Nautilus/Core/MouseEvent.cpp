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

#ifndef _NT_CORE_EVENT_MOUSE_EVENT_CPP_
    #define _NT_CORE_EVENT_MOUSE_EVENT_CPP_

#include "MouseEvent.h"

namespace Nt
{
    uint32 MouseButtonEvent::GetMouseButton() const
    {
        return m_button;
    }

    MouseButtonEvent::MouseButtonEvent(uint32 button) :
        m_button(button)
    {}

    MouseButtonPressedEvent::MouseButtonPressedEvent(uint32 button) :
        MouseButtonEvent(button)
    {}

    std::string MouseButtonPressedEvent::ToString(void) const
    {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << m_button;
        return ss.str();
    }

    MouseButtonReleasedEvent::MouseButtonReleasedEvent(uint32 button) :
        MouseButtonEvent(button)
    {}

    std::string MouseButtonReleasedEvent::ToString(void) const
    {
        std::stringstream ss;
        ss << "MouseButtonReleasedEvent: " << m_button;
        return ss.str();
    }

    MouseMovedEvent::MouseMovedEvent(const float32 x, const float32 y) :
        m_x(x), m_y(y)
    {}

    float32 MouseMovedEvent::GetX() const
    {
        return m_x;
    }

    float32 MouseMovedEvent::GetY() const
    {
        return m_y;
    }

    std::string MouseMovedEvent::ToString(void) const
    {
        std::stringstream ss;
        ss << "MouseMovedEvent: " << m_x << ", " << m_y;
        return ss.str();
    }

    MouseScrolledEvent::MouseScrolledEvent(const float32 xOffset, const float32 yOffset) :
        m_xOffset(xOffset), m_yOffset(yOffset)
    {}

    float32 MouseScrolledEvent::GetXOffset() const
    {
        return m_xOffset;
    }

    float32 MouseScrolledEvent::GetYOffset() const
    {
        return m_yOffset;
    }

    std::string MouseScrolledEvent::ToString(void) const
    {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
        return ss.str();
    }
} // namespace Nt

#endif // _NT_CORE_EVENT_MOUSE_EVENT_CPP_