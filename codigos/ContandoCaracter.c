#include <stdio.h>
#include <string.h>

#define tamanho_max_caracter 100

int main()
{
    char str[tamanho_max_caracter];
    int qtd;

    printf ("Digite uma palavra ou frase: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    qtd = strlen(str);
    printf("A quantidade de caracteres: %d caracteres.\n", qtd);
}