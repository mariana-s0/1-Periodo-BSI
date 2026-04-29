#include <stdio.h>
#define NUMEROS 10
 int main(){
    int vNumero[NUMEROS];
    int i;

    for(i=0;i<=NUMEROS;i++){
        printf("\nForneça o número %d \n",i+1);
        scanf("%d",&vNumero[i]);
    }
    for(i=NUMEROS-1;i>=0; i--){
        printf("\n%d",vNumero[i]);
    }
    return 0;
 }