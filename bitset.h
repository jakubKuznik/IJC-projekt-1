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
#define RESERVED_FOR_ARRAY_SIZE 1 //First 64 bits are reserved for array size


#define BIT_0 0
#define BIT_1 1


typedef long unsigned bitset_t;


//bit index is equal to     bit position is equal to 
//      n/32                         n%32
#define bitset_create(jmeno_pole, velikost) \
    _Static_assert(velikost >= 0, "ERROR: Array can not be negative size."); \
    bitset_t jmeno_pole[velikost/SIZE_U_INT + RESERVED_FOR_ARRAY_SIZE];\
    for(long unsigned int i = 0; i < (velikost/SIZE_U_INT) + 1; i++) jmeno_pole[i] = 0;\
    jmeno_pole[0] = velikost;


/*
nastaví zadaný bit v poli na hodnotu zadanou výrazem
(nulový výraz == bit 0, nenulový výraz == bit 1)
*/
#define bitset_setbit(jmeno_pole, index, vyraz) \
    if(vyraz == BIT_0) ( jmeno_pole[(index/SIZE_U_INT) + RESERVED_FOR_ARRAY_SIZE] |= (0 << (index % SIZE_U_INT))); \
    else if(vyraz == BIT_1) ( jmeno_pole[(index/SIZE_U_INT) + RESERVED_FOR_ARRAY_SIZE] |= (1 << (index % SIZE_U_INT))); \
    else return 0;   //call error 


/*
získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1

*/
#define bitset_getbit(jmeno_pole,index)\
    (jmeno_pole[(index / SIZE_U_INT + RESERVED_FOR_ARRAY_SIZE)] & (1 << (index % SIZE_U_INT)))



/*
Pokud alokace selže, ukončete program s chybovým hlášením:
"bitset_alloc: Chyba alokace paměti"
*/
#define bitset_alloc(jmeno_pole,velikost)\
    _Static_assert(velikost >= 0, "ERROR: Array can not be negative size."); \
    bitset_t *jmeno_pole = malloc((velikost/8) + SIZE_U_INT_BYTES);\
    if(jmeno_pole == NULL) printf("error"); \
    for(long unsigned int i = 0; i < (velikost/SIZE_U_INT) + 1; i++) jmeno_pole[i] = 0;\
    jmeno_pole[0] = velikost;



/*
uvolní paměť dynamicky (bitset_alloc) alokovaného pole
*/
#define bitset_free(jmeno_pole)\
    free(jmeno_pole);


/*
vrátí deklarovanou velikost pole v bitech (uloženou v poli)
bitset_size(jmeno_pole)
*/






