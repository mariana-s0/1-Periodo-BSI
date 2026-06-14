/*O Resort Sample The Best, localizado na charmosa cidade de Alvinopolis, é administrado
pelo carismático empresário Johnes Cota.O resort é famoso por sua estrutura gigantesca e, 
por isso , não há limite de quartos, ou seja, todos os hóspedes são acomodados confortavelmente!
Johnes Cota, que adora números e estátisticas, quer descobrir qual(is) dia(s) ,ao ano o resort fica
mais cheio.Ele contratou você, uma mente brilhante da programação,para resolver esse desafio.
Como funciona
Cada hóspede,ao fazer a reserva,informa:
    O dia de entrada(check-in)
    O dia de saída(check-out)
Regra importante:O dia de sáida snão conta como Hospedagem - o hóspede desocupa o quarto logo
pela manhã.
Exemplo:Um hóspede que entra no dia 5 e sai no dia 10 ocupa os dias:5,6,7,8 e 9.O dia 10 já está livre 
para outro hóspede.
O ano tem 365 dias (Considere 1° de janeiro = dia 1, 31 de dezembro = dia 365).Todas as reservas acontecem dentro
do mesmo ano (nada de viagem no tempo!)
Sua missão
    Criar um programa que, dados todas as reservas do ano, diga qual(is) dia(s) o resort teve o maior número de hóspedes
    simultaneamente.
    Entrada:
        Um número inteiro N(1<N<1000),representando a quantidade de reservas
        Em seguida,N linhas,cada uma com dois inteiros:entrada e saida(1<entrada<saida<365)
    Saida:
        Os dias (em ordem crescente) que tiveram a maior ocupação,um por linha.
        Dica de Johnes Cota:
        Se mais de um dia tiver a mesma ocupação máxima,quero ver todos eles!Não quero perder nenhum dia de glória do meu resort!*/

#include <stdio.h>
#define TAM_MAX 365

void ocupacaoMaxima(int ocupacoes[TAM_MAX],int tamanho){
    int j,//Percorre o vetor de ocupações
        maior=0;//Encontra o(s) dia(s) com mais ocupação(ões)

    for(j=0;j<tamanho;j++){
        if(ocupacoes[j]>maior){
            maior=ocupacoes[j];
        }
    }
    for(j=0;j<tamanho;j++){
        if(ocupacoes[j]==maior){
            printf("\nOcupação(ões) máxima(s): %d\n",j);
        }
    }
    return ;
}
int main(){
    int reservas,//Número de reservas feitas
        i,//Loop de reservas
        entrada,//Dias de entrada
        saida,//Dias de saída
        cont,//Contador de ocupações
        ocupacoes[TAM_MAX]={0 };//Vetor de ocupações

        printf("\nForneça o número de reservas:\n");
        scanf("%d",&reservas);

        for(i=0;i<reservas;i++){
            printf("\nForneça o dia de entrada:\n");
            scanf("%d",&entrada);
            printf("\nForneça o dia de saída:\n");
            scanf("%d",&saida);

            for(cont=entrada;cont<saida;cont++){
                ocupacoes[cont]++;
            }
        }
        ocupacaoMaxima(ocupacoes,TAM_MAX);

    return 0;
}