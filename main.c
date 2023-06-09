#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int main(){
    int escolha; // escolha um algoritmo
    long int n; // numero de registros de log
    int ordem; // 0 para ordem decrescente e 1 para ordem crescente
    clock_t start, end; // medir tempo de execucao
    double cpu_time; // tempo de execucao
    long int numComparacoes = 0; // numero de comparacoes
    long int numTrocas = 0; // numero de trocas

    userinput(&escolha, &n, &ordem);    

    LogRecord** logArray = malloc(n * sizeof(LogRecord)); // alocando memoria para o vetor de registros de log
    if (logArray == NULL){
        printf("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }
    // gerando registros de log
    for(int i = 0; i < n; i++){
        logArray[i] = generateLogRecord();
    }
    // ordenando registros de log
    if(ordem < 2){
        quickSort(logArray, 0, n-1, &numComparacoes, &numTrocas, ordem); // organiza o registro
        numComparacoes = 0;
        numTrocas = 0;
    }
    ordem = 1; // crescente

    switch (escolha){
    case 1:
        printf("Bubble Sort\n");
        start = clock();
        bubbleSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 2:
        printf("Insertion Sort\n");
        start = clock();
        insertionSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 3:
        printf("Selection Sort\n");
        start = clock();
        selectionSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 4:
        printf("Shell Sort\n");
        start = clock();
        shellSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 5:
        printf("Merge Sort\n");
        start = clock();
        mergeSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 6:
        printf("Heap Sort\n");
        start = clock();
        heapSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 7:
        printf("Quick Sort\n");
        start = clock();
        quickSort(logArray, 0, n-1, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 8:
        printf("Comb Sort\n");
        start = clock();
        combSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 9:
        printf("Cocktail Shaker Sort\n");
        start = clock();
        cocktailShakerSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 10:
        printf("Bingo Sort\n");
        start = clock();
        bingoSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    default:
        printf("Algoritmo nao encontrado.\n");
        return 1;
        break;
    }
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    //printRegistros(logArray, n);
    printf("Tempo de execucao: %lf segundos\n", cpu_time);
    printf("Numero de comparacoes: %lu\n", numComparacoes);
    printf("Numero de trocas: %lu\n", numTrocas);

    // liberando memoria alocada para os registros de log
    for(int i = 0; i < n; i++){
        free(logArray[i]);
    }
    free(logArray);   
    return 0;
}