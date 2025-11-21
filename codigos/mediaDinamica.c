#include <stdio.h>
#include <stdlib.h>

float FMediaDeNotas(float notas[], int tam){
    
    float ValorTotal = 0;

    for (int i = 0; i < tam ; i++)
    {
        ValorTotal += notas[i];
    }
     
    return ValorTotal / (float)tam;
}


int main()
{
    int tam;

    printf("\nEntre com a quantidade de notas: ");
    scanf("%d", &tam);

    float *notas = malloc(tam * sizeof(float));

    for (int i = 0; i < tam; i++)
    {
        printf("\nDigite a nota[%d]: ", i+1);
        scanf("%f", &notas[i]);
    }
    
    printf("A Media de notas = %.2f", FMediaDeNotas(notas, tam));

    free(notas);

}