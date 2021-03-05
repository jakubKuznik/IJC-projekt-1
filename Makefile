CC = gcc
LD = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -lm -O2


#COPILE WITH MACROS 
primes: primes.o error.o eratoshenes.o
	gcc $(CFLAGS) primes.o error.o eratoshenes.o -o primes

primes.o: primes.c primes.h bitset.h
	gcc $(CFLAGS) -c primes.c -o primes.o

eratoshenes.o: eratoshenes.c primes.h bitset.h 
	gcc $(CFLAGS) -c eratoshenes.c -o eratoshenes.o

error.o: error.h error.c
	gcc $(CFLAGS) -c error.c -o error.o


#COMPILE WITH INLINE FUNCTIONS 
primes-i: primes.o error.o eratoshenes.o
	gcc $(CFLAGS) -DUSE_INLINE primes-i.o error.o eratoshenes-i.o -o primes-i

primes-i.o: primes.c primes.h bitset.h
	gcc $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

eratoshenes-i.o: eratoshenes.c primes.h bitset.h 
	gcc $(CFLAGS) -DUSE_INLINE -c eratoshenes-i.c -o eratoshenes-i.o


clean:
	rm *.o main

run:
	./primes
	./primes-i