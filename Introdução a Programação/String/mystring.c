
#include <ctype.h>
void converteMaiuscula(char str[]){
     int i;
     for(i=0;str[i]!='\0';i++){
        str=toupper(str[i]);
     }
}
void converteMinuscula(char str[]){
    int i;
     for(i=0;str[i];i++){
        str=tolower(str[i]);
     }
}