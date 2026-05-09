#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

void imprime(int *v, int t){
	int i;
		for (i=0; i<t; i++){
		printf("vetor[%d] = %d //// Endereco de memoria: %p \n", i+1,v[i], &v[i] );
	}
}

void imprime15(int *v, int t){
	int i;
		for (i=0; i<t; i++){
		printf("vetor[%d] = %d //// Endereco de memoria: %p \n", i+1,v[i], &v[i] );
	}
}

void imprime8(int *v, int t){
	int i;
		for (i=0; i<t; i++){
		printf("vetor[%d] = %d //// Endereco de memoria: %p \n", i+1,v[i], &v[i] );
	}
}

int main(void){
	int i, tam, *vet;
	tam=10;
	srand(time (NULL)) ;
	vet=malloc(tam*sizeof(int));
	for (i=0; i<tam; i++){
		*(vet+i)=rand()%91 + 10;
		printf("%d elemento: %d \n", i+1, *(vet+i));
	}
	
	printf("Endereco de memoria do vetor %p\n", &vet);
	imprime(vet,tam);
	
	printf("Vetor com 15 elementos agora\n");
	*vet=realloc(vet, 15*sizeof(int));
	tam=15;
		for (i=0; i<tam; i++){
		*(vet+i)=rand()%90 + 100;
		printf("%d elemento: %d \n", i+1, *(vet+i));
	}
	
	imprime15(vet,tam);

	printf("Vetor com 8 elementos agora\n");
	*vet=realloc(vet, 8*sizeof(int));
	tam=8;
		for (i=0; i<tam; i++){
		*(vet+i)=rand()%90 + 100;
		printf("%d elemento: %d \n", i+1, *(vet+i));
	}

	imprime8(vet,tam);


return 0;
}
