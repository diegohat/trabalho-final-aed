#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Reserva Reserva;
typedef struct Blockf Blockf;
typedef struct Fila Fila;

struct Reserva
{
	int prateleira;
	int cod;
};

struct Blockf
{
	Reserva data;
	Blockf *prox;
};

struct Fila
{
	Blockf *first;
	Blockf *last;
};

void FilaVazia(Fila *f);
void Enfileira(Fila *f, Reserva d);
void Desenfileira(Fila *f, Reserva *d);
void FilaImprime(Fila *f);

#endif