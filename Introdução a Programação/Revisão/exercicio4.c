/*Exercício 04
Implemente uma função em linguagem C que seja responsável por ler os nomes de uma sequência
de apostadores e armazená-los em uma matriz de caracteres (strings). A função deve obedecer aos
seguintes requisitos:
1. Assinatura e Parâmetros: A função deve receber como parâmetros a matriz de strings onde
os nomes serão armazenados, o número máximo N de cadastros permitidos e uma variável
(passada por referência/ponteiro) que armazenará a quantidade real de nomes lidos com
sucesso.
2. Restrição de Unicidade: Para cada nome digitado pelo usuário, a função deve verificar se ele
já foi cadastrado anteriormente na matriz.
• Se o nome for repetido, o programa deve exibir uma mensagem de erro e solicitar
que o usuário digite um novo nome para aquela posição.
• Se o nome for único, ele deve ser aceito e armazenado.
3. Condição de Parada: A leitura deve ser interrompida quando o limite máximo N for atingido
ou quando o usuário digitar uma condição de parada específica (por exemplo, a palavra
"FIM" ou responder "Não" a uma pergunta de continuidade).*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUMERO_MAXIMO 100
#define TAMANHO_NOME 100
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

/*void cadastro(char vNomes[][TAMANHO_NOME],int tamanho,int *quantidade){
    int sair,i,achou,t;
    char novoNome[TAMANHO_NOME];
   do{
        printf("Forneça o nome:");
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
        while(i<*quantidade && achou==0){
            if (strcmp(novoNome,vNomes[i])==0)
                achou=1;
            else
                i++;
        }
        if(achou==0){
            strcpy(vNomes[*quantidade],novoNome);
            *quantidade = *quantidade + 1;
            //(*quantidade)++;
        }
        else
            printf("\nNome Repetido!!!\n");
        if(*quantidade<tamanho){
            printf("Deseja continuar com o cadastro? 1-Sim e 2-Não:");
            scanf("%d",&sair);
            limpaBuffer();
        }
   }while(sair==1);
}*/
int cadastro(char vNomes[][TAMANHO_NOME],int tamanho,int quantidade){
    int sair,i,achou,t;
    char novoNome[TAMANHO_NOME];
   do{
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
            //(*quantidade)++;
        }
        else
            printf("\nNome Repetido!!!\n");
        if(quantidade<tamanho){
            printf("Deseja continuar comn o cadastro? 1-Sim e 2-Não:");
            scanf("%d",&sair);
            limpaBuffer();
        }
   }while(sair==1);
   return quantidade;
}

int main(){
    char nomes[NUMERO_MAXIMO][TAMANHO_NOME];
    int numeroCadastrados= 0,i;
    numeroCadastrados=cadastro(nomes,NUMERO_MAXIMO,0);
    printf("\nNomes Cadastrados\n");
    for(i=0;i<numeroCadastrados;i++)
        printf("%s\n",nomes[i]);

}
