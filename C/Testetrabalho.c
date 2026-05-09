#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/* novas funcoes */
int existe_no_arranjo(int v[], int tamanho, int valor);
void gerar_arranjo(int v[], int n);
void imprimir_arranjo(int v[], int n);
int *juntar_todos_arranjos(int **arranjos, int qtd, int n);
p_no montar_melhor_arvore(int v[], int inicio, int fim);
void liberar_arvore(p_no raiz);

int comparar(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

int main(){
	p_no raiz = criar_arvore();
	int A, n, i;
	int **arranjos;
	int *vetor_final;
	int total_elementos;

	clock_t inicio_total, fim_total;
	clock_t inicio_merge, fim_merge;
	clock_t inicio_ord, fim_ord;
	clock_t inicio_arvore, fim_arvore;

	double tempo_merge, tempo_ord, tempo_arvore, tempo_total;

	srand(time(NULL));

	printf("Quantidade de arranjos (maximo 10): ");
	scanf("%d", &A);

	while(A < 1 || A > 10){
		printf("Valor invalido. Digite entre 1 e 10: ");
		scanf("%d", &A);
	}

	printf("Quantidade de elementos em cada arranjo: ");
	scanf("%d", &n);

	while(n <= 0){
		printf("Valor invalido. Digite um valor maior que 0: ");
		scanf("%d", &n);
	}

	arranjos = malloc(A * sizeof(int *));
	if(arranjos == NULL){
		printf("Erro de alocacao de memoria.\n");
		return 1;
	}

	for(i = 0; i < A; i++){
		arranjos[i] = malloc(n * sizeof(int));
		if(arranjos[i] == NULL){
			printf("Erro de alocacao de memoria.\n");
			return 1;
		}
	}

	inicio_total = clock();

	printf("\nArranjos gerados automaticamente:\n");
	for(i = 0; i < A; i++){
		gerar_arranjo(arranjos[i], n);
		printf("Arranjo %d: ", i + 1);
		imprimir_arranjo(arranjos[i], n);
	}

	inicio_merge = clock();
	vetor_final = juntar_todos_arranjos(arranjos, A, n);
	fim_merge = clock();

	total_elementos = A * n;

	printf("\nVetor final apos juntar todos os arranjos:\n");
	imprimir_arranjo(vetor_final, total_elementos);

	inicio_ord = clock();
	qsort(vetor_final, total_elementos, sizeof(int), comparar);
	fim_ord = clock();

	printf("\nVetor final ordenado:\n");
	imprimir_arranjo(vetor_final, total_elementos);

	inicio_arvore = clock();
	raiz = montar_melhor_arvore(vetor_final, 0, total_elementos - 1);
	fim_arvore = clock();

	printf("\nPre-ordem da arvore:\n");
	pre_ordem(raiz);
	printf("\n");

	fim_total = clock();

	tempo_merge = (double)(fim_merge - inicio_merge) / CLOCKS_PER_SEC;
	tempo_ord = (double)(fim_ord - inicio_ord) / CLOCKS_PER_SEC;
	tempo_arvore = (double)(fim_arvore - inicio_arvore) / CLOCKS_PER_SEC;
	tempo_total = (double)(fim_total - inicio_total) / CLOCKS_PER_SEC;

	printf("\nTempos de execucao:\n");
	printf("Juntar arranjos: %.8f segundos\n", tempo_merge);
	printf("Ordenacao final: %.8f segundos\n", tempo_ord);
	printf("Arvore: %.8f segundos\n", tempo_arvore);
	printf("Total: %.8f segundos\n", tempo_total);

	for(i = 0; i < A; i++){
		free(arranjos[i]);
	}
	free(arranjos);
	free(vetor_final);
	liberar_arvore(raiz);

	return 0;
}

int existe_no_arranjo(int v[], int tamanho, int valor){
	int i;
	for(i = 0; i < tamanho; i++){
		if(v[i] == valor)
			return 1;
	}
	return 0;
}

void gerar_arranjo(int v[], int n){
	int i = 0;
	int valor;

	while(i < n){
		valor = rand() % 1000;
		if(!existe_no_arranjo(v, i, valor)){
			v[i] = valor;
			i++;
		}
	}
}

void imprimir_arranjo(int v[], int n){
	int i;
	printf("[ ");
	for(i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	printf("]\n");
}

int *juntar_todos_arranjos(int **arranjos, int qtd, int n){
	int *resultado;
	int i, j, k = 0;

	resultado = malloc(qtd * n * sizeof(int));
	if(resultado == NULL){
		printf("Erro de alocacao de memoria.\n");
		exit(1);
	}

	for(i = 0; i < qtd; i++){
		for(j = 0; j < n; j++){
			resultado[k++] = arranjos[i][j];
		}
	}

	return resultado;
}

p_no montar_melhor_arvore(int v[], int inicio, int fim){
	int meio;
	p_no raiz;

	if(inicio > fim)
		return NULL;

	meio = (inicio + fim) / 2;

	raiz = malloc(sizeof(struct no));
	if(raiz == NULL){
		printf("Erro de alocacao de memoria.\n");
		exit(1);
	}

	raiz->valor = v[meio];
	raiz->esq = montar_melhor_arvore(v, inicio, meio - 1);
	raiz->dir = montar_melhor_arvore(v, meio + 1, fim);

	return raiz;
}

void liberar_arvore(p_no raiz){
	if(raiz != NULL){
		liberar_arvore(raiz->esq);
		liberar_arvore(raiz->dir);
		free(raiz);
	}
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

p_no buscar(p_no raiz, int x){
	if(raiz == NULL || x == raiz->valor)
		return raiz;
	if(x < raiz->valor)
		return buscar(raiz->esq, x);
	else
		return buscar(raiz->dir, x);
}

p_no inserir(p_no raiz, int x){
	p_no novo;
	if(raiz == NULL){
		novo = malloc(sizeof(struct no));
		if(novo == NULL){
			printf("Erro de alocacao de memoria.\n");
			exit(1);
		}
		novo->esq = novo->dir = NULL;
		novo->valor = x;
		return novo;
	}
	if(x < raiz->valor)
		raiz->esq = inserir(raiz->esq, x);
	else
		raiz->dir = inserir(raiz->dir, x);
	return raiz;
}

void pre_ordem(p_no raiz){
	if(raiz != NULL){
		printf("%d ", raiz->valor);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

void pos_ordem(p_no raiz){
	if(raiz != NULL){
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%d ", raiz->valor);
	}
}

void in_ordem(p_no raiz){
	if(raiz != NULL){
		in_ordem(raiz->esq);
		printf("%d ", raiz->valor);
		in_ordem(raiz->dir);
	}
}
