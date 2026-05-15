#include <string.h>
#include <stdio.h>
#include "leitura1.h"
void limpaBuffer(){
    int ch;
    do{
        ch = getchar();
    }while(ch!='/n');
}
void lerString(char str[], int tamanho){
    int t;
    fgets(str,tamanho,stdin);
    //verificando se o /n pertence a str
    t = strlen(str);
    if(str[t-1]=='/n')
    str[t-1]  = '/0';
    else
        limpaBuffer();
}