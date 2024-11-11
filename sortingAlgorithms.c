#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx; // Declaração das variáveis
    for (i = 0; i < n-1; i++) { // Loop para percorrer o array
        min_idx = i; // Inicializa o índice mínimo com o índice atual
        for (j = i+1; j < n; j++) // Loop para encontrar o menor elemento
            if (arr[j] < arr[min_idx])  // Compara o elemento atual com o elemento mínimo
                min_idx = j; // Atualiza o índice mínimo se encontrar um elemento menor
        int temp = arr[min_idx]; // Troca o elemento mínimo com o elemento atual
        arr[min_idx] = arr[i]; // Atualiza o elemento mínimo com o elemento atual
        arr[i] = temp; // Atualiza o elemento atual com o elemento mínimo
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, chave, j; // Declaração das variáveis
    for (i = 1; i < n; i++) { // Loop para percorrer o array
        chave = arr[i]; // Armazena o elemento atual
        j = i - 1;
        while (j >= 0 && arr[j] > chave) { // Loop para encontrar a posição correta do elemento
            arr[j + 1] = arr[j]; // Move o elemento para a direita
            j = j - 1; // Decrementa o índice
        }
        arr[j + 1] = chave; // Atualiza a posição correta do elemento
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j; // Declaração das variáveis
    for (i = 0; i < n-1; i++) // Loop para percorrer o array
        for (j = 0; j < n-i-1; j++) // Loop para comparar os elementos
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1]; // Troca os elementos
                arr[j+1] = temp; // Troca os elementos
            }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k; // Declaração das variáveis
    int n1 = m - l + 1; // Calcula o tamanho do subarray esquerdo
    int n2 = r - m; // Calcula o tamanho do subarray direito
    
    int L[n1], R[n2]; // Declaração dos subarrays esquerdo e direito
    
    for (i = 0; i < n1; i++) // Loop para copiar os elementos do subarray esquerdo
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++) // Loop para copiar os elementos do subarray direito
        R[j] = arr[m + 1 + j];
        
    i = 0; // Inicializa o índice do subarray esquerdo
    j = 0; // Inicializa o índice do subarray direito
    k = l; // Inicializa o índice do array original
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // Copia o elemento do subarray esquerdo para o array original
            i++; // Incrementa o índice do subarray esquerdo
        }
        else {
            arr[k] = R[j]; // Copia o elemento do subarray direito para o array original
            j++; // Incrementa o índice do subarray direito
        }
        k++; // Incrementa o índice do array original
    }
    
    while (i < n1) {
        arr[k] = L[i]; // Copia o elemento do subarray esquerdo para o array original
        i++; // Incrementa o índice do subarray esquerdo
        k++; // Incrementa o índice do array original
    }
    
    while (j < n2) {
        arr[k] = R[j]; // Copia o elemento do subarray direito para o array original
        j++; // Incrementa o índice do subarray direito
        k++; // Incrementa o índice do array original
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // Incrementa o índice do array original
            int temp = arr[i]; // Armazena o elemento atual
            arr[i] = arr[j]; // Troca o elemento atual com o elemento mínimo
            arr[j] = temp; // Troca o elemento mínimo com o elemento atual
        }
    }
    int temp = arr[i + 1]; // Armazena o elemento atual     
    arr[i + 1] = arr[high]; // Troca o elemento atual com o elemento mínimo
    arr[high] = temp; // Troca o elemento mínimo com o elemento atual
    return (i + 1); // Retorna o índice do elemento pivô
}

void quickSort(int arr[], int low, int high) {
    if (low < high) { // Verifica se o array tem mais de um elemento
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior elemento com o índice atual
    int l = 2 * i + 1; // Calcula o índice do filho esquerdo
    int r = 2 * i + 2; // Calcula o índice do filho direito
    
    if (l < n && arr[l] > arr[largest]) // Compara o filho esquerdo com o maior elemento
        largest = l;
        
    if (r < n && arr[r] > arr[largest]) // Compara o filho direito com o maior elemento
        largest = r;
        
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest]; // Troca o elemento atual com o maior elemento
        arr[largest] = temp; // Troca o maior elemento com o elemento atual
        heapify(arr, n, largest); // Chama a função heapify recursivamente
    }
}

