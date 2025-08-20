#include <stdio.h>
#include <stdbool.h> // Biblioteca para usar o tipo de dado 'bool' (true/false)

// --- Desafio de Batalha Naval - MateCheck (Nível Novato) ---
// Este código cria um tabuleiro de Batalha Naval, posiciona dois navios
// (um na horizontal e um na vertical) e exibe o resultado.

// --- Requisitos: Definição de constantes para fácil manutenção ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// --- Legibilidade: Usar constantes para representar os elementos do jogo ---
#define AGUA 0
#define NAVIO 3

int main() {
    // 1. Represente o Tabuleiro:
    // Uma matriz (array bidimensional) para representar o tabuleiro 10x10.
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Documentação: Inicializa todas as posições do tabuleiro com 'AGUA' (0).
    // Loops aninhados são perfeitos para percorrer uma matriz.
    printf("Inicializando o tabuleiro com água...\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicione os Navios:
    // Requisito: Coordenadas iniciais definidas diretamente no código.
    // Navio 1 (Horizontal)
    int navioH_linha = 2;
    int navioH_coluna = 3;

    // Navio 2 (Vertical)
    int navioV_linha = 4;
    int navioV_coluna = 5;

    // --- Posicionando o Navio Horizontal com Validação ---
    printf("Posicionando navio horizontal na linha %d, coluna %d...\n", navioH_linha, navioH_coluna);

    // Requisito: Validar se o navio cabe nos limites do tabuleiro.
    if (navioH_coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // O navio cabe. Agora vamos posicioná-lo.
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navioH_linha][navioH_coluna + i] = NAVIO;
        }
    } else {
        printf("ERRO: Navio horizontal fora do tabuleiro!\n");
    }

    // --- Posicionando o Navio Vertical com Validação ---
    printf("Posicionando navio vertical na linha %d, coluna %d...\n", navioV_linha, navioV_coluna);

    // Requisito: Validar se o navio cabe nos limites do tabuleiro.
    if (navioV_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // O navio cabe. Agora, precisamos verificar se ele não se sobrepõe ao outro.

        // Requisito: Garantir que os navios não se sobreponham.
        bool sobreposicao = false; // Uma "flag" para indicar se há sobreposição.
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se a posição onde queremos colocar uma parte do navio já está ocupada.
            if (tabuleiro[navioV_linha + i][navioV_coluna] == NAVIO) {
                sobreposicao = true;
                break; // Se encontrou uma sobreposição, não precisa continuar verificando.
            }
        }

        // Se a flag 'sobreposicao' continuar falsa, significa que o local está livre.
        if (!sobreposicao) {
            // Posições válidas e sem sobreposição, vamos posicionar o navio.
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navioV_linha + i][navioV_coluna] = NAVIO;
            }
        } else {
            printf("ERRO: Sobreposição detectada! O navio vertical não pode ser posicionado aqui.\n");
        }

    } else {
        printf("ERRO: Navio vertical fora do tabuleiro!\n");
    }

    // 3. Exiba o Tabuleiro:
    // Utiliza loops aninhados para percorrer e imprimir cada célula da matriz.
    printf("\n--- Tabuleiro Final da Batalha Naval ---\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Imprime o valor da célula seguido de um espaço para formatação.
            printf("%d ", tabuleiro[i][j]);
        }
        // Pula para a próxima linha ao final de cada linha do tabuleiro.
        printf("\n");
    }

    return 0;
}