/*Questão 10
Implemente uma função que calcule as raízes de uma equação do segundo grau ax² + bx + c = 0. A
função deve receber os coeficientes a, b e c e armazenar as raízes reais em dois ponteiros (x1 e x2).
Deve verificar se a ≠ 0 e se o Δ = b² − 4ac é maior ou igual a zero. A função deve retornar 1 se o
cálculo for possível e 0 se não houver raízes reais ou se não for uma equação do segundo grau.*/

#include <stdio.h>
#include "matematica.h" 
#include "leitura.h"

int main(){
    float a,b,c,r1,r2;
    a = lerFloat();
    b = lerFloat();
    c = lerFloat();

    if(equacao(a,b,c,&r1,&r2)== 1){
        printf("\nRaízes da Equação = %f e %f\n",r1,r2);
    
     } else {
            printf("\nNão foi possível calcular as raízes !!\n");
     }
    return 0;
}