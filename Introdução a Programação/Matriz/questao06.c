/*Questão 06
Na computação gráfica, as imagens digitais são matrizes de pixels. Quando aplicamos um efeito de
desfoque (blur), o software calcula a média dos valores dos pixels vizinhos para suavizar a imagem.
Faça um programa que:
1. Crie uma matriz 4x4 de inteiros representando os tons de cinza de uma imagem (valores de
0 a 100) preenchida pelo usuário.
2. Gere uma segunda matriz (Matriz Modificada). Cada posição interna dessa nova matriz
(linhas 1 e 2, colunas 1 e 2 — ignorando as bordas para facilitar) deve receber a média
aritmética entre o seu próprio valor original e os seus 4 vizinhos diretos (cima, baixo,
esquerda e direita).
3. Exiba a matriz original e a matriz com o efeito de desfoque aplicado.*/

#include <stdio.h>
#define TAM_MAX 4
#define TAM_BORDA 3
int main(){
    int m[TAM_MAX][TAM_MAX],
        mBlur[TAM_MAX][TAM_MAX],
        lin,col;
        printf("\nForneça os valores da matriz :\n");
        for(lin=0;lin<TAM_MAX;lin++){
            for(col=0;col<TAM_MAX;col++){
                scanf("%d",&m[lin][col]);
                mBlur[lin][col] = m[lin][col];
            }
        }

        for(lin=0;lin<TAM_BORDA;lin++){
            for(col=0;col<TAM_BORDA;col++){
                mBlur[lin][col] = (m[lin][col] + m[lin - 1][col] + m[lin + 1][col] + m[lin][col -1] + m[lin][col - 1])/5;
            }
        }
        printf("\nMatriz Original :\n");
        for(lin=0;lin<TAM_MAX;lin++){
            for(col=0;col<TAM_MAX;col++){
                printf("%d\t",m[lin][col]);
            }
            printf("\n");
        }
        printf("\nMatriz Modificada\n");
        for(lin=0;lin<TAM_MAX;lin++){
            for(col=0;col<TAM_MAX;col++){
                printf("%d\t",mBlur[lin][col]);
            }
            printf("\n");
        }
    return 0;
}