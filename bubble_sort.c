#include <stdio.h>
#include <stdlib.h>

void bubble_sort (int *arr, int size) {
    int aux, flag;
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

    int size, num;
    
    for(int n = 1; n <= 20; n++){
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

        while (fscanf(fp, "%d", &num)) {
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
