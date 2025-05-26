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

#ifndef _NT_CORE_EVENT_EVENT_INL_
    #define _NT_CORE_EVENT_EVENT_INL_

#include "Event.h"

namespace Nt
{
    template<class T, typename F>
    bool EventDispatcher::Dispatch(const F& func)
    {
        if (m_event.GetEventType() == T::GetStaticType())
        {
            m_event.SetHandled(func(static_cast<T&>(m_event)));
            return true;
        }
        return false;
    }
} // namespace Nt

#endif // _NT_CORE_EVENT_EVENT_INL_