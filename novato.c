#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++){
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
           printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
}

int main(){

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 7;

     int sobreposicaoHorizontal = 0;

if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO){
    for (int i = 0; i < TAMANHO_NAVIO; i++){
        if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != 0)
        {
            sobreposicaoHorizontal = 1;
            break;
        }
        
    }
    
}

    
    if (!sobreposicaoHorizontal){
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
        }
        
    }
    int sobreposicaoVertical = 0;

    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO){
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            if (tabuleiro[linhaVertical + i][colunaVertical] != 0){
                sobreposicaoVertical = 1;
                break;
            }
            
        }
        
    }
    if (!sobreposicaoVertical){
        for (int i = 0; i < TAMANHO_NAVIO; i++)
        {
            tabuleiro[linhaVertical + i][colunaVertical] = 3;
        }
        
    }
     exibirTabuleiro(tabuleiro);
    
return 0;
}