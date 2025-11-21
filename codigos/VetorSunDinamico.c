#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam1, tam2;

    printf("\nDigite o tamanho do primeiro vetor: ");
    scanf("%d", &tam1);

    printf("\nDigite o tamanho do primeiro vetor: ");
    scanf("%d", &tam2);

    int *vetor = malloc(tam1 * sizeof(int));

    int *vetor2 = malloc(tam2 * sizeof(int));

    int *vetor3 = malloc((tam1 + tam2) * sizeof(int));

    if ((vetor == NULL || vetor2 == NULL) || vetor3 == NULL)
    {
        printf("Erro ao alocar memoria!");
        return 1;
    }

    //inserir elementos do primeiro vetor
    for (int i = 0; i < tam1; i++)
    {
        printf("Entre com o %d elemento do vetor 1: ", i+1);
        scanf("%d", &vetor[i]);
    }
    printf("\n");
    //inserir elementos do segundo vetor
    for (int i = 0; i < tam2; i++)
    {
        printf("Entre com o %d elemento do vetor 2: ", i+1);
        scanf("%d", &vetor2[i]);

    }    
    // soma os elementos
    for (int i = 0; i < tam1 || i < tam2; i++)
    {
        if (i < tam1 && i < tam2)
            vetor3[i] = vetor[i] + vetor2[i];
        else if (i < tam1)
            vetor3[i] = vetor[i];
        else
            vetor3[i] = vetor2[i];
    }
    //imprime as somas 
    for (int i = 0; i < tam1 || i < tam2 ; i++)
    {
        printf("\nvetor[%d] + vetor2[%d] = %d", i, i, vetor3[i]);
    }
    
    free(vetor);
    free(vetor2);
    free(vetor3);

}   