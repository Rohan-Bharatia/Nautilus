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

#pragma once

#ifndef _NT_CORE_WINDOW_H_
    #define _NT_CORE_WINDOW_H_

#include "Vertex.h"
#include "KeyEvent.h"
#include "MouseEvent.h"
#include "ApplicationEvent.h"

namespace Nt
{
    struct NT_API WindowDesc
    {
        std::string title;
        Vec2u position;
        uint32 width;
	uint32 height;
	Color bgColor;
    };

    struct NT_API WindowHandle
    {
    #if defined(NT_PLATFORM_WINDOWS)
	HINSTANCE hinstance;
	HWND hwnd;
    #elif defined(NT_PLATFORM_LINUX)
	Display* display;
	::Window window;
	Colormap colormap;
    #elif defined(NT_PLATFORM_MACOS)
	#ifdef __OBJC__
	    NSWindow* window;
	    id<NSWindowDelegate> delegate;
	#else // (NOT) __OBJC__
	    void* window;
	    void* delegate;
	#endif // __OBJC__
    #elif defined(NT_PLATFORM_IOS)
	#ifdef __OBJC__
            UIWindow* window;
            id<UIWindowSceneDelegate> delegate;
        #else // (NOT) __OBJC__
            void* window;
            void* delegate;
        #endif // __OBJC__
    #elif defined(NT_PLATFORM_ANDROID)
    	android_app* app;
	ANativeActivity* activity;
	ANativeWindow* window;
    #elif defined(NT_PLATFORM_WASM)
	emscripten::val document;
	emscripten::val canvas;
    #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID), defined(NT_PLATFORM_WASM)
    };

    class NT_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

	NT_CLASS_DEFAULTS(Window)
	Window(WindowDesc desc);

	void SetEventCallback(EventCallbackFn callback);

	bool Initialize(void);
	void OnUpdate(void);
	void Shutdown(void);

	WindowDesc GetDescription(void);
	WindowHandle GetHandle(void);

    private:
    #if defined(NT_PLATFORM_WINDOWS)
    	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wprm, LPARAM lprm);
    #elif defined(NT_PLATFORM_ANDROID)
	static int32 HandleInput(struct android_app* app, AInputEvent* event);
	static void HandleCommand(struct android_app* app, int32 cmd);
    #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_ANDROID)

	WindowDesc m_desc;
	WindowHandle m_handle;
	EventCallbackFn m_eventCallback;
    };
} // namespace Nt

#endif // _NT_CORE_WINDOW_H_
