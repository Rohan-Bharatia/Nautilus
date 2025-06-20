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

#ifndef _NT_CORE_WASM_WINDOW_CPP_
    #define _NT_CORE_WASM_WINDOW_CPP_

#include "../Window.h"

#include "../Logger.h"

namespace Nt
{
    bool Window::Initialize(void)
    {
	m_handle.document = emscripten::val::global("document");

	if (!m_handle.document)
	{
	    Logger::Error("Failed to create document!");
	    return false;
	}

	m_handle.canvas = m_handle.document.call<emscripten::val>("createElement");

	std::ostringstream bgColorCSS;
    	bgColorCSS << "rgba("
        	   << m_desc.bgColor.r << ","
                   << m_desc.bgColor.g << ","
                   << m_desc.bgColor.b << ","
		   << m_desc.bgColor.a << ")";

	m_handle.canvas["width"]  = emscripten::val(m_desc.width);
	m_handle.canvas["height"] = emscripten::val(m_desc.height);
	m_handle.canvas["style"].set("backgroundColor", emscripten::val(bgColorCSS.str()));
	m_handle.canvas["style"].set("position", emscripten::val("absolute"));
	m_handle.canvas["style"].set("left", emscripten::val(std::to_string(m_desc.position.x) + "px"));
	m_handle.canvas["style"].set("top", emscripten::val(std::to_string(m_desc.position.y) + "px"));
    }

    void Window::OnUpdate(void)
    {
    	m_handle.document.call<void>("addEventListener", emscripten::val("keydown"),
        			     emscripten::val::module_property("dynCall_vii").call<emscripten::val>("bind",
				     emscripten::val::module_property("dynCall_vii"),
            	EM_JS(int, [](int, int)
	        {
                    KeyPressedEvent event(emscripten::val::global("event")["keyCode"].as<int32>(),
				    	  emscripten::val::global("event")["repeat"].as<bool>());
                    m_eventCallback(event);
                    return 0;
            	}, 0, 0)
            )
    	);

    	m_handle.document.call<void>("addEventListener", emscripten::val("keyup"),
        			     emscripten::val::module_property("dynCall_vii").call<emscripten::val>("bind",
				     emscripten::val::module_property("dynCall_vii"),
            	EM_JS(int, [](int, int)
		{
                    KeyReleasedEvent event(emscripten::val::global("event")["keyCode"].as<int32>());
                    m_eventCallback(event);
                    return 0;
            	}, 0, 0)
            )
    	);

    	m_handle.document.call<void>("addEventListener", emscripten::val("keypress"),
        			     emscripten::val::module_property("dynCall_vii").call<emscripten::val>("bind",
				     emscripten::val::module_property("dynCall_vii"),
            	EM_JS(int, [](int, int)
		{
                    KeyTypedEvent event(emscripten::val::global("event")["charCode"].as<int32>());
                    m_eventCallback(event);
                    return 0;
            	}, 0, 0)
            )
    	);

    	m_handle.canvas.call<void>("addEventListener", emscripten::val("mousedown"),
        		       	   emscripten::val::module_property("dynCall_vii").call<emscripten::val>("bind",
			           emscripten::val::module_property("dynCall_vii"),
            	EM_JS(int, [](int, int)
	    	{
                    MouseButtonPressedEvent event(emscripten::val::global("event")["button"].as<int32>());
                    m_eventCallback(event);
                    return 0;
            	}, 0, 0)
            )
    	);

    	m_handle.canvas.call<void>("addEventListener", emscripten::val("mouseup"),
        	      		   emscripten::val::module_property("dynCall_vii").call<emscripten::val>("bind",
		      		   emscripten::val::module_property("dynCall_vii"),
            	EM_JS(int, [](int, int)
		{
                    MouseButtonReleasedEvent event(emscripten::val::global("event")["button"].as<int32>());
                    m_eventCallback(event);
                    return 0;
            	}, 0, 0)
            )
    	);

    	m_handle.canvas.call<void>("addEventListener", emscripten::val("mousemove"),
			  	   emscripten::val::module_property("dynCall_vii").call<emscripten::val>("bind",
			  	   emscripten::val::module_property("dynCall_vii"),
            	EM_JS(int, [](int, int)
		{
                    MouseMovedEvent event(emscripten::val::global("event")["offetX"].as<float32>(),
				    	  emscripten::val::global("event")["offsetY"].as<float32>());
                    m_eventCallback(event);
                    return 0;
            	}, 0, 0)
            )
    	);

    	m_handle.canvas.call<void>("addEventListener", emscripten::val("wheel"),
			  	   emscripten::val::module_property("dynCall_vii").call<emscripten::val>("bind",
			  	   emscripten::val::module_property("dynCall_vii"),
            	EM_JS(int, [](int, int)
		{
                    MouseScrolledEvent event(emscripten::val::global("event")["deltaX"].as<float32>(),
				    	     emscripten::val::global("event")["deltaY"].as<float32>());
                    m_eventCallback(event);
                    return 0;
		}, 0, 0)
            )
   	);

    	emscripten_set_resize_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, nullptr, false,
        			       [](int, const EmscriptenUiEvent* e, void*) -> EM_BOOL
	{
            WindowResizeEvent event(e->windowInnerWidth, e->windowInnerHeight);
            m_eventCallback(event);
            return true;
	});

   	m_handle.document.call<void>("addEventListener", emscripten::val("beforeunload"),
		      	 	     emscripten::val::module_property("dynCall_vii").call<emscripten::val>("bind",
		       		     emscripten::val::module_property("dynCall_vii"),
       		EM_JS(int, [](int, int)
		{
                    WindowCloseEvent event;
                    m_eventCallback(event);
                    return 0;
            	}, 0, 0)
            )	
    	);
    }

    void Window::Shutdown(void)
    {
	// Nothing to destroy
    }

    Rect Window::GetSize(void)
    {
	float32 width, height;
	emscripten_get_element_css_size("#canvas", &width, &height);
	return Rect(0, 0, width, height);
    }
} // namespace Nt

#endif // _NT_CORE_WASM_WINDOW_CPP_
