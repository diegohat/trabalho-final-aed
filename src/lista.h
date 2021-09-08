#ifndef LISTA_H 
#define LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"pilha.h"

#define MAXTAM 3
#define MAXLIVRO 10

typedef struct Prateleira{
	int id;
    Livro livros[MAXLIVRO];
}Prateleira;

typedef struct Lista{
	Prateleira vet[MAXTAM];
	int first;
	int last;
}Lista;

void FLVazia(Lista *l);
void LInsert(Lista *l, Prateleira  d);
void LImprime(Lista *l);
void Initialize(Lista *l);

#endif