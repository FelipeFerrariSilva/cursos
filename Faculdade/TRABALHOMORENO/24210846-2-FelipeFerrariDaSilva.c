#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include <time.h>
#include <stdbool.h>

//Exercicio 1
//Temos o historico do navegador que fica armazenado em esquema de pilha, e outro exemplo e o ctrl + z que apaga a ultima coisa que acabamos de fazer ou digitar

//Exercicio 2
//O ponteiro deve ser do tipo no, que consumira numa arquitetura de 32 bits = 4 bytes, na de 64 bits = 8 bytes.
//O tipo do ponteiro deve ser um ponteiro para o tipo do próprio nó da pilha, ele é necessário para fazer o encadeamento entre os elementos da pilha.

//Exercicio 3
//Podemos fazer o push que é inserir um elemento no topo, pop para remover o elemento do topo, peek/top	que é consultar o elemento do topo sem remover,
//isempty para verificar se a pilha está vazia e size para obter a quantidade de elementos na pilha.

//Exercicio 4
//Ao atribuir NULL ao ponteiro que aponta para o topo da pilha, estamos dizendo que não tem nenhum elemento na pilha. 
//Isso indica que qualquer operação que consulte o topo reconhecerá a pilha como vazia
//e se não for feito a liberação de memória os elementos vão se perder gerando um vazamento de memória.

//Exercicio 5
//O vetor estático usamos quando já sabemos o tamanho fixo dos dados e precisa de um acesso rápido,
//o vetor dinâmico usamos quando precisamos de flexibilidade de tamanho no vetor, a lista encadeada	usamos quando precisamos de muitas inserções/remoções e não sabe o tamanho total.

//Exercicio 6
/*typedef struct No {
    char nome[30];
    int idade;
    struct No* prox;
} No;

No* topo = NULL; 

void push() {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    printf("Digite o nome: ");
    getchar(); 
    fgets(novo->nome, 30, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; 

    printf("Digite a idade: ");
    scanf("%d", &novo->idade);

    novo->prox = topo;
    topo = novo;
}

void pop() {
    if (topo == NULL) {
        printf("A pilha esta vazia!\n");
        return;
    }

    No* temp = topo;
    topo = topo->prox;

    printf("Elemento removido: %s, %d anos\n", temp->nome, temp->idade);
    free(temp);
}

void imprimir() {
    if (topo == NULL) {
        printf("A pilha esta vazia!\n");
        return;
    }

    No* atual = topo;
    printf("\nElementos na pilha:\n");
    while (atual != NULL) {
        printf("Nome: %s | Idade: %d\n", atual->nome, atual->idade);
        atual = atual->prox;
    }
}

int main() {
    int opcao;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir Pilha\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                imprimir();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 4);

    while(topo != NULL) {
        pop();
    }

    return 0;
}*/

//Exercicio 7
/*typedef struct No {
    char nome[30];
    int idade;
    struct No* prox;
} No;

No* topo = NULL;

void push() {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    printf("Digite o nome: ");
    getchar();
    fgets(novo->nome, 30, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';

    printf("Digite a idade: ");
    scanf("%d", &novo->idade);

    novo->prox = topo;
    topo = novo;
}

void pop() {
    if (topo == NULL) {
        printf("A pilha esta vazia!\n");
        return;
    }

    No* temp = topo;
    topo = topo->prox;

    printf("Elemento removido: %s, %d anos\n", temp->nome, temp->idade);
    free(temp);
}

void imprimir() {
    if (topo == NULL) {
        printf("A pilha esta vazia!\n");
        return;
    }

    No* atual = topo;
    printf("\nElementos na pilha:\n");
    while (atual != NULL) {
        printf("Nome: %s | Idade: %d\n", atual->nome, atual->idade);
        atual = atual->prox;
    }
}

int tamanhoPilha() {
    int contador = 0;
    No* atual = topo;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    return contador;
}

int main() {
    int opcao;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir Pilha\n");
        printf("4 - Ver Tamanho da Pilha\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                imprimir();
                break;
            case 4:
                printf("Quantidade de elementos na pilha: %d\n", tamanhoPilha());
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 5);

    while(topo != NULL) {
        pop();
    }

    return 0;
}*/

