/*Ler um conjunto de inteiros e retornar o maior número*/

#include <stdio.h>
#define TAMANHO 5
int maiorValor(int v[],int tamanho){
    int i,maior;
    maior=v[0];
    for(i=1;i<tamanho;i++){
        if(v[i]>maior)
        maior=v[1];
    }
    return maior;
}
int main (){
    int numero,maiorNumero,v [TAMANHO],cont,i;

    for(i=0;i<TAMANHO;i++){
        printf("\nForneça o %d° número :\n",i++);
        scanf("%d",&v[i]);
    }
}
