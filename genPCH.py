includes = [
    "algorithm",
    "any",
    "array",
    "atomic",
    "barrier",
    "bitset",
    "cassert",
    "ccomplex",
    "cctype",
    "cerrno",
    "cfenv",
    "cfloat",
    "cinttypes",
    "ciso646",
    "climits",
    "clocale",
    "cmath",
    "csetjmp",
    "csignal",
    "cstdarg",
    "cstddef",
    "cstdio",
    "cstdlib",
    "cstring",
    "ctime",
    "cwchar",
    "cwctype",
    "charconv",
    "chrono",
    "codecvt",
    "compare",
    "complex",
    "concepts",
    "condition_variable",
    "cstdbool",
    "cstdint",
    "cstdio",
    "cstdlib",
    "cstring",
    "ctime",
    "ctgmath",
    "cuchar",
    "deque",
    "exception",
    "execution",
    "expected",
    "filesystem",
    "float.,h"
    "format",
    "forward_list",
    "fstream",
    "functional",
    "future",
    "generator",
    "initializer_list",
    "iomanip",
    "ios",
    "iosfwd",
    "iostream",
    "istream",
    "iterator",
    "latch",
    "limits",
    "list",
    "locale",
    "map",
    "math.,h"
    "memory",
    "memory_resource",
    "mutex",
    "new",
    "numbers",
    "numeric",
    "optional",
    "ostream",
    "print",
    "queue",
    "random",
    "ranges",
    "ratio",
    "regex",
    "scoped_allocator",
    "semaphore",
    "set",
    "shared_mutex",
    "source_location",
    "span",
    "spanstream",
    "stack",
    "stacktrace",
    "stdexcept",
    "streambuf",
    "string",
    "string_view",
    "syncstream",
    "system_error",
    "text_encoding",
    "thread",
    "tuple",
    "type_traits",
    "typeindex",
    "typeinfo",
    "unordered_map",
    "unordered_set",
    "utility",
    "valarray",
    "variant",
    "vector"
]

with open("Nautilus/PCH.h", "w") as f:
    f.write("""#pragma region LICENSE

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
\n""")
    for include in includes:
        f.write(f"#if __has_include(<{include}>)\n")
        f.write(f"    #include <{include}>\n")
        f.write(f"#endif // __has_include(<{include}>)\n")
    f.write("\n#endif // _PCH_H_")
