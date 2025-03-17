#pragma once

#ifndef _NT_WINDOW_WINDOW_BASE_h_
    #define _NT_WINDOW_WINDOW_BASE_h_

#include "WindowDesc.h"

#include <memory>

namespace nt
{
    class WindowBase
    {
    public:
        WindowBase()                                   = default;
        ~WindowBase()                                  = default;
        WindowBase(const WindowBase& other)            = default;
        WindowBase& operator=(const WindowBase& other) = default;

        virtual void initialize() = 0;
        virtual bool pollEvents() = 0;
        virtual void update()     = 0;
        virtual void destroy()    = 0;
        virtual void* getHandle() = 0;
    };

    std::unique_ptr<WindowBase> createWindow(const WindowDesc& desc);
} // namespace nt

#endif // _NT_WINDOW_WINDOW_BASE_h_