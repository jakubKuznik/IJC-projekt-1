// Solution for IJC-DU1, task b), 28.2.2021
// File:        error.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.

#include <stdio.h>
#include "error.h"
#include <stdarg.h>
#include <stdlib.h>


void warning_msg(const char *fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    fprintf(stderr, "CHYBA:");
    vfprintf(stderr, fmt, arg);
}


void error_exit(const char *fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    fprintf(stderr, "CHYBA:");
    vfprintf(stderr, fmt, arg);
    exit(1); 
}