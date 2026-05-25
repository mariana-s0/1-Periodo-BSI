/*Exercício 03
Durante um campeonato muito esperado, foi criado um jogo de loteria esportiva em que os
participantes precisam prever os resultados de 13 partidas. Para cada jogo, o resultado possível é
representado pelos números 1, 2 ou 3, correspondendo às três colunas de aposta.
Faça um programa que leia um vetor com 13 números inteiros representando o gabarito oficial das
partidas. Em seguida, leia, para cada apostador, o nome do apostador (que deve ser único e
funcionar como seu identificador) e um vetor com 13 números inteiros representando suas
respostas. O programa deve garantir que não haja dois apostadores com o mesmo nome. Para cada
participante válido, o programa deve comparar suas respostas com o gabarito e calcular a
quantidade de acertos obtidos. Essas informações devem ser armazenadas durante a leitura dos
dados.
Após a leitura de todos os apostadores (no máximo 100), o programa deve apresentar um relatório
final mostrando, para cada nome de apostador, a quantidade total de acertos obtidos.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUMERO_MAXIMO 100
#define TAMANHO_NOME 100
#define NUMERO_JOGOS 13
void converteMaiuscula(char str[]){
    int i;
    for(i=0;str[i]!='\0';i++)
       str[i]=toupper(str[i]);
}
void limpaBuffer(){
    char c;
    do{
        c=getchar();
    }while(c!='\n');
}

int cadastro(char vNomes[][TAMANHO_NOME],int quantidade){
    int i,achou,t;
    char novoNome[TAMANHO_NOME];

    printf("Forneça o nom e:");
    fgets(novoNome,TAMANHO_NOME,stdin);
    t=strlen(novoNome);
    if(novoNome[t-1]=='\n')
        novoNome[t-1]='\0';
    else
        limpaBuffer(); 
    
    converteMaiuscula(novoNome);
    //verificando se o nome é único
    i=0;
    achou=0;
    while(i<quantidade && achou==0){
        if (strcmp(novoNome,vNomes[i])==0)
            achou=1;
        else
            i++;
    }
    if(achou==0){
        strcpy(vNomes[quantidade],novoNome);
        quantidade = quantidade + 1;
        
        
    }
    else
        printf("\nNome Repetido!!!\n");
        
   return quantidade;
}
void lerRespostas(int v[],int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        printf("Forneça a resultado 1, 2 ou 3 do %do. jogo:",i+1);
        scanf("%d",&v[i]);
        while(v[i]< 1 ||v[i]> 3){
            printf("Forneça a resultado 1, 2 ou 3 do %do. jogo:",i+1);
            scanf("%d",&v[i]);
        }
    }
}

int main(){
    char nomes[NUMERO_MAXIMO][TAMANHO_NOME];
    int gabarito[NUMERO_JOGOS],acertos[NUMERO_MAXIMO],respostas[NUMERO_JOGOS];
    int numeroCadastrados= 0,retorno,i,sair;
    //lendo o gabarito

    lerRespostas(gabarito,NUMERO_JOGOS);
    do{
        limpaBuffer();
        retorno=cadastro(nomes,NUMERO_MAXIMO,0);
        if(retorno!=numeroCadastrados){
            numeroCadastrados=retorno;
            lerRespostas(respostas,NUMERO_JOGOS);
            //conferir o cartao
            for(i=0;i<NUMERO_JOGOS;i++)
                if(gabarito[i]==respostas[i])
                    acertos[i]++;
        }
        if(numeroCadastrados<NUMERO_MAXIMO){
            printf("Deseja continuar comn o cadastro? 1-Sim e 2-Não:");
            scanf("%d",&sair);
           
        }
    }while(numeroCadastrados<NUMERO_MAXIMO && sair !=1)    ;

    for(i=0;i<numeroCadastrados;i++){
        printf("\n%s\n",nomes);
        printf("\n\n")
    }

    

}