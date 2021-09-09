#include "tokenizer.h"

void pilhaTOK(char *path, Pilha *L)
{
    FILE *file;
    const char s[] = "P,";
    char *tok;
    char linha[1024];
    char *res;

    file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo!\n");
        return;
    }

    while (!feof(file))
    {
        Livro *d = malloc(sizeof(Livro));
        res = fgets(linha, 1024, file);
        tok = strtok(res, s);
        d->prateleira = atoi(tok);

        while (tok != NULL)
        {
            d->cod = atoi(tok);
            tok = strtok(NULL, s);
            d->status = false;
        }
        Push(L, *d);
    }
    fclose(file);
}

void filaTOK(char *path, Fila *R)
{
    FILE *file;
    const char s[] = "R,";
    char *tok;
    char linha[1024];
    char *res;

    file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo!\n");
        return;
    }

    while (!feof(file))
    {
        Reserva *r = malloc(sizeof(Reserva));
        res = fgets(linha, 1024, file);
        tok = strtok(res, s);
        r->prateleira = atoi(tok);
        while (tok != NULL)
        {
            r->cod = atoi(tok);
            tok = strtok(NULL, s);
        }

        Enfileira(R, *r);
    }
    fclose(file);
}