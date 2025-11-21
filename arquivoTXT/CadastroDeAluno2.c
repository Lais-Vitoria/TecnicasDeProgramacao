#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nome[99];
    int idade;
    float nota;


}aluno;


int main()
{
    int qtdAluno;

    printf("\nDigite a quantidade de alunos: ");
    scanf("%d", &qtdAluno);

    aluno *pessoa = (aluno*) malloc(qtdAluno * sizeof(aluno));

    if (pessoa == NULL)
    {
        printf("Erro ao alocar memoria!");
        return 1;
    }
    //Solicita os dados dos alunos.
    for (int i = 0; i < qtdAluno; i++)
    {
        printf("Nome do aluno[%d]: ", i + 1);
        scanf(" %[^\n]", pessoa[i].nome);
       
        printf("Idade do aluno[%d]: ", i + 1);
        scanf("%d", &pessoa[i].idade);

        printf("Nota final do aluno[%d]: ", i + 1);
        scanf("%f", &pessoa[i].nota);
    }
    
    FILE *AlunosCadastrados = fopen("AlunosCadastrados.txt", "w");

    if (AlunosCadastrados == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return 0;
    }
    //
    for (int i = 0; i < qtdAluno; i++)
    {
        fprintf(AlunosCadastrados,"\nNome: %s, Idade: %d, Nota: %.2f",pessoa[i].nome, pessoa[i].idade, pessoa[i].nota);
    }
    //imprime na tela os dados
    printf("\nLista de alunos cadastrados: ");
    for (int i = 0; i < qtdAluno; i++)
    {
        printf("\nNome: %s, Idade: %d, Nota: %.2f",pessoa[i].nome, pessoa[i].idade, pessoa[i].nota);
    }

    fclose(AlunosCadastrados);

    printf("\nDados salvos com sucesso!");

    free(pessoa);

}