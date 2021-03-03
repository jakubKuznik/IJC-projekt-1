// Solution for IJC-DU1, task a), 28.2.2021
// File:        bitset.h
// Author:      Jakub Kuzník, FIT
// School acco. xkuzni04
// Compiled:    gcc 9.9.3.0

#include <stdio.h>
#include "primes.h"

#define ARRAY_SIZE 1000


int main()
{
    bitset_alloc(pole_bitu, ARRAY_SIZE);


    /*
    for(int i = 0; i < ARRAY_SIZE; i++)
        bitset_setbit(pole_bitu, i, BIT_1);
    */
    printf("%ld", pole_bitu[0]);

    Eratosthenes();
    bitset_free(pole_bitu);
    return 0;

     
}

/*
fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
*/     