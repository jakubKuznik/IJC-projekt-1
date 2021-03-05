// Solution for IJC-DU1, task a), 28.2.2021
// File:        primes.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
//   

#include <stdio.h>
#include "primes.h"
#include <time.h>


#define ARRAY_SIZE 200000000


int main()
{
    clock_t start;
    start = clock();
    
    //bitset_create(pole_bitu, ARRAY_SIZE);  //stack alocation
    bitset_alloc(pole_bitu, ARRAY_SIZE);     //heap alocation
    Eratosthenes(pole_bitu);
    
    //if bit is 0 == num is prime 

    for(bitset_index_t i = 0; i < bitset_size(pole_bitu); i++)
    {
        /*Vrites number that has bit value zero. 0 indicate that it is prime num.*/
        //if(!(bitset_getbit(pole_bitu, i))) printf("%ld\n",i);
    }
    
    
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    
    bitset_free(pole_bitu); 
    return 0;
}
