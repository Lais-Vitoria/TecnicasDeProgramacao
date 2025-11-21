#include <stdio.h>
#include <locale.h>

int Ffatorial(int Num){
    if (Num == 0 || Num == 1)
    {
        return 1;
    }
    return Num * Ffatorial(Num - 1);
}


int main()
{
    int Numero;

    setlocale(LC_ALL, "pt-BR.UTF-8");

    printf("\nDigite um número: ");
    scanf("%d", &Numero);

    printf("\nO fatorial do número %d é: %d", Numero, Ffatorial(Numero));
}