//Exercicio 8
/*typedef struct No {
    char* nome;
    int idade;
    struct No* prox;
} No;

No* topo = NULL;

void push() {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    char buffer[100];
    printf("Digite o nome: ");
    getchar();
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    novo->nome = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    if (novo->nome == NULL) {
        printf("Erro ao alocar memória para o nome!\n");
        free(novo);
        return;
    }
    strcpy(novo->nome, buffer);

    printf("Digite a idade: ");
    scanf("%d", &novo->idade);

    novo->prox = topo;
    topo = novo;
}

void pop() {
    if (topo == NULL) {
        printf("A pilha esta vazia!\n");
        return;
    }

    No* temp = topo;
    topo = topo->prox;

    printf("Elemento removido: %s, %d anos\n", temp->nome, temp->idade);

    free(temp->nome);
    free(temp);
}

void imprimir() {
    if (topo == NULL) {
        printf("A pilha esta vazia!\n");
        return;
    }

    No* atual = topo;
    printf("\nElementos na pilha:\n");
    while (atual != NULL) {
        printf("Nome: %s | Idade: %d\n", atual->nome, atual->idade);
        atual = atual->prox;
    }
}

int tamanhoPilha() {
    int contador = 0;
    No* atual = topo;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    return contador;
}

void limparPilha() {
    while (topo != NULL) {
        pop();
    }
}

int main() {
    int opcao;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir Pilha\n");
        printf("4 - Ver Tamanho da Pilha\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                imprimir();
                break;
            case 4:
                printf("Quantidade de elementos na pilha: %d\n", tamanhoPilha());
                break;
            case 5:
                printf("Saindo...\n");
                limparPilha();
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 5);

    return 0;
}*/

//Exercicio 9
/*typedef struct No {
    int valor;
    struct No* prox;
} No;

No* topo = NULL;

void push(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;
    novo->valor = valor;
    novo->prox = topo;
    topo = novo;
}

void imprimirPilha() {
    No* atual = topo;
    printf("\nConteudo da pilha:\n");
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

bool existe(int array[], int tamanho, int valor) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (array[i] == valor) return true;
    }
    return false;
}

int main() {
    int numeros[10];
    int contador = 0;
    srand(time(NULL));

    while (contador < 10) {
        int num = rand() % 100 + 1;
        if (!existe(numeros, contador, num)) {
            numeros[contador] = num;
            push(num);
            contador++;
        }
    }

    imprimirPilha();

    while (topo != NULL) {
        No* temp = topo;
        topo = topo->prox;
        free(temp);
    }

    return 0;
}*/

//Exercicio 10
//A pilha vai ficar com o E no topo e A na base

//Exercicio 11
//Podemos tirar o 2 o 8 e o 3, pois o pop ele desce para o proximo indice do vetor,
//por mais que tenham mais numeros acima dele, o pop nao entende isso e ele so funciona enquanto o topo for maior ou igual a zero

//Exercicio 12
//Uma lista simplesmente encadeada é uma sequência de nós onde cada nó guarda um dado e um ponteiro para o próximo nó. Na inserção, cria-se um novo nó que aponta para o início da lista, e o início é atualizado para esse nó.
//Na remoção, o nó do início é removido, o início passa a apontar para o próximo nó, e o nó removido é liberado.

//Exercicio 13
//Uma lista duplamente encadeada é uma estrutura de dados onde cada nó possui três campos principais: o dado, um ponteiro para o próximo nó e um ponteiro para o nó anterior,
//onde permite navegação para frente e para trás na lista e facilidade para inserção e remoção de elementos em qualquer posição, pois é possível acessar os nós anteriores e posteriores diretamente.

//Exercicio 14
/*typedef struct No {
    int valor;
    struct No* prox;
} No;*/

//Exercicio 15
//A lista simplesmente encadeada possui apenas um ponteiro que aponta para o próximo nó, permitindo navegação apenas no sentido direto.
//Já a lista duplamente encadeada possui dois ponteiros, um que aponta para o próximo nó e outro que aponta para o nó anterior, permitindo a navegação em ambos os sentidos.
 
//Exercicio 16
/*typedef struct No {
    int valor;
    struct No* prox;
} No;*/

//Exercicio 17
//A linha 5 faz com que o algoritmo percorra a lista encadeada verificando cada elemento,
//parando apenas quando encontrar o número buscado ou chegar ao final da lista.

//Exercicio 18
//O resultado vai ser 10 20 30 40 50.

//Exercicio 19
/*typedef struct No {
    int valor;
    struct No* prox;
} No;*/
//Na lista circular, o último nó aponta de volta para o primeiro.

