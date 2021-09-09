#include "lista.h"

void FLVazia(Lista *l)
{
	l->first = 0;
	l->last = 0;
}

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
		printf("\n");
		printf("Prateleira: %d\n", l->vet[i].id);

		for (int j = 0; j < MAXLIVRO; j++)
		{
			// printf("Prateleira: %d\t", l->vet[i].livros[j].prateleira);
			// printf("\n");
			printf("Cod: %d\t", l->vet[i].livros[j].cod);
			printf("Status: %d\t", l->vet[i].livros[j].status);
			printf("\n");
		}
	}
}
