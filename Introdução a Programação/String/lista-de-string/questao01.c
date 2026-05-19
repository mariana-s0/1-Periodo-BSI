#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* transformaMaiuscula(char texto[]){
    int i;
    for(i=0;texto [i] != '\n';i++){
        texto[i]=toupper(texto[i]);
    }
    return texto;
}

int main (){
    char texto[50];
    printf("\nForneça um nome :\n");
    fgets(texto,50,stdin);
    printf("\nNome fornecido : %s\n",transformaMaiuscula(texto));
    return 0;
} 