CC = gcc
LD = gcc

CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -lm -O2 
all: primes primes-i steg-decode

# primes primes-i
##########################################################################
#COPILE WITH MACROS 
primes: primes.o error.o eratosthenes.o
	gcc $(CFLAGS) primes.o error.o eratosthenes.o -o primes

primes.o: primes.c primes.h bitset.h
	gcc $(CFLAGS) -c primes.c -o primes.o

eratosthenes.o: eratosthenes.c primes.h bitset.h 
	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

error.o: error.h error.c
	gcc $(CFLAGS) -c error.c -o error.o


#COMPILE WITH INLINE FUNCTIONS 
primes-i: primes-i.o error.o eratosthenes-i.o bitset.o
	gcc $(CFLAGS) -DUSE_INLINE primes-i.o error.o eratosthenes-i.o bitset.o -o primes-i

primes-i.o: primes.c
	gcc $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

eratosthenes-i.o: eratosthenes.c primes.h
	gcc $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o


bitset.o: bitset.c bitset.h
	gcc $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset.o
	                
# steg-decode
####################################################################
steg-decode: steg-decode.o eratosthenes.o error.o ppm.o
	gcc $(CFLAGS) steg-decode.o eratosthenes.o error.o ppm.o -o steg-decode

steg-decode.o: steg-decode.c primes.h bitset.h error.h ppm.h
	gcc $(CFLAGS) -c steg-decode.c -o steg-decode.o

ppm.o: ppm.c error.h ppm.h
	gcc $(CFLAGS) -c ppm.c -o ppm.o




clean:
	rm *.o main

run: primes primes-i
	./primes
	./primes-i
