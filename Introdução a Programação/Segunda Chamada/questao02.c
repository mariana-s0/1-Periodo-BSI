/*O prefeito quer saber qual(is) jogador(es) acumularam mais pontos ao longo de toda a história do AlvinoPlay*/
#include <stdio.h>
#include <string.h>
#define TAM 100
#define PONTOS 10
#define MAX_JOGADORES 100

void acumulaPontos(char nomes[][TAM],int pontos[],int *totalJogadores,char nome[],int pontuacao){
    int i;
    for(i=0;i<*totalJogadores;i++){
        if(strcmp(nome,nomes[i])==0){
            pontos[i] += pontuacao;
            return;
        }
    }
    strcpy(nomes[*totalJogadores],nome);
    pontos[*totalJogadores]=pontuacao;
    (*totalJogadores)++;
}
void imprimeCampeoes(char nomes[][TAM],int pontos[],int totalJogadores){
    int i,maior=0;
    for(i=0;i<totalJogadores;i++){
        if(pontos[i]>maior){
            maior = pontos[i];
        }
    }
    printf("\nCampeao(oes):\n");
    for(i=0;i<totalJogadores;i++){
        if(pontos[i]==maior){
            printf("\n%s\n",nomes[i]);
        }
    }
}
void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n');
}
int main(){
    int semanas,jogadores,cont,i,totalJogadores=0;
    char nomes[MAX_JOGADORES][TAM],nome[TAM];
    int pontos[MAX_JOGADORES]={0};

    printf("\nForneça o número de semanas:\n");
    scanf("%d",&semanas);

    for(cont=0;cont<semanas;cont++){
        printf("\nForneça a quantidade de jogadores:\n");
        scanf("%d",&jogadores);
        limpaBuffer();
        for(i=0;i<jogadores;i++){
            printf("\nForneça o nome do %d° jogador:\n",i);
            fgets(nome,TAM,stdin);
            acumulaPontos(nomes,pontos,&totalJogadores,nome,PONTOS-i);
        }
    }
    imprimeCampeoes(nomes,pontos,totalJogadores);
    return 0;
}