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

### Quais módulos das disciplinas usados:###

Para a realização do projeto proposto, foram selecionados alguns módulos dos conhecimentos adquiridos durante o semestre da disciplina AEDS, de forma que a escolha e utilização de cada um deles, seja a mais adequada possível, trazendo maior qualidade e funcionalidade ao código. Para isso foram utilizados os aprendizados no que diz respeito à análise assintótica, estruturas lineares estáticas e estruturas lineares dinâmicas, tendo uma justificativa para cada utilização.

Primeiramente será utilizada a análise assintótica, isso servirá para demonstrar o custo computacional do programa no caso médio e, com isso, provar que o custo atingido será viável visto os benefícios que trará para a operação da biblioteca. Para tanto, devemos também considerar que mesmo sem o sistema informatizado, já existe um custo para realizar os processos da biblioteca, portanto não seria criado um custo, ele seria apenas readequado.

Outro módulo de nossos estudos que será utilizado será o referente às estruturas lineares estáticas, que no caso do projeto proposto, estará presente na estrutura de lista que representarão as prateleiras da biblioteca. Neste caso, foi escolhida uma estrutura estática, devido ao fato de que o número de prateleiras e a capacidade de livros de cada prateleira já serem conhecidos, portanto já seria possível criar essas estruturas com o conhecimento de suas dimensões o que faz com que não fosse necessário utilizar a forma dinâmica, visto que a memória necessária para a estrutura já estaria definida ainda na criação da mesma.

Finalizando a relação de módulos do conhecimento adquirido na disciplina, utilizaremos, também, as estruturas lineares dinâmicas, que serão representadas pela pilha de livros a serem cadastrados na biblioteca e também na fila de livros reservados. A escolha por estrutura dinâmica nestes dois casos tem o mesmo motivo, afinal, ambas as estruturas são iniciadas sem que se conheçam as dimensões delas, ou seja, não é certo que toda inclusão de livros terá a mesma quantidade de exemplares, logo o tamanho da estrutura pode variar a cada utilização. O mesmo ocorre com a relação dos livros reservados, isto é, a fila dos livros que estão locados pode variar conforme os livros vão sendo devolvidos ou incluídos no sistema, portanto é mais interessante que sejam usadas estruturas dinâmicas nestes casos, dessa forma não ocorrerá de se alocar uma memória excessiva que não será utilizada ou o caso contrário, em que faltaria memória para a inclusão de dados na estrutura.

Além do exposto acima, outro fator que foi determinante na escolha de qual estrutura utilizar para cada propósito do programa, foi o fato de que para a inclusão dos livros no sistema, ou seja, para que o livro seja incluído no sistema, não é necessário que seja seguida nenhuma sequência, portanto foi escolhida a pilha pois ela garante que o objetivo de guardar todos os livros que precisarem, sem seguir ordem alguma, porém isso não altera pois os livros vão ser organizados no momento de irem para a prateleira (lista estática). A adoção da lista para as prateleiras também passou por este raciocínio, visto que não é necessário seguir uma ordem para locar ou guardar um livro, e que sabendo a posição correta de cada item, basta ir diretamente nessa localização, sem que seja necessário percorrer toda uma estrutura.

## Desenvolvimento: ##
### Estruturas ###

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
filaTOK(char *path, Fila *R)

```
Lê o arquivo-texto linha a linha, sendo que a cada uma delas é caracterizado um volume e, um a um, estes são empilhados até que o arquivo-texto finalize. É considerado como o valor referente ao código da prateleira o algarismo após o R e os algarismos após a vírgula referem-se à variável da posição na prateleira.











exit
