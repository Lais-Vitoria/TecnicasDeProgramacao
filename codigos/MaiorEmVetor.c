#include <stdio.h>
#include <stdlib.h>

int F_MaiorValor(int vetor[], int num, int *NumMaior ){

    *NumMaior = vetor[0];

    for (int i = 0; i < num; i++)
    {
        if (vetor[i] > *NumMaior)
        {
            *NumMaior = vetor[i];
        }
        
    }
    
    return *NumMaior;
}


int main()
{
    int vetor[4];
    int MaiorNum;

    for (int i = 0; i < 4; i++)
    {
        printf("\nEntre com o [%d] Numero: ", i+1);
        scanf("%d", &vetor[i]);
    }

    F_MaiorValor(vetor, 4, &MaiorNum);
    
    printf("O maior numero do vetor: %d", MaiorNum);
    
}