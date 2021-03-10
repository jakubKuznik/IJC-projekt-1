// Solution for IJC-DU1, task a), 28.2.2021
// File:        ppm.h
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// 

#include <stdio.h>

struct ppm 
{
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);


/*uvolní paměť dynamicky alokovanou v ppm_read*/
void ppm_free(struct ppm *p);

/*Check file format return NULL if foramt is bad*/
int file_format(FILE *file);