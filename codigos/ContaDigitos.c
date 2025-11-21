#include <stdio.h>

int FcontarDigitos(int n) {

    int cont = 0;

    if (n == 0) return 1; 

    while (n != 0) 
    {
        n /= 10; 
        cont++;
    }
    return cont;
}

int main() {
    int num ;

    printf("Entre com um numero: ");
    scanf("%d", &num);

    printf("Numero de digitos: %d\n", FcontarDigitos(num));

}
