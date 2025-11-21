#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 300

const char* temas[] = {
    "Variáveis Compostas Homogêneas Unidimensionais",
    "Variáveis Compostas Homogêneas Multidimensionais",
    "Variáveis Compostas Heterogêneas Multidimensionais",
    "Modularização; Funções e Procedimentos",
    "Passagem de Parâmetros",
    "Escopo de Identificadores",
    "Cadeia de Caracteres"
};

const char* subtitulos[] = {
    "Importância:",
    "Boas práticas:",
    "Exemplo em C:"
};

void mostrarMenuPrincipal() {
    printf("\n|-----------------------------------------------------------|\n");
    printf("|                  Menu Principal                           |\n");
    printf("+-----------------------------------------------------------+\n");
    for (int i = 0; i < 7; i++) {
        printf(" %d - %s\n", i + 1, temas[i]);
    }
    printf(" 8 - Sair.\n");
    printf("+-----------------------------------------------------------+\n");
    printf("Escolha um tema: ");
}

void mostrarSubmenu() {
    printf("\n---- Submenu ----\n");
    printf("1 - Importância\n");
    printf("2 - Boas práticas\n");
    printf("3 - Ver exemplo\n");
    printf("4 - Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
}

void exibirIntroducao(const char* nomeArquivo, int temaSelecionado) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char linha[TAM_LINHA];
    char chaveTema[150];
    strcpy(chaveTema, temas[temaSelecionado - 1]); // <-- agora procura o nome direto

    int dentroDoTema = 0;

    while (fgets(linha, TAM_LINHA, arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';

        // Verifica se encontrou o título do tema
        if (!dentroDoTema && strcmp(linha, chaveTema) == 0) {
            dentroDoTema = 1;
            continue;
        }

        // Se encontrou o tema, imprime até a próxima seção
        if (dentroDoTema) {
            if (strstr(linha, "Importância:") != NULL) break;
            printf("%s\n", linha);
        }
    }

    fclose(arquivo);
}


void exibirSubtopico(const char* nomeArquivo, int temaSelecionado, int subSelecionado) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char linha[TAM_LINHA];
    char chaveTema[150];
    strcpy(chaveTema, temas[temaSelecionado - 1]);

    int dentroDoTema = 0;
    int imprimir = 0;

    while (fgets(linha, TAM_LINHA, arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';

        if (!dentroDoTema && strcmp(linha, chaveTema) == 0) {
            dentroDoTema = 1;
            continue;
        }

        if (dentroDoTema) {
            // Quando encontra o subtítulo correto, começa a imprimir
            if (strstr(linha, subtitulos[subSelecionado - 1]) != NULL) {
                imprimir = 1;
                continue;
            }

            // Se encontrar outro subtítulo, para de imprimir
            for (int i = 0; i < 3; i++) {
                if (i != subSelecionado - 1 && strstr(linha, subtitulos[i]) != NULL) {
                    imprimir = 0;
                }
            }

            if (imprimir) {
                printf("%s\n", linha);
            }

            // Se encontrar o próximo tema, para a leitura
            for (int i = 0; i < 7; i++) {
                if (strcmp(linha, temas[i]) == 0 && i != (temaSelecionado - 1)) {
                    fclose(arquivo);
                    return;
                }
            }
        }
    }

    fclose(arquivo);
}