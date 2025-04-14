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

#ifndef _NT_CORE_PLATFORM_EMSCRIPTEN_WINDOW_CPP_
    #define _NT_CORE_PLATFORM_EMSCRIPTEN_WINDOW_CPP_

#include "../Window.h"

#include "../../Logger.h"

namespace nt
{
    static val document = val::global("document");
    static val window   = val::global("window");

    bool Window::initialize(const WindowDesc& desc)
    {
        m_desc = desc;

        // Get or create canvas
        val canvas = document.call<val>("getElementById", std::string("nautilus-canvas"));

        if (canvas.isUndefined() || canvas.isNull())
        {
            canvas = document.call<val>("createElement", std::string("canvas"));
            canvas.set("id", std::string("nautilus-canvas"));
            document["body"].call<void>("appendChild", canvas);
        }

        m_handle.canvas = canvas;

        canvas["width"]  = desc.width;
        canvas["height"] = desc.height;

        // Style canvas for position and fullscreen options
        canvas["style"].set("position", "absolute");
        canvas["style"].set("left", std::to_string(desc.x) + "px");
        canvas["style"].set("top", std::to_string(desc.y) + "px");

        if (desc.fullscreen)
        {
            canvas["style"].set("width", "100%");
            canvas["style"].set("height", "100%");
        }

        if (desc.title.length())
            document.set("title", val(desc.title));

        if (desc.onCreate)
            desc.onCreate();

        return true;
    }

    bool Window::pollEvents()
    {
        // Events are handled by HTML5
        return true;
    }

    void Window::update()
    {
        // The window is updated automatically with HTML5

        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void Window::close()
    {
        if (m_desc.onClose)
            m_desc.onClose();

        if (!m_handle.canvas.isNull() && !m_handle.canvas.isUndefined())
            m_handle.canvas.["remove"]();
    }

    const WindowDesc& Window::getWindowDesc() const
    {
        return m_desc;
    }

    const NativeHandle& Window::getHandle() const
    {
        return m_handle;
    }
} // namespace nt

#endif // _NT_CORE_PLATFORM_EMSCRIPTEN_WINDOW_CPP_
