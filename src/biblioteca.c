#include "biblioteca.h"

void GuardarLivro(Pilha *L, Lista *P)
{
    Block *aux;
    aux = L->top;

    while (aux != L->base)
    {
        Pop(L, &aux->data);
        for (int i = 0; i < MAXTAM; i++)
        {
            if ((aux->data.prateleira) == (P->vet[i].id))
            {
                for (int j = 0; j < MAXLIVRO; j++)
                {
                    if (aux->data.cod == P->vet[i].livros[j].cod)
                    {
                        P->vet[i].livros[j] = aux->data;
                        P->vet[i].livros[j].status = true;
                    }
                }
            }
        }
        aux = aux->prox;
    }
}

void RetirarLivro(Fila *R, Lista *P)
{
    Blockf *aux;
    Blockf comp;

    aux = R->first->prox;

    while (aux != NULL)
    {
        comp = *aux;
        Desenfileira(R, &aux->data);
        for (int i = 0; i < MAXTAM; i++)
        {
            if ((comp.data.prateleira) == (P->vet[i].id))
            {
                for (int j = 0; j < MAXLIVRO; j++)
                {
                    if ((comp.data.cod) == (P->vet[i].livros[j].cod))
                    {
                        if (P->vet[i].livros[j].status)
                        {
                            P->vet[i].livros[j].status = false;
                        }
                        else if (!P->vet[i].livros[j].status)
                        {
                            printf("Livro indisponível!\n");
                        }
                    }
                }
            }
        }
        aux = aux->prox;
    }
}