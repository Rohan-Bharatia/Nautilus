import os

def check_first_run() -> bool:
    test_file = os.path.join(os.path.dirname(__file__), 'PCH.txt')
    if os.path.exists(test_file):
        return True
    return False

if not check_first_run():
    with open('PCH.txt', 'w') as f:
        f.write('PCH has been generated!')
else:
    # A list of standard library headers to include in the precompiled header
    includes = [
        'algorithm',
        'any',
        'array',
        'atomic',
        'barrier',
        'bitset',
        'cassert',
        'ccomplex',
        'cctype',
        'cerrno',
        'cfenv',
        'cfloat',
        'cinttypes',
        'ciso646',
        'climits',
        'clocale',
        'cmath',
        'csetjmp',
        'csignal',
        'cstdarg',
        'cstddef',
        'cstdio',
        'cstdlib',
        'cstring',
        'ctime',
        'cwchar',
        'cwctype',
        'charconv',
        'chrono',
        'codecvt',
        'compare',
        'complex',
        'concepts',
        'condition_variable',
        'cstdbool',
        'cstdint',
        'cstdio',
        'cstdlib',
        'cstring',
        'ctime',
        'ctgmath',
        'cuchar',
        'deque',
        'exception',
        'execution',
        'expected',
        'filesystem',
        'float.,h'
        'format',
        'forward_list',
        'fstream',
        'functional',
        'future',
        'generator',
        'initializer_list',
        'iomanip',
        'ios',
        'iosfwd',
        'iostream',
        'istream',
        'iterator',
        'latch',
        'limits',
        'list',
        'locale',
        'map',
        'math.,h'
        'memory',
        'memory_resource',
        'mutex',
        'new',
        'numbers',
        'numeric',
        'optional',
        'ostream',
        'print',
        'queue',
        'random',
        'ranges',
        'ratio',
        'regex',
        'scoped_allocator',
        'semaphore',
        'set',
        'shared_mutex',
        'source_location',
        'span',
        'spanstream',
        'stack',
        'stacktrace',
        'stdexcept',
        'streambuf',
        'string',
        'string_view',
        'syncstream',
        'system_error',
        'text_encoding',
        'thread',
        'tuple',
        'type_traits',
        'typeindex',
        'typeinfo',
        'unordered_map',
        'unordered_set',
        'utility',
        'valarray',
        'variant',
        'vector'
    ]

    input_file = os.path.join(os.path.dirname(__file__), '..', 'Nautilus', 'PCH.h')

    # Generate the precompiled header file (C++ standard library headers and platform-specific library headers)
    with open(input_file, 'w') as f:
        f.flush()
        f.write('''#pragma region LICENSE

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

    #pragma once

    #ifndef _PCH_H_
        #define _PCH_H_

    #include "Core/Preprocessor.h"
    \n''')
        for include in includes:
            f.write(f'#if __has_include(<{include}>)\n')
            f.write(f'    #include <{include}>\n')
            f.write(f'#endif // __has_include(<{include}>)\n')
        f.write('''
    #if defined(NT_PLATFORM_WINDOWS)
        #include <Windows.h>
        #include <intrin.h>
    #elif defined(NT_PLATFORM_LINUX)
        #include <unistd.h>
        #include <fstream>
        #include <cstring>
        #include <cpuid.h>
        #include <X11/Xlib.h>
        #include <X11/Xutil.h>
        #include <X11/Xatom.h>
    #elif defined(NT_PLATFORM_MACOS)
        #ifdef __OBJC__
            #import <Cocoa/Cocoa.h>
            #import <QuartzCore/QuartzCore.h>
            #include <IOKit/ps/IOPowerSources.h>
            #include <IOKit/ps/IOPSKeys.h>
        #endif // __OBJC__
        #include <sys/sysctl.h>
        #include <sys/types.h>
        #include <sys/sysctl.h>
        #include <unistd.h>
        #include <cpuid.h>
    #elif defined(NT_PLATFORM_IOS)
        #ifdef __OBJC__
            #import <UIKit/UIKit.h>
            #import <QuartzCore/QuartzCore.h>
        #endif // __OBJC__
        #include <sys/sysctl.h>
        #include <sys/types.h>
        #include <sys/sysctl.h>
        #include <unistd.h>
        #include <cpuid.h>
    #elif defined(NT_PLATFORM_ANDROID)
        #include <android/log.h>
        #include <android/native_activity.h>
        #include <android/native_window.h>
        #include <android/asset_manager.h>
        #include <android/api-level.h>
        #include <unistd.h>
        #include <sys/sysinfo.h>
        #include <cpu-features.h>
    #elif defined(NT_PLATFORM_WASM)
        #include <emscripten/emscripten.h>
        #include <emscripten/html5.h>
    #endif // defined(NT_PLATFORM_WINDOWS), defined(NT_PLATFORM_LINUX), defined(NT_PLATFORM_MACOS), defined(NT_PLATFORM_IOS), defined(NT_PLATFORM_ANDROID), defined(NT_PLATFORM_WASM)
    ''')
        f.write('\n#endif // _PCH_H_')
