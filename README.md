# Trabalho Final - Algoritmos e Estrutura de Dados #
Trabalho realizado para a disciplina de Algoritmos e Estrutura de Dados \
CEFET - MG Campus V \
Jorge Vitor G. de Souza \
Gabriel Vitor Silva \
Diego Trindade \

## Compilar ##
```
  make
  make run
```
## introdução ##
### Apresentação do Problema ###

Uma pequena biblioteca, THE BOOK IS ON THE TABLE, pretende modernizar sua estrutura visto que seu proprietário e bibliotecário, seu Madruga, vem achando cansativo ter que, a cada cliente, se deslocar às prateleiras para procurar pelo volume desejado, considerando grande o número de viagens até as prateleiras, e muita dessas vezes, em vão, afinal o livro se encontrava locado. Seu Madruga diz também que pretende ampliar a atual estrutura física da biblioteca, porém, devido ao fato de o sistema de gerenciamento dela ser ainda todo manual, isso fica inviável, considerando que o atual cenário já vem o desgastando.

Pensemos no seguinte cenário, chegam à biblioteca três pessoas e cada uma deseja locar 2 livros cada. Aparentemente seria algo simples de se resolver, mas conforme descrito acima, o gerenciamento é todo manual, logo seu Madruga, terá que a cada cliente pesquisar o livro nas prateleiras, portanto 3 viagens. Caso consideremos que ele só consulta um livro por vez, ele teria que fazer 6 viagens apenas com esses clientes, algo que no volume mensal de clientes, traria um esforço grande. Já imaginou se ele pudesse resolver isso com apenas alguns cliques? E ele pode, e é isso que será proposto adiante.

Considerando a situação da biblioteca THE BOOK IS ON THE TABLE foi decidido que seria realizado um projeto tendo como objetivo a modernização do sistema de gerenciamento da biblioteca e com isso otimizar o serviço atual prestado e possibilitar que a ampliação desejada pelo seu Madruga, seja realizada de forma que ele estará preparado para gerenciar um número cada vez maior de exemplares.

Dito isto, fica estipulado que o vigente projeto terá como grande área de conhecimento que será tratada, o gerenciamento de bibliotecas, tanto por ser uma área de suma importância para a disseminação de conhecimento e, consequente, evolução intelectual do ser humano, mas também por existir nessa área alguns locais que ainda necessitam de uma solução tecnológica para melhor controle dos exemplares. Sendo assim o segmento de nosso problema, terá foco nas estruturas de organização de livros considerando que é praticamente o coração do gerenciamento de biblioteca pois trata do cerne da atividade, que é a guarda, conservação e organização das publicações que possui.

### Quais módulos das disciplinas usados: ###

Para a realização do projeto proposto, foram selecionados alguns módulos dos conhecimentos adquiridos durante o semestre da disciplina AEDS, de forma que a escolha e utilização de cada um deles, seja a mais adequada possível, trazendo maior qualidade e funcionalidade ao código. Para isso foram utilizados os aprendizados no que diz respeito à análise assintótica, estruturas lineares estáticas e estruturas lineares dinâmicas, tendo uma justificativa para cada utilização.

Primeiramente será utilizada a análise assintótica, isso servirá para demonstrar o custo computacional do programa no caso médio e, com isso, provar que o custo atingido será viável visto os benefícios que trará para a operação da biblioteca. Para tanto, devemos também considerar que mesmo sem o sistema informatizado, já existe um custo para realizar os processos da biblioteca, portanto não seria criado um custo, ele seria apenas readequado.

Outro módulo de nossos estudos que será utilizado será o referente às estruturas lineares estáticas, que no caso do projeto proposto, estará presente na estrutura de lista que representarão as prateleiras da biblioteca. Neste caso, foi escolhida uma estrutura estática, devido ao fato de que o número de prateleiras e a capacidade de livros de cada prateleira já serem conhecidos, portanto já seria possível criar essas estruturas com o conhecimento de suas dimensões o que faz com que não fosse necessário utilizar a forma dinâmica, visto que a memória necessária para a estrutura já estaria definida ainda na criação da mesma.

