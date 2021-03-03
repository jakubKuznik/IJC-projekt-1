CC = gcc
LD = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -lm


primes: primes.o error.o eratoshenes.o
	gcc $(CFLAGS) primes.o eratoshenes.o error.o -o primes



primes.o: primes.c primes.h bitset.h
	gcc $(CFLAGS) -c primes.c -o primes.o

eratoshenes.o: eratoshenes.c primes.h bitset.h 
	gcc $(CFLAGS) -c eratoshenes.c -o eratoshenes.o

error.o: error.h error.c
	gcc $(CFLAGS) -c error.c -o error.o

clean:
	rm *.o main