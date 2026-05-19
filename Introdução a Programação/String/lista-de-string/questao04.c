#include <stdio.h>
#include <string.h>

int comparaString (char str1[], char str2[]){
    int i =0;
    while(str1[i] != '\0' || str2[i] !='\0'){
        if(str1[i] != str2[i]){
            return 1;
        }
            i++;
    }
    return 0;
}
int main (){
    char str1[10],str2[10];
    printf("\nDigite a primeira palavra:\n");
    fgets(str1,10,stdin);
    printf("\nDigite a segunda palavra:\n");
    fgets(str2,10,stdin);


    int resultado = comparaString(str1,str2);

    if(resultado == 0){
        printf ("\nSão iguais !!\n");
    }else
        printf("\nSão diferentes !!\n");

    return 0;
}