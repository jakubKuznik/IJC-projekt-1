// Solution for IJC-DU1, task a), 28.2.2021
// File:        bitset.h
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Template for working with array of bits  

#ifndef _BITSET_H
#define _BITSET_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"
#include <limits.h>


#define SIZE_U_INT (sizeof(unsigned long) * 8)
#define SIZE_U_INT_BYTES sizeof(unsigned long)
//First node of array is reserved for array size
//Second is reserved becouse we are dividing number so there has to be some reserve 
#define RESERVED 2 
#define BIT_0 0
#define BIT_1 1


typedef long unsigned *bitset_t;
typedef unsigned long bitset_index_t;


/* Vytvoří a inicializuje pole bitů na stacku. */
#define bitset_create(jmeno_pole, velikost) \
    _Static_assert(velikost >= 0, "ERROR: Array can not be negative size."); \
    long unsigned jmeno_pole[(velikost)/SIZE_U_INT + RESERVED] = {velikost, };\
    jmeno_pole[0] = velikost


/* Alokuje pole bitu na heapu je potřeba uvolnit pamět pomocí bitset_free() */
#define bitset_alloc(jmeno_pole,velikost)\
    _Static_assert(velikost >= 0, "CHYBA: Array can not be negative size."); \
    _Static_assert(velikost <= ULLONG_MAX, "CHYBA: Maximum size reached."); \
    bitset_t jmeno_pole =  (bitset_t) calloc(((velikost)/8) + SIZE_U_INT_BYTES, 1); \
    if(jmeno_pole == NULL) error_exit("bitset_alloc: Calloc error."); \
    jmeno_pole[0] = velikost

/* Uvolní paměť dynamicky (bitset_alloc) alokovaného pole */
#define bitset_free(jmeno_pole)\
    free(jmeno_pole)


/*                          MACROS                   */ 
/*These ll compile if there is NOT parameter USE_INLINE */
#ifndef USE_INLINE

    /* Získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1 */
    #define bitset_getbit(jmeno_pole, index) \
        (index >= jmeno_pole[0]) ? \
         error_exit("bitset_setbit: Index %lu mimo roysah 0..%lu", index),0 \
        :((jmeno_pole[index/SIZE_U_INT + RESERVED] >> (index % SIZE_U_INT )) & 1)  
        

    /* Nastaví zadaný bit v poli na hodnotu zadanou výrazem */
    #define bitset_setbit(jmeno_pole, index, vyraz) \
        if(index >= jmeno_pole[0]) error_exit("bitset_setbit: Index %lu mimo roysah 0..%lu", index);\
        ((vyraz != 0) ? \
        (jmeno_pole[index/SIZE_U_INT + 1] |= 1L << (index % SIZE_U_INT))\
        : (jmeno_pole[index/SIZE_U_INT + 1] &= ~(1L << (index%SIZE_U_INT))))    

    /* Vrátí deklarovanou velikost pole v bitech uloženou na indexu 0 */
    #define bitset_size(jmeno_pole) \
        jmeno_pole[0]


/*               INLINE FUNCTIONS                    */ 
/* These ll compile if there is parameter USE_INLINE */
#else

    /* Získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1 */
    inline char bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
    {
        if(index >= jmeno_pole[0])
            error_exit("bitset_setbit: Index %lu mimo roysah 0..%lu", index);
        return ((jmeno_pole[index/SIZE_U_INT + RESERVED] >> (index % SIZE_U_INT )) & 1);
    }
    /* Nastaví zadaný bit v poli na hodnotu zadanou výrazem */
    inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index,char vyraz)
    {
        if(index >= jmeno_pole[0])
            error_exit("bitset_setbit: Index %lu mimo roysah 0..%lu", index);
        ((vyraz != 0) ? (jmeno_pole[index/SIZE_U_INT + 1] |= 1L << (index % SIZE_U_INT)) : (jmeno_pole[index/SIZE_U_INT + 1] &= ~(1L << (index%SIZE_U_INT))));
    }
    
    /* Vrátí deklarovanou velikost pole v bitech uloženou na indexu 0 */
    inline long unsigned bitset_size(bitset_t jmeno_pole)
    {
        return jmeno_pole[0];
    }

#endif
#endif
