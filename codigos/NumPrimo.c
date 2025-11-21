#include <stdio.h>
#include <locale.h>

void Fprimo (int Num)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    if(Num == 2 || Num%2 != 0)
    {
        printf("\nO número %d é primo!", Num);
    }
    else
        printf("\nO número %d não é primo!", Num);
} 

int main()
{
    int  Numero;

    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    printf("\nEntre com um numero: ");
    scanf("%d", &Numero);

    Fprimo(Numero);
}