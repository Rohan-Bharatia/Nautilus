#pragma once

#ifndef _NT_CORE_h_
	#define _NT_CORE_h_

#ifdef NT_PLATFORM_WINDOWS
	#ifdef NT_BUILD_DLL
		#define NT_API __declspec(dllexport)
	#else // (NOT) NT_BUILD_DLL
		#define NT_API __declspec(dllimport)
	#endif //NT_BUILD_DLL
#else // NT_PLATFORM_WINDOWS
	#error Nautilus Engine only supports Windows!
#endif // NT_PLATFORM_WINDOWS

#endif // _NT_CORE_h_