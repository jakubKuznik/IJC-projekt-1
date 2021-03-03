// Solution for IJC-DU1, task a), 28.2.2021
// File:        bitset.h
// Author:      Jakub Kuzník, FIT
// School acco. xkuzni04
// Compiled:    gcc 9.9.3.0


#include <stdio.h>
#include <assert.h>
#include "error.h"

//multiply by eight becouse sizeof return size in bytes not bit.
#define SIZE_U_INT (sizeof(unsigned long) * 8)
#define RESERVED_FOR_ARRAY_SIZE 1 //First 64 bits are reserved for array size


#define BIT_0 0
#define BIT_1 1


typedef long unsigned bitset_t;


//bit index is equal to     bit position is equal to 
//      n/32                         n%32
#define bitset_create(jmeno_pole, velikost) \
    _Static_assert(velikost >= 0, "ERROR: Array can not be negative size."); \
    bitset_t jmeno_pole[velikost/SIZE_U_INT + RESERVED_FOR_ARRAY_SIZE];\
    for(long unsigned int i = 1; i < (velikost/SIZE_U_INT) + 1; i++) jmeno_pole[i] = 0; 


/*
nastaví zadaný bit v poli na hodnotu zadanou výrazem
(nulový výraz == bit 0, nenulový výraz == bit 1)
*/
#define bitset_setbit(jmeno_pole, index, vyraz) \
    if(vyraz == BIT_0) ( jmeno_pole[(index/SIZE_U_INT)] |= (0 << (index % SIZE_U_INT))); \
    else if(vyraz == BIT_1) ( jmeno_pole[(index/SIZE_U_INT)] |= (1 << (index % SIZE_U_INT))); \
    else return 0;   //call error 


/*
získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1

*/
#define bitset_getbit(jmeno_pole,index)\
    (jmeno_pole[(index / SIZE_U_INT)] & (1 << (index % SIZE_U_INT)))

/*
definuje proměnnou jmeno_pole tak, aby byla kompatibilní s polem
vytvořeným pomocí bitset_create, ale pole bude alokováno dynamicky.
Př: bitset_alloc(q,100000L); // q = pole 100000 bitů, nulováno
Použijte  assert  pro kontrolu maximální možné velikosti pole.
Pokud alokace selže, ukončete program s chybovým hlášením:
"bitset_alloc: Chyba alokace paměti"
bitset_alloc(jmeno_pole,velikost)
*/


/*
uvolní paměť dynamicky (bitset_alloc) alokovaného pole
bitset_free(jmeno_pole)
*/


/*
vrátí deklarovanou velikost pole v bitech (uloženou v poli)
bitset_size(jmeno_pole)
*/






