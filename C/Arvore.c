#include <stdio.h>
#include <stdlib.h>
typedef struct no *p_no;
struct no{
	int valor;
	p_no dir, esq;
};
p_no criar_arvore();
void pre_ordem(p_no raiz);
void pos_ordem(p_no raiz);
void in_ordem(p_no raiz);
p_no inserir(p_no raiz, int x);
p_no buscar(p_no raiz, int chave);
p_no minimo(p_no raiz);
p_no maximo(p_no raiz);


int main(){
    p_no raiz = criar_arvore();
    // Inserir 100, 70, 150, 60, 80, 130, 170
    raiz = inserir(raiz,100);
    raiz = inserir(raiz,70);
    raiz = inserir(raiz,150);
    raiz = inserir(raiz,60);
    raiz = inserir(raiz,80);
    raiz = inserir(raiz,130);
    raiz = inserir(raiz,170);
/*    printf("Pre-ordem....................................\n");
    pre_ordem(raiz);
    printf("\n\nIn-ordem....................................\n");
    in_ordem(raiz);
    printf("\n\nPos-ordem....................................\n");
    pos_ordem(raiz); */
    
    printf("Menor ou minimo =  %d\n", minimo(raiz)->valor);
    printf("Maior ou maximo =  %d", maximo(raiz)->valor);
	return 0;
}

p_no maximo(p_no raiz){
	if(raiz == NULL || raiz->dir == NULL)
		return raiz;
		return maximo(raiz->dir);
}

p_no minimo(p_no raiz){
	if(raiz == NULL || raiz->esq == NULL)
		return raiz;
		return minimo(raiz->esq);
}

p_no criar_arvore(){
	return NULL;
}
p_no buscar(p_no raiz, int x) {
    if (raiz == NULL || x == raiz->valor)
        return raiz;
    if (x < raiz->valor)
        return buscar(raiz->esq, x);
    else
        return buscar(raiz->dir, x);
}
p_no inserir(p_no raiz, int x) {
    p_no novo;
    if (raiz == NULL) {
    novo = malloc(sizeof(struct no));
    novo->esq = novo->dir = NULL;
    novo->valor = x;
    return novo;
    }   
    if (x < raiz->valor)
        raiz->esq = inserir(raiz->esq, x);
    else
        raiz->dir = inserir(raiz->dir, x);
    return raiz;
}

void pre_ordem(p_no raiz){
	if(raiz != NULL){
		printf("%d ",raiz->valor);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}
void pos_ordem(p_no raiz){
	if(raiz != NULL){
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%d ",raiz->valor);
	}
}
void in_ordem(p_no raiz){
	if(raiz != NULL){
		in_ordem(raiz->esq);
		printf("%d ",raiz->valor);
		in_ordem(raiz->dir);
	}
}





