#include <stdio.h>
#include <stdlib.h>

void FCopiaString(char *string1, char *string2 ){

    while (*string1 != '\0')
    {
        *string2=*string1;
        string1++;
        string2++;
    }
    *string2= '\0'; 
     
}

int main()
{
    char original[30], copia[30];

    printf("\nDigite uma string: ");
    scanf("%s", original);

    FCopiaString(original,copia);

    printf("String copiada: %s", copia);
}
