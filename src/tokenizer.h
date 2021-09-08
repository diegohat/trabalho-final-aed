#ifndef TOKENIZER_H 
#define TOKENIZER_H

#include "pilha.h"
#include "fila.h"
#include<string.h>

void pilhaTOK(char *path, Pilha *L);
void filaTOK(char *path, Fila *R);

#endif