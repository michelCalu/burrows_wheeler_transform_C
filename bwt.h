#ifndef bwt_h
#define bwt_h

#define DIMMAX 50

#include <stdio.h>

typedef struct {                                    /* 1 Row = 1 index + 1 rotation du char "text" */
    int index;
    char text[DIMMAX];
} Row;


int compare (const void *s1, const void *S2);
void compression(char *text, int len, int MTF_result[], int *pos);
void rotation (Row matrix[],  int len, char stcopy [len]);
int find_pos (char text[], Row matrix[], int len);


#endif 
