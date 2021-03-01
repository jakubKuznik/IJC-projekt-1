// Solution for IJC-DU1, task a), 28.2.2021
// File:        bitset.h
// Author:      Jakub Kuzník, FIT
// School acco. xkuzni04
// Compiled:    gcc 9.9.3.0


/*
Typ bitového pole (pro předávání parametru do funkce odkazem).
*/
typedef unsigned int[] bitset_t;


/*
Typ indexu do bitového pole.
*/
typedef unsigned long bitset_index_t;


/*
definuje a _nuluje_ proměnnou jmeno_pole
(POZOR: opravdu musí _INICIALIZOVAT_ pole bez ohledu na
to, zda je pole statické nebo automatické/lokální!
Vyzkoušejte obě varianty, v programu použijte lokální pole.)
Použijte  static_assert  pro kontrolu velikosti pole.
Př: static bitset_create(p,100); // p = pole 100 bitů, nulováno
bitset_create(q,100000L);    // q = pole 100000 bitů, nulováno
bitset_create(q,-100);       // chyba při překladu
*/

bitset_create(jmeno_pole,velikost);


bitset_create(jmeno_pole,velikost)
{

}


/*
definuje proměnnou jmeno_pole tak, aby byla kompatibilní s polem
vytvořeným pomocí bitset_create, ale pole bude alokováno dynamicky.
Př: bitset_alloc(q,100000L); // q = pole 100000 bitů, nulováno
Použijte  assert  pro kontrolu maximální možné velikosti pole.
Pokud alokace selže, ukončete program s chybovým hlášením:
"bitset_alloc: Chyba alokace paměti"
*/
bitset_alloc(jmeno_pole,velikost)
{

}


/*
uvolní paměť dynamicky (bitset_alloc) alokovaného pole
*/
bitset_free(jmeno_pole)
{

}


/*
vrátí deklarovanou velikost pole v bitech (uloženou v poli)
*/
bitset_size(jmeno_pole)
{

}


/*
nastaví zadaný bit v poli na hodnotu zadanou výrazem
(nulový výraz == bit 0, nenulový výraz == bit 1)
Př: bitset_setbit(p,20,1);
*/
bitset_setbit(jmeno_pole,index,výraz)
{

}


/*
získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1
Př: if(bitset_getbit(p,i)==1) printf("1");
if(!bitset_getbit(p,i))   printf("0");
*/
bitset_getbit(jmeno_pole,index)
{

}


