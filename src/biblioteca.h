/*
biblioteca.h
Métodos Guardar e Retirar Livros - Definição em biblioteca.c
*/
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "pilha.h"
#include "lista.h"
#include "fila.h"

void GuardarLivro(Pilha *L, Lista *P);
void RetirarLivro(Fila *R, Lista *P);

#endif