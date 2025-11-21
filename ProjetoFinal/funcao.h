
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estrutura.h"

#define TAMANHO_TABULEIRO 10
#define NUM_SUBMARINOS 5
#define MAX_TENTATIVAS 5

//declaração
void iniciarNovoJogo(Celula m1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Celula m2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int *contsub, int *tent);
void iniciarjogoCarregado(Celula m1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Celula m2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int *contsub, int *tent);
void mostrarInstrucoes();
void inicializarTabuleiro(Celula tabuleiro[10][10]);
void posicionarSubmarinos(Celula tabuleiro[10][10]);
void imprimirTabuleiro(Celula tabuleiro[10][10]);
void printTabuleiroComSubmarino(Celula tabuleiro[10][10]);
int realizarJogada(Celula tabuleiro[10][10], int linha, int coluna);
void salvarJogo(Celula m2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],Celula m1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int *tentativas, int *qtdSubmarinos, const char *nome_arquivo);
int carregarJogoSalvo(Celula m1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],Celula m2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int *tentativas,int *submarinosEncontrados,const char *nomeArquivo);

// definições
void iniciarNovoJogo(Celula m1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Celula m2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int *contsub, int *tent){
    
    int linha, coluna;
    char local[10];

    while (*contsub < NUM_SUBMARINOS && *tent < MAX_TENTATIVAS) {
        printf("\nDigite a linha (0-9) e coluna (0-9): ");
        scanf("%d %d", &linha, &coluna);

        while (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
            printf("Coordenadas inválidas! Digite novamente: ");
            scanf("%d %d", &linha, &coluna);
        }

        if (m2[linha][coluna].foiAtacado == 0) {
           (*tent)++;
            if (realizarJogada(m1, linha, coluna)) {
                m2[linha][coluna].tipo = 'x'; // acerto
                (*contsub)++;
                printf("Acertou um submarino!\n");
            } else {
                m2[linha][coluna].tipo = 'o'; // erro
                printf("Água...\n");
            }
            m2[linha][coluna].foiAtacado = 1;

            printf("\nTabuleiro Atual:\n");
            imprimirTabuleiro(m2);
        } else {
            printf("Você já tentou nesta coordenada, escolha outra.\n");
        }
    }

    if (*contsub < NUM_SUBMARINOS) {
            printf("\nVocê perdeu! Usou todas as tentativas e encontrou %d submarino(s).\n", *contsub);
            printf("Deseja ver onde estavam os submarinos? (Sim/Nao): ");
            scanf(" %s", local);
            if (strcmp(local, "Sim") == 0) {
                printf("\nTabuleiro com submarinos:\n");
                printTabuleiroComSubmarino(m1);
                printf("Até o próximo jogo.\n");
            } else {
        
                salvarJogo(m2, m1, tent, contsub, "ultimapartida.txt");
            }
        } 
    else {
        printf("Você ganhou!\n");  
    }
    
}

void iniciarjogoCarregado(Celula m1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Celula m2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int *contsub, int *tent){
    
    *tent = 0;
    int linha, coluna;
    char local[5];

    while (*contsub < NUM_SUBMARINOS && *tent < MAX_TENTATIVAS) {
        printf("\nDigite a linha (0-9) e coluna (0-9): ");
        scanf("%d %d", &linha, &coluna);

        while (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
            printf("Coordenadas inválidas! Digite novamente: ");
            scanf("%d %d", &linha, &coluna);
        }

        if (m2[linha][coluna].foiAtacado == 0) {
           (*tent)++;
            if (realizarJogada(m1, linha, coluna)) {
                m2[linha][coluna].tipo = 'x'; // acerto
                (*contsub)++;
                printf("Acertou um submarino!\n");
            } else {
                m2[linha][coluna].tipo = 'o'; // erro
                printf("Água...\n");
            }
            m2[linha][coluna].foiAtacado = 1;

            printf("\nTabuleiro Atual:\n");
            imprimirTabuleiro(m2);
        } else {
            printf("Você já tentou nesta coordenada, escolha outra.\n");
        }
    }

    if (*contsub < NUM_SUBMARINOS) {
        printf("\nVocê perdeu! Usou todas as tentativas e encontrou %d submarino(s).\n", *contsub);
        printf("Deseja ver onde estavam os submarinos? Digite Sim ou Nao: ");
        scanf(" %s", local);
        if (strcmp(local, "Sim") == 0) {
            printf("\nTabuleiro com submarinos:\n");
            printTabuleiroComSubmarino(m1);
        } else {
            printf("Até o próximo jogo.\n");
        }
    } else {
        printf("Você ganhou!\n");
    }

    
}

