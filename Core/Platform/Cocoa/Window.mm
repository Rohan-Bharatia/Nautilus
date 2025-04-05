//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#import "../Window.h"

#import "../../Logger.h"

@interface Window : NSObject
{
    NSWindow* m_window;
}

namespace nt
{

    void Window::create(const std::string& title)
    {
        m_window = [[NSWindow alloc] initWithContentRect:NSMakeRect(100, 100, 800, 600)
                                                styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable
                                                backing:NSBackingStoreBuffered
                                                    defer:NO];
        [m_window setTitle:[NSString stringWithUTF8String:title.c_str()]];
        [m_window makeKeyAndOrderFront:nil];
    }

    bool Window::pollEvents()
    {
        NSEvent* event;
        while ((event = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:nil inMode:NSDefaultRunLoopMode dequeue:YES]))
        {
            [NSApp sendEvent:event];
        }

        return true;
    }

    void Window::update()
    {
        [NSApp updateWindows];
    }

    void Window::destroy()
    {
        if (m_window)
        {
            [m_window close];
            [m_window release];
        }
    }

    void* Window::getNativeHandle()
    {
        return (void*)m_window;
    }

    float Window::getDeltaTime()
    {
        static CFTimeInterval lastTime = 0;
        CFTimeInterval currentTime     = CFAbsoluteTimeGetCurrent();
        float deltaTime                = (currentTime - lastTime);
        lastTime                       = currentTime;
        return deltaTime;
    }
}
