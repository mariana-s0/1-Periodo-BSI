/*Exercício 01
Implemente uma função que receba um vetor de números inteiros e retorne um novo vetor contendo
apenas os elementos que aparecem exatamente uma única vez no vetor original (ou seja, elementos 
sem duplicatas).  */

#include <stdio.h>
#define TAM 4
int recebeInteiro(int vOriginal[],int tamanho,int vDestino[]){
    int i,k,
    cont,pos;
    for(i=0;i<tamanho;i++){
        for(k=0;k<tamanho;k++){
            cont=0;
            if(vOriginal[i]==vOriginal[k]){
                cont++;
            }
        }
        if(cont==1){
            vDestino[pos]=vOriginal[i];
            pos++;
        }
    }
    return pos;

}
int main (){
    int original[TAM]={1,2,4,4},
    destino[TAM],
    qtde,i;

    qtde=recebeInteiro(original,TAM,destino);

    printf("\nElementos sem duplicatas :\n");

    for(i=0;i<qtde;i++){
        printf("%d",destino[i]);
    }

    return 0;
}

