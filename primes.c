// Solution for IJC-DU1, task a), 28.2.2021
// File:        bitset.h
// Author:      Jakub Kuzník, FIT
// School acco. xkuzni04
// Compiled:    gcc 9.9.3.0

#include <stdio.h>
#include "primes.h"



int main()
{
    unsigned long size = 1000;
    bitset_create(pole_bitu, size);

    {
    for(int i = 0; i < size; i++)
        bitset_setbit(pole_bitu, size, BIT_1);
    }

    Eratosthenes();
    return 0;

     
}

/*
fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
*/     