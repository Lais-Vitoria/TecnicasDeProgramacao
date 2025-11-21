
#include <stdio.h>
#include <locale.h>
#include "estruturas.h"
#include "funcoes.h"


int main() {
    Aluno *alunos = NULL;
    int totalAlunos = 0; // quantidade de alunos cadastrado
    int opcao;

    setlocale(LC_ALL, "pt-BR.UTF-8");

    do {// Menu inicial.
        printf("\n--- MENU ---\n");
        printf("1 - Cadastrar Aluno.\n");
        printf("2 - Pesquisar.\n");
        printf("0 - Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                FCadastra_Aluno(&alunos, &totalAlunos);
                printf("\nAlunos cadastrados com sucesso!\n");
                break;
            case 2:
                do
                {// menu secudario. 
                    printf("\n---- MENU DE PESQUISA ----\n\n");
                    printf("1 - Todos os alunos cadastrado.\n");
                    printf("2 - Todos os alunos acima da media.\n");
                    printf("3 - Todos os alunos abaixo da media.\n");
                    printf("0 - sair.\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao);

                    switch (opcao)
                    {
                    case 1:
                        FListaTodosAlunos("CadastroDeAluno.txt");
                        printf("\n");
                        break;
                    case 2:
                        FListaAlunosAprovados("CadastroDeAluno.txt");
                        printf("\n");
                        break;
                    case 3:
                        FListaAlunosReprovados("CadastroDeAluno.txt");
                        printf("\n");
                        break;
                    case 0:
                        printf("\nEncerrando...");
                        break;
                    default:
                        printf("\nOpção inválida.\n");
                        break;
                    }
                    
                }while(opcao != 0);

                break;
            case 0:
                printf("\nEncerrando...");
                break;
            default:
                printf("\nOpção inválida.");
        }
    } while (opcao != 0);

    free(alunos);
    return 0;
}
