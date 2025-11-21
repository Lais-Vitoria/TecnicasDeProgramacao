#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Fsoma(int *vetor, int n){

    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma += vetor[i];
    }
    
    return soma;
}


int main()
{
    setlocale(LC_ALL, "pt-BR.UTF-8");

    int n;

    printf("Entre com um numero inteiro: ");
    scanf("%d", &n);

    int *vetor = malloc(n * sizeof (int));

    if (!vetor)
    {
        printf("erro ao alocar o vetor\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Entre com o %d° valor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("A Soma dos elementos do vetor = %d", Fsoma(vetor,n));

    free(vetor);
}

