#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* transformaMinuscula(char texto[]){
    int i;
    for(i=0;texto [i] != '\n';i++){
        texto[i]=tolower(texto[i]);
    }
    return texto;
}

int main (){
    char texto[50];
    printf("\nForneça um nome :\n");
    fgets(texto,50,stdin);
    printf("\nNome fornecido : %s\n",transformaMinuscula(texto));
    return 0;
} 