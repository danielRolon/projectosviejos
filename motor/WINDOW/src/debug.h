#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <stdio.h>
#include <stdarg.h>

bool PRINT_CONSOLE = true;

int print_console(const char* format, ...)
{
    if (!PRINT_CONSOLE) return 0;

    va_list arg;
    int done;

    va_start (arg, format);
    done = vfprintf(stdout, format, arg);
    va_end (arg);

    return done;
}

#endif