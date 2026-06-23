#include <stdio.h>
#include <string.h>
#include "funcionario.h"
void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c!='\n');
}
int pesquisa(TFuncionario v[], int ultimaPos,int mat){
    int i;
    for(i=0;i<ultimaPos;i++){
        if(v[i].matricula==mat){
            return i;
        }
    }
    return -1;
}
int cadastrar(TFuncionario v[],int tamanho,int *ultimaPos){
    int mat,achou,i,t;
    if(*ultimaPos==tamanho-1){
        printf("\nVetor Cheio\n");
        return 0;
    }
    else{
        printf("Forneça a matrícula:");
        scanf("%d",&mat);
        //verificar se a matrícula já existe
        if(pesquisa(v,ultimaPos,mat)!=-1){
            (*ultimaPos)++;
            v[*ultimaPos].matricula=mat;
            printf("Forneça o nome:");
            limpaBuffer();
            fgets(v[*ultimaPos].nome,100,stdin);
            //verificando se tem algo no buffer de entrada
            t = strlen(v[*ultimaPos].nome);
            if(v[*ultimaPos].nome[t-1]=='\n')
                v[*ultimaPos].nome[t-1]='\0';
            else
                limpaBuffer();
            printf("Forneça o salário:");
            scanf("%f",&v[*ultimaPos].salario);
            return 1;
        }
        else    
            printf("\nMatrícula Repetida!!!\n");
            return 0;
    }
}

void listar(TFuncionario v[],int ultimaPos){
    int i;
    //verificando se tem pelo menos um funcionário cadastrado
    if(ultimaPos>=0){
        printf("\nFuncionários Cadastrados\n");
        for(i=0;i<=ultimaPos;i++){
            printf("Matrícula: %d\n",v[i].matricula);
            printf("Nome: %s\n",v[i].nome);
            printf("Salário: %.1f\n",v[i].salario);
        }
    }
    else
        printf("\nNenhum Funcionário Cadastrado!!!\n");
}
void consultar(TFuncionario v[],int ultimaPos){
    int mat,posicao;
    //verificando se tem pelo menos um funcionário cadastrado
    if(ultimaPos>=0){
       printf("\nForneça a matrícula:\n");
       scanf("%d",&mat);
       /*Verficando se a matricula foi encontrada*/
       posicao = pesquisa(v,ultimaPos,mat);
       if(posicao!=-1){
            printf("\nDados do Funcionário\n");
            printf("Matrícula: %d\n",v[posicao].matricula);
            printf("Nome: %s\n",v[posicao].nome);
            printf("Salário: %.1f\n",v[posicao].salario);
        }
        else
            printf("\nMatrícula Inexistente!!\n");
    }
    else
        printf("\nNenhum Funcionário Cadastrado!!!\n");

}
int excluir(TFuncionario v[],int *ultimaPos){
     int i,mat,posicao;
    //verificando se tem pelo menos um funcionário cadastrado
    if(*ultimaPos>=0){
       printf("\nForneça a matrícula:\n");
       scanf("%d",&mat);
       /*Verficando se a matricula foi encontrada*/
       posicao = pesquisa(v,*ultimaPos,mat);
       if(posicao!=-1){
        v[posicao]=v[*ultimaPos];
        /*Exclusão levando em consideração a relevância da ordem
        cronológica de inserção.
        for(i=posicao+1;i<=*ultimaPos;i++){
            v[i-1]=v[i];
        }*/
           return 1;
       }
        else{
            printf("\nMatrícula Inexistente!!\n");
            return 0;
        }
    } 
    else
        printf("\nNenhum Funcionário Cadastrado!!!\n");
        return 0;

}