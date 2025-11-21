#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "FuncoesDoMenu.h"

int main() {

    setlocale(LC_ALL, "pt-BR.UTF-8");

    int temaEscolhido, subopcao;
    const char* nomeArquivo = "conceitos.txt";

    do {
        mostrarMenuPrincipal();
        scanf("%d", &temaEscolhido);
        getchar(); // limpa o \n

        if (temaEscolhido >= 1 && temaEscolhido <= 7) {
            printf("\n----- %s -----\n\n", temas[temaEscolhido - 1]);
            exibirIntroducao(nomeArquivo, temaEscolhido);

            do {
                mostrarSubmenu();
                scanf("%d", &subopcao);
                getchar(); // limpa o \n

                if (subopcao >= 1 && subopcao <= 3) {
                    printf("\n--- %s ---\n\n", subtitulos[subopcao - 1]);
                    exibirSubtopico(nomeArquivo, temaEscolhido, subopcao);
                } else if (subopcao != 4) {
                    printf("Opção inválida.\n");
                }

            } while (subopcao != 4);
        } else if (temaEscolhido != 8) {
            printf("Opção inválida.\n");
        }

    } while (temaEscolhido != 8);

    printf("Programa encerrado.\n");
    return 0;
}
