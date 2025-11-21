
#include <locale.h>
#include "funcao.h"
#include "estrutura.h"


int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    Celula m1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    Celula m2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    int tent = 0;
    int contsub = 0;
    int opcao = 0;

   do {
        printf("\n===== BATALHA NAVAL =====\n");
        printf("1. Iniciar Novo Jogo\n");
        printf("2. Carregar Jogo Salvo\n");
        printf("3. Ver Instruções\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inicializarTabuleiro(m1);

                inicializarTabuleiro(m2);

                posicionarSubmarinos(m1);

                iniciarNovoJogo(m1, m2, &tent, &contsub);
                break;
            case 2:
                carregarJogoSalvo(m1, m2, &tent, &contsub, "ultimapartida.txt");
                
                break;
            case 3:
                mostrarInstrucoes();
                break;
            case 4:
                printf("Saindo do jogo. Até mais!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;

}