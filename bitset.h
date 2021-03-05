// Solution for IJC-DU1, task a), 28.2.2021
// File:        bitset.h
// Author:      Jakub Kuzník, FIT
// School acco. xkuzni04
// Compiled:    gcc 9.9.3.0


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"

//multiply by eight becouse sizeof return size in bytes not bit.
#define SIZE_U_INT (sizeof(unsigned long) * 8)
#define SIZE_U_INT_BYTES sizeof(unsigned long)
#define RESERVED 1 //First 64 bits are reserved for array size

#define MAX_SIZE 200000000
#define BIT_0 0
#define BIT_1 1


typedef long unsigned *bitset_t;
typedef unsigned long bitset_index_t;


//bit index is equal to     bit position is equal to 
//      n/32                         n%32
#define bitset_create(jmeno_pole, velikost) \
    _Static_assert(velikost >= 0, "ERROR: Array can not be negative size."); \
    bitset_t jmeno_pole[velikost/SIZE_U_INT + RESERVED] = {velikost, };\
    jmeno_pole[0] = velikost


/*
nastaví zadaný bit v poli na hodnotu zadanou výrazem
(nulový výraz == bit 0, nenulový výraz == bit 1)
*/
#define bitset_setbit(jmeno_pole, index, vyraz) \
	((vyraz != 0) ? (jmeno_pole[index/SIZE_U_INT + 1] |= 1L << (index % SIZE_U_INT)) : (jmeno_pole[index/SIZE_U_INT + 1] &= ~(1L << (index%SIZE_U_INT))))    


//if(index > bitset_size(jmeno_pole)) error_exit("Index %lu mimo rozsah 0..%lu", index, bitset_size(jmeno_pole)); 

/*
získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1
*/
#define bitset_getbit(jmeno_pole, index) \
    ((jmeno_pole[index/SIZE_U_INT + RESERVED] >> (index % SIZE_U_INT )) & 1)


/*
Pokud alokace selže, ukončete program s chybovým hlášením:
"bitset_alloc: Chyba alokace paměti"
*/
#define bitset_alloc(jmeno_pole,velikost)\
    _Static_assert(velikost >= 0, "CHYBA: Array can not be negative size."); \
    _Static_assert(velikost <= MAX_SIZE, "CHYBA: Maximum size reached."); \
        bitset_t jmeno_pole =  (bitset_t) calloc((velikost/8) + SIZE_U_INT_BYTES, 1); \
    if(jmeno_pole == NULL) error_exit("bitset_alloc: Chyba alokace paměti"); \
    jmeno_pole[0] = velikost


/*
uvolní paměť dynamicky (bitset_alloc) alokovaného pole
*/
#define bitset_free(jmeno_pole)\
    free(jmeno_pole)


/*
Vrátí deklarovanou velikost pole v bitech uloženou na indexu 0
*/
#define bitset_size(jmeno_pole) jmeno_pole[0]




