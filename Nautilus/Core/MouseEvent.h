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

#ifndef _NT_CORE_EVENT_MOUSE_EVENT_H_
    #define _NT_CORE_EVENT_MOUSE_EVENT_H_

#include "Event.h"

namespace Nt
{
    class NT_API MouseButtonEvent :
        public Event
    {
    public:
        NT_CLASS_DEFAULTS(MouseButtonEvent)
        MouseButtonEvent(void) = default;

        uint32 GetMouseButton() const;

        NT_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        uint32 m_button;

        MouseButtonEvent(uint32 button);
    };

    class NT_API MouseButtonPressedEvent :
        public MouseButtonEvent
    {
    public:
        NT_CLASS_DEFAULTS(MouseButtonPressedEvent)
        MouseButtonPressedEvent(void) = default;
        MouseButtonPressedEvent(uint32 button);

        std::string ToString(void) const override;

        NT_EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class NT_API MouseButtonReleasedEvent :
        public MouseButtonEvent
    {
    public:
        NT_CLASS_DEFAULTS(MouseButtonReleasedEvent)
        MouseButtonReleasedEvent(void) = default;
        MouseButtonReleasedEvent(uint32 button);

        std::string ToString(void) const override;

        NT_EVENT_CLASS_TYPE(MouseButtonReleased)
    };

    class NT_API MouseMovedEvent :
        public Event
    {
    public:
        NT_CLASS_DEFAULTS(MouseMovedEvent)
        MouseMovedEvent(void) = default;
        MouseMovedEvent(const float32 x, const float32 y);

        float32 GetX() const;
        float32 GetY() const;

        std::string ToString(void) const override;

        NT_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        NT_EVENT_CLASS_TYPE(MouseMoved)

    private:
        float32 m_x, m_y;
    };

    class NT_API MouseScrolledEvent :
        public Event
    {
    public:
        NT_CLASS_DEFAULTS(MouseScrolledEvent)
        MouseScrolledEvent(void) = default;
        MouseScrolledEvent(const float32 xOffset, const float32 yOffset);

        float32 GetXOffset() const;
        float32 GetYOffset() const;

        std::string ToString(void) const override;

        NT_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        NT_EVENT_CLASS_TYPE(MouseScrolled)

    private:
        float32 m_xOffset, m_yOffset;
    };
} // namespace Nt

#endif // _NT_CORE_EVENT_MOUSE_EVENT_H_
