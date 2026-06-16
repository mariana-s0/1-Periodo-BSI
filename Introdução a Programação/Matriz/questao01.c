/*Questão 01
Faça um programa que leia as dimensões de uma matriz quadrada de ordem N, onde N é menor ou
igual a 10. Preencha cada posição da matriz com a soma dos seus próprios índices (ou seja, M[i][j] =
i + j). Ao final, imprima a matriz na tela em formato de tabela.*/
#include <stdio.h>

 int main(){
    int n,lin,col,m[10][10];
    printf("\nForneça o valor de N (N<=10):\n");
    scanf("%d",&n);

    for(lin=0;lin<n;lin++){
        for(col=0;col<n;col++){
            m[lin][col]=lin+col;
        }
    }
    for(lin=0;lin<n;lin++){
        for(col=0;col<n;col++){
             printf("\t%d",m[lin][col]);
        }
        printf("\n");
    }
    return 0;
 }