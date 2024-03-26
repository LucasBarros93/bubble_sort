#include <stdio.h>
#include <stdlib.h>

void bubble_sort (int *arr, int size) {
    int aux;
    for (int k = 1; k < size; k++) {
        for (int j = 0; j < size-1; j++) {

            if (arr[j] > arr[j+1]) {
                aux      = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

void main(void){

    char *filename = "n.i";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Error: could not open file %s", filename);
        return;
    }

    int num, x=0;
    int arr[100];
    while (fscanf(fp, "%d", num) == 1) {
        arr[x] = num;
        x++;
    }
    fclose(fp);

    // int tam_arq;

    // FILE *arq;
    // arq = fopen("n.i", "r");  // abrindo o arquivo
    
    // if (arq == NULL){  // verificando se o arquivo foi lido corretamente
    //     printf("Erro na leitura do arquivo!\n");
    //     exit(0);
    // }

    // for(int i = 1; i <= 20; i++){
    //     fscanf(arq, "%d", &tam_arq);  // lendo apenas a primeira linha para saber quantos números o arquivo tem
    //     int *vetor = calloc(tam_arq, sizeof(int));
        
    // }
    
    // return 0;
}