#ifndef mtf_h
#define mtf_h

/* index des chars ASCII utilisés. on prend 26 lettres en commençant à 97 = {a,b,c,...z}*/
#define LETTERS 26
#define ASCII_START 97


int MoveToFront(char *alphabet_ptr, char curr_char);
void init_MTF(char *str, int size, int *MTF_result);

#endif 
