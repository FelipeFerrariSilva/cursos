#include<stdio.h>
#include<stdlib.h>

int main (void){
	int i, tam, *vet, valor;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	
	vet=malloc(tam*sizeof(int));
	
	for (i=0; i<tam; i++){
		printf("Digite o %d valor: ", i+1);
		scanf("%d", &valor);
		*(vet+i)=valor;
	}
	
	for (i=0; i<tam; i++){
		printf("vetor[%d] = %d \n", i+1,vet[i]);
    }
    free(vet);
}
