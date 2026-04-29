#include <math.h>
#include "matematica.h"
 int equacao(float a, float b, float c, float *raiz1, 
    float *raiz2){
    int delta;
    if(a!=0){
        delta= pow(b,2)-4*a*c;
            if(delta>=0){
                *raiz1=(-b+sqrt(delta))/(2*a);
                *raiz2=(-b-sqrt(delta))/(2*a);
                return 1;
            }
            else
                return 0;
    }
    else 
        return 0;
}
int soma(int a, int b){
    return a + b;
}

int fatorial(int n){
    int i,fat=1;
    if(n<0)
        return -1;
    else{
        //GERANDO OS NÚMEROS INTEIROS DE 1 A N
        for(i=1;i<=n;i++){
            fat*=i;
        }
        return fat;
    }    
}

int numeroArranjos(int n , int s){
    if(n<s || n<=0 || s<=0)
        return -1;
 
     return fatorial(n)/fatorial(n-s);
}