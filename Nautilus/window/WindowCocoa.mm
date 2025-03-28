#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2025 Rohan Bharatia

#pragma endregion LICENSE

#import "WindowCocoa.h"

#import "../core/Timer.h"

#import <OpenGL/gl.h>
#import <EGL/egl.h>

namespace nt
{
    WindowCocoa::WindowCocoa(const WindowDesc& desc) :
        m_desc(desc), m_scale(1.0f, 1.0f, 1.0f),  m_window(nullptr)
    {}

    void WindowCocoa::initialize()
    {
        // Set window properties
        NSWindowStyleMask style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable;
        if (!m_desc.resizable)
            style &= ~NSWindowStyleMaskResizable;
        if (!m_desc.movable)
            style &= ~NSWindowStyleMaskTitled;
        if (!m_desc.closable)
            style &= ~NSWindowStyleMaskClosable;
        if (!m_desc.maximizable)
            style &= ~NSWindowStyleMaskMiniaturizable;
        if (!m_desc.minimizable)
            style &= ~NSWindowStyleMaskMiniaturizable;
        if (!m_desc.canFullscreen)
            style &= ~NSWindowStyleMaskFullSizeContentView;

        // Create window
        m_window = [[NSWindow alloc] initWithContentRect:NSMakeRect(m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height)
                                               styleMask:style
                                                 backing:NSBackingStoreBuffered
                                                   defer:NO];

        // Center window (if necessary)
        if (m_desc.centered)
        {
            NSRect screenRect = [[NSScreen mainScreen] frame];
            NSRect windowRect = [m_window frame];
            float x           = (screenRect.size.width - windowRect.size.width) / 2;
            float y           = (screenRect.size.height - windowRect.size.height) / 2;
            [m_window setFrameOrigin:NSMakePoint(x, y)];
        }

        // Set window title & color
        [m_window setTitle:m_desc.title.c_str()];
        [m_window setBackgroundColor:[NSColor colorWithCalibratedRed:m_desc.backgroundColor.red / 255.0
                                                                 green:m_desc.backgroundColor.green / 255.0
                                                                  blue:m_desc.backgroundColor.blue / 255.0
                                                                 alpha:1.0]];

        // Set window states
        if (m_desc.visible)
        {
            if (m_desc.fullscreen)
            {
                [m_window setContentSize:[[NSScreen mainScreen] frame].size];
                [m_window setFrame:[[NSScreen mainScreen] frame] display:YES];
            }
            if (m_desc.maximized)
            {
                [m_window setContentSize:[[NSScreen mainScreen] frame].size];
                [m_window setFrame:[[NSScreen mainScreen] frame] display:YES];
            }
            if (m_desc.minimized)
                [m_window miniaturize:nil];
            if (!m_desc.fullscreen && !m_desc.maximized && !m_desc.minimized)
                [m_window orderOut:nil];
        }
        else
            [m_window makeKeyAndOrderFront:nil];

        // Set focus
        if (m_desc.focus)
            [m_window makeFirstResponder:nil];

        // Set modal state
        if (m_desc.modal)
            [NSApp runModalForWindow:m_window];

        // Initialize OpenGL
        EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        EGLSurface surface = eglCreateWindowSurface(display, EGL_NO_CONFIG, [m_window CGLContextObj], NULL);
        EGLContext context = eglCreateContext(display, EGL_NO_CONFIG, EGL_NO_CONTEXT, NULL);
        eglMakeCurrent(display, surface, surface, context);

        glEnable(GL_DEPTH_TEST);

        NSView view  = [[NSView alloc] initWithFrame:NSMakeRect(0, 0, m_desc.width, m_desc.height)];
        NSRect frame = [view frame];
        glViewport(0, 0, frame.size.width, frame.size.height);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    bool WindowCocoa::pollEvents()
    {
        // Poll events
        NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                            untilDate:[NSDate distantPast]
                                              inMode:NSDefaultRunLoopMode
                                             dequeue:YES];

        if (event)
        {
            [NSApp sendEvent:event];
            return true;
        }

        return false;
    }

    void WindowCocoa::update()
    {
        // Update window
        [m_window display];

        // Callback function
        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void WindowCocoa::frame(std::vector<ReadableVertex>& vertices)
    {
        // Enable vertex arrays
        glVertexPointer(3, GL_FLOAT, sizeof(ReadableVertex), &vertices[0].position);
        glEnableClientState(GL_VERTEX_ARRAY);

        // Enable texture arrays
        glTexCoordPointer(2, GL_FLOAT, sizeof(ReadableVertex), &vertices[0].uv);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        // Enable color arrays
        glColorPointer(4, GL_FLOAT, sizeof(ReadableVertex), &vertices[0].color);
        glEnableClientState(GL_COLOR_ARRAY);

        // Manipulate w/ matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(m_pitch.inRadians(), 1.0f, 0.0f, 0.0f);
        glRotatef(m_roll.inRadians(), 0.0f, 1.0f, 0.0f);
        glRotatef(m_yaw.inRadians(), 0.0f, 0.0f, 1.0f);
        glTranslatef(m_translation.x, m_translation.y, m_translation.z);
        glScalef(m_scale.x, m_scale.y, m_scale.z);

        // Draw the vertices
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        // Disable v/t/c arrays
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
    }

    void WindowCocoa::clear(const Color& color)
    {
        glClearColor(color.red / 255.0, color.green / 255.0, color.blue / 255.0, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowCocoa::swapBuffers()
    {
        eglSwapBuffers(eglGetDisplay(EGL_DEFAULT_DISPLAY), eglGetCurrentSurface(EGL_DRAW));
    }

    void WindowCocoa::translate(float x, float y, float z)
    {
        m_translation += Vec3f(x, y, z);
    }

    void WindowCocoa::scale(float x, float y, float z)
    {
        m_scale += Vec3f(x, y, z);
    }

    void WindowCocoa::rotateX(float x)
    {
        m_pitch += radians(x);
    }

    void WindowCocoa::rotateY(float y)
    {
        m_roll += radians(y);
    }

    void WindowCocoa::rotateZ(float z)
    {
        m_yaw += radians(z);
    }

    void WindowCocoa::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Destroy OpenGL
        EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        eglDestroyContext(display, eglGetCurrentContext());
        eglDestroySurface(display, eglGetCurrentSurface(EGL_DRAW));
        eglTerminate(display);

        // Destroy window
        if (m_window)
            [m_window close];
    }

    void* WindowCocoa::getHandle()
    {
        return static_cast<void*>(m_window);
    }

    WindowDesc WindowCocoa::getDescription()
    {
        return m_desc;
    }
} // namespace nt
