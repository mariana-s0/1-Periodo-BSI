#include <stdio.h>
#include <string.h>

int calculaTamanhoString(char texto[]){
    return strlen(texto);
}

int main (){
    char texto[51];
    printf("\nForneça um texto :\n");
    fgets(texto,51,stdin);

    texto[strcspn(texto,"\n")] = '\0';


    printf("\nTamanho : %d\n",calculaTamanhoString(texto));
    return 0;
}