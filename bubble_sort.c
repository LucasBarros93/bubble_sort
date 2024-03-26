#include <stdio.h>
#include <stdlib.h>

void bubble_sort (int *arr, int size) {
    int aux;
    int flag;
    for (int k = 1; k < size; k++) {
        flag = 0;
        for (int j = 0; j < size - k; j++) {
            
            if (arr[j] > arr[j+1]) {
                aux      = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = aux;
                flag = 1;
            }
        }

        if(flag == 0){  // flag=0 significa que não houve mudança nenhuma no vetor, logo, ele já está ordenado.
            break;
        }
    }
}

void main(void){

    int n;
    int size;
    int num;
    
    for(n = 1; n <= 20; n++){
        int x = 0;
        char filename[10];
        sprintf(filename, "%d.in", n);
        FILE *fp = fopen(filename, "r");

        if (fp == NULL){
            printf("Error: could not open file %s", filename);
            return;
        }

        fscanf(fp, "%d", &size);  // lendo apenas a primeira linha para saber quantos números o arquivo tem
        int *arr = calloc(size, sizeof(int));

        while (fscanf(fp, "%d", &num) == 1) {
            arr[x] = num;
            x++;
        }
        fclose(fp);

        bubble_sort(arr, size);

      /*  if(n == 2){
            for(int p = 0; p<size; p++){
                printf("%d ", arr[p]);

            }  isso aqui é só pra testar se tá ordenando*/
        free(arr);
    }
    
}

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