#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
	setlocale(LC_ALL, "Portuguese");
  struct pessoa{
    char nome[50];
    char fone[15];
    char email[30];
    char cpf[15];
                 
  };
  struct pessoa p[3];
    
  int i;
  
  for(i = 0; i <3; i++){
        printf("Digite o nome: ");
    	scanf("%s", p[i].nome);
        printf("Digite o numero: ");
        scanf("%s", p[i].fone);
        printf("Digite o email: ");
        scanf("%s", p[i].email);
        printf("Digite o cpf: ");
        scanf("%s", p[i].cpf);
  }
  
  int x,y,z;
  char w;
  float k;
  double n;
  
  int *ptr_x, *ptr_y, *ptr_z;
  char *ptr_w;
  float *ptr_k;
  double *ptr_n;
  
  ptr_x=&x;
  ptr_y=&y;
  ptr_z=&z;
  ptr_w=&w;
  ptr_k=&k;
  ptr_n=&n;
  
  x=10;
  y=20;
  *ptr_z=(10*y)-20;
  w=p[1].nome[2];
  k=90;
  n= 0,325*(*ptr_x + *ptr_y);

  printf("Variavel x= %d, Endereço de memoria: %p \n", x,&x);
  printf("Variavel y= %d, Endereço de memoria: %p \n", y,&y);
  printf("Variavel z= %d, Endereço de memoria: %p \n", z,&z);
  printf("Ponteiro x= %d, Endereço de memoria: %p \n", *ptr_x,&ptr_x);
  printf("Ponteiro y= %d, Endereço de memoria: %p \n", *ptr_y,&ptr_y);
  printf("Ponteiro z= %d, Endereço de memoria: %p \n", *ptr_z,&ptr_z);
  printf("Ponteiro w= %c, Endereço de memoria: %p \n", *ptr_w,&ptr_w);
  printf("Ponteiro k= %d, Endereço de memoria: %p \n", *ptr_k,&ptr_k);
  printf("Ponteiro n= %d, Endereço de memoria: %p \n", *ptr_n,&ptr_n);
  printf("Ponteiro x aponta para endereço de memoria: %p \n", &*ptr_x);
  printf("Ponteiro y aponta para endereço de memoria: %p \n", &*ptr_y);
  printf("Ponteiro z aponta para endereço de memoria: %p \n", &*ptr_z);
  printf("Ponteiro w aponta para endereço de memoria: %p \n", &*ptr_w);
  printf("Ponteiro k aponta para endereço de memoria: %p \n", &*ptr_k);
  printf("Ponteiro n aponta para endereço de memoria: %p \n", &*ptr_n); 
  printf("Tam. em bytes de x: %d\n", sizeof(x));
  printf("Tam. em bytes de y: %d\n", sizeof(y));
  printf("Tam. em bytes de z: %d\n", sizeof(z));
  printf("Tam. em bytes de w: %d\n", sizeof(w));
  printf("Tam. em bytes de k: %d\n", sizeof(k));
  printf("Tam. em bytes de n: %d\n", sizeof(n));
  printf("Tam. em bytes de ptr_x: %d\n", sizeof(ptr_x));
  printf("Tam. em bytes de ptr_y: %d\n", sizeof(ptr_y));
  printf("Tam. em bytes de ptr_z: %d\n", sizeof(ptr_z));
  printf("Tam. em bytes de ptr_w: %d\n", sizeof(ptr_w));
  printf("Tam. em bytes de ptr_k: %d\n", sizeof(ptr_k));
  printf("Tam. em bytes de ptr_n: %d\n", sizeof(ptr_n));
  printf("Tam. em bytes de struct pessoa: %d\n", sizeof(struct pessoa));
  
  
  
  system("pause");
  return 0;
}
