

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h" 

//lista das funções.
void FCadastra_Aluno(Aluno **alunos, int *totalAlunos);// Função de cadastro.
void FListaTodosAlunos(const char *Nome_ArquivoT);// Função que pesquisa todos os alunos.
void FListaAlunosAprovados(const char *Nome_ArquivoA);// Função que pesquisa os alunos acima ou igual a media 7.0.
void FListaAlunosReprovados(const char *Nome_ArquivoR);// Função que pesquisa os alunos abaixo da media 7.0.

// função para cadastra o aluno.
void FCadastra_Aluno(Aluno **alunos, int *totalAlunos) {
    int novoCadastro;

    do 
    {   
        printf("\nDigite quantos alunos deseja cadastrar: ");
        if (scanf("%d", &novoCadastro) != 1) { 
            printf("Entrada inválida! Digite apenas números inteiros positivos.\n");
            getchar();
            novoCadastro = 0;
        } else if (novoCadastro <= 0) {
            printf("Quantidade inválida, digite apenas número maior que 0!\n");
        }

    } while (novoCadastro <= 0);
    
    // Realoca espaço para os novos alunos
    *alunos = realloc(*alunos, (*totalAlunos + novoCadastro) * sizeof(Aluno));
    if (*alunos == NULL) {
        printf("Erro ao realocar memória!\n");
        exit(1);
    }
    
    // Cadastra os alunos 
    for (int i = 0; i < novoCadastro; i++) {

        Aluno *alunoAtual = &(*alunos)[*totalAlunos + i];

        printf("Entre com o nome do aluno[%d]: ", i + 1 + *totalAlunos);
        getchar();
        fgets(alunoAtual->nome, 100, stdin);
        alunoAtual->nome[strcspn(alunoAtual->nome, "\n")] = '\0';

        printf("Digite a matrícula: ");
        scanf("%d", &alunoAtual->matricula);

        printf("Digite a nota 1: ");
        scanf("%f", &alunoAtual->n1);

        printf("Digite a nota 2: ");
        scanf("%f", &alunoAtual->n2);

        getchar();
        printf("Digite a cidade: ");
        fgets(alunoAtual->endereco.cidade, 50, stdin);
        alunoAtual->endereco.cidade[strcspn(alunoAtual->endereco.cidade, "\n")] = '\0';

        printf("Digite o estado: ");
        fgets(alunoAtual->endereco.estado, 10, stdin);
        alunoAtual->endereco.estado[strcspn(alunoAtual->endereco.estado, "\n")] = '\0';
    }

    // Atualiza o número total de alunos
    *totalAlunos += novoCadastro;

    // Salva no arquivo 
    FILE *CadastroDeAluno = fopen("CadastroDeAluno.txt", "a");

    if (CadastroDeAluno == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    for (int i = *totalAlunos - novoCadastro; i < *totalAlunos; i++) {
        fprintf(CadastroDeAluno, "Nome: %s - Matricula: %d - Nota1: %.2f - Nota2: %.2f - Cidade: %s - Estado: %s\n",
            (*alunos)[i].nome, (*alunos)[i].matricula, (*alunos)[i].n1, (*alunos)[i].n2,
            (*alunos)[i].endereco.cidade, (*alunos)[i].endereco.estado);
    }

    fclose(CadastroDeAluno);
}


//função de pesquisa para mostra todos os alunos cadastrados.
void FListaTodosAlunos(const char *Nome_ArquivoT){
    
    printf("\n----- Todos os alunos cadastrados -----\n ");
    
    FILE *Arquivo = fopen(Nome_ArquivoT, "r"); // Abre o arquivo existente para leitura.

    // verifica a abertura do arquivo, caso não consiga abri o arquivo imprime uma mensagem.
    if (Arquivo == NULL)
    {
        printf("Falha ao abrir o arquivo!");
        exit(1);
    }
    
    Aluno ta; //define uma estrutura de aluno.

    // ler o arquivo.
    if (Arquivo)
    {  
        while (fscanf(Arquivo, "Nome: %[^-] - Matricula: %d - Nota1: %f - Nota2: %f - Cidade: %[^-] - Estado: %s\n", 
            ta.nome, &ta.matricula, &ta.n1 , &ta.n2, ta.endereco.cidade, ta.endereco.estado) == 6) 
        {
            printf("\nNome: %s - Matricula: %d - Nota1: %.2f - Nota2: %.2f - Cidade: %s - Estado: %s",
                ta.nome, ta.matricula, ta.n1, ta.n2, ta.endereco.cidade, ta.endereco.estado); // imprime os dados do arquivo.
        }
        
    }

    fclose(Arquivo);// fecha o arquivo.
    
}

//função de pesquisa para mostra os alunos aprovados.
void FListaAlunosAprovados(const char *Nome_ArquivoA){
    printf("\n---- Alunos acima da media(7.0) ----\n");
    
    FILE *arquivo = fopen(Nome_ArquivoA, "r");// Abre o arquivo existente para leitura.

    // verifica a leitura do arquivo, caso não consiga ler o arquivo imprime uma mensagem.
    if (arquivo == NULL)
    {
        printf("Erro ao ler arquivo!");
        exit(1);
    }
    
    Aluno a;//define uma estrutura de aluno.

    // ler o arquivo.
    while (fscanf(arquivo, "Nome: %[^-] - Matricula: %d - Nota1: %f - Nota2: %f - Cidade: %[^-] - Estado: %s\n",
        a.nome, &a.matricula, &a.n1, &a.n2, a.endereco.cidade, a.endereco.estado) == 6)
    {
        float media;
        // calcula a media e verfica se esta igual ou acima da media 7.0.
        if ((media = (a.n1 + a.n2) / 2) >= 7.0)
        {
            printf("\nNome: %s - Nota1: %.2f - Nota2: %.2f - Media: %.2f", a.nome, a.n1, a.n2, media);// imprime os dados do arquivo.
        }
        
    }
    
    fclose(arquivo);// fecha o arquivo.
}

//função de pesquisa para mostras os alunos reprovados.
void FListaAlunosReprovados(const char *Nome_ArquivoR){

    printf("\n---- Alunos abaixo da media(7.0) ----\n");

    FILE *arquivo = fopen(Nome_ArquivoR, "r"); // Abre o arquivo existente para leitura.

    // verifica a leitura do arquivo, caso não consiga ler o arquivo imprime uma mensagem.
    if (arquivo == NULL)
    {
        printf("Erro ao ler arquivo!");
        exit(1);
    }
    
    Aluno ar;//define uma estrutura de aluno.

    // ler o arquivo.
    while (fscanf(arquivo, "Nome: %[^-] - Matricula: %d - Nota1: %f - Nota2: %f - Cidade: %[^-] - Estado: %s\n",
        ar.nome, &ar.matricula, &ar.n1, &ar.n2, ar.endereco.cidade, ar.endereco.estado) == 6)
    {
        float media;

        // calcula a media e verifica se esta abaixo da media 7.0.
        if ((media = (ar.n1 + ar.n2) / 2) < 7.0)
        {
            printf("\nNome: %s - Nota1: %.2f - Nota2: %.2f - Media: %.2f", ar.nome, ar.n1, ar.n2, media);// imprime os dados do arquivo.
        }
        
    }

    fclose(arquivo);// fecha o arquivo.
}