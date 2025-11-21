#include <stdio.h>

void Fquadrado(int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void Ftriangulo(int tamanho){
    
    for (int i = 0; i <= tamanho; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i > j)
            {
                printf("*");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void Frentangulo(int altura , int largura){
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
}

void FiguraGeometricas(){
    int opcao, tamanho, altura, largura;
    do {
        printf("\n+-----------------------------+");
        printf("\n|   Figuras geometricas       |");
        printf("\n+-----------------------------+");
        printf("\n| 1 - Quadrado                |");
        printf("\n| 2 - Triangulo               |");
        printf("\n| 3 - Retangulo               |");
        printf("\n| 4 - Voltar ao menu principal|");
        printf("\n+-----------------------------+");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("\nDigite o tamanho do lado: ");
                scanf("%d", &tamanho);
                    Fquadrado(tamanho);
                break;
            case 2:
                printf("\nDigite a altura do triangulo: ");
                scanf("%d", &tamanho);
                    Ftriangulo(tamanho);
                break;
            case 3:
                printf("\nDigite a altura do retangulo: ");
                scanf("%d", &altura);
                printf("\nDigite a largura do retangulo: ");
                scanf("%d", &largura);
                    Frentangulo(altura, largura);
                break;
            case 4:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida, tente novamente.\n");
        }
    } while(opcao != 4);
}

int main()
{
    int opcao;

    do
    {
        printf("\n+--------------------------+");
        printf("\n|       MENU PRINCIPAL     |");
        printf("\n+--------------------------+");
        printf("\n| 1 - Desenhar figuras     |");
        printf("\n| 2 - Sair do programa     |");
        printf("\n+--------------------------+");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

       switch (opcao)
       {
       case 1:
            FiguraGeometricas(opcao);
        break;
        case 2:
            printf("\nSaindo do sistema...");
        break;
        default:
            printf("\nOpcao invalida, Digite novamente: ");
        break;
        }
 
        
    } while (opcao != 2);
    
}

