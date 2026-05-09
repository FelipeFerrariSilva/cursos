#include <stdio.h>

char tb[3][3] = {
 	{' ',' ',' '},
 	{' ',' ',' '},
 	{' ',' ',' '}
};

void verificar_ganhador();
char jogador = ' ';
int jogadas = 0;
void iniciar();
void jogar();
void terminar();
void mostrar();

int main(){
	mostrar();
	jogador = 'x';
	jogar();
	return 0;
}

int diagonal_p(char letra){
	return(tb[0][0] == letra && tb[1][1] == letra && tb[2][2] == letra);
}

int diagonal_s(char letra){
	return(tb[0][2] == letra && tb[1][1] == letra && tb[2][0] == letra);
}

int linha(int l, char letra){
	return(tb[l][0] == letra && tb[l][1] == letra && tb[l][2] == letra);
}

int coluna(int c, char letra){
	return(tb[0][c] == letra && tb[1][c] == letra && tb[2][c] == letra);
}

void verificar_ganhador(int l, int c, char letra){
	int ganhou = 0;
	if(l == c) if(diagonal_p(letra)) return 1;
	if( (l == 0 && c == 2) || (l == 1 && c ==1) || (l ==2 && c == 0) )
		if(diagonal_s(letra)) return 1;
	if (linha(l, letra)) return 1;
	return coluna(c,letra);
}

void trocar_jogador(){
	if(jogador == 'x') jogador ='o';
	else jogador = 'x';
}

void jogar(){
	int l,c;
	printf("Digite a linha: ");
	scanf("%d", &l);
	printf("\n Digite a coluna: ");
	scanf("%d", &c);
	//Antes de marcar, validar o local.
	tb[l-1][c-1] = jogador;
	trocar_jogador();
	jogadas ++;
	mostrar();
}

void mostrar(){
	int l, c;
	for(l = 0; l < 3; l ++){
		printf("|");
		for(c = 0; c < 2; c ++){
			printf("%c ,", tb[l][c]);
		}
		printf("%c ", tb[l][2]);
		printf("|\n");
	}
	printf("\n \n");
}
