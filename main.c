#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sorting_algorithms.h"
#include "utils.h"

int main() {
    srand(time(NULL));
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int num_tamanhos = 5;

    printf("\nIniciando analise de desempenho dos algoritmos de ordenacao...\n");

    // Abre arquivo para salvar resultados
    FILE *fp = fopen("resultados.csv", "w");
    fprintf(fp, "Tamanho,Selection,Insertion,Bubble,Merge,Quick,Heap\n");

    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];

        int* arr_original = gerarArrayAleatorio(tamanho);
        int* arr;
        clock_t inicio, fim;
        double tempo[6];

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        selectionSort(arr, tamanho);
        fim = clock();
        tempo[0] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        insertionSort(arr, tamanho);
        fim = clock();
        tempo[1] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        bubbleSort(arr, tamanho);
        fim = clock();
        tempo[2] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        mergeSort(arr, 0, tamanho - 1);
        fim = clock();
        tempo[3] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        quickSort(arr, 0, tamanho - 1);
        fim = clock();
        tempo[4] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        free(arr);

        arr = copiarArray(arr_original, tamanho);
        inicio = clock();
        heapSort(arr, tamanho);
        fim = clock();
        tempo[5] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        free(arr);

        free(arr_original);

        // Salva no CSV
        fprintf(fp, "%d,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f\n", tamanho, tempo[0], tempo[1], tempo[2], tempo[3], tempo[4], tempo[5]);
    }

    fclose(fp);
    printf("\nAnalise concluida! Resultados salvos em resultados.csv\n\n");
    sleep(10);
    return 0;
}
