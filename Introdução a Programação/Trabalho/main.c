#include <stdio.h>
#include "memoria.h"
#include "memoria.c"
#define TAMANHO_MEMORIA 30

int main(){
    int opcao;
    int memoria[TAMANHO_MEMORIA];
    int alocacoes[3],desperdicios[3];
    int pid,quantidade;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Exibir memória\n");
        printf("2 - Alocar processo (First Fit)\n");
        printf("3 - Alocar processo (Best Fit)\n");
        printf("4 - Alocar processo (Worst Fit)\n");
        printf("5 - Liberar processo\n");
        printf("6 - Compactar memória\n");
        printf("7 - Relatório da memória\n");
        printf("8 - Relatório de eficiência\n");
        printf("0 - Sair\n");

        printf("Escolha uma opção:");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:
                exibirMemoria(memoria,TAMANHO_MEMORIA);
                break;

            case 2:
                printf("Informe o PID:");
                scanf("%d",&pid);
                
                printf("Informe a quantidade:");
                scanf("%d",&quantidade);

                alocarFirstFit(memoria,TAMANHO_MEMORIA,pid,quantidade);
                break;

            case 3:
                printf("Informe o PID:");
                scanf("%d",&pid);
                
                printf("Informe a quantidade:");
                scanf("%d",&quantidade);

                alocarBestFit(memoria,TAMANHO_MEMORIA,pid,quantidade);
                break;

            case 4:
                printf("Informe o PID:");
                scanf("%d",&pid);
                
                printf("Informe a quantidade:");
                scanf("%d",&quantidade);

                alocarWorstFit(memoria,TAMANHO_MEMORIA,pid,quantidade);
                break;
                
            case 5:
                printf("Informe o PID:");
                scanf("%d",&pid);

                liberarProcesso(memoria,TAMANHO_MEMORIA,pid);
                break;

            case 6:
                compactarMemoria(memoria,TAMANHO_MEMORIA);
                break;
            
            case 7:
                relatorioMemoria(memoria,TAMANHO_MEMORIA);
                break;
            
            case 8:
                relatorioEficiencia(alocacoes,desperdicios);
                break;

            case 0:
                printf("Encerrando ...");
                break;

            default:
                printf("\nOpção Inválida !!\n");
        }

    } while(opcao!=0);

    return 0;
}