#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
   Copiar vetor
   ========================= */
void copiarVetor(int origem[], int destino[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
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
   Merge Sort - merge
   ========================= */
void merge(int vetor[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esquerda = (int *) malloc(n1 * sizeof(int));
    int *direita  = (int *) malloc(n2 * sizeof(int));

    if (esquerda == NULL || direita == NULL) {
        printf("Erro ao alocar memoria no merge.\n");
        free(esquerda);
        free(direita);
        exit(1);
    }

    int i;
    for (i = 0; i < n1; i++) {
        esquerda[i] = vetor[inicio + i];
    }

    int j;
    for (j = 0; j < n2; j++) {
        direita[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    int k = inicio;

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    free(esquerda);
    free(direita);
}

/* =========================
   Merge Sort - recursivo
   ========================= */
void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

/* =========================
   Quick Sort - particao
   ========================= */
int particao(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;
    int j;

    for (j = inicio; j < fim; j++) {
        if (vetor[j] < pivo) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return i + 1;
}

/* =========================
   Quick Sort - recursivo
   ========================= */
void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int posPivo = particao(vetor, inicio, fim);

        quickSort(vetor, inicio, posPivo - 1);
        quickSort(vetor, posPivo + 1, fim);
    }
}

int main() {
    srand(time(NULL));

    /* =========================
       MUDE AQUI O TAMANHO
       ========================= */
    int n = 75000;

    int *original   = (int *) malloc(n * sizeof(int));
    int *vInsertion = (int *) malloc(n * sizeof(int));
    int *vSelection = (int *) malloc(n * sizeof(int));
    int *vBubble    = (int *) malloc(n * sizeof(int));
    int *vMerge     = (int *) malloc(n * sizeof(int));
    int *vQuick     = (int *) malloc(n * sizeof(int));

    if (original == NULL || vInsertion == NULL || vSelection == NULL ||
        vBubble == NULL || vMerge == NULL || vQuick == NULL) {
        printf("Erro ao alocar memoria.\n");

        free(original);
        free(vInsertion);
        free(vSelection);
        free(vBubble);
        free(vMerge);
        free(vQuick);

        return 1;
    }

    /* Gerar vetor aleatorio */
    int i;
    for (i = 0; i < n; i++) {
        original[i] = rand() % 1000;
    }

    /* Fazer copias */
    copiarVetor(original, vInsertion, n);
    copiarVetor(original, vSelection, n);
    copiarVetor(original, vBubble, n);
    copiarVetor(original, vMerge, n);
    copiarVetor(original, vQuick, n);

    clock_t inicio, fim;
    double tempoInsertion, tempoSelection, tempoBubble, tempoMerge, tempoQuick;

    /* Insertion Sort */
    inicio = clock();
    insertionSort(vInsertion, n);
    fim = clock();
    tempoInsertion = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    /* Selection Sort */
    inicio = clock();
    selectionSort(vSelection, n);
    fim = clock();
    tempoSelection = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    /* Bubble Sort */
    inicio = clock();
    bubbleSort(vBubble, n);
    fim = clock();
    tempoBubble = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    /* Merge Sort */
    inicio = clock();
    mergeSort(vMerge, 0, n - 1);
    fim = clock();
    tempoMerge = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    /* Quick Sort */
    inicio = clock();
    quickSort(vQuick, 0, n - 1);
    fim = clock();
    tempoQuick = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nTempos de execucao para %d elementos:\n", n);
    printf("Insertion Sort: %.8f segundos\n", tempoInsertion);
    printf("Selection Sort: %.8f segundos\n", tempoSelection);
    printf("Bubble Sort:    %.8f segundos\n", tempoBubble);
    printf("Merge Sort:     %.8f segundos\n", tempoMerge);
    printf("Quick Sort:     %.8f segundos\n", tempoQuick);

    /* Se quiser mostrar os vetores ordenados, descomente abaixo */
    /*
    printf("\nVetores ordenados:\n");

    printf("\nInsertion Sort:\n");
    imprimirVetor(vInsertion, n);

    printf("\nSelection Sort:\n");
    imprimirVetor(vSelection, n);

    printf("\nBubble Sort:\n");
    imprimirVetor(vBubble, n);

    printf("\nMerge Sort:\n");
    imprimirVetor(vMerge, n);

    printf("\nQuick Sort:\n");
    imprimirVetor(vQuick, n);
    */

    free(original);
    free(vInsertion);
    free(vSelection);
    free(vBubble);
    free(vMerge);
    free(vQuick);

    return 0;
}
