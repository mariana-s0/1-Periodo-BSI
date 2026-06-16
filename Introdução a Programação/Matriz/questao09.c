/*Questão 09
Na Teoria de Sistemas, define-se como elemento minimax de uma matriz o menor elemento da
linha onde se encontra o maior elemento de toda a matriz. Escreva um programa que preencha uma
matriz M de dimensões 15x15 com valores inteiros fornecidos pelo usuário. Em seguida, o
programa deve analisar a matriz para identificar e exibir o valor do elemento minimax, indicando
também em qual linha e coluna ele está localizado. Caso haja mais de um elemento com o maior
valor global, adote a linha da primeira ocorrência encontrada para realizar a busca pelo menor
elemento.*/
#include <stdio.h>
#define NL 3
#define NC 3
int main(){
    int matriz[NL][NC]={{1,2,3},{2,0,6},{7,8,0}},lin,col,maiorElemento,menorElemento,linhaMaior;
    maiorElemento = matriz[0][0];
    linhaMaior = 0;
    for(lin=0;lin<NL;lin++){
        for(col=0;col<NC;col++){
            if(matriz[lin][col]>maiorElemento){
                maiorElemento=matriz[lin][col];
                linhaMaior= lin;
            }
        }
    }
    //Encontrando o elemento minimax
    menorElemento = matriz[linhaMaior][0];
    for(col=1;col<NC;col++){
        if(matriz[linhaMaior][col]<menorElemento){
            menorElemento= matriz[linhaMaior][col];
        }
    }
    printf("\nValor de MiniMax : %d\n",menorElemento);
    return 0;
}