// Solution for IJC-DU1, task a), 28.2.2021
// File:        ppm.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
//   

#include <stdio.h>
#include "bitset.h"
#include "ppm.h"

#define ERROR_BAD_FORMAT -1 //Code for bad file format 
#define COLOR 3 //R*B*G
#define LIMIT_IMAGE_SIZE 8000*8000*3

/*
načte obsah PPM souboru do touto funkcí dynamicky
alokované struktury. Při chybě formátu použije funkci warning_msg
a vrátí NULL.
*/
struct ppm * ppm_read(const char * filename)
{
    struct ppm *image = NULL;
    int xsize_temp = 0, ysize_temp = 0;  //These are temporarily var. For image size.

    FILE *file = fopen(filename, "r");
    if(file == NULL) //check if fopen was succesfull 
        goto error_3;

    if(file_format(file) == ERROR_BAD_FORMAT) //check file format is bad  
        goto error_1;
    
    if(fscanf(file, "%d %d",&xsize_temp, &ysize_temp) != 2) //check if get size of image is succ.
        goto error_2;

    if((xsize_temp*ysize_temp*COLOR) > LIMIT_IMAGE_SIZE) //Check if image is bigger than our limit
        goto error_4;    

    image = (struct ppm*)malloc(sizeof(struct ppm) + sizeof(char) * COLOR * (xsize_temp)* (ysize_temp));
    image->xsize = xsize_temp;
    image->ysize = ysize_temp;

    int c = 0; 
    int index = 0;
    while ((c = fgetc(file)) != EOF)
    {
        image->data[index++] = (char)c;
    }

    fclose(file);
    return image;

/*Bad image format error */
error_1: 
    warning_msg(" Bad image format.\n");
    fclose(file);
    return NULL;

/*Bad image range error. Problem with geting image size.*/
error_2: 
    warning_msg(" Bad image range.\n");
    fclose(file);
    return NULL;

/*Can´t open file error. */
error_3:
    warning_msg(" Can´t open file.\n");
    return NULL;

/*Limit reached picture cant be bigger than 8000x8000*/
error_4:
    warning_msg(" Limit reached picture cant be bigger than 8000x8000\n");
    fclose(file);
    return NULL;

}
 

/*uvolní paměť dynamicky alokovanou v ppm_read*/
void ppm_free(struct ppm *p)
{
    free(p);
}

/*Check file format is ppm. If not return -1*/
int file_format(FILE *file)
{
    char buffer[16] = {0, }; 
    if(!fgets(buffer, sizeof(buffer), file))
    {
        warning_msg(" Invalid image format");
        return ERROR_BAD_FORMAT;
    }
    if (buffer[0] != 'P' || buffer[1] != '6') 
    {
         warning_msg(" Invalid image format ");
         return ERROR_BAD_FORMAT;
    }
    return 0;
}