//Exercicio 20
/*typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;*/
//Além de apontar para o próximo nó prox, o nó também aponta para o anterior ant.

//Exercicio 21
//Gerenciamento de processos em sistemas operacionais. O sistema operacional usa listas encadeadas para organizar e controlar processos em execução, em espera ou prontos para serem executados.

//Exercicio 22
//Lista simplesmente encadeada: Cada nó contém um ponteiro apenas para o próximo nó.
//Lista duplamente encadeada: Cada nó contém dois ponteiros: um para o próximo e outro para o anterior.

//Exercicio 23
//Será 10 20 40 50. Na lista simplesmente encadeada, a remoção de um elemento significa ajustar o ponteiro do nó anterior para apontar para o próximo nó, "pulando" o nó que foi removido.

//Exercicio 24
/*void sair() {
    no* temp;
    while (top != NULL) {
        temp = top;
        top = top->proximo;
        free(temp);
    }
    printf("\nMemória liberada com sucesso.\n");
}*/

//Exercicio 25
//Não existe um "fim" na lista, a navegação pode continuar indefinidamente. Pode ser simplesmente ou duplamente encadeada: Dependendo se há um ou dois ponteiros por nó.
//Permite navegação contínua sem precisar verificar o final da lista. Ao percorrer a lista, quando chegamos no último nó, automaticamente voltamos ao início.
//Muito usada em sistemas que precisam de percursos cíclicos, como jogos, buffers circulares, ou escalonadores de processos.

//Exercicio 26
//A) [ Dado | Próximo ] -> [ Dado | Próximo ] -> [ Dado | NULL ]
//B) NULL <- [ Ant | Dado | Próx ] <-> [ Ant | Dado | Próx ] <-> [ Ant | Dado | NULL ]
//C) [ Dado | Próximo ] -> [ Dado | Próximo ] -> [ Dado | Próximo ] ->
//           |_______________________________________________________|

//Exercicio 27
//As regras para inserção e remoção de elementos (nós) em uma lista envolvem principalmente o correto ajuste dos ponteiros para manter a integridade da estrutura. 
//Na inserção, o novo nó deve ser criado e seus ponteiros configurados para se conectar aos nós já existentes, dependendo do tipo de lista: em listas simplesmente encadeadas,
//o novo nó aponta para o próximo; em listas duplamente encadeadas, ele aponta para o próximo e para o anterior; em listas circulares, o ciclo deve ser mantido. 
//Já na remoção, é essencial ajustar os ponteiros dos nós vizinhos ao nó que será excluído, para que a sequência da lista continue válida. Após o ajuste, a memória do nó removido deve ser liberada para evitar vazamentos,
//também é importante sempre verificar se a lista não está vazia antes de realizar a remoção, evitando erros de acesso a ponteiros nulos.

//Exercicio 28
//Topo -> [19] -> [8] -> [71] -> NULL
//p aponta para o nó com valor 19.

//Exercicio 29
//Para determinar o tamanho de uma lista encadeada, percorremos toda a lista a partir do primeiro nó até o final, contando cada nó visitado.
//Criamos uma variável contadora (ex: int tamanho = 0;).
//Usamos um laço (while) para percorrer a lista.
//A cada nó visitado, incrementamos o contador.E quando chegarmos ao final (nó com prox == NULL), o contador terá o total de elementos.

//Exercicio 30
/*typedef struct No {
    int valor;
    struct No* prox;
} No;

No* lista = NULL;
No* pares = NULL;
No* impares = NULL;

void inserir(No** lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *lista;
    *lista = novo;
}

int ehPar(int num) {
    return num % 2 == 0;
}

void separarParesEImpares(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        if (ehPar(atual->valor)) {
            inserir(&pares, atual->valor);
        } else {
            inserir(&impares, atual->valor);
        }
        atual = atual->prox;
    }
}

void imprimirLista(No* lista, char* nome) {
    printf("%s: ", nome);
    No* atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    inserir(&lista, 10);
    inserir(&lista, 7);
    inserir(&lista, 4);
    inserir(&lista, 9);
    inserir(&lista, 2);

    separarParesEImpares(lista);

    imprimirLista(lista, "Lista original");
    imprimirLista(pares, "Lista de pares");
    imprimirLista(impares, "Lista de ímpares");

    return 0;
}*/

//Exercicio 31
//O valor final sera 15.