Finalizando a relação de módulos do conhecimento adquirido na disciplina, utilizaremos, também, as estruturas lineares dinâmicas, que serão representadas pela pilha de livros a serem cadastrados na biblioteca e também na fila de livros reservados. A escolha por estrutura dinâmica nestes dois casos tem o mesmo motivo, afinal, ambas as estruturas são iniciadas sem que se conheçam as dimensões delas, ou seja, não é certo que toda inclusão de livros terá a mesma quantidade de exemplares, logo o tamanho da estrutura pode variar a cada utilização. O mesmo ocorre com a relação dos livros reservados, isto é, a fila dos livros que estão locados pode variar conforme os livros vão sendo devolvidos ou incluídos no sistema, portanto é mais interessante que sejam usadas estruturas dinâmicas nestes casos, dessa forma não ocorrerá de se alocar uma memória excessiva que não será utilizada ou o caso contrário, em que faltaria memória para a inclusão de dados na estrutura.

Além do exposto acima, outro fator que foi determinante na escolha de qual estrutura utilizar para cada propósito do programa, foi o fato de que para a inclusão dos livros no sistema, ou seja, para que o livro seja incluído no sistema, não é necessário que seja seguida nenhuma sequência, portanto foi escolhida a pilha pois ela garante que o objetivo de guardar todos os livros que precisarem, sem seguir ordem alguma, porém isso não altera pois os livros vão ser organizados no momento de irem para a prateleira (lista estática). A adoção da lista para as prateleiras também passou por este raciocínio, visto que não é necessário seguir uma ordem para locar ou guardar um livro, e que sabendo a posição correta de cada item, basta ir diretamente nessa localização, sem que seja necessário percorrer toda uma estrutura.

## Desenvolvimento: ##
### Estruturas ###
![Representação das estruturas e métodos](c_program_books.gif)
Para o desenvolvimento do projeto conforme definido foram criados tipos de dados específicos para alcançar o objetivo proposto, essa tipagem foi criada a partir do registro struct, que faz com que possamos agrupar variáveis distintas sob um mesmo tipo de dado. Cada uma dessas struct’s criadas será apresentada a seguir.

```
struct Livro{
    int prateleira;
    int cod;
    bool status;
};

```
Livro que contemplará três variáveis, prateleira, cod e status, sendo a primeira do tipo inteiro que representará a prateleira à qual o livro pertence, a seguinte também será do tipo inteiro e representará a posição do livro na prateleira e por fim a variável status do tipo booleano que definir a disponibilidade do livro na biblioteca.

```
struct Block{
    Livro data;
    Block *prox;
};

```

Block que representará o bloco dessa pilha dinâmica, sendo as variáveis dessa struct uma do tipo Livro, data, e o outro um ponteiro do tipo Block que servirá para orientar o próximo item da pilha.

```
struct Pilha{
    Block *base;
    Block *top;
};

```

Pilha que terá dois ponteiros do tipo Block que serão o topo e o fundo da pilha e servirá para a orientação quando necessário preencher ou percorrer a pilha.

```
struct Reserva{
    int prateleira;
    int cod;
};

```

Reserva que será uma tipagem de dados semelhante ao Livro, porém sem o status, as demais variáveis serão iguais ao do Livro, pois é com elas que procuraremos nas prateleiras para alterar o status de um livro quando for reservado, logo serão também dois inteiros para prateleira e cod.

```
struct Blockf{
    Reserva data;
    Blockf *prox;
};

```
Blockf seguirá o mesmo padrão do Block, porém neste caso ele se refere a um bloco da fila de reservas e não da pilha de livros, portanto ele contará com uma variável do tipo Reserva que servirá para armazenar a reserva na fila.

```
struct Fila{
    Blockf *first;
    Blockf *last;
};

```

Fila que terá dois ponteiros do tipo Blockf que serão o início e o final da fila e servirá para a orientação quando necessário preencher ou percorrer a fila.

```
struct Prateleira{
    int id;
    Livro livros[MAXLIVRO];
};

```
Prateleira que contará com uma variável do tipo inteiro que será o código referente à prateleira, além de um vetor do tipo Livro que contará com um tamanho pré-definido pela capacidade da prateleira, MAXLIVRO.

```
struct Lista{
    Prateleira vet[MAXTAM];
    int first;
    int last;
};

```
Lista que terá um vetor do tipo Prateleira e terá um valor pré-definido pela quantidade de prateleiras no local, MAXTAM. Além disso, ele teria dois inteiros de início e fim da lista para orientação para preencher e percorrer a lista quando necessário.

