#include <stdio.h>

int Fsoma(int Num , int Num2){
    return Num + Num2;
}

int main()
{
    int Num, Num2;

    printf("\nEntre com o primeiro numero: ");
    scanf("%d", &Num);

    printf("\nEntre com o segundo numero numero: ");
    scanf("%d", &Num2);

    printf(" %d + %d = %d", Num, Num2, Fsoma(Num, Num2));


}