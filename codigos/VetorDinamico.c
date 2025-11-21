#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = malloc( tamanho * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria!");
        return 1;
    }

    //entrada dos numeros no vetor
    for (int i = 0; i < tamanho; i++)
    {
        printf("Entre com o numero[%d] = ", i + 1);
        scanf("%d", &vetor[i]);
    }
    // imprimindo os valores do vetor
    printf("\nLista do vetor");
    for (int i = 0; i < tamanho; i++)
    {
        printf("\nVetor[%d] = %d", i, vetor[i]);
    }
    
    free(vetor);
}