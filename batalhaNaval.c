#include <stdio.h>
#include <stdbool.h> // Biblioteca para usar o tipo de dado 'bool' (true/false)

// --- Desafio de Batalha Naval - MateCheck (Nível Novato) ---
// Este código cria um tabuleiro de Batalha Naval, posiciona dois navios
// e exibe o resultado com cabeçalhos alfabéticos para as linhas (A-J)
// e numéricos para as colunas (0-9).

// --- Requisitos: Definição de constantes para fácil manutenção ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// --- Legibilidade: Usar constantes para representar os elementos do jogo ---
#define AGUA 0
#define NAVIO 3

int main() {
    // 1. Represente o Tabuleiro:
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições do tabuleiro com 'AGUA' (0).
    printf("Inicializando o tabuleiro com água...\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicione os Navios:
    // Navio 1 (Horizontal)
    int navioH_linha = 2; // Corresponderá à linha 'C'
    int navioH_coluna = 3;

    // Navio 2 (Vertical)
    int navioV_linha = 4; // Corresponderá à linha 'E'
    int navioV_coluna = 5;

    // --- Posicionando o Navio Horizontal com Validação ---
    printf("Posicionando navio horizontal na linha C, coluna 3...\n");
    if (navioH_coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navioH_linha][navioH_coluna + i] = NAVIO;
        }
    } else {
        printf("ERRO: Navio horizontal fora do tabuleiro!\n");
    }

    // --- Posicionando o Navio Vertical com Validação ---
    printf("Posicionando navio vertical na linha E, coluna 5...\n");
    if (navioV_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        bool sobreposicao = false;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navioV_linha + i][navioV_coluna] == NAVIO) {
                sobreposicao = true;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navioV_linha + i][navioV_coluna] = NAVIO;
            }
        } else {
            printf("ERRO: Sobreposição detectada! O navio vertical não pode ser posicionado aqui.\n");
        }
    } else {
        printf("ERRO: Navio vertical fora do tabuleiro!\n");
    }

    // 3. Exiba o Tabuleiro com cabeçalhos de linha e coluna:
    printf("\n--- Tabuleiro Final da Batalha Naval ---\n");

    // Imprime o cabeçalho das colunas (eixo X)
    printf("    "); // Espaço inicial para alinhar com as linhas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n"); // Pula a linha após o cabeçalho

    // Imprime as linhas com seus respectivos cabeçalhos (eixo Y)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // NOVO: Imprime o cabeçalho da linha com uma letra do alfabeto
        printf(" %c |" ,'A' + i);

        // Imprime o conteúdo da linha (água ou navio)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        // Pula para a próxima linha ao final de cada linha do tabuleiro.
        printf("\n");
    }

    return 0;
}