#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VAZIO 0
#define NAVIO 3



void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++){
        printf("%2d ", j);

    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++){
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++){
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
    
 int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcaoLinha, int direcaoColuna){
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            int novaLinha = linha + i * direcaoLinha;
            int novaColuna = coluna + i * direcaoColuna;

            if (novaLinha < 0 || novaLinha >= TAMANHO_TABULEIRO || novaColuna < 0 || novaColuna >= TAMANHO_TABULEIRO)
                return 0;
        
            if (tabuleiro[novaLinha][novaColuna] != VAZIO)
                return 0;
    
        }
        return 1;
 }

 void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcaoLinha, int direcaoColuna){
    for (int i = 0; i < TAMANHO_NAVIO; i++){
       int novaLinha = linha + i * direcaoLinha;
       int novaColuna = coluna + i * direcaoColuna;
       tabuleiro[novaLinha][novaColuna] = NAVIO;
    }
    
}

int main(){
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    int navios[4][4] = {

        {2, 1, 0, 1},
        {5, 7, 1, 0},
        {0, 0, 1, 1},
        {3, 7, 1, -1}
    };

    for (int i = 0; i < 4; i++){
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int dirLinha = navios[i][2];
        int dirColuna = navios[i][3];

        if (podePosicionar(tabuleiro, linha, coluna, dirLinha, dirColuna)) {
            posicionarNavio(tabuleiro, linha, coluna, dirLinha,dirColuna);
        }else {
                printf("Não foi possivel posicionar o navio %d...\n", i + 1);
            }
        
        
    }
    exibirTabuleiro(tabuleiro);

    return 0;
    
}