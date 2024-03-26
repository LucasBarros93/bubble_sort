#include <stdio.h>
#include <stdlib.h>

int i, j;

int *vetor_ordenado(int *vetor, int tam_arq){
    
    //int tam = sizeof(vetor)/sizeof(vetor[0]);  determinando o tamanho do vetor, acredito que não será necesário

    for(i = 0; i < tam_arq; i++){
        for(j = 0; j < tam_arq; )
    }
    
}

int main(){

    int tam_arq;

    FILE *arq;
    arq = fopen("n.i", "r");  // abrindo o arquivo
    
    if (arq == NULL){  // verificando se o arquivo foi lido corretamente
        printf("Erro na leitura do arquivo!\n");
        exit(0);
    }

    for(i = 1; i <= 20; i++){
        fscanf(arq, "%d", &tam_arq);  // lendo apenas a primeira linha para saber quantos números o arquivo tem
        int *vetor = calloc(tam_arq, sizeof(int));
        
    }
    

    return 0;
}