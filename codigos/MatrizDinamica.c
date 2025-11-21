#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam, tam2;
    int i,j;

    printf("Digite a quantidade de linha da matriz: ");
    scanf("%d", &tam);

    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &tam2);


    int **matriz = malloc(tam * sizeof(int *));

    if (matriz == NULL)
    {
        printf("Erro ao alocar memoria!");
        return 1;
    }

    for (int i = 0; i < tam; i++)
    {
       matriz[i] = malloc(tam2 * sizeof(int ));
    }
    
    
    //preenchendo a matriz
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam2; j++)
        {
            printf("Digite o elemento [%d][%d]: ", i,j);
            scanf("%d", &matriz[i][j]);
        }
        
    }

    printf("\nMatriz\n");
    // imprimido a matriz
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam2; j++)
        {
            printf(" %d", matriz[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < tam ; i++)
    {
        free(matriz[i]);
    }
    
    free(matriz);
    
}
