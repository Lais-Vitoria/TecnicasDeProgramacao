#include <stdio.h>
#include <stdlib.h>

struct Turma
{
    char Aluno[20];
    int turma;
};


int main()
{
    struct Turma t[5];
    int i;

    for ( i = 0; i < 5; i++)
    {
        printf("Digite o nome do aluno[%d]: ", i + 1);
        scanf("%s", t[i].Aluno);

        printf("Digite a turma do aluno[%d]: ", i + 1);
        scanf("%d", &t[i].turma);
    }
    
    for ( i = 0; i < 5; i++)
    {
        printf("\nTurma: %d - Aluno[%d]: %s", t[i].turma, i, t[i].Aluno);
    }
    return 0;
}