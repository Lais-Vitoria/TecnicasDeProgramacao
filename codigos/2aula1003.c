#include <stdio.h>
#include <stdlib.h>
#include "2aula1003.h"

int main(){
    //ponteiro que vai apontar para o vetor criado
    int *vetor , tam, i;
    //Lendo o tamaho do vetor
    printf("Digite um tamanho: ");
    scanf("%d", &tam);
    //vetor vai receber um enderenço de memoria com o vetor que foi alocado
    vetor = alocavetor(tam);
    //colocando alguns valores no vetor

    vetor[0] = 1;
    vetor[1] = 2;
    vetor[20] = 3;
    // imprimindo o vetor
    for  (i = 0; i < tam; i++)
    {
        printf("%d", vetor[i]);
    }
    
    free(vetor);
    
}