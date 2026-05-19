#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenar(char *destino, char *fonte){
    strcat(destino,fonte);
}
int main (){

    char str1[30], str2[10];

    printf("\nForneça a primeira palavra:\n");
    fgets(str1,30,stdin);

    printf("\nForneça a segunda palavra:\n");
    fgets(str2,10,stdin);

    concatenar(str2,str1);

    printf("\nPalavra concatenada : %s",str1);
    
    return 0;
}