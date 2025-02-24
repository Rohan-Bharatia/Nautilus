//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                               ...
//                  Copyright (C) 2024 Rohan Bharatia

#pragma once

#ifndef _NT_NAUTILUS_h_
    #define _NT_NAUTILUS_h_

// C/C++ exit codes
#define NT_EXIT_SUCCESS 0
#define NT_EXIT_MINOR_ERROR 1
#define NT_EXIT_MAJOR_ERROR 2
#define NT_EXIT_CMD_NOT_FOUND 127
#define NT_EXIT_SIGILL 132
#define NT_EXIT_SIGTRAP 133
#define NT_EXIT_SIGABRT 134
#define NT_EXIT_SIGFPE 136
#define NT_EXIT_STACK_OVERFLOW 137
#define NT_EXIT_SIGBUS 138
#define NT_EXIT_SEGMENTATION_FAULT 139
#define NT_EXIT_SIGXCPU 152 | 158
#define NT_EXIT_SIGXFSZ 153 | 159

#endif // _NT_NAUTILUS_h_