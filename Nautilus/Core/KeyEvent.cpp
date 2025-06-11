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

#ifndef _NT_CORE_EVENT_KEY_EVENT_CPP_
    #define _NT_CORE_EVENT_KEY_EVENT_CPP_

#include "KeyEvent.h"

namespace Nt
{
    uint32 KeyEvent::GetKeyCode(void) const
    {
        return m_keyCode;
    }

    KeyEvent::KeyEvent(uint32 keyCode) : 
        m_keyCode(keyCode)
    {}

    KeyPressedEvent::KeyPressedEvent(uint32 keyCode, uint32 repeatCount) : 
        KeyEvent(keyCode), m_repeatCount(repeatCount)
    {}

    uint32 KeyPressedEvent::GetRepeatCount(void) const
    {
        return m_repeatCount;
    }

    std::string KeyPressedEvent::ToString(void) const
    {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
        return ss.str();
    }

    KeyReleasedEvent::KeyReleasedEvent(uint32 keyCode) :
        KeyEvent(keyCode)
    {}

    std::string KeyReleasedEvent::ToString(void) const
    {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << m_keyCode;
        return ss.str();
    }

    KeyTypedEvent::KeyTypedEvent(uint32 keyCode) :
        KeyEvent(keyCode)
    {}

    std::string KeyTypedEvent::ToString(void) const
    {
        std::stringstream ss;
        ss << "KeyTypedEvent: " << m_keyCode;
        return ss.str();
    }
} // namespace Nt

#endif // _NT_CORE_EVENT_KEY_EVENT_CPP_