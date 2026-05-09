#include <stdio.h>
#include <stdlib.h>

/* =========================
   Função para imprimir vetor
   ========================= */
void imprimirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

/* =========================
   Selection Sort
   ========================= */
void selectionSort(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho - 1; i++) {
        int menor = i;

        int j;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

/* =========================
   Insertion Sort
   ========================= */
void insertionSort(int vetor[], int tamanho) {
    int i;
    for (i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
}

/* =========================
   Bubble Sort
   ========================= */
void bubbleSort(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho - 1; i++) {
        int j;
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

/* =========================
   Merge de 3 vetores ordenados
   ========================= */
void mergeTresVetores(int v1[], int n1, int v2[], int n2, int v3[], int n3, int resultado[]) {
    int i = 0, j = 0, k = 0, r = 0;

    while (i < n1 || j < n2 || k < n3) {
        int menor;
        int origem = -1;

        if (i < n1) {
            menor = v1[i];
            origem = 1;
        }

        if (j < n2 && (origem == -1 || v2[j] < menor)) {
            menor = v2[j];
            origem = 2;
        }

        if (k < n3 && (origem == -1 || v3[k] < menor)) {
            menor = v3[k];
            origem = 3;
        }

        resultado[r++] = menor;

        if (origem == 1) {
            i++;
        } else if (origem == 2) {
            j++;
        } else if (origem == 3) {
            k++;
        }
    }
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    if (n < 4) {
        printf("O vetor precisa ter no minimo 4 elementos.\n");
        return 1;
    }

    int vetor[n];

    printf("Digite os elementos do vetor:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    /* Divisão em 3 partes */
    int n1 = n / 3;
    int n2 = n / 3;
    int n3 = n - n1 - n2;

    int parte1[n1];
    int parte2[n2];
    int parte3[n3];

    for (i = 0; i < n1; i++) {
        parte1[i] = vetor[i];
    }

    for (i = 0; i < n2; i++) {
        parte2[i] = vetor[n1 + i];
    }

    for (i = 0; i < n3; i++) {
        parte3[i] = vetor[n1 + n2 + i];
    }

    printf("\nVetor original:\n");
    imprimirVetor(vetor, n);

    printf("\nParte 1 antes do Selection Sort:\n");
    imprimirVetor(parte1, n1);

    printf("Parte 2 antes do Insertion Sort:\n");
    imprimirVetor(parte2, n2);

    printf("Parte 3 antes do Bubble Sort:\n");
    imprimirVetor(parte3, n3);

    /* Ordenação de cada parte */
    selectionSort(parte1, n1);
    insertionSort(parte2, n2);
    bubbleSort(parte3, n3);

    printf("\nParte 1 depois do Selection Sort:\n");
    imprimirVetor(parte1, n1);

    printf("Parte 2 depois do Insertion Sort:\n");
    imprimirVetor(parte2, n2);

    printf("Parte 3 depois do Bubble Sort:\n");
    imprimirVetor(parte3, n3);

    /* Merge final */
    int resultado[n];
    mergeTresVetores(parte1, n1, parte2, n2, parte3, n3, resultado);

    printf("\nVetor final apos o merge:\n");
    imprimirVetor(resultado, n);

    return 0;
} 
