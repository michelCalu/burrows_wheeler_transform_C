#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bwt.h"
#include "mtf.h"



/* récupère une saisie de  0 -> length caractères (inclus '/0') */
int readStringFromUser(char *input, int length){
    
    char *c = NULL;
    if (fgets(input, length, stdin) != NULL){
        
        c = strchr(input, '\n');
        if (c != NULL){
            *c = '\0';
        }
        return 1;
    }
    else{
        
        return 0;
    }
}



int main(void) {
    
    char texte[DIMMAX];
    int pos;
    int MTF_result[DIMMAX] = {0};

    printf("Enter text to BWT: ");
    
    if (readStringFromUser (texte,DIMMAX) ){
    
        int len = (int)strlen(texte);
   
        compression(texte, len, MTF_result, &pos);
    
        printf("Move-to-Front result: ");
        for (int j = 0; j < len; j++) {
            printf("%d ", MTF_result[j]);
        }printf("\n\n\n");
    }
  
    return EXIT_SUCCESS;
}
