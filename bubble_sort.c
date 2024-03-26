#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

        double time_averege = 0;

        for(int _ = 0; _<10; _++){
            int x = 0;
            char filename[13];
            sprintf(filename, "./tests/%d.in", n);
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

            clock_t t = clock();
            bubble_sort(arr, size);
            t = clock() - t;

            double time_taken = ((double)t)/CLOCKS_PER_SEC;  // calcula o tempo levado para executar a função

            time_averege += time_taken;

            free(arr);
        }
        
        printf("Tempo demorado para o arquivo %d: %lf\n", n, time_averege/10);

    }
    
}
