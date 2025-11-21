#include <stdio.h>
#include <stdlib.h>

void FlimpaTela(){
    system("CLS");
}

void Ftroca(int *a, int *b){
    
    int aux = *a;
    *a = *b;
    *b = aux;
}


int main()
{
    int Num1, Num2;

    printf("\nEntre com o primeiro numero: ");
    scanf("%d", &Num1);

    printf("\nEntre com segundo numero: ");
    scanf("%d", &Num2);

    FlimpaTela();

    printf("\nValor antes da troca Numero 1: %d", Num1);
    printf("\nvalor antes da troca Numero 2: %d", Num2);
    
    Ftroca(&Num1, &Num2);

    printf("\n\nValor Trocado Numero 1: %d", Num1);
    printf("\nvalor Trocado Numero 2: %d", Num2);
    
}