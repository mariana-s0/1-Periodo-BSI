#include <stdio.h>
#include "leitura.h"
void limpaBuffer(){
    int ch;
    while((ch=getchar()) !='\n' && (ch!=EOF));

    
}
int lerInteiro(){
    int retorno,valor;
    do{
        printf("\nForneça um inteiro :\n");
        retorno = scanf("%d",&valor);
        if(retorno!=1){
            printf("\nValor incorreto !!\n");
            limpaBuffer();
        }
    }while(retorno !=1);
    limpaBuffer();
    return valor;
}

float lerFloat(){
    int retorno;
    float valor;
    do{
        printf("\nForneça um número real :\n");
        retorno = scanf("%f",&valor);
        if(retorno!=1){
            printf("\nValor incorreto !!\n");
            limpaBuffer();
        }
    }while(retorno !=1);
    limpaBuffer();
    return valor;
}