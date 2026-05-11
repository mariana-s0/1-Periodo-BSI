/*Questão 14
Um sistema registra as últimas 10 senhas digitadas incorretamente para análise de segurança.
Faça um programa que:
• Leia 10 números representando tentativas de senha 
• Armazene em um vetor 
• Verifique se alguma senha foi digitada duas vezes seguidas 
• Mostre a posição onde isso ocorreu*/

#include <stdio.h>
#define TAMANHO 5
int main(){
    int v[TAMANHO],errou=0,i;
    for(i=0;i<TAMANHO-1;i++){
        printf("\nForneça um número:\n");
        scanf("%d",v[i]);
    }

    //Verificando se ocorreu erro
    for(i=0;i<TAMANHO-1;i++){
        if(v[i]==v[i+1]){
            printf("\nErros nas posições %d e %d\n",i,i+1);
            errou=1;
        }
    }
    if(errou==0)
    printf("\nNão ocorreu erro!!\n");
    return 0;
}
