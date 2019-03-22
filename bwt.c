#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bwt.h"
#include "mtf.h"



void compression (char *text, int len, int MTFresult[], int *pos){
    
    Row matrix[len];
    char str_copy[len];
    char BWTresult[DIMMAX]={0};
    
    strcpy(str_copy,text);
    
    rotation (matrix, len, str_copy);                         //* 1. rotation des lettres 1 index vers la droite
    
    qsort (matrix, len, sizeof(Row), compare);               // 2. tri par qsort des rotations
    
    *pos=find_pos (text, matrix, len);                         // 3. retrouver le string original parmi les rotations
    
    for (int i = 0; i < len; i++){
        
        if (BWTresult[0] == 0) {                                   //* 4.récupérer le dernier char et ajouter dans result[]
            sprintf(BWTresult, "%c", matrix[i].text[len-1]);
        } else {
            sprintf(BWTresult, "%s%c", BWTresult, matrix[i].text[len-1]);
        }
    }
    
    printf("\nBWT result: %d'%s'\n", *pos, BWTresult);
    
    init_MTF (BWTresult, (int)strlen(BWTresult), MTFresult);           /* 5 envoi vers mtf */
}



void rotation (Row matrix[],  int len, char str_copy [len]){
    char tmp;
    char *current_rotation;
    int i,j;
    
    for (i = 0; i < len; i++) {
        
        matrix[i].index = i;
        current_rotation = str_copy;
        strcpy(matrix[i].text, current_rotation);
        
         /* 2. shift des lettres de {0,1,...len-2} 1 char vers la droite. tmp = derniere lettre, repasse en pos [0] */
        tmp = str_copy[len-1];
        
        for (j = len-1; j > 0; j--) {
            str_copy[j] = str_copy[j - 1];
        }
        str_copy[j] = tmp;
        
    }
}


int compare (const void *s1, const void *s2) {					/* fction de comparaison de
                                                                 strings utilisée par qsort */
    return strcmp( ( (Row *)s1 )->text, ( (Row *)s2 )->text );
    
}


int find_pos (char text[], Row matrix[], int len){

    for (int i = 0; i < len; i++) {

            if (strcmp(text,matrix[i].text) == 0){
                return i;
                
            }
    }
    
    return -1;
}



