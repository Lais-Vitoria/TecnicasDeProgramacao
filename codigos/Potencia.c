#include <stdio.h>

int Fpotencia(int base, int expoente) {

    int resultado = 1;
    
    for (int i = 0; i < expoente; i++) {
        resultado *= base;  
    }
    return resultado;
}

int main() {

    int base, expoente;

    printf("\nEntre com a base: ");
    scanf("%d", &base);

    printf("\nEntre com o expoente: ");
    scanf("%d", &expoente);

    printf("%d^%d = %d\n", base, expoente, Fpotencia(base, expoente));

}