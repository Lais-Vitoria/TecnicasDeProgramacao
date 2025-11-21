#include <stdio.h>
#include <string.h>
#include <locale.h>

int FehPalindromo(char str[]) 
{
    int tamanho = strlen(str);

    for (int i = 0; i < tamanho / 2; i++) {
        if (str[i] != str[tamanho - i - 1]) {
            return 0; 
        }
    }

    return 1; 
}

int main() 
{
    setlocale(LC_ALL, "pt-BR.UTF-8");

    char palavra[30];

    printf("\nDigite uma palavra: ");
    scanf("%s", &palavra);
    
    if (FehPalindromo(palavra))
        printf("\"%s\" é um palíndromo!\n", palavra);
    else
        printf("\"%s\" não é um palíndromo.\n", palavra);
    
    r