void heapSort(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) // Loop para construir o heap
        heapify(arr, n, i);
        
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp; // Troca o elemento atual com o maior elemento
        heapify(arr, i, 0); // Chama a função heapify recursivamente
    }
}

// Função para gerar array aleatório
int* gerarArrayAleatorio(int tamanho) {
    int* arr = (int*)malloc(tamanho * sizeof(int)); // Aloca memória para o array
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 10000; // Gera números aleatórios entre 0 e 9999
    }
    return arr; // Retorna o array aleatório
}

// Função para copiar array
int* copiarArray(int* arr, int tamanho) {
    int* copia = (int*)malloc(tamanho * sizeof(int)); // Aloca memória para a cópia do array
    for (int i = 0; i < tamanho; i++) {
        copia[i] = arr[i];
    }
    return copia; // Retorna a cópia do array
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    int tamanhos[] = {100, 1000, 10000, 50000, 100000}; // Array com os tamanhos dos arrays
    int num_tamanhos = 5; // Número de tamanhos dos arrays
    
    printf("Análise de Desempenho dos Algoritmos de Ordenação\n\n");
    printf("Tamanho\tSelection\tInsertion\tBubble\t\tMerge\t\tQuick\t\tHeap\n");
    
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        int* arr_original = gerarArrayAleatorio(tamanho); // Gera o array original
        int* arr;
        clock_t inicio, fim; // Declaração das variáveis para medir o tempo
        double tempo;
        
        printf("%d\t", tamanho); // Imprime o tamanho do array
        // Selection Sort
        arr = copiarArray(arr_original, tamanho); // Copia o array original
        inicio = clock(); // Inicializa o tempo
        selectionSort(arr, tamanho); // Ordena o array
        fim = clock(); // Finaliza o tempo
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo
        printf("%.6f\t", tempo); // Imprime o tempo
        free(arr); // Libera a memória alocada para o array
        
        // Insertion Sort
        arr = copiarArray(arr_original, tamanho); // Copia o array original
        inicio = clock(); // Inicializa o tempo
        insertionSort(arr, tamanho); // Ordena o array
        fim = clock(); // Finaliza o tempo
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo
        printf("%.6f\t", tempo); // Imprime o tempo
        free(arr); // Libera a memória alocada para o array
        
        // Bubble Sort
        arr = copiarArray(arr_original, tamanho); // Copia o array original
        inicio = clock(); // Inicializa o tempo
        bubbleSort(arr, tamanho); // Ordena o array
        fim = clock(); // Finaliza o tempo
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo
        printf("%.6f\t", tempo); // Imprime o tempo
        free(arr); // Libera a memória alocada para o array
        
        // Merge Sort
        arr = copiarArray(arr_original, tamanho); // Copia o array original
        inicio = clock(); // Inicializa o tempo
        mergeSort(arr, 0, tamanho - 1); // Ordena o array
        fim = clock(); // Finaliza o tempo
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo
        printf("%.6f\t", tempo); // Imprime o tempo
        free(arr); // Libera a memória alocada para o array
        
        // Quick Sort
        arr = copiarArray(arr_original, tamanho); // Copia o array original
        inicio = clock(); // Inicializa o tempo
        quickSort(arr, 0, tamanho - 1); // Ordena o array
        fim = clock(); // Finaliza o tempo
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo
        printf("%.6f\t", tempo); // Imprime o tempo
        free(arr); // Libera a memória alocada para o array
        
        // Heap Sort
        arr = copiarArray(arr_original, tamanho); // Copia o array original
        inicio = clock(); // Inicializa o tempo
        heapSort(arr, tamanho); // Ordena o array
        fim = clock(); // Finaliza o tempo
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo
        printf("%.6f\n", tempo); // Imprime o tempo
        free(arr); // Libera a memória alocada para o array
        
        free(arr_original); // Libera a memória alocada para o array original   


    }

    sleep(10);
    
    return 0;
}
