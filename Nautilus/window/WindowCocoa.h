#pragma once

#ifndef _NT_WINDOW_WINDOW_COCAO_h_
    #define _NT_WINDOW_WINDOW_COCAO_h_

#include "WindowBase.h"

#import <Cocoa/Cocoa.h>

namespace nt
{
    class WindowCocoa :
        public WindowBase
    {
    public:
        WindowCocoa()                                    = default;
        WindowCocoa(const WindowDesc& desc);
        ~WindowCocoa()                                   = default;
        WindowCocoa(const WindowCocoa& other)            = default;
        WindowCocoa& operator=(const WindowCocoa& other) = default;

        void initialize() override;
        bool pollEvents() override;
        void update() override;
        void destroy() override;

        void* getHandle() override;

    private:
        NSWindow* m_window;
        WindowDesc m_desc;
    };
} // namespace nt

#endif // _NT_WINDOW_WINDOW_COCAO_h_