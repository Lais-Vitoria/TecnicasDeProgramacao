#include <stdio.h>
#include <locale.h>

void NumPar(int Num){
    setlocale(LC_ALL, "pt-BR.UTF-8");
    if (Num % 2 == 0)
    {
        printf("\n %d é par", Num);
    }
    else
        printf("\n %d é impar", Num);
}

int main(){
    int Num;

    printf("\nEntre com o numero: ");
    scanf("%d", &Num);

    NumPar(Num);
}