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

#ifndef _NT_CORE_EVENT_EVENT_H_
    #define _NT_CORE_EVENT_EVENT_H_

#include "PCH.h"

#define NT_EVENT_CLASS_TYPE(type) static EventType GetStaticType(void) { return EventType::type; }                \
								  virtual EventType GetEventType(void) const override { return GetStaticType(); } \
								  virtual std::string GetName(void) const override { return NT_STRINGIFY(type); }
#define NT_EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags(void) const override { return category; }

namespace Nt
{
    enum class EventType
    {
        None = 0,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled,
        WindowResize,
        WindowClose,
        AppTick,
        AppUpdate,
        AppRender,
    };

    enum EventCategory
    {
        None                     = 0,
        EventCategoryApplication = 0x00001,
        EventCategoryInput       = 0x00010,
        EventCategoryKeyboard    = 0x00100,
        EventCategoryMouse       = 0x01000,
        EventCategoryMouseButton = 0x10000,
    };

    class NT_API Event
    {
    public:
        NT_CLASS_DEFAULTS(Event)
        Event(void) = default;

        void SetHandled(bool handled);
        bool IsHandled() const;

        virtual EventType GetEventType(void) const = 0;
		virtual std::string GetName(void) const    = 0;
		virtual int GetCategoryFlags(void) const   = 0;
		virtual std::string ToString(void) const;

        bool IsInCategory(EventCategory category) const;

    private:
        bool m_handled = false;
    };

    class NT_API EventDispatcher
    {
    public:
        NT_CLASS_DEFAULTS(EventDispatcher)
        EventDispatcher(void) = delete;
        EventDispatcher(Event& event);

        template<class T, typename F>
        bool Dispatch(const F& func);

    private:
        Event& m_event;
    };

    std::ostream& operator<<(std::ostream& os, const Event& e);
} // namespace Nt

#include "Event.inl"

#endif // _NT_CORE_EVENT_EVENT_H_
