#include <stdio.h>
/*Função que calcula a área e o perímetro de uma superfície retangular.*/
    double calculaAreaPerimetro(double base, double altura , double *area, double *perimetro){
        if(base<=0 || altura<=0)
            return -1.0;
        else{
            *area = base * altura;
            *perimetro = 2*base + 2*altura;
             return 1.0;
        }
           
    }
int main(){
    double b,a,res,valorArea,valorPerimetro;
    printf("\nForneça as medidas da base e altura:\n");
    scanf("%lf %lf",&b,&a);
    res = calculaAreaPerimetro(b,a,&valorArea,&valorPerimetro);
    if(res!= -1.0){
        printf("\nValor da área =%lf\n",valorArea);
        printf("\nValor do perímetro =%lf\n",valorPerimetro);
    }
    else
        printf("\nMedidas incorretas !!\n");
    return 0;
}