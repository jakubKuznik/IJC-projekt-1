// Solution for IJC-DU1, task a), 28.2.2021
// File:        bitset.h
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Template for working with array of bits  


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"
#include <limits.h>

#define SIZE_U_INT (sizeof(unsigned long) * 8)
#define SIZE_U_INT_BYTES sizeof(unsigned long)
#define RESERVED 1 //First node of array is reserved for array size 

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
    if(jmeno_pole == NULL) error_exit("bitset_alloc: Chyba alokace paměti"); \
    jmeno_pole[0] = velikost

/* Uvolní paměť dynamicky (bitset_alloc) alokovaného pole */
#define bitset_free(jmeno_pole)\
    free(jmeno_pole)






/* bitset_getbit(), bitset_setbit(), bitset_size()
   Are macros that can be Inline functions        */
/* These ll compile if there is parameter USE_INLINE */
//#ifdef USE_INLINE



/*These ll compile if there is NOT parameter USE_INLINE */
#ifndef USE_INLINE


    /* Získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1 */
    #define bitset_getbit(jmeno_pole, index) \
        ((jmeno_pole[index/SIZE_U_INT + RESERVED] >> (index % SIZE_U_INT )) & 1)

    /* Nastaví zadaný bit v poli na hodnotu zadanou výrazem */
    #define bitset_setbit(jmeno_pole, index, vyraz) \
        ((vyraz != 0) ? (jmeno_pole[index/SIZE_U_INT + 1] |= 1L << (index % SIZE_U_INT)) : (jmeno_pole[index/SIZE_U_INT + 1] &= ~(1L << (index%SIZE_U_INT))))    

    /* Vrátí deklarovanou velikost pole v bitech uloženou na indexu 0 */
    #define bitset_size(jmeno_pole) \
        jmeno_pole[0]


#endif
