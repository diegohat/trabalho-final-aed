/*
lista.c
Métodos da Estrutura - Lista Estática
Método Initialize para inicializar as prateleiras pra receberem os livros
*/
#include "lista.h"

void FLVazia(Lista *l)
{
	l->first = 0;
	l->last = 0;
}

/*
Função: Initialize - Inicializa as prateleiras e adiciona um indice a cada uma
@param l: Lista Estática
*/
void Initialize(Lista *l)
{
	int id = 1;
	while (l->last != MAXTAM)
	{
		Prateleira d;
		d.id = id;
		id++;
		for (int i = 0; i < MAXLIVRO; i++)
		{
			d.livros[i].cod = i;
			d.livros[i].status = false;
		}
		LInsert(l, d);
	}
}

void LInsert(Lista *l, Prateleira d)
{
	if (l->last >= MAXTAM)
	{
		printf("LISTA CHEIA!\n");
	}
	else
	{
		l->vet[l->last] = d;
		l->last++;
	}
}

void LImprime(Lista *l)
{
	for (int i = l->first; i < l->last; i++)
	{
		printf("Prateleira: %d", l->vet[i].id);
		printf("\t\t\t");
	}
	
	for (int j = 0; j < MAXLIVRO; j++)
	{
		printf("\n");

		for (int i = l->first; i < l->last; i++)
		{
			// printf("Prateleira: %d\t", l->vet[i].livros[j].prateleira);
			// printf("\n");
			printf("Cod: %d\t", l->vet[i].livros[j].cod);
			printf("Status: %d\t", l->vet[i].livros[j].status);
			printf("\t");
		}
	}
}
