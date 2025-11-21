#include <stdio.h>
#include <string.h>

#define tamanho_max_caracter 100

int main()
{
    char str1[tamanho_max_caracter];
    char str2[tamanho_max_caracter];
    char resultado[2*tamanho_max_caracter];

    printf("Digite a primeira palavra ou frase: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Digite a primeira palavra ou frase: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    strcpy(resultado, str1);
    strcat(resultado, "");
    strcat(resultado, str2);
    printf("A concatenacao de '%s' e '%s concatenado fica assim --> %s\n", str1, str2, resultado);

    return 0;

}