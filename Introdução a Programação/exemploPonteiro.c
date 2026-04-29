#include <stdio.h>

int main(){
    int *ptr,a=100;

    printf("\nValo de a = %d\n",a);
    printf("\nEndereço de a = %p\n", &a);
    ptr = &a;
    printf("\nValor armazenado em ptr =%p\n",ptr);
    //a=5;
    *ptr = 5;
    printf("\nValo de a = %d\n",a);
    printf("\nValor da região de memória apontada por ptr = %d\n",*ptr);
    
    return 0;
}