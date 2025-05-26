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

#ifndef _NT_CORE_EVENT_APPLICATION_EVENT_H_
    #define _NT_CORE_EVENT_APPLICATION_EVENT_H_

#include "Event.h"

namespace Nt
{
    class NT_API WindowResizeEvent :
        public Event
    {
    public:
        NT_CLASS_DEFAULTS(WindowResizeEvent)
        WindowResizeEvent(void) = default;
        WindowResizeEvent(uint32 width, uint32 height);

        uint32 GetWidth() const;
        uint32 GetHeight() const;

        std::string ToString() const override;

        NT_EVENT_CLASS_CATEGORY(EventCategoryApplication)
        NT_EVENT_CLASS_TYPE(WindowResize)

    private:
        uint32 m_width, m_height;
    };

    class NT_API WindowCloseEvent :
        public Event
    {
    public:
        NT_CLASS_DEFAULTS(WindowCloseEvent)
        WindowCloseEvent(void) = default;

        NT_EVENT_CLASS_CATEGORY(EventCategoryApplication)
        NT_EVENT_CLASS_TYPE(WindowClose)
    };

    class NT_API AppTickEvent :
        public Event
    {
    public:
        NT_CLASS_DEFAULTS(AppTickEvent)
        AppTickEvent(void) = default;

        NT_EVENT_CLASS_CATEGORY(EventCategoryApplication)
        NT_EVENT_CLASS_TYPE(AppTick)
    };

    class NT_API AppUpdateEvent :
        public Event
    {
    public:
        NT_CLASS_DEFAULTS(AppUpdateEvent)
        AppUpdateEvent(void) = default;

        NT_EVENT_CLASS_CATEGORY(EventCategoryApplication)
        NT_EVENT_CLASS_TYPE(AppUpdate)
    };

    class NT_API AppRenderEvent :
        public Event
    {
    public:
        NT_CLASS_DEFAULTS(AppRenderEvent)
        AppRenderEvent(void) = default;

        NT_EVENT_CLASS_CATEGORY(EventCategoryApplication)
        NT_EVENT_CLASS_TYPE(AppRender)
    };
} // namespace Nt

#endif // _NT_CORE_EVENT_APPLICATION_EVENT_H_
