/*Questão 03
Faça um programa que gere uma matriz 4x4 de char com a configuração
                        1   0   0   0
                        0   1   0   0
                        0   0   1   0
                        0   0   0   1                               */
#include <stdio.h>
#define TAM_MAX 4
int main(){
    char m[TAM_MAX][TAM_MAX];
    int lin,col;

    for(lin=0;lin<TAM_MAX;lin++){
        for(col=0;col<TAM_MAX;col++){
            if(lin == col){
                m[lin][col] = '1';
            }
            else
                m[lin][col] = '0';
        }
    }
    for(lin=0;lin<TAM_MAX;lin++){
        for(col=0;col<TAM_MAX;col++){
            printf("%c",m[lin][col]);
        }
        printf("\n");
    }
    return 0;
}