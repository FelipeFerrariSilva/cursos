#include<stdlib.h>
#include<stdio.h>

void push(int item); //empilhar
void pop();  //desempilhar
void imprimir();
int entrada_dados();

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
}no;

no *top = NULL;
//------------------------------------------------
int main(){
	int n,opcao;
	do{
		system("cls");
		printf("\n\nMenu\n1. Empilhar \n2. Desempilhar \n3. Imprimir \n4. Sair ");
		printf("\nEscolha uma opcao (0-4): ");
		scanf("%d", &opcao);
		switch (opcao){
			case 1:
				n=entrada_dados();
				push(n); //empilhar
				break;
			case 2:
				pop(); //desempilhar
				break;
			case 3:
				imprimir();
				break;
		}
	}while (opcao!=4);
	system("pause");
	return 0;}
//------------------------------------------------
void push(int item){
	printf("\nEMPILHANDO......\n");
	no *novo=malloc(sizeof(no));
	//necessário verificar se há memória
	novo->dado=item;
	novo->proximo=top;
	top=novo;
	printf("\nValor %d empilhado\n", novo->dado);
	system("pause");
}
//------------------------------------------------
void pop(){
	printf("\nDESEMPILHANDO.....\n");
	if (top==NULL)
	printf("A pilha esta vazia\n");
	else{
		no *temp;
		temp=top;
		top=top->proximo;
		printf("\n%d Desempilhado \n", temp->dado);
		free(temp);
	}
	system("pause");
}
//------------------------------------------------
void imprimir(){
	no *temp;
	temp=top;
	printf("\nIMPRIMINDO PILHA.....\n");
	while(temp!=NULL){
		printf("%d\n", temp->dado);
		temp=temp->proximo;
	}
	system("pause");
}
//-----------------------------------------------
int entrada_dados(){
	int valor;
	printf("\nEntre com valor a empilhar: ");
	scanf("%d", &valor);
	return valor;
}
