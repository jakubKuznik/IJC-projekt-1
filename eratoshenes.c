// Solution for IJC-DU1, task a), 28.2.2021
// File:        eratoshenes.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// File contain alorithm that find all the primes number 


#include "primes.h"
#include <math.h>


void Eratosthenes(bitset_t pole)
{
    bitset_index_t array_size = bitset_size(pole);
    //double e = sqrt(array_size);    
    bitset_index_t erat_max = array_size;

    //num 0 and 1 are not primes 
    bitset_setbit(pole, 0, BIT_1);
    bitset_setbit(pole, 1, BIT_1);


    
    for(bitset_index_t i = 2; i < 14144 ; i++)
    {
        if(!(bitset_getbit(pole, i)))  //if bit is 0
        {
         
            //find all multiples of number. and seting them to non primes 
            for(bitset_index_t index = 2*i; index < array_size ; index += i)             
            {
                bitset_setbit(pole, index, BIT_1);
            }
        }
    }
}
