#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    FILE *arquivo;

    arquivo = fopen("pessoa.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    if (arquivo)
    {
        while ((c = getc(arquivo)) != EOF){
            printf("%c", c);
        }
        
    }
    return 0;
}