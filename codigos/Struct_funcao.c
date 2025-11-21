#include <stdio.h>

struct Aluno
{
    char nome[20];
    float nota;
};

void FAluno(struct Aluno a){
    printf("Nome: %s \nNota: %.2f ", a.nome, a.nota);
}

