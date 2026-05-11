/*Questão 08
Um professor deseja verificar se uma sequência de números digitada pelos alunos já está em ordem 
crescente. Faça um programa que:
• Leia 10 números inteiros 
• Armazene os números em um vetor 
• Verifique se os valores estão em ordem crescente 
• Mostre uma mensagem informando se o vetor está ou não ordenado*/

#include <stdio.h>
#define TAMANHO 10

int verificaVetorOrdenado(int vet[],int tamanho){
    int i,ordenado=1;
    for(i=0;i<tamanho-1;i++){
        if(v[i]>v[i+1]){
            ordenado=0;
            break;
        }
    }
    return ordenado;
}

int main(){
    int v[TAMANHO],ordenado=1,i;
    for(i=0;i<TAMANHO-1;i++){
        printf("\nForneça um número:\n");
        scanf("%d",&v[i]);
    }

    //Verificando se está ordenado
    for(i=0;i<TAMANHO-1;i++){
        if(v[i]>=v[i+1]){
            ordenado=0;
            break;
        }
    }
    /*for(i=0;i<TAMANHO-1 && ordenado==1;i++){
        if(v[i]<=v[i+1]){
            ordenado=0;   
        }
    }*/
    return 0;
}