### Leitura dos arquivos de texto: ###

```
void pilhaTOK(char *path, Pilha *L)
{
    FILE *file;
    const char s[] = "P,";
    char *tok;
    char linha[1024];
    char *res;

    file = fopen(path, "r");//-------------------------->n
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo!\n");//>1 ou 0
        return;
    }

    while (!feof(file))//------------------------------->n
    {
        Livro *d = malloc(sizeof(Livro));//------------->n
        res = fgets(linha, 1024, file);//--------------->n
        tok = strtok(res, s);//------------------------->n
        d->prateleira = atoi(tok);//-------------------->n

        while (tok != NULL)//--------------------------->n²
        {
            d->cod = atoi(tok);//----------------------->n²
            tok = strtok(NULL, s);//-------------------->n²
            d->status = false;//------------------------>n²
        }
        Push(L, *d);//---------------------------------->n
    }
    fclose(file);//------------------------------------->1
    //------------------------------------------->total: 4n²+7n+1
}

```
Lê o arquivo-texto linha a linha, sendo que a cada uma delas é caracterizado um volume e, um a um, estes são empilhados até que o arquivo-texto finalize. Considera-se o algarismo após o P referente à variável prateleira que representa o código da prateleira e os algarismos após a vírgula referem-se à posição na prateleira, por premissa adotada todos livros empilhados são com status em false, pois quando forem passados para a lista de prateleiras terão o status mudado para true.

```
void filaTOK(char *path, Fila *R)
{
    FILE *file;
    const char s[] = "R,";
    char *tok;
    char linha[1024];
    char *res;

    file = fopen(path, "r");//------------------------------->1
    if (file == NULL)//-------------------------------------->1
    {
        printf("Não foi possível abrir o arquivo!\n");//----->1 ou 0
        return;
    }

    while (!feof(file))//----------------------------------->n
    {
        Reserva *r = malloc(sizeof(Reserva));//------------->n
        res = fgets(linha, 1024, file);//------------------->n
        tok = strtok(res, s);//----------------------------->n
        r->prateleira = atoi(tok);//------------------------>n
        while (tok != NULL)//------------------------------->n²
        {
            r->cod = atoi(tok);//--------------------------->n²
            tok = strtok(NULL, s);//------------------------>n²
        }

        Enfileira(R, *r);//--------------------------------->n+4
    }
    fclose(file);//----------------------------------------->1
}//----------------------------------------------------->total: 3n²+6n+7

```
Lê o arquivo-texto linha a linha, sendo que a cada uma delas é caracterizado um volume e, um a um, estes são empilhados até que o arquivo-texto finalize. É considerado como o valor referente ao código da prateleira o algarismo após o R e os algarismos após a vírgula referem-se à variável da posição na prateleira.

### Guardar Livros: ###

```

void Initialize(Lista *l)
{
	int id = 1;//---------------------------------->1
	while (l->last != MAXTAM)//-------------------->n
	{
		Prateleira d;
		d.id = id;//------------------------------->n
		id++;
		for (int i = 0; i < MAXLIVRO; i++)//------->n(2n+2)
		{
			d.livros[i].cod = i;//----------------->n
			d.livros[i].status = false;//---------->n
		}
		LInsert(l, d);//--------------------------->4
	}//------------------------------------------>total:2n²+6n+4
}

```
Inicializa a prateleira de modo a criar o número de prateleiras necessárias e posições por prateleira (MAXTAM MAXLIVROS), sendo adicionado o código da prateleira, da posição e o status como false, pois só tem o espaço do livro criado, sem o livro ainda.

