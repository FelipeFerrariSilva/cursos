#include <stdio.h>
#include <locale.h>

typedef struct {
    char nome[50]; // Nome do Jogador Ex: Moreno
    int idade; // Idde do jogador Ex: 41
    char classe[20]; // Classe do Jogador Ex: "Guerreiro", "Mago", etc.
} personagem;
//------------------------------------------------------------------------------
typedef struct {
    int nivel; // Nível do jogador no jogo Ex: 12
    int experiencia; // Pontuação de experiência Ex: 890
    personagem p; // Dados do personagem
} jogador;
//------------------------------------------------------------------------------
typedef struct apelido {
    jogador jog; //jog é uma variável do tipo jogador
    struct apelido *proximo; //*proximo é um ponteiro do nó
} no;
//------------------------------------------------------------------------------
no *topo = NULL; //topo é ponteiro que indica o TOPO da pilha

void push(jogador j);     // procedimento Empilhar
void pop();               // procedimento Desempilhar
void mostra_pilha();      // procedimento Imprimir pilha
void liberar_pilha();     // procedimento Limpar memória
jogador entrada_dados();  // função Entrada de dados que retorna dados do jogador

//-------------------------------------------
int main() {
    setlocale(LC_ALL, ""); //ativa teclado padrão do windows
    int opcao;
    jogador dados;
    do {
        system("cls");
        printf("\nMenu - Pilha de Jogadores");
        printf("\n1. Empilhar Jogador");
        printf("\n2. Desempilhar Jogador");
        printf("\n3. Apresenta Pilha");
        printf("\n4. Limpar Memória");
        printf("\n5. Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        fflush(stdin); 

        switch (opcao) {
            case 1:
                dados = entrada_dados();
                push(dados);
                break;
            case 2:
                pop();
                break;
            case 3:
                mostra_pilha();
                break;
            case 4:
                liberar_pilha();
                break;
            default:
                printf("Opção inválida");
                           
        }
        system("pause");
    } while (opcao != 5);

    liberar_pilha(); // limpeza final
    printf("\nFim do programa.\n");
    system("pause");
    return 0;
}
//-------------------------------------------
void push(jogador j) {
   no *novo=malloc(sizeof(no));
   if(novo){
   	novo-> jog=j;
   	novo-> proximo=topo;
   	topo=novo;
   }
    printf("\nJogador %s empilhado com sucesso!\n", j.p.nome);
}
//-------------------------------------------
void pop() {
	if(topo==NULL)
		printf("A pilha esta vazia\n");
	else{
		no *temp;
		temp=topo;
		topo=topo->proximo;
		printf("\nDESEMPILHANDO COM SUCESSO\n\n");
		free(temp);
	}
	system("pause");
}
//-------------------------------------------
void mostra_pilha() {
    no *temp;
    temp=topo;
    printf("\nIMPRIMINDO PILHA...\n");
    while (temp!=NULL){
    	printf("NOME: %s\nIDADE: %i\nCLASSE: %s\nNIVEL: %i\nEXPERIENCIA: %i\n", temp->jog.p.nome, temp->jog.p.idade, temp->jog.p.classe, temp->jog.nivel, temp->jog.experiencia);
    	temp=temp -> proximo;
	}
	system("pause");
}
//-------------------------------------------
void liberar_pilha() {
 	while(topo!=NULL){
 	 pop();
 }
    printf("\nMemória liberada com sucesso.\n");
}
//-------------------------------------------
jogador entrada_dados() {
    jogador jog;
    printf("\nCadastro do Jogador:\n");
    printf("Nome: ");
    scanf("%s",&jog.p.nome);
    fflush(stdin);
    printf("Idade: ");
    scanf("%i", &jog.p.idade);
    fflush(stdin);
    printf("Classe do jogador: ");
    scanf("%s", &jog.p.classe);
    fflush(stdin);
    printf("Nivel do jogador: ");
    scanf("%i", &jog.nivel);
    fflush(stdin);
    printf("Nivel de experiencia do jogador: ");
    scanf("%i", &jog.experiencia);
   
    return jog;
}

