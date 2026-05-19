#include <stdio.h>
#include <stdlib.h>

void apagaString(char texto[],char letra){
    int j=0, i=0;
    while(texto[i]!='\0'){
        if(texto[i]!=letra){
            texto[j] = texto[i];
            j++;
        }
        i++;
    }
    texto[j]= '\0';

}

int main (){
char texto[10] ,letra; 

    printf ("\nDigite um texto :");
    fgets(texto,10,stdin);
    printf ("\nDigite uma letra :");
    scanf("%c",&letra);

    apagaString(texto,letra);

    printf ("\nNova palavra: %s\n",texto);
    return 0;

}