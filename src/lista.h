/*
lista.h
Definição de estruturas das prateleiras e lista
Estrutura de Dados - Lista Estática
*/

#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

#define MAXTAM 3
#define MAXLIVRO 10

//definição de estruturas
typedef struct Prateleira
{
	int id;
	Livro livros[MAXLIVRO]; //vetor de livros representando suas posições nas prateleiras
} Prateleira;

typedef struct Lista
{
	Prateleira vet[MAXTAM]; //vetor de prateleiras representando suas posições na biblioteca -> Lista == "Biblioteca"
	int first;
	int last;
} Lista;

//Métodos da lista - Descrição em lista.c
void FLVazia(Lista *l);
void LInsert(Lista *l, Prateleira d);
void LImprime(Lista *l);
void Initialize(Lista *l);

#endif