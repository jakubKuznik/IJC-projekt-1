#include "bitset.h"


/* Získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1 */
extern char bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);

/* Nastaví zadaný bit v poli na hodnotu zadanou výrazem */
extern void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index,char vyraz);

    
/* Vrátí deklarovanou velikost pole v bitech uloženou na indexu 0 */
extern long unsigned bitset_size(bitset_t jmeno_pole);