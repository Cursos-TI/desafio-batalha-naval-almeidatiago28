#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VAZIO 0
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HABILIDADE 5


void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
        printf("  ");
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++){
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++){
            if (tabuleiro[i][j] == VAZIO)
            printf(" ~ ");
            
                else if (tabuleiro[i][j] == NAVIO) 
                    printf(" N ");
                   else if (tabuleiro[i][j] == HABILIDADE)
                   printf(" * ");

        }
                    printf("\n");
    }

}

    int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcaoLinha, int direcaoColuna){
        for (int i = 0; i < TAMANHO_NAVIO; i++)
        {
            int novaLinha = linha + i * direcaoLinha;
            int novaColuna = coluna + i * direcaoColuna;

            if (novaLinha < 0 || novaLinha >= TAMANHO_TABULEIRO || novaColuna < 0 || novaColuna >= TAMANHO_TABULEIRO)
                return 0;

                if (tabuleiro[novaLinha][novaColuna] != VAZIO)
              return 0;
                
        }
        return 1;
        
    }

    void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int dirLinha, int dirColuna){
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            int novaLinha = linha + i * dirLinha;
            int novaColuna = coluna + i * dirColuna;
            tabuleiro[novaLinha][novaColuna] = NAVIO;
        }
        
    }


    void construirCone(int matriz[ TAM_HABILIDADE][TAM_HABILIDADE]){
        for (int i = 0; i < TAM_HABILIDADE; i++){
            for (int j = 0; j < TAM_HABILIDADE; j++){
                int meio = TAM_HABILIDADE / 2;
                if (j >= meio - i && j <= meio + i)
                    matriz[i][j] = 1;
                else 
                    matriz[i][j] = 0;

                
            }
            
        }
        
    }

    void construirCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]){
        int meio = TAM_HABILIDADE / 2;
        for (int i = 0; i < TAM_HABILIDADE; i++){
            for (int j = 0; j < TAM_HABILIDADE; j++){
                if (i == meio || j == meio)
                    matriz[i][j] = 1;
                else 
                    matriz[i][j] = 0;  
            }
            
        }
        
    }

    void construirOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]){
        int meio = TAM_HABILIDADE / 2;
        for (int i = 0; i < TAM_HABILIDADE; i++){
            for (int j = 0; j < TAM_HABILIDADE; j++) {
                if (abs(meio - i) + abs(meio - j) <= meio)
                    matriz[i][j] = 1;
                
                else    
                    matriz[i][j] = 0;
           
                
            }
            
        }

 }


    void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna){
        int offset = TAM_HABILIDADE / 2;

        for (int i = 0; i < TAM_HABILIDADE; i++){
           for (int j = 0; j < TAM_HABILIDADE; j++){
                if (habilidade[i][j] == 1){
                    int linhaTabuleiro = origemLinha + (i - offset);
                    int colunaTabuleiro = origemColuna + (j - offset);

                    if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                        colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO &&
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] == VAZIO) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                        }
                    
                }
                
           }
           
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


            if (podePosicionar(tabuleiro, linha, coluna, dirLinha, dirColuna)){
                posicionarNavio(tabuleiro, linha, coluna, dirLinha, dirColuna);
            } else {
                printf("Não foi possivel posicionar o navio %d...\n", i + 1);
            }
            
        }
        

        int cone[TAM_HABILIDADE][TAM_HABILIDADE];
        int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
        int octaedro [TAM_HABILIDADE][TAM_HABILIDADE];



        construirCone(cone);
        construirCruz(cruz);
        construirOctaedro(octaedro);


        aplicarHabilidade (tabuleiro, cone, 2, 2);
        aplicarHabilidade (tabuleiro, cruz, 7, 7);
        aplicarHabilidade (tabuleiro, octaedro, 5, 2);

        exibirTabuleiro(tabuleiro);


return 0;
        
    }