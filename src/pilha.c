#include "pilha.h"

void PilhaVazia(Pilha *p)
{
	p->base = (Block *)malloc(sizeof(Block));
	p->top = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Livro d)
{
	Block *aux = (Block *)malloc(sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, Livro *d)
{
	Block *aux;

	if (p->base == p->top || p == NULL)
	{
		printf("PILHA VAZIA!\n");
		return;
	}
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
}

void PilhaImprime(Pilha *p)
{
	Block *aux;

	aux = p->top;
	while (aux != p->base)
	{
		printf("Prateleira: %d\n", aux->data.prateleira);
		printf("Cod: %d\n", aux->data.cod);
		printf("Status: %d\n", aux->data.status);
		aux = aux->prox;
	}
}