
#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#ifndef _NT_CORE_WINDOW_CPP_
    #define _NT_CORE_WINDOW_CPP_

#include "Window.h"

namespace Nt
{
    Window::Window(WindowDesc desc) : 
	m_desc(desc)
    {
        NT_ASSERT(desc.title.empty(), "Window title must not be empty!");
    	NT_ASSERT(desc.position.x >= 0, "Window y position must be in valid bounds!");
    	NT_ASSERT(desc.position.y >= 0, "Window y position must be in valid bounds!");
    	NT_ASSERT((desc.width - desc.position.x) > 0, "Window width must be in valid bounds!");
    	NT_ASSERT((desc.height - desc.position.y) > 0, "Window height must be in valid bounds!");
    }

    void Window::SetEventCallback(EventCallbackFn callback)
    {
        m_eventCallback = callback;
    }

    WindowDesc Window::GetDescription(void)
    {
        return m_desc;
    }

    WindowHandle Window::GetHandle(void)
    {
        return m_handle;
    }
} // namespace Nt

#endif // _NT_CORE_WINDOW_CPP_
