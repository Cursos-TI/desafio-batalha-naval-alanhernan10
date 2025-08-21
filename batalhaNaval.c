#include <stdio.h>

// --- Desafio de Batalha Naval - MateCheck (Nível Mestre) ---
// VERSÃO COM HABILIDADES MENORES (3x3)

// --- Constantes ---
#define TAMANHO_TABULEIRO 10
// ALTERAÇÃO: O tamanho da área de efeito foi reduzido de 5 para 3.
#define TAMANHO_HABILIDADE 3

// --- Constantes de Elementos ---
#define AGUA 0
#define AOE_CONE 1
#define AOE_CRUZ 3
#define AOE_OCTAEDRO 5
#define AFETADO 1
#define NAO_AFETADO 0

// --- Protótipos das Funções ---
void criarHabilidade(int tam, int matriz[][tam], char tipo);
void aplicarHabilidade(int tab[][TAMANHO_TABULEIRO], int hab[][TAMANHO_HABILIDADE], int ol, int oc, int marca_habilidade);
void exibirTabuleiro(int tab[][TAMANHO_TABULEIRO]);
int valorAbsoluto(int n);

// --- Função Principal (Orquestrador) ---
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarHabilidade(TAMANHO_HABILIDADE, cone, 'C');
    criarHabilidade(TAMANHO_HABILIDADE, cruz, '+');
    criarHabilidade(TAMANHO_HABILIDADE, octaedro, 'O');

    printf("Aplicando habilidades especiais (tamanho 3x3) no tabuleiro...\n");
    
    // A origem do cone foi ajustada para 1, para que a ponta apareça na linha 0.
    // (centro da habilidade 1 - deslocamento da ponta 1 = 0)
    aplicarHabilidade(tabuleiro, cone, 1, 5, AOE_CONE);
    
    aplicarHabilidade(tabuleiro, cruz, 7, 2, AOE_CRUZ);
    aplicarHabilidade(tabuleiro, octaedro, 4, 5, AOE_OCTAEDRO);

    exibirTabuleiro(tabuleiro);

    return 0;
}

// --- Funções (Nenhuma alteração necessária aqui) ---

void aplicarHabilidade(int tab[][TAMANHO_TABULEIRO], int hab[][TAMANHO_HABILIDADE], int ol, int oc, int marca_habilidade) {
    int centro_h = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (hab[i][j] == AFETADO) {
                int alvo_l = ol + (i - centro_h);
                int alvo_c = oc + (j - centro_h);
                if (alvo_l >= 0 && alvo_l < TAMANHO_TABULEIRO && alvo_c >= 0 && alvo_c < TAMANHO_TABULEIRO) {
                    if (tab[alvo_l][alvo_c] == AGUA) {
                        tab[alvo_l][alvo_c] = marca_habilidade;
                    }
                }
            }
        }
    }
}

void exibirTabuleiro(int tab[][TAMANHO_TABULEIRO]) {
    printf("\n--- Tabuleiro com Habilidades ---\n");
    printf("    ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) { printf("%d ", j); }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %c | ", 'A' + i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void criarHabilidade(int tam, int matriz[][tam], char tipo) {
    int centro = tam / 2;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            int afeta = 0;
            switch (tipo) {
                case 'C': if (i <= centro && j >= centro - i && j <= centro + i) afeta = 1; break;
                case '+': if (i == centro || j == centro) afeta = 1; break;
                case 'O': if (valorAbsoluto(i - centro) + valorAbsoluto(j - centro) <= centro) afeta = 1; break;
            }
            matriz[i][j] = afeta;
        }
    }
}

int valorAbsoluto(int n) {
    return (n < 0) ? -n : n;
}