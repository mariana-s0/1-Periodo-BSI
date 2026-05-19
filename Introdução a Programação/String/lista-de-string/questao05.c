#include <stdio.h>
#include <stdlib.h>

int recebeString(char texto[], char letra){
    int aux=0,i=0;
    while(texto[i]!='\0'){
        if(texto[i]==letra){
            aux ++;
        }
        i++;
    }
    return aux;

}
int main (){
    char texto[10] ,letra; 

    printf ("\nDigite um texto :");
    fgets(texto,10,stdin);
    printf ("\nDigite uma letra :");
    scanf("%c",&letra);

    printf ("\nTotal de letras que aparece no texto : %d\n",recebeString(texto,letra));
    return 0;

}