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

#ifndef _NT_WINDOW_WINDOW_WIN32_cpp_
    #define _NT_WINDOW_WINDOW_WIN32_cpp_

#include "WindowWin32.h"

namespace nt
{
    WindowWin32::WindowWin32(const WindowDesc& desc, const GraphicsAPI& api) :
        m_desc(desc), m_api(api), m_hwnd(nullptr), m_hinstance(nullptr),
        m_vao(0), m_vbo(0), m_program(0), m_vertex(0), m_fragment(0)
    {}

    void WindowWin32::initialize()
    {
        m_hinstance = GetModuleHandle(NULL);

        // Create window context
        WNDCLASSEXA wc{};
        wc.cbSize        = sizeof(WNDCLASSEXA);
        wc.style         = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc   = &WindowWin32::wndProc;
        wc.hInstance     = m_hinstance;
        wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.lpszClassName = "NautilusWindowClass";


        RegisterClassExA(&wc);

        // Create window
        m_hwnd = CreateWindowExA(0, wc.lpszClassName, m_desc.title.c_str(), WS_OVERLAPPEDWINDOW,
                                 m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height,
                                 nullptr, nullptr, m_hinstance, nullptr);

        SetWindowLongPtr(m_hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

        ShowWindow(m_hwnd, SW_SHOWDEFAULT);
        UpdateWindow(m_hwnd);

        // Initialize GLAD
        gladLoadGL((GLADloadfunc)wglGetProcAddress);

        // Initialize OpenGL
        HDC hdc = GetDC(m_hwnd);

        PIXELFORMATDESCRIPTOR pfd{};
        pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.nVersion   = 1;
        pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cDepthBits = 24;
        pfd.iLayerType = PFD_MAIN_PLANE;

        SetPixelFormat(hdc, ChoosePixelFormat(hdc, &pfd), &pfd);

        wglMakeCurrent(hdc, wglCreateContext(hdc));

        // Enable depth (3d) support
        glEnable(GL_DEPTH_TEST);

        // Callback function
        if (m_desc.onCreate)
            m_desc.onCreate();
    }

    void WindowWin32::shader(std::string vertex, std::string fragment)
    {
        // Create and compile vertex shader
        m_vertex                 = glCreateShader(GL_VERTEX_SHADER);
        const char* vertexSource = vertex.c_str();
        glShaderSource(m_vertex, 1, &vertexSource, NULL);
        glCompileShader(m_vertex);

        // Create and compile fragment shader
        m_fragment                 = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fragmentSource = fragment.c_str();
        glShaderSource(m_fragment, 1, &fragmentSource, NULL);
        glCompileShader(m_fragment);

        // Create and link program
        m_program = glCreateProgram();
        glAttachShader(m_program, m_vertex);
        glAttachShader(m_program, m_fragment);
        glLinkProgram(m_program);

        // Use program
        glUseProgram(m_program);
    }

    bool WindowWin32::pollEvents()
    {
        MSG msg{};
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                return false;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return true;
    }

    void WindowWin32::update()
    {
        UpdateWindow(m_hwnd);

        // Callback function
        if (m_desc.onUpdate)
            m_desc.onUpdate();
    }

    void WindowWin32::frame(std::vector<ReadableVertex> vertices)
    {
        // Render
        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);

        glGenBuffers(1, &m_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(ReadableVertex), vertices.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ReadableVertex), (void*)(sizeof(float) * 3)); // Position

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(ReadableVertex), (void*)(sizeof(float) * 2)); // Texture

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(ReadableVertex), (void*)(sizeof(float) * 4)); // Color

        glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        glDisableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
    }

    void WindowWin32::clear(const Color& color)
    {
        glClearColor(color.red / 255.0f, color.green / 255.0f, color.blue / 255.0f, color.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void WindowWin32::swapBuffers()
    {
        SwapBuffers(GetDC(m_hwnd));
    }

    void WindowWin32::destroy()
    {
        // Callback function
        if (m_desc.onDestroy)
            m_desc.onDestroy();

        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteProgram(m_program);
        glDeleteShader(m_vertex);
        glDeleteShader(m_fragment);

        wglMakeCurrent(GetDC(m_hwnd), NULL);
        wglDeleteContext(wglGetCurrentContext());

        if (m_hwnd)
            DestroyWindow(m_hwnd);
    }

    void* WindowWin32::getHandle()
    {
        return static_cast<void*>(m_hwnd);
    }

    WindowDesc WindowWin32::getDescription()
    {
        return m_desc;
    }

    LRESULT CALLBACK WindowWin32::wndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
    {
        WindowWin32* win = nullptr;

        if (msg == WM_NCCREATE)
        {
            CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lp);
            win              = reinterpret_cast<WindowWin32*>(cs->lpCreateParams);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(win));
        }
        else
            win = reinterpret_cast<WindowWin32*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

        switch (msg)
        {
            case WM_DESTROY:
            case WM_CLOSE:
                PostQuitMessage(0);
                break;
            case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HBRUSH hbrush = CreateSolidBrush(RGB(win->m_desc.backgroundColor.red,
                                                     win->m_desc.backgroundColor.green,
                                                     win->m_desc.backgroundColor.blue));
                HDC hdc       = BeginPaint(hwnd, &ps);
                FillRect(hdc, &ps.rcPaint, hbrush);
                EndPaint(hwnd, &ps);
                DeleteObject(hbrush);
                break;
            }
            default:
                return DefWindowProc(hwnd, msg, wp, lp);
        }

        return 0;
    }
} // namespace nt

#endif // _NT_WINDOW_WINDOW_WIN32_cpp_
