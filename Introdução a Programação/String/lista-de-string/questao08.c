#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenarLimitado(char *destino, char *fonte, int n){
    int i = 0;
    while (destino[i] != '\0') {
        *destino++;
    }
  
    while (i < n && *fonte != '\0') {
        *destino = *fonte;
        destino++;
        fonte++;
        i++;
    }
    *destino = '\0';
}

int main (){
    char str1[30],str2[10];
    int n ;

    printf("\nForneça a primeira palavra:\n");
    fgets(str1,30,stdin);

    printf("\nForneça a segunda palavra:\n");
    fgets(str2,10,stdin);
    
    printf("\nForneça o número máximo de caracteres :\n");
    scanf("%d",&n);

    concatenarLimitado(str1,str2,n);

    printf("\nPalavra concatenada : %s\n",str1);

    return 0;
}