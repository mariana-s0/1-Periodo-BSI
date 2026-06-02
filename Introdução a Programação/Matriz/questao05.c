/*Questão 05
Em um tabuleiro de Batalha Naval de tamanho 6x6, o usuário está tentando adivinhar onde estão os
navios inimigos. Faça um programa que:
1. Preencha uma matriz de inteiros onde a maioria das posições é 0 (água) e exatamente 4
posições sorteadas por você contêm o número 5 (navios ocultos).
2. O usuário deve digitar uma linha e uma coluna para dar um "disparo".
3. Se ele acertar o navio (5), exiba "Fogo! Navio destruído!".
4. Se ele acertar a água (0), o programa deve fazer uma varredura automática na mesma linha e
na mesma coluna do disparo e contar quantos navios estão naquela "linha de visão" do radar,
exibindo: "Água! Mas o radar detectou X navio(s) nessa linha/coluna".*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ORDEM 6
#define NUMERO_NAVIOS 5
void incializaMatriz(int mapa[][ORDEM],int nl,int nc,int numeroNavios){
    int lin,col,cont=0;
    for(lin=0;lin<nl;lin++){
        for(col=0;col<nc;col++){
            mapa[lin][col]=0;
        }
    }
        srand(time(NULL));
        do{
            lin = rand()%nl;
            col = rand()%nc;
            //Verificando se a posição está livre
            if(mapa[lin][col]==0){
                mapa[lin][col]=1;
                cont++;
            }
        }while(cont<numeroNavios);
        printf("\nForneça a linha e a coluna para dar um disparo:\n");
        scanf("%d %d",&lin,&col);
        if(mapa[lin][col]==0){
            
        }
    
}
void imprimeMatriz(int m[][ORDEM],int nl, int nc){
    int lin,col;
    for(lin=0;lin<nl;lin++){
        for(col=0;col<nc;col++){
            printf("%d\t",m[lin][col]);
        }
        printf("\n");
    }
}
int main(){
    int mapa[ORDEM][ORDEM],tentativas,naviosAbatidos;
    incializaMatriz(mapa,ORDEM,ORDEM,NUMERO_NAVIOS);
    imprimeMatriz(mapa,ORDEM,ORDEM);
    
    return 0;
}