// Solution for IJC-DU1, task a), 28.2.2021
// File:        steg-decode.c
// Author:      Jakub Kuzník, FIT
// Compiled:    gcc 9.9.3.0
// Program can find hiden message in given image. 

#include "ppm.h"
#include "error.h"
#include "primes.h"

#include <limits.h>
#include <ctype.h>
#include <stdio.h>

//true or false value idicate if secrete message end with \0 or not  
#define NOT_VALID_END_CHARACTER 0  


int main(int argc, char *argv[])
{
    if(argc != 2)
        goto error_1;

    struct ppm *image;
    image = ppm_read(argv[1]);
    if(image == NULL) //Load image image.data[] return NULL if not sucesfull
        goto error_2;

    bitset_alloc(bit_array, (COLOR * image->xsize * image->ysize)); //heap alocation, second argument is array size
    Eratosthenes(bit_array);
    
    char secrete_character = 0; //here i ll store secrete character bit by bit from secret_bit.
    char secrete_bit = 0; //here i ll always store one bit 
    int byte_counter = 0; //byte identificator every 8 bit is reset to 0
    char valid_end_character = NOT_VALID_END_CHARACTER; //indicate if message end with \0
    for(unsigned int i = 23; i < (image->xsize * image->ysize * COLOR); i++)
    {
        if(!(bitset_getbit(bit_array, i)))
        {
            secrete_bit = image->data[i] & 1; //store bit
            secrete_bit = secrete_bit << byte_counter; //move bit to correct position
            secrete_character |= secrete_bit; //Bits are assembled using or

            byte_counter++;
            secrete_bit = 0;

            if(byte_counter == 8)
            {
                fputc(secrete_character, stdout);
                byte_counter = 0;
                
                if(secrete_character == '\0') //message ending character
                {
                    valid_end_character = 1; //The end character is valid so i change this identificator value 
                    break;
                }
                secrete_character = 0;
            }
        }
    }
    bitset_free(bit_array);
    ppm_free(image);
    if(valid_end_character == NOT_VALID_END_CHARACTER) //if message does not end wiht \0 byte 
        error_exit(" Message does not end with \\0 character\n");
    return 0;

/*Error for bad execution there has to be just one argument and that is file_name of image  */
error_1:
    error_exit("Bad execution (hint: ./steg-decode file)\n");

/*Can not load file error*/
error_2:
    return 0;
}