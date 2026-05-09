// implemente uma versão que não permita a inserção de valores repetidos na lista, bem como uma opção que permita a remoção de um elemento da lista.
#include <stdlib.h>
#include <stdio.h>
typedef struct apelido_struct{
  int val;
  struct apelido_struct *prox;
}no;
//---------------------------------------
int repetido(no *lista, int num){
	if (lista == NULL)
		return 0;
	
	while(lista){
		if (lista->val==num)
			return 1;
		lista = lista->prox;
	}
	return 0;
}
//---------------------------------------
void remover(no **lista, int num){
	no *aux = *lista, *anterior = NULL;
	while (aux && aux ->val != num){
		anterior = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL){
		printf("\nValor nao encontrado!");
		return;
	}
	
	if (anterior == NULL){
		*lista = aux->prox;
	}else {
		anterior->prox = aux->prox;
	}
	
	free(aux);
	printf("\nValor removido!");
}
//---------------------------------------
void inserir_inicio(no **lista, int num){
	no *novo=malloc(sizeof(no));
   if (novo){
    novo->val=num;
    novo->prox=*lista;
    *lista=novo;
  }  
  else
    printf("erro ao alocar memoria \n");   
}
//---------------------------------------
void inserir_fim(no **lista, int num){
  no *aux, *novo=malloc(sizeof(no));
   if (novo){
    novo->val=num;
    novo->prox=NULL;
    if (*lista==NULL)
      *lista=novo;
    else{
      aux=*lista;
      while(aux->prox)
        aux=aux->prox;
      aux->prox=novo;  
    }
  }  
  else
    printf("erro ao alocar memoria \n");   
}
//---------------------------------------
void inserir_ordenado(no **lista, int num){
  no *aux, *novo=malloc(sizeof(no));
  novo->val=num;
  if (*lista==NULL){
    novo->prox=NULL;
    *lista=novo;
  }else if(novo->val<(*lista)->val){
    novo->prox=*lista;
    *lista=novo;
    }else{
    aux=*lista;
    while(aux->prox && novo->val>aux->prox->val)
      aux=aux->prox;
    novo->prox=aux->prox;
    aux->prox=novo;  
  }
}
void imprimir(no *no){
  printf("\nLista: ");
  while (no){
    printf("%d ",no->val);
    no=no->prox;
  }
  printf("\n\n");
}
//-------------------------------------
int main() {
  no *lista=NULL;
  int opcao,val,anterior;
  do{
    printf("\n1 inserir no inicio");
    printf("\n2 inserir no final");
    printf("\n3 inserir ordenado");
    printf("\n4 remover");
    printf("\n5 imprimir");
    printf("\n6 fim");
    printf("\nopcao: ");
    fflush(stdin);
    scanf("%d",&opcao);
    switch (opcao) {
      case 1:
        printf("\nvalor a inserir: ");
        fflush(stdin);
        scanf("%d",&val);
        repetido(&lista, val);
        inserir_inicio(&lista,val);
        break;
      case 2:
        printf("\nvalor a inserir: ");
        fflush(stdin);
        scanf("%d",&val);
        repetido(&lista, val);
        inserir_fim(&lista,val);
        break;
      case 3:
        printf("\nvalor a inserir: ");
        fflush(stdin);
        scanf("%d",&val);
        repetido(&lista, val);
        inserir_ordenado(&lista,val);
        break;
      case 4:
        printf("\nValor a remover: ");
        fflush(stdin);
        scanf("%d", &val);
        remover(&lista, val);
        break;
      case 5:
        imprimir(lista);     
        break;
     } 
  }
  while (opcao!=6); 
  system("pause");
  return 0;
}
