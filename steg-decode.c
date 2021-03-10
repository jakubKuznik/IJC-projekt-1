
// Solution for IJC-DU1, task a), 28.2.2021
// File:        steg-decode.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
//  

#include "ppm.h"
#include "error.h"
#include "primes.h"

#include <limits.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
        error_exit("Bad execution (hint: ./steg-decode file)\n");

    struct ppm *image;

    image = ppm_read(argv[1]);




    ppm_free(image);
    return 0;
}