void mostrarInstrucoes() {
    printf("\n\n--- Instruções do Jogo ---\n");
    printf("Você deve encontrar os submarinos escondidos no tabuleiro.\n");
    printf("Digite coordenadas (linha e coluna) para lançar torpedos.\n");
    printf("'x' = acerto, 'o' = erro, '~' = água.\n");
    printf("Você vence ao encontrar todos os submarinos antes de esgotar as tentativas!\n");
}

void inicializarTabuleiro(Celula tabuleiro[10][10]) {
    for (int l = 0; l < 10; l++) {
        for (int c = 0; c < 10; c++) {
            tabuleiro[l][c].tipo = '~';
            tabuleiro[l][c].foiAtacado = 0;
        }
    }
}

void posicionarSubmarinos(Celula tabuleiro[10][10]) {
    int l, c;
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        l = rand() % 10;
        c = rand() % 10;
        if (tabuleiro[l][c].tipo != 's') {
            tabuleiro[l][c].tipo = 's';
        } else {
            i--;
        }
    }
}

void imprimirTabuleiro(Celula tabuleiro[10][10]) {
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int l = 0; l < 10; l++) {
        printf("%d ", l);
        for (int c = 0; c < 10; c++) {
            if (tabuleiro[l][c].foiAtacado) {
                printf("%c ", tabuleiro[l][c].tipo);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void printTabuleiroComSubmarino(Celula tabuleiro[10][10]) {
    printf("\n");
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for(int l=0 ; l<10 ; l++) {
		printf("%d ", l);
		for(int c=0 ; c<10 ; c++) {
			printf("%c ", tabuleiro[l][c].tipo);
		}
		printf("\n");
	}
    
}

int realizarJogada(Celula tabuleiro[10][10], int linha, int coluna) {
    if (tabuleiro[linha][coluna].tipo == 's') {
        tabuleiro[linha][coluna].tipo = 'x';
        return 1;
    } else {
        tabuleiro[linha][coluna].tipo = 'o';
        return 0;
    }
}

void salvarJogo(Celula m2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],Celula m1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int *tentativas, int *qtdSubmarinos, const char *nome_arquivo){

   FILE *arquivo = fopen(nome_arquivo, "w+");

    if (arquivo == NULL)
    {
        printf("\nFalha ao abrir arquivo para salvar o jogo!");
        exit(0);
    }
    
    // Salva dados gerais
    fprintf(arquivo, "%d %d\n", *tentativas, *qtdSubmarinos);

     // Salva o tabuleiro com submarinos (m1)
    fprintf(arquivo, "#Tabuleiro Submarinos (m1)\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            fprintf(arquivo, "%c ", m1[i][j].tipo);
        }
        fprintf(arquivo, "\n");
    }

    // Salva o tabuleiro de tiros (m2)
    fprintf(arquivo, "#Tabuleiro Jogador (m2)\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            fprintf(arquivo, "%c ", m2[i][j].tipo);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Jogo salvo com sucesso em '%s'.\n", nome_arquivo);
      
}

int carregarJogoSalvo(Celula m1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],Celula m2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int *tentativas, int *submarinosEncontrados, const char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "r");


    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para carregar o jogo.\n");
        return 0; // falha
    }

    // Lê tentativas e submarinos encontrados
    fscanf(arquivo, "%d %d", tentativas, submarinosEncontrados);

    char linha[100];

    // Ignora linha do cabeçalho
    fgets(linha, sizeof(linha), arquivo); // consome o \n após fscanf
    fgets(linha, sizeof(linha), arquivo); // #Tabuleiro Submarinos

    // Lê tabuleiro m1
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            fscanf(arquivo, " %c", &m1[i][j].tipo);
            m1[i][j].foiAtacado = 0; // resetado por padrão
        }
    }

    fgets(linha, sizeof(linha), arquivo); // consome \n final da última linha
    fgets(linha, sizeof(linha), arquivo); // #Tabuleiro Jogador

    // Lê tabuleiro m2
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            fscanf(arquivo, " %c", &m2[i][j].tipo);
            // Define se já foi atacado com base no conteúdo
            if (m2[i][j].tipo == 'x' || m2[i][j].tipo == 'o') {
                m2[i][j].foiAtacado = 1;
            } else {
                m2[i][j].foiAtacado = 0;
            }
        }
    }

    fclose(arquivo);
    printf("Jogo carregado com sucesso de '%s'.\n", nomeArquivo);
    iniciarjogoCarregado(m1, m2, submarinosEncontrados, tentativas);
    return 1; // sucesso
} 

