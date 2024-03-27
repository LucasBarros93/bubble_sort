#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort_0(int *arr, int size){  // função pura, sem nenhuma otimização
    int aux, flag;
    for (int k = 1; k < size; k++) {
        for (int j = 0; j < size - 1; j++) { 
            if (arr[j] > arr[j+1]) {
                aux      = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = aux;
                flag = 1;
            }
        }
    }
}

void bubble_sort_1(int *arr, int size){  // função com primeira melhoria implementada
    int aux, flag;
    for (int k = 1; k < size; k++) {
        for (int j = 0; j < size - k; j++) { // aqui está a primeira otimização, o vetor sempre é percorrido uma "casa" a menos, pois a cada iteração temos certeza que o maior numero está o final, então ele não é comparado com os demais.
            if (arr[j] > arr[j+1]) {
                aux      = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = aux;
                flag = 1;
            }
        }
    }
}

void bubble_sort_2(int *arr, int size){  // função com segunda melhoria implementada
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
        if (flag == 0) {  // flag=0 significa que não houve mudança nenhuma no vetor, logo, ele já está ordenado. Esta é a segunda otimização.
            break;
        }
    }
}

int main(void) {
    int size, num;
    
    FILE *fw = fopen("./result.csv", "w");
    if (fw == NULL)
        printf("Error opening the file");

    for (int n = 1; n <= 20; n++) {
        double total_time_0 = 0.0;
        double total_time_1 = 0.0;
        double total_time_2 = 0.0;

        char filename[13];
        sprintf(filename, "./tests/%d.in", n);
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: could not open file %s", filename);
            return 1;
        }

        for (int i = 0; i < 10; i++) {
            int x = 0;

            fscanf(fp, "%d", &size);  // lendo apenas a primeira linha para saber quantos números o arquivo tem
            int *arr0 = calloc(size, sizeof(int));
            int *arr1 = calloc(size, sizeof(int));
            int *arr2 = calloc(size, sizeof(int));
            while (fscanf(fp, "%d", &num) == 1) {
                arr0[x] = num;
                arr1[x] = num;
                arr2[x] = num;
                x++;
            }

            clock_t t = clock();
            bubble_sort_0(arr0, size);  // aqui deve ser selecionada a variação da função a ser utilizada
            t = clock() - t;

            double time_taken_0 = ((double)t) / CLOCKS_PER_SEC;  // calcula o tempo levado para executar a função
            total_time_0 += time_taken_0;

            t = clock();
            bubble_sort_1(arr1, size);  // aqui deve ser selecionada a variação da função a ser utilizada
            t = clock() - t;

            double time_taken_1 = ((double)t) / CLOCKS_PER_SEC;  // calcula o tempo levado para executar a função
            total_time_1 += time_taken_1;

            t = clock();
            bubble_sort_2(arr2, size);  // aqui deve ser selecionada a variação da função a ser utilizada
            t = clock() - t;

            double time_taken_2 = ((double)t) / CLOCKS_PER_SEC;  // calcula o tempo levado para executar a função
            total_time_2 += time_taken_2;

            free(arr0);
            free(arr1);
            free(arr2);
        }
        fclose(fp);

        double avg_time_0 = total_time_0 / 10.0;
        double avg_time_1 = total_time_1 / 10.0;
        double avg_time_2 = total_time_2 / 10.0;
        //printf("Tempo médio para o arquivo %d: %lf\n", n, avg_time);
        fprintf(fw, "%d, %lf, %lf, %lf \n", n, avg_time_0, avg_time_1, avg_time_2);
    }

    fclose(fw);

    return 0;
}