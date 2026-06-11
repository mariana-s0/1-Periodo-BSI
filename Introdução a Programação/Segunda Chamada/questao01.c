/*Dia de entrada , dia de saída, vetor de 365 dias, quantidade de reservas,dia(s) com mais reserva*/
#include <stdio.h>
#define TAM 366
void reservas(int dias[],int tamanho){
    int i,maior=0;
    for(i=0;i<tamanho;i++){
        if(dias[i]>maior){
            maior=dias[i];
    }
    }
        for(i=0;i<tamanho;i++){
            if(dias[i]==maior){
                printf("\nDia(s) com mais reservas :%d\n",i);
            }
        }
    return;
}
int main(){
    int cont,i,
    qtdReservas,
    entrada,saida,
    dias[TAM]={0};
    printf("\nForneça a quantidade de reservas a ser feita :\n");
    scanf("%d",&qtdReservas);
    for(cont=0;cont<qtdReservas;cont++){
        printf("\nForneça o dia de entrada:\n");
        scanf("%d",&entrada);
        printf("\nForneça o dia de saída:\n");
        scanf("%d",&saida);
        for(i=entrada;i<saida;i++){
            dias[i]++;
        }
    }
    reservas(dias,TAM);
    return 0;
}