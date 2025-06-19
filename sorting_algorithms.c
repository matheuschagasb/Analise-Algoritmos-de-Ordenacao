#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}


void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
        
    i = 0; j = 0; k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    while (i < n1)
        arr[k++] = L[i++];
    
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontra o ponto médio
        int m = l + (r - l) / 2;

        // Ordena a metade esquerda
        mergeSort(arr, l, m);

        // Ordena a metade direita
        mergeSort(arr, m + 1, r);

        // Combina as duas metades ordenadas
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o array e obtém o índice do pivô
        int pi = partition(arr, low, high);

        // Ordena os elementos antes do pivô
        quickSort(arr, low, pi - 1);

        // Ordena os elementos depois do pivô
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
        
    if (r < n && arr[r] > arr[largest])
        largest = r;
        
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Um por um, extrai os elementos do heap
    for (int i = n - 1; i > 0; i--) {
        // Move o maior elemento para o final do array
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Reaplica o heapify na raiz
        heapify(arr, i, 0);
    }
}


int* gerarArrayAleatorio(int tamanho) {
    int* arr = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
        arr[i] = rand() % 10000;
    return arr;
}


int* copiarArray(int* arr, int tamanho) {
    int* copia = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
        copia[i] = arr[i];
    return copia;
}

int main() {
    srand(time(NULL));  // Inicializa a semente do gerador de números aleatórios

    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int num_tamanhos = 5;

    printf("Análise de Desempenho dos Algoritmos de Ordenação\n\n");
    printf("Tamanho\tSelection\tInsertion\tBubble\t\tMerge\t\tQuick\t\tHeap\n");

    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];

        int* arr_original = gerarArrayAleatorio(tamanho);
        int* arr;
        clock_t inicio, fim;
        double tempo;

        printf("%d\t", tamanho);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        selectionSort(arr, tamanho);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("%.6f\t", tempo);
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        insertionSort(arr, tamanho);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("%.6f\t", tempo);
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        bubbleSort(arr, tamanho);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("%.6f\t", tempo);
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        mergeSort(arr, 0, tamanho - 1);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("%.6f\t", tempo);
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        quickSort(arr, 0, tamanho - 1);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("%.6f\t", tempo);
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        heapSort(arr, tamanho);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("%.6f\n", tempo);
        free(arr);

        free(arr_original);
    }

    sleep(10);  // Pausa de 10 segundos para permitir visualização do resultado
    return 0;
}
