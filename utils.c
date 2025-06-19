#include <stdlib.h>
#include "utils.h"

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
