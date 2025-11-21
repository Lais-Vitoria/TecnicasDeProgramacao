#include <stdio.h>
#include <stdlib.h>

int Fsoma(int *Num1, int *Num2){

    return *Num1 + *Num2;
}


int main()
{
    int Num1, Num2;

    printf("Entre com um numero: ");
    scanf("%d", &Num1);

    printf("Entre com outro numero: ");
    scanf("%d", &Num2);

    printf("A Soma de %d + %d = %d", Num1, Num2, Fsoma(&Num1, &Num2));

}