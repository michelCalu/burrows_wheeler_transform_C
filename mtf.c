#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mtf.h"



int MoveToFront (char *alphabet_ptr, char curr_char);
void init_MTF (char *str, int size, int *MTF_result);



void init_MTF (char *str, int size_str, int *MTF_result) {
    
    char alphabet[LETTERS];
    
    for (int i=0; i < LETTERS; i++){
        
        alphabet[i]=(char)(i+ASCII_START);
    }
    
    
    for (int j = 0; j < size_str; j++) {
        
        MTF_result[j] = MoveToFront ( alphabet, str[j] );
    }
}


int MoveToFront (char *alphabet_ptr, char curr_char) {
  
    char *ptr_to_char=NULL;                                     // ptr vers la position du char courant dans alphabet
    char *alphabet_cpy=NULL;
    int char_pos = 0;
    
    
    

    alphabet_cpy = (char *)malloc(strlen(alphabet_ptr));        
    strcpy(alphabet_cpy, alphabet_ptr);

    ptr_to_char = strchr(alphabet_cpy, curr_char);              // recherche de l'index du char courant
    char_pos = (int) (ptr_to_char - alphabet_cpy);


    strncpy(alphabet_ptr + 1, alphabet_cpy, char_pos);          // décalage à droite des 'char_pos' premieres lettres
    alphabet_ptr[0] = curr_char;                                // shift du char courant en position [0] de l'alphabet
    free(alphabet_cpy);

    return char_pos;
}





