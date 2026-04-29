#include <stdio.h>
#define QUANTIDADE_NOTAS 80
#define NOTA_MAXIMA 10

int main(){
    int vFrequencia[NOTA_MAXIMA+1],nota,i;
        for(i=1;i<=QUANTIDADE_NOTAS;i++){
            printf("\nForneça a %da. nota de 0 a 10:\n",i);
            scanf("%d",&nota);
    
            while(nota<0 || nota>NOTA_MAXIMA){
                printf("\nNota Incorreta !!\n");
                printf("\nForneça a %da. nota de 0 a 10:\n",i);
                scanf("%d",&nota);
            }
             vFrequencia[nota]++;
        }
       printf("\nFrequencia de cada nota\n");
       printf("Nota\t\ Frequencia");

    return 0;
}