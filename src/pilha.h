#ifndef PILHA_H 
#define PILHA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Livro Livro;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Livro{
    int prateleira;
	int cod;
    bool status;
};

struct Block{
	Livro data;
	Block *prox;
};

struct Pilha{
	Block *base;
	Block *top;
};

void PilhaVazia(Pilha *p);
void Push(Pilha *p, Livro d);
void Pop(Pilha *p, Livro *d);
void PilhaImprime(Pilha *p);

#endif