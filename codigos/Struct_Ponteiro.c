#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char modelo[30];
    int ano;
}Carro;

int main()
{   
    Carro carro1;

    Carro *carro2 = &carro1;

    printf("Digite o modelo do carro: ");
    scanf("%s", carro2->modelo);

    printf("Digite o ano do carro: ");
    scanf("%d", &carro2->ano);

    printf("\nModelo: %s - Ano: %d", carro2->modelo, carro2->ano);
}