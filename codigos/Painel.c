#include <stdio.h>

void Painel(){
    printf("\n+--------------------------+");
    printf("\n|     SISTEMA DE GESTAO    |");
    printf("\n+--------------------------+");
    printf("\n| 1 - Cadrastrar usuario.  |");
    printf("\n| 2 - Consultar Dados.     |");
    printf("\n| 3 - Sair.                |");
    printf("\n+--------------------------+");
}


int main() 
{
    int opcao, idade;
    char nome[20];

    Painel();

    do
    {
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite seu primeiro nome: ");
            scanf(" %s", nome);
            printf("\nDigite sua idade: ");
            scanf("%d", & idade);
            
            printf("\nUsuario cadastrado com sucesso!\n");
            break;
        case 2:
            printf("\nNome do usuario: %s", nome);
            printf("\nIdade do usuario: %d\n", idade);
            break;
        case 3:
            printf("\nSaindo do sistema...");
            break;
        default:
            printf("\nOpção invalida! Escolha entre 1 e 3.\n");
            break;
        }

    } while (opcao!=3);

    
    return 0;
}