```
void GuardarLivro(Pilha *L, Lista *P)
{
    Block *aux;
    aux = L->top;//------------------------------------------------>1

    while (aux != L->base)//--------------------------------------->n
    {
        Pop(L, &aux->data);//-------------------------------------->n(4)
        for (int i = 0; i < MAXTAM; i++)//------------------------->n(2n+2)
        {
            if ((aux->data.prateleira) == (P->vet[i].id))//-------->n²+n
            {
                for (int j = 0; j < MAXLIVRO; j++)//--------------->n²(2n+2)
                {
                    if (aux->data.cod == P->vet[i].livros[j].cod)//->n³
                    {
                        P->vet[i].livros[j] = aux->data;//---------->n³
                        P->vet[i].livros[j].status = true;//-------->n³
                    }
                }
            }
        }
        aux = aux->prox;//------------------------------------------>n
    }//-------------------------------------------------------->total: 4n³+4n²+9n
}

```
Faz o pop na pilha de modo que todo elemento tenha o código da prateleira e da posição lidos e com isso possa ser alocado corretamente na posição em que foi designado. Em caso de encontrar a posição do livro que foi arrancado da pilha para procura, ele será incluído na lista das prateleiras e terá seu status alterado de false para true o que caracterizaria que ele estaria disponível para locação, ou seja, ele se encontra em prateleira.

### Retira Livros ###

```
void RetirarLivro(Fila *R, Lista *P)
{
    Blockf *aux;
    Blockf comp;

    aux = R->first->prox;//--------------------------------------------->1

    while (aux != NULL)//----------------------------------------------->n
    {
        comp = *aux;//-------------------------------------------------->n
        Desenfileira(R, &aux->data);//---------------------------------->n(5)
        for (int i = 0; i < MAXTAM; i++)//------------------------------>n(2n+2)
        {
            if ((comp.data.prateleira) == (P->vet[i].id))//------------->n²+n
            {
                for (int j = 0; j < MAXLIVRO; j++)//--------------------->n²(2n+2)
                {
                    if ((comp.data.cod) == (P->vet[i].livros[j].cod))//--->n³
                    {
                        if (P->vet[i].livros[j].status)//----------------->n³
                        {
                            P->vet[i].livros[j].status = false;//--------->n³
                        }
                        else if (!P->vet[i].livros[j].status)//---------->0
                        {
                            printf("Livro indisponível!\n");//----------->0
                        }
                    }
                }
            }
        }
        aux = aux->prox;//----------------------------------------------->n
    }//------------------------------------------------------------->total: 4n³+4n²+10n
}

```
Desenfileira livro a livro que está contido na fila de reservas e compara um a um aos livros contidos nas posições de cada uma das prateleiras, cobrindo toda a coleção de exemplares, e ao encontrar o livro procurado a partir da fila de reservas ele altera o status desse livro para false, o que faz com que ele seja considerado como indisponível, e prossegue para o próximo livro da fila de reservas até que ela seja inteiramente varrida.

Caso o livro já não esteja disponível no momento da tentativa de reserva, o programa informa a indisponibilidade do mesmo e prossegue com a busca pelo próximo livro, caso ainda exista algum na fila ainda não procurado. 

## O que espera receber como resultado: ##

Desenvolvida toda a parte da implementação dos códigos do programa, é esperado que obtenha-se, como resultado, um relatório em que seria mostrado a relação de todos os livros por prateleira, de forma que essas seriam dispostas pela numeração, além é claro da relação dos livros que pertencem a cada prateleira. Ademais, seria informado também juntamente a cada exemplar, qual seu status no atual momento, isto é, se o livro encontra-se disponível ou se ele está locado, garantindo-se assim, todas as informações pertinentes para o bibliotecário, como se o exemplar existe na biblioteca, e caso exista, em que prateleira/posição ele se encontra e se ele tem disponibilidade para locação.

Conforme adotado como premissa, a estrutura que representará as prateleiras será uma lista estática, devido ao fato de que o tamanho máximo dessa estrutura já está definida pois consideramos que essa dimensão deve-se referir ao tamanho físico disponível para o armazenamento dos livros – prateleiras e posições nas prateleiras. Portanto ao considerarmos que esta estrutura não terá o seu tamanho variando, não seria interessante se fazer a retirada e inclusão dos livros toda vez que algum deles for locado/devolvido, sendo utilizado como mecanismo para essa alteração de disponibilidade do livro, um controlador do tipo booleano que seria true quando o livro se encontra-se disponível. 

Nota-se que tal estratégia já garante um ganho de custo computacional, visto que como a estrutura adotada não terá seu tamanho alterado é possível utilizar a forma estática da estrutura, além de garantir que o processo será mais barato por apenas trocar o status do livro quando no momento de locação ou devolução, considerando que não seria necessário incluir e excluir os livros toda vez que houvesse alguma alteração na disponibilidade.

