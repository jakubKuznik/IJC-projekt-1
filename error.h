// Solution for IJC-DU1, task a), 28.2.2021
// File:        error.h
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Header fille for error.c 


/**
 * Write error and program continue 
*/
void warning_msg(const char *fmt, ...);


/**
 * Write error and end program 
*/
void error_exit(const char *fmt, ...);