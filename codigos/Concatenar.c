#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void FConcatenarString(char *str1, char *str2 , char*str3 ){
    
    strcpy(str3, str1);
    strcat(str3, str2);
    
}

int main()
{
    char string1[30], string2[30], stringConcat[60];

    printf("\nDigite uma string: ");
    scanf("%s", string1);

    printf("\nDigite outra string: ");
    scanf(" %s", string2);


    FConcatenarString(string1, string2, stringConcat);

    printf("String concatenada: %s", stringConcat);
}
