#include <stdio.h>

//Matriz De Adjacencia
int ma[10][10] = {
	{0,0,1,1,1,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{1,1,0,1,1,1,1,0,0,0},
	{1,0,1,0,0,1,1,0,0,0},
	{1,0,1,0,0,1,0,1,0,0},
	{0,0,1,1,1,0,1,1,1,1},
	{0,0,1,1,0,1,0,0,0,1},
	{0,0,0,0,1,1,0,0,1,0},
	{0,0,0,0,0,1,0,1,0,1},
	{0,0,0,0,0,1,1,0,1,0}
};
int quantidade_loops();
int arestas();
int maior_grau();
int menor_grau();
int main(){
	printf("Loop(s): %d \n",quantidade_loops());
	printf("Aresta(s): %d \n",arestas());
	printf("Maior grau: %d \n",maior_grau());
	printf("Menor grau: %d \n",menor_grau());
	return 0;
}
int maior_grau(){
	int maior = 0;
	int i,j = 0;
	for(i = 0; i < 10; i++){
		int m = 0;
		for(j = 0; j < 10; j++) m += ma[i][j];
		if(m > maior) maior = m;
	}
	return maior;
}
int menor_grau(){
	int menor = 11;
	int i,j = 0;
	for(i = 0; i < 10; i++){
		int m = 0;
		for(j = 0; j < 10; j++) m += ma[i][j];
		if(m < menor) menor = m;
	}
	return menor;
}
int arestas(){
	int a = 0;
	int i, j = 0;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			//if(i == j && ma[i][j] == 1) a++;
			//a += ma[i][j];
			a += ma[i][j] + (i == j && ma[i][j] == 1);
		}	
	}
	return a/2;
}
int quantidade_loops(){
	int loops = 0;
	int i = 0;
	for(i = 0; i < 10; i++)
		loops += ma[i][i];
		return loops;
}