Logo o que se espera com este projeto e a implantação do mesmo é que o gerenciador da biblioteca possa ter em mãos de forma simples e ágil, as informações importantes para ele, como a disposição da coleção de exemplares pelas prateleiras, e também, se o título está livre para a locação, ou seja, disponível na prateleira informada, ou se ele está locado, o que mostraria ele na prateleira correspondente porém com status de indisponivel.

## Resultados: ##

Como resultado para o projeto proposto teremos, conforme já dito anteriormente, um relatório com as informações necessárias de cada livro para o gerenciamento de locações e devoluções. Foi montado um menu que possibilitará o usuário as opções das operações disponíveis que seriam:

- Guardar livros;
- Reserva de livros;
- Impressão de relação de livros nas estantes.

Para a demonstração do funcionamento do sistema, iremos realizar a leitura de dois arquivos de texto, sendo um o de livros a serem guardados no sistema e outro referente aos que seriam retirados do mesmo. Inicialmente selecionamos a opção de Guardar Livros, após a leitura do primeiro arquivo, seria gerada uma pilha com os livros que seriam guardados nas prateleiras, depois de gerada a pilha o próximo passo seria a inclusão desses itens nas prateleiras. Feito esse primeiro  processo, em caso de selecionarmos a opção de imprimir o relatório, apareceriam as prateleiras e os livros que a compõem definidos pela posição de cada um, além disso teríamos um status em que 1 considera ele como disponível e 0 ele é considerado locado.

Para continuar a exemplificação do funcionamento do programa, passemos ao processo seguinte, que no caso será a Reserva de Livros, este procedimento terá a mesma base do anterior, onde um arquivo-texto seria lido para que fossem identificados quais livros seriam reservados, sendo que a cada livro a ser reservado, ele seria incluído na fila de reservas. Com ele na fila de reservas é preciso buscar na lista de prateleiras os livros contidos na fila, e ao ser encontrado, o livro teria o seu status de disponibilidade alterado para false, o que caracterizaria que ele estaria locado.

Terminado este processo, bastaria imprimir novamente o relatório e notar que houve uma alteração do primeiro relatório gerado, onde os livros constantes no arquivo-texto de reservas teriam seus status alterados de 1 (disponível) para 0 (locado). Com isso é possível perceber que o sistema proposto funciona e poderia ser utilizado para gerenciar a biblioteca de modo a trazer melhorias no controle e otimização do processo de organização dos livros.

## Conclusão: ##

Decorridos todas as etapas do processo para a realização projeto proposto, desde a sua idealização, modelagem, construção e desenvolvimento, conclui-se o quanto é importante estruturar o algoritmo de acordo com a demanda, porém sempre se atentando para as possibilidades de utilização de cada conhecimento adquirido, adequando as ferramentas, disponíveis na bibliografia, ao problema. Ao atentar-se a isto, é possível atingir um programa eficaz, ou seja, que consegue cumprir com a necessidade para a qual ele é desenvolvido e que o faça de maneira mais rápida e/ou barata, visto que muitas vezes um custo computacional elevado, pode inviabilizar uma ferramenta, destacando-se a importância da assertividade na escolha das estruturas e interações dos métodos nelas contidas.

Dois fatores exemplificam o pensamento acima, sendo um deles relativo à escolha da estrutura e outro referente ao campo lógico dos métodos utilizados. Com relação à estrutura mais adequada, destaca-se a escolha pela pilha dinâmica no caso dos livros que seriam guardados nas prateleiras, já que não existe a necessidade dos livros serem guardados em alguma ordem específica e, também, o fato de escolher a lista estática para as prateleiras, considerando já conhecermos o tamanho da estrutura, o que torna mais adequada essa estrutura. Já no campo lógico dos métodos utilizados, vale destacar, novamente, a escolha em manter os livros nas prateleiras e apenas alterar o controlador booleano de disponibilidade deles, afinal caso o retirássemos, teríamos que colocá-lo novamente na mesma posição quando fosse do momento da devolução do livro, o que acarretaria em um processo mais oneroso do ponto de vista de custo computacional além de não fazer sentido lógico considerando que a classificação dos livros em uma biblioteca mantém os livros na mesma posição devido à ordem alfabética/tema.







exit
