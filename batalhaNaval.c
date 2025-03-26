#include <stdio.h>
	
	// Tamanho do tabuleiro
	#define TABULEIRO 10
	
	// Tamanho dos navios
	#define NAVIO 3
	
	// Tamanho das matrizes de habilidade
	#define HABILIDADE 5
	
	// Foi inicialido o tabuleiro em 0s (água)
	void inicializarTabuleiro(int tabuleiro[TABULEIRO][TABULEIRO]) {
	    for (int i = 0; i < TABULEIRO; i++) {
	        for (int j = 0; j < TABULEIRO; j++) {
	            tabuleiro[i][j] = 0;
	        }
	    }
	}
	
	// Posicionamento do navio na horizontalmente
	void posicionarNavioHorizontal(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int coluna) {
	    for (int i = 0; i < NAVIO; i++) {
	        tabuleiro[linha][coluna + i] = 3;
	    }
	}
	
	// Posicionamento do  navio na verticalmente
	void posicionarNavioVertical(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int coluna) {
	    for (int i = 0; i < NAVIO; i++) {
	        tabuleiro[linha + i][coluna] = 3;
	    }
	}
	
	// Posicionamento do navio na diagonal (crescente)
	void posicionarNavioDiagonalCrescente(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int coluna) {
	    for (int i = 0; i < NAVIO; i++) {
	        tabuleiro[linha + i][coluna + i] = 3;
	    }
	}
	
	// Posicionamento do navio na diagonal (decrescente)
	void posicionarNavioDiagonalDecrescente(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int coluna) {
	    for (int i = 0; i < NAVIO; i++) {
	        tabuleiro[linha + i][coluna - i] = 3;
	    }
	}
	
	// Comando criado para verificar  se há sobreposição de navios
	int verificarSobreposicao(int tabuleiro[TABULEIRO][TABULEIRO], int linha, int coluna, int direcao) {
	    for (int i = 0; i < NAVIO; i++) {
	        if (direcao == 0) { // Horizontal
	            if (tabuleiro[linha][coluna + i] != 0) return 1;
	        } else if (direcao == 1) { // Vertical
	            if (tabuleiro[linha + i][coluna] != 0) return 1;
	        } else if (direcao == 2) { // Diagonal Crescente
	            if (tabuleiro[linha + i][coluna + i] != 0) return 1;
	        } else if (direcao == 3) { // Diagonal Decrescente
	            if (tabuleiro[linha + i][coluna - i] != 0) return 1;
	        }
	    }
	    return 0;
	}
	
	// Foi criada a matriz de habilidade 
	void criarMatrizCone(int matriz[HABILIDADE][HABILIDADE]) {
	    for (int i = 0; i < HABILIDADE; i++) {
	        for (int j = 0; j < HABILIDADE; j++) {
	            if (j >= i && j <HABILIDADE - i) {
	                matriz[i][j] = 1;
	            } else {
	                matriz[i][j] = 0;
	            }
	        }
	    }
	}
	
	// Matriz de habilidade 
	void criarMatrizCruz(int matriz[HABILIDADE][HABILIDADE]) {
	    for (int i = 0; i < HABILIDADE; i++) {
	        for (int j = 0; j < HABILIDADE; j++) {
	            if (i == HABILIDADE / 2 || j == HABILIDADE / 2) {
	                matriz[i][j] = 1;
	            } else {
	                matriz[i][j] = 0;
	            }
	        }
	    }
	}
	
	// Matriz de habilidade 
	void criarMatrizOctaedro(int matriz[HABILIDADE][HABILIDADE]) {
	    for (int i = 0; i < HABILIDADE; i++) {
	        for (int j = 0; j < HABILIDADE; j++) {
	            if (i + j >= HABILIDADE / 2 && i + j <= 3 * HABILIDADE / 2 &&
	                i - j >= -HABILIDADE / 2 && i - j <= HABILIDADE / 2) {
	                matriz[i][j] = 1;
	            } else {
	                matriz[i][j] = 0;
	            }
	        }
	    }
	}
	
	// Linha de comando para fazer a sobrepor a matriz de habilidade ao tabuleiro
	void sobreporHabilidade(int tabuleiro[TABULEIRO][TABULEIRO], int matriz[HABILIDADE][HABILIDADE], int linha, int coluna) {
	    int centro = HABILIDADE / 2;
	    for (int i = 0; i < HABILIDADE; i++) {
	        for (int j = 0; j < HABILIDADE; j++) {
	            int x = linha + i - centro;
	            int y = coluna + j - centro;
	            if (x >= 0 && x < TABULEIRO && y >= 0 && y < TABULEIRO && matriz[i][j] == 1) {
	                tabuleiro[x][y] = 5; // Marca a área afetada pela habilidade
	            }
	        }
	    }
	}
	
	// Função para exibir o tabuleiro
	void exibirTabuleiro(int tabuleiro[TABULEIRO][TABULEIRO]) {
	    for (int i = 0; i < TABULEIRO; i++) {
	        for (int j = 0; j < TABULEIRO; j++) {
	            printf("%d ", tabuleiro[i][j]);
	        }
	        printf("\n");
	    }
	}
	
	// Função principal
	int main() {
	    // Declaração do tabuleiro
	    int tabuleiro[TABULEIRO][TABULEIRO];
	
	    // Inicializa o tabuleiro com 0s
	    inicializarTabuleiro(tabuleiro);
	
	    //  Posições iniciais do navio horizontal (linha, coluna)
	    int linhaHorizontal = 2;
	    int colunaHorizontal = 3;
	
	    //  Posições iniciais do navio vertical (linha, coluna)
	    int linhaVertical = 5;
	    int colunaVertical = 7;
	
	    //  Posições iniciais do navio diagonal crescente (linha, coluna)
	    int linhaDiagonalCrescente = 1;
	    int colunaDiagonalCrescente = 1;
	
	    // Posições iniciais do navio diagonal decrescente (linha, coluna)
	    int linhaDiagonalDecrescente = 2;
	    int colunaDiagonalDecrescente = 8;
	
	    // Validação das coordenadas dos navios
	    if (colunaHorizontal + NAVIO <= TABULEIRO && 
	        linhaVertical + NAVIO <= TABULEIRO && 
	        linhaDiagonalCrescente + NAVIO <= TABULEIRO && 
	        colunaDiagonalCrescente + NAVIO <= TABULEIRO && 
	        linhaDiagonalDecrescente + NAVIO <= TABULEIRO && 
	        colunaDiagonalDecrescente - NAVIO >= 0) {
	
	        // Verifica se há sobreposição de navios
	        if (!verificarSobreposicao(tabuleiro, linhaHorizontal, colunaHorizontal, 0) &&
	            !verificarSobreposicao(tabuleiro, linhaVertical, colunaVertical, 1) &&
	            !verificarSobreposicao(tabuleiro, linhaDiagonalCrescente, colunaDiagonalCrescente, 2) &&
	            !verificarSobreposicao(tabuleiro, linhaDiagonalDecrescente, colunaDiagonalDecrescente, 3)) {
	
	            // Posiciona o navio horizontal
	            posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
	
	            // Posiciona o navio vertical
	            posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);
	
	            // Posiciona o navio diagonal crescente
	            posicionarNavioDiagonalCrescente(tabuleiro, linhaDiagonalCrescente, colunaDiagonalCrescente);
	
	            // Posiciona o navio diagonal decrescente
	            posicionarNavioDiagonalDecrescente(tabuleiro, linhaDiagonalDecrescente, colunaDiagonalDecrescente);
	
	            // Foi criada as matrizes de habilidade
	            int matrizCone[HABILIDADE][HABILIDADE];
	            int matrizCruz[HABILIDADE][HABILIDADE];
	            int matrizOctaedro[HABILIDADE][HABILIDADE];
	
	            criarMatrizCone(matrizCone);
	            criarMatrizCruz(matrizCruz);
	            criarMatrizOctaedro(matrizOctaedro);
	
	            // Define os pontos de origem das habilidades
	            int linhaCone = 4, colunaCone = 4;
	            int linhaCruz = 7, colunaCruz = 2;
	            int linhaOctaedro = 1, colunaOctaedro = 6;
	
	            // Sobrepor as habilidades ao tabuleiro
	            sobreporHabilidade(tabuleiro, matrizCone, linhaCone, colunaCone);
	            sobreporHabilidade(tabuleiro, matrizCruz, linhaCruz, colunaCruz);
	            sobreporHabilidade(tabuleiro, matrizOctaedro, linhaOctaedro, colunaOctaedro);
	
	            // Exibe o tabuleiro com os navios e as áreas de efeito das habilidades
	            exibirTabuleiro(tabuleiro);
	        } else {
	            printf("Erro: Navios se sobrepõem. Verifique as coordenadas.\n");
	        }
	    } else {
	        printf("Coordenadas inválidas para os navios. Verifique os limites do tabuleiro.\n");
	    }
	
	    return 0;
	}
