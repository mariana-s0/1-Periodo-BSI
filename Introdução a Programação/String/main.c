#include <stdio.h>
#include <string.h>
#include "leitura1.h"
#include "mystrings.h"
#define QUANTIDADE_MAXIMA 100

int main(){
    int quantidade=0, // Representa o numero de produtos cadastrados
    opcao,i,achou;
    float vendas[QUANTIDADE_MAXIMA],estoque[QUANTIDADE_MAXIMA];
    char nomes[QUANTIDADE_MAXIMA][50],nomeProduto[50];

    do{
        printf("\n1-Cadastro de Produto\n0-Fim");
        printf("Forneça sua opção:");
        scanf("%d",&opcao);

        switch (opcao){
        case 1:
            // Verificando se tem espaço disponível para mais um produto
            if(quantidade==QUANTIDADE_MAXIMA){
                printf("\nVetor Cheio !!\n");
                break;
            }
            printf("Forneça o nome do produto a ser cadastrado:");
            limpaBuffer();
            lerString(nomeProduto,50);
            converteMaiuscula(nomeProduto);
            //pesquisa sequencial
            i=0;
            achou=0;
            while(i<quantidade && achou==0){
                if(strcmp(nomeProduto,nomes[i])==0)
                achou = 1;
                else
                    i++;
            }
            //Verificando se o produto foi encontrado
            if(achou==1){
                printf("Produto já cadatrado");
                break;
            }
            strcpy(nomes[quantidade],nomeProduto);
            printf("Quantidade em Estoque:");
            scanf("%f",&estoque[quantidade]);
            while(estoque[quantidade]<0){
                printf("A quantidade em Estoque deve ser >=0 !!");
                scanf("%f",&estoque[quantidade]);
            }
            vendas[quantidade]=0;
            quantidade++;
        }
    }while(opcao!=0);
    return 0;
}