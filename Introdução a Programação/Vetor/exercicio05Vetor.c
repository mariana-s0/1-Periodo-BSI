/*Leia 15 idades e mostre a moda (idade que mais aparece)*/
#include <stdio.h>
#define TAMANHO 5
int main (){
    int v [TAMANHO],i,k,cont,moda,maiorOcorrencia=-1;
     //ler o vetor
     for(i=0;i<TAMANHO;i++){
        printf("\nForneça o %d° elemento:\n",i++);
        scanf("%d",&v[i]);
     }
     for(i=0;i<TAMANHO;i++){
        cont=1;
        for(k=i+1;k<TAMANHO;k++){
            if(v[i]==v[k]){
                cont++;
            }
        }
        /*Verificando se o número de ocorrência da posição corrente é maior que a moda*/
        if(cont>maiorOcorrencia){
            moda=v[i];
            maiorOcorrencia=cont;
        }
     }
}