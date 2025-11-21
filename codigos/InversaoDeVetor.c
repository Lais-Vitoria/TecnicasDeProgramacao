#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void F_InversaoDoVetor(int *vetorI){

    for (int i = 0; i < 4; i++)
    {
       int aux;
       
       aux = vetorI[i];
       vetorI[i] = vetorI[7-i];
       vetorI[7-i] = aux;

    }
    
}


int main()
{
    setlocale(LC_ALL, "pt-BR.UTF-8");

    int Vetor[8];

    for (int i = 0; i < 8; i++)
    {
        printf("Entre com o vetor[%d]: ", i+1);
        scanf("%d", &Vetor[i]);
    }
    
    printf("\nVetor antes da inverção\n\n");

    for (int i = 0; i < 8; i++)
    {
        printf("Vetor[%d] = %d\n", i+1, Vetor[i]);
    }

    F_InversaoDoVetor(Vetor);
    
    printf("\nVetor Invertido\n\n");

    for (int i = 0; i < 8; i++)
    {
        printf("Vetor[%d] = %d\n", i+1, Vetor[i]);
    }
}