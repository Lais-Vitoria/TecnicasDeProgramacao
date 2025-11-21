#include <stdio.h>
#include <locale.h>

void Fmaior(int N1, int N2){

    setlocale(LC_ALL, "pt-BR.UTF-8");

    if( N1 > N2){
        printf("%d é maior que %d!", N1, N2);
    }
    else
        printf("%d é maior que %d!", N2, N1); 
}


int main()
{
    int Num1, Num2;

    printf("\nEntre com o primeiro numero: ");
    scanf("%d", &Num1);

    printf("\nEntre com o segundo numero: ");
    scanf("%d", &Num2);

    Fmaior(Num1, Num2);
}