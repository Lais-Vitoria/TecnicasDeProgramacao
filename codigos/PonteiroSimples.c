#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a = 5;
    int *b = &a;

    printf("Valor inicial: %d\n", a);

    *b = 50;

    printf("Valor modificado: %d\n", a);
    
}