#include "fila.h"

void FilaVazia(Fila *f){
	f->first = (Blockf*) malloc (sizeof(Blockf));
	f->last  = f->first;
	f->first->prox = NULL;
}

void Enfileira(Fila *f, Reserva d){
	f->last->prox = (Blockf*) malloc (sizeof(Blockf));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void Desenfileira(Fila *f, Reserva *d){
	Blockf *aux;

	if(f->first == f->last || f == NULL || f->first->prox == NULL){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first;
	f->first = f->first->prox;
	d->cod = aux->data.cod;
	d->prateleira = aux->data.prateleira;
	free(aux);
}

void FilaImprime(Fila *f){
	Blockf *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%d\n", aux->data.prateleira);
		printf("%d\n", aux->data.cod);
		aux = aux->prox;
	}
}