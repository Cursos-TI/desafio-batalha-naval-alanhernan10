#include <stdio.h>
#include <stdbool.h> // Biblioteca para usar o tipo de dado 'bool'

// --- Desafio de Batalha Naval - MateCheck (Nível Aventureiro) ---
// VERSÃO CORRIGIDA: Lógica de posicionamento diagonal refeita para maior clareza e correção.

// --- Constantes do Jogo ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// --- Protótipo da Função ---
bool posicionarNavio(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao);

// --- Função Principal ---
int main() {
    // 1. Cria e inicializa o tabuleiro com 'AGUA'
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    printf("Inicializando o tabuleiro com água...\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posiciona os Quatro Navios usando a função corrigida
    printf("\nTentando posicionar os navios...\n");

    // Navio 1: Horizontal na linha C
    if (posicionarNavio(tabuleiro, 2, 4, 'H')) {
        printf("- Navio Horizontal posicionado com sucesso!\n");
    } else {
        printf("- FALHA ao posicionar o Navio Horizontal.\n");
    }

    // Navio 2: Vertical na coluna 8
    if (posicionarNavio(tabuleiro, 4, 8, 'V')) {
        printf("- Navio Vertical posicionado com sucesso!\n");
    } else {
        printf("- FALHA ao posicionar o Navio Vertical.\n");
    }

    // Navio 3: Diagonal Principal, começando em (A,0)
    if (posicionarNavio(tabuleiro, 0, 0, 'D')) {
        printf("- Navio Diagonal (Principal) posicionado com sucesso!\n");
    } else {
        printf("- FALHA ao posicionar o Navio Diagonal (Principal).\n");
    }

    // Navio 4: Diagonal Secundária, começando em (A,9)
    if (posicionarNavio(tabuleiro, 0, 9, 'E')) {
        printf("- Navio Diagonal (Secundária) posicionado com sucesso!\n");
    } else {
        printf("- FALHA ao posicionar o Navio Diagonal (Secundária).\n");
    }

    // 3. Exibe o Tabuleiro Final
    printf("\n--- Tabuleiro Final da Batalha Naval ---\n");
    printf("    ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %c | ", 'A' + i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/**
 * @brief Tenta posicionar um navio no tabuleiro, realizando todas as validações. (VERSÃO CORRIGIDA)
 * @param tabuleiro A matriz do jogo.
 * @param linha A linha inicial do navio.
 * @param coluna A coluna inicial do navio.
 * @param orientacao A orientação: 'H', 'V', 'D' (Principal), 'E' (Esquerda/Secundária).
 * @return true se o navio foi posicionado com sucesso, false caso contrário.
 */
bool posicionarNavio(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    // --- Etapa 1: Validação de Limites (antes de percorrer as células) ---
    switch (orientacao) {
        case 'H': if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false; break;
        case 'V': if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false; break;
        case 'D': if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false; break;
        case 'E': if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - (TAMANHO_NAVIO - 1) < 0) return false; break;
        default: return false; // Orientação inválida
    }

    // --- Etapa 2: Validação de Sobreposição ---
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna; // Coordenadas da peça atual do navio
        switch (orientacao) {
            case 'H': c += i; break;
            case 'V': l += i; break;
            case 'D': l += i; c += i; break;
            case 'E': l += i; c -= i; break;
        }
        if (tabuleiro[l][c] == NAVIO) return false; // Se a célula já está ocupada, falha.
    }

    // --- Etapa 3: Posicionamento ---
    // Se passou por todas as validações, posiciona o navio.
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        switch (orientacao) {
            case 'H': c += i; break;
            case 'V': l += i; break;
            case 'D': l += i; c += i; break;
            case 'E': l += i; c -= i; break;
        }
        tabuleiro[l][c] = NAVIO;
    }

    return true; // Retorna sucesso
}