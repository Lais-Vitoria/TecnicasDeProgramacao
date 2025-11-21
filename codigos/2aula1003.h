#include <stdlib.h>

//aloca vetor do tamho digitado
int* alocavetor(int tamanho){
    //criando o ponteiro
    int* v;
    // a memoria é alocada e o ponteiro recebe o enderenço da memoria 
    v = (int*) malloc( tamanho * sizeof(int));
    return v;
} 