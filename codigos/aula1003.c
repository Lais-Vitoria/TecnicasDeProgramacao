#include <stdio.h>
#include <stdlib.h>
#include "aula1003.h" \\Estrutura Pessoa


int main(){
    
    struct Pessoa p = {"Lais Vitoria", 20, 1.53};

    printf("Nome..: %s\nIdade..: %d\nAltura: %.2f\n", p.nome, p.idade, p.altura);
    
}