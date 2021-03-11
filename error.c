// Solution for IJC-DU1, task a), 28.2.2021
// File:        error.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// This is erorr template that can be used in any programe  


#include <stdio.h>
#include "error.h"
#include <stdarg.h>
#include <stdlib.h>


/**
 * Write error and program continue 
*/
void warning_msg(const char *fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    fprintf(stderr, "CHYBA:");
    vfprintf(stderr, fmt, arg);
}

/**
 * Write error and end program 
*/
void error_exit(const char *fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    fprintf(stderr, "CHYBA:");
    vfprintf(stderr, fmt, arg);
    exit(1); 
}