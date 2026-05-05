/*Questão 03
Implemente uma função soma_media(int a, int b, int *soma, float *media)
que calcule a soma e a média de dois números inteiros. Os resultados devem ser retornados por
meio dos ponteiros.*/

#include <stdio.h>
void soma_media(int a, int b, int *soma, float *media){

       *soma = a+b;
       *media =(float)(a+b)/2; 
}
int main(){
    int a,b,valorSoma;
    float valorMedia;
    printf("\nForneça dois números inteiros :\n");
    scanf("%d %d",&a,&b);
    soma_media(a,b,&valorSoma,&valorMedia);
    printf("\nValor da soma =%d\n",valorSoma);
    printf("\nValor da média = %f\n",valorMedia);

    return 0;
}