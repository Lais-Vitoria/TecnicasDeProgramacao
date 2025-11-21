#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int FTamanhoDaString(char string[], int *tamanho) 
{
        
    int i = 0;
    while (string[i] != '\0') 
    {  
        i++;
    }

    *tamanho = i;  
    return 0;  
}

int main()
{
    char string[50];
    int tamanho;

    printf("Entre com uma string: ");
    scanf("%s", string);

    FTamanhoDaString(string, &tamanho);

    printf("Numero de caracteres na string: %d", tamanho);
}