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

namespace nt
{
    WindowCocoa::WindowCocoa(const WindowDesc& desc) :
        m_desc(desc), m_window(nullptr),
        m_vao(0), m_vbo(0), m_ebo(0), m_vshader(0), m_fshader(0), m_program(0)
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
        NSOpenGLPixelFormatAttribute attrs[] =
        {
            NSOpenGLPFADoubleBuffer,
            NSOpenGLPFADepthSize,     24,
            NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
            0
        };

        NSOpenGLPixelFormat* pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
        NSOpenGLContext* ctx    = [[NSOpenGLContext alloc] initWithFormat:pf shareContext:nil];
        EGLDisplay display      = [EAGLContext currentContext].eglDisplay;
        EGLConfig config;
        EGLint num_configs;
        eglChooseConfig(display, attrs, &config, 1, &num_configs);
        EGLSurface surface      = eglCreateWindowSurface(display, config, (EGLNativeWindowType)[ctx view], NULL);
        EGLContext ctx          = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);

        eglMakeCurrent(display, surface, surface, ctx);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    void WindowCocoa::useShader(std::string vertex, std::string fragment)
    {
        // Create and compile vertex shader
        m_vshader                = glCreateShader(GL_VERTEX_SHADER);
        const char* vertexSource = vertex.c_str();
        glShaderSource(m_vshader, 1, &vertexSource, nullptr);
        glCompileShader(m_vshader);

        // Create and compile fragment shader
        m_fshader                  = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fragmentSource = fragment.c_str();
        glShaderSource(m_fshader, 1, &fragmentSource, nullptr);
        glCompileShader(m_fshader);

        // Create program and attach shaders
        GLuint program = glCreateProgram();
        glAttachShader(program, m_vshader);
        glAttachShader(program, m_fshader);
        glLinkProgram(program);

        // Use program
        glUseProgram(program);

        // Delete shaders (program has a reference to them)
        glDeleteShader(m_vshader);
        glDeleteShader(m_fshader);

        // Store program ID
        m_program = program;
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

    void WindowCocoa::clear(const Color& color)
    {
        // Clear screen with specified color
        glClearColor(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowCocoa::swapBuffers()
    {
        // Swap front and back buffers
        [m_window display];
    }

    void WindowCocoa::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        // Delete program
        glDeleteProgram(m_program);

        // Delete OpenGL context
        [EAGLContext setCurrentContext:nil];

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
