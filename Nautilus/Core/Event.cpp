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

#ifndef _NT_CORE_EVENT_EVENT_CPP_
    #define _NT_CORE_EVENT_EVENT_CPP_

#include "Event.h"

namespace Nt
{
    void Event::SetHandled(bool handled)
    {
        m_handled = handled;
    }

    bool Event::IsHandled(void) const
    {
        return m_handled;
    }

	std::string Event::ToString(void) const
    {
        return GetName();
    }

    bool Event::IsInCategory(EventCategory category) const
    {
        return GetCategoryFlags() & category;
    }

    EventDispatcher::EventDispatcher(Event& event) 
        : m_event(event)
    {}

    std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
} // namespace Nt

#endif // _NT_CORE_EVENT_EVENT_CPP_