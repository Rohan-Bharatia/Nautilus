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

#ifndef _NT_CORE_EVENT_KEY_EVENT_H_
    #define _NT_CORE_EVENT_KEY_EVENT_H_

#include "Event.h"

namespace Nt
{
    class NT_API KeyEvent :
        public Event
    {
    public:
        NT_CLASS_DEFAULTS(KeyEvent)
        KeyEvent(void) = default;

        uint32 GetKeyCode(void) const;

        NT_EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        uint32 m_keyCode;

        KeyEvent(uint32 keyCode);
    };

    class NT_API KeyPressedEvent :
        public KeyEvent
    {
    public:
        NT_CLASS_DEFAULTS(KeyPressedEvent)
        KeyPressedEvent(void) = default;
        KeyPressedEvent(uint32 keyCode, uint32 repeatCount);

        uint32 GetRepeatCount(void) const;

        std::string ToString(void) const override;

        NT_EVENT_CLASS_TYPE(KeyPressed)

    private:
        uint32 m_repeatCount;
    };

    class NT_API KeyReleasedEvent :
        public KeyEvent
    {
    public:
        NT_CLASS_DEFAULTS(KeyReleasedEvent)
        KeyReleasedEvent(void) = default;
        KeyReleasedEvent(uint32 keyCode);

        std::string ToString(void) const override;

        NT_EVENT_CLASS_TYPE(KeyReleased)
    };

    class NT_API KeyTypedEvent :
        public KeyEvent
    {
    public:
        NT_CLASS_DEFAULTS(KeyTypedEvent)
        KeyTypedEvent(void) = default;
        KeyTypedEvent(uint32 keyCode);

        std::string ToString(void) const override;

        NT_EVENT_CLASS_TYPE(KeyTyped)
    };
} // namespace Nt

#endif // _NT_CORE_EVENT_KEY_EVENT_H_
