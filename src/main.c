/*
Trabalho Final da Disciplina de AEDS I
DATA: 09/09/2021
-------------------------------------------------------
Representação de um sistema de biblioteca virtual
(Guardar livros Devolvidos & Retirar Livros Reservados)
-------------------------------------------------------
Integrantes do Grupo:
Diego Henrique Almeida Trindade
Frederico Dantés Macedo Neves
Gabriel Vitor Silva
Jorge Vitor Gonçalves de Souza
-------------------------------------------------------
main.c
Estrutura principal do programa
Menu com opções de execução de chamadas de métodos
*/
#include "pilha.h"
#include "lista.h"
#include "fila.h"
#include "biblioteca.h"
#include "tokenizer.h"

#include <time.h>
#include <unistd.h>

int main()
{
    char validate = 0;

    printf("Bem-vindo a biblioteca virtual! Deseja iniciar o programa? [s] / [n]\n");
    scanf("%c", &validate);

    if (validate == 's' || validate == 'S')
    {
        printf("Inicializando a biblioteca...\n");
        sleep(1);

        Pilha L; // pilha de livros
        Lista P; // lista de prateleiras
        Fila R;  // fila de reserva

        //Inicializando as estruturas vazias
        PilhaVazia(&L);
        FLVazia(&P);
        FilaVazia(&R);

        printf("Realizando leitura de banco de dados...\n");
        sleep(1);

        //Tokenizando as entradas de texto do arquivo.
        pilhaTOK("./arq_livros.txt", &L);
        filaTOK("./arq_reservas.txt", &R);
        //PilhaImprime(&L);

        printf("Gerando pratileiras virtuais...\n");
        sleep(1);

        //Inicializando as prateleiras e adicionando indices
        Initialize(&P);

        int choice = 0;

        //Menu principal do programa (FRONT END)
        while (choice != 9)
        {
            printf("\nMENU:\n[1]Guardar livros recebidos nas prateleiras.\n[2]Retirar livros reservados das prateleiras.\n[3]Imprimir relatório das prateleiras.\n[9]Sair.\n");

            scanf("%i", &choice);

            switch (choice)
            {
            case 1:
                printf("Guardando livros nas posições corretas...\n");
                GuardarLivro(&L, &P);
                sleep(1);
                printf("Livros guardados.\n");
                break;

            case 2:
                printf("Retirando livros reservados para locação...\n");
                RetirarLivro(&R, &P);
                sleep(1);
                printf("Livros retirados.\n");
                break;
            
            case 3:
                printf("Imprimindo relatório...\n");
                sleep(1);
                LImprime(&P);
                printf("\nFim do relatório.\n");
                break;

            case 9:
                printf("Obrigado por utilizar o sistema de biblioteca virtual.\n");
                break;

            default:
                printf("Digite uma opção válida.\n");
                break;
            }


        }
        return 0;
    }
    else
    {
        printf("Obrigado por utilizar o sistema de biblioteca virtual.\n");
        return 0;
    }
}