/*Questão 09
Implemente uma função  que copie caracteres de origem para destino a partir de posInicio. O
destino deve ser finalizado com \0 e presume-se que tenha espaço suficiente. A função retorna 1
para sucesso ou 0  posInicio for inválido (negativo ou além do tamanho da string) ou qtde for menor
ou igual a zero. Caso qtde exceda o limite da string original, deve-se copiar os caracteres
disponíveis até o fim, retornando sucesso. 
int copiarSubstring(char *destino, char *origem, int posInicio, int qtde)*/

#include <stdio.h>
#include <string.h>

    int copiarSubstring(char *destino, char *origem, int posInicio, int qtde){
        int i,tam;
        tam=strlen(origem);
        if(posInicio < 0 || posInicio >= tam || qtde <= 0){
            return 0;
        }
        for(i = 0; i < qtde && origem[posInicio + i] != '\0'; i++){
            destino[i] = origem[posInicio + i];
        }
        destino[i] = '\0';
        return 1;

    }
    int main(){

        char origem[30],destino[15];
        int qtde,posInicio,i;

        printf("\nForneça a palavra origem :\n");
        fgets(origem,30,stdin);


        for(i=0;origem[i] != '\0';i++){
            if(origem[i] == '\n'){
                origem[i] = '\0';
                break;
            }
        }
        printf("\nForneça a quantidade :\n");
        scanf("%d",&qtde);

        if(copiarSubstring(destino,origem,posInicio,qtde)){
            printf("\nSubstring copiada : %s\n",destino);
        }else
            printf("\nErro ao copiar substring\n");
        return 0;
    }

