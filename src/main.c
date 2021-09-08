#include"pilha.h"
#include"lista.h"
#include"fila.h"
#include"biblioteca.h"
#include"tokenizer.h"

int main(){
    Pilha L;    // pilha de livros
    Lista P;    // lista de prateleiras
    Fila R;     // fila de reserva

    PilhaVazia(&L);
    FLVazia(&P);
    FilaVazia(&R);

    pilhaTOK("./arq_livros.txt", &L);
    filaTOK("./arq_reservas.txt", &R);
    //PilhaImprime(&L);

    Initialize(&P);

    GuardarLivro(&L, &P);

    LImprime(&P);

    RetirarLivro(&R, &P);
    
    LImprime(&P);  

    return 0;
}