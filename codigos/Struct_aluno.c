#include <stdio.h>

struct aluno
{
    char nome[20];
    float nota;

};


int main()
{
    struct aluno A1[3];
    int i;

    // inserindo dados dos alunos;
    for (i = 0; i < 3; i++)
    {
        printf("\nDigite o nome do aluno[%d]: ", i + 1);
        scanf("%s", A1[i].nome);

        printf("Digite a nota do aluno[%d]", i + 1);
        scanf("%f", &A1[i].nota);
    }

    printf("\nLista de Alunos\n");
    //imprimdo a lista de alunos;
    for ( i = 0; i < 3; i++)
    {
        printf("\nAluno[%d]: %s - Nota: %.2f", i, A1[i].nome, A1[i].nota);
    }

    return 0;
}