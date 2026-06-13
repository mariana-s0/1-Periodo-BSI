/*O prefeito Johnes Cota recebeu uma mapa topográfico da região de Alvinópolis representado por um
vetor de N números inteiros. Cada número representa a altitudade do terreno em metros . O mapa pode
ter até 10.000 posições (N<=10.000).
Definições:
    Terra:altitude:>0
    Água:altitude<=0
    Ilha:sequencia contigua de valores >0 cercada por agua (<=0)
Regras:
    Ilhas são separadas por pelo menos uma posição de água(<=0)
    Uma ilha pode ser formada por apenas 1 ponto de terra
    Duas ilhas não podem se tocar(Sempre ha agua entre elas)
O prefeito quer resolver tres problemas sobre o mapa.Você deve implementar todas as funções solicitadas.
Entrada :
N
altura1,altura2 ... alturaN
Saída:
NUMERO DE ILHAS : X
MAIOR ALTURA MAXIMA: Y (posicoes:p1,p2)
ILHAS SUPERIORES::Q(inicio:il,i2... fim fl,f12)
Observação : Se não houver ilhas superiores, exibir apenas ILHAS SUPERIORES :0(sem os parênteses)
Implemente as funções:
int contarIlhas(int mapa[],int N);
    Que retorna o número total de ilhas no mapa.
int maiorAlturaMaxima(int mapa[],int N,int posicoes[],int *tamanhoVetor);
    Retorna o valor da maior altitude máxima dentre todas as ilhas
    Preenche o vetor posicoes com os indices de inicio de TODAS as ilhas que possuem essa altitude maxima
    Preenche tamanhoVetor(por referencia) com a quantidade de posições preenchidas 
int ilhasSuperiores(int mapa[],int N,int posicoesInicio[],int posicoesFim[]);
Uma ilha é considerada superior se sua altura média (soma das altura/tamanho)for maior que 5 e seu tamanho por pelo menos 3.
    Preenche posicoesInicio com os indices de inicio das ilhas superiores 
    Preenche posicoesFim com os indices de fim(ultimo elemento da ilha) correspondentes
    Retorna a quantidade de ilhas superiores encontradas 
*/

#include <stdio.h>
#define TAM_MAX 10000
int contarIlhas(int mapa[TAM_MAX],int N){
    int cont,//Contador do tamanho do mapa
    ilhas=0;//Contador para o número de ilhas encontradas
    for(cont=0;cont<N;cont++){
        if(mapa[cont] > 0 && (cont == 0 || mapa[cont-1] <= 0)){
            ilhas++;
        }
    }
    return ilhas;
}
int maiorAlturaMaxima(int mapa[],int N,int posicoes[],int *tamanhoVetor){
    int cont,//Contador do tamanho do mapa
        j,//Contador Auxiliar
        maiorGlobal=0,//Verificando qual é a maior ilha
        maiorIlha,//Maior ilha encontrada
        inicio;//Indice de inicio da ilha

        *tamanhoVetor=0;

    for(cont=0;cont<N;cont++){
        if(mapa[cont] > 0 && (cont == 0 || mapa[cont -1] <=0)){
            inicio = cont;
            maiorIlha =  mapa[cont];
            j = cont;
            while(j < N && mapa[j] > 0){
                if(mapa[j] > maiorIlha){
                    maiorIlha = mapa[j];
                }
                j++;
            }
            if(maiorIlha>maiorGlobal){
                maiorGlobal = maiorIlha;

                *tamanhoVetor=0;
                posicoes[*tamanhoVetor]=inicio;
                (*tamanhoVetor)++;
            }
            else
                if(maiorIlha == maiorGlobal){
                    posicoes[*tamanhoVetor]=inicio;
                    (*tamanhoVetor)++;
            }
        }
    }
    return maiorGlobal;
}
int ilhasSuperiores(int mapa[],int N,int posicoesInicio[],int posicoesFim[]){
    int qtdIlhasS=0,//Quantidade de Ilhas Superiores
        cont;//Contador do tamanho da ilha
    float media;//Media da ilha
        for(cont=0;cont<N;cont++){
            if(mapa[cont] > 0 && (cont == 0 || mapa[cont - 1] <=0)){
                int soma = 0,
                    tamanho = 0,
                    inicio = cont,
                    fim,
                    j = cont;
                    while(j < N && mapa[j] > 0){
                        soma += mapa[j];
                        tamanho++;
                        j++;
                    }
                    fim = j-1;

                    media=(float)soma/tamanho;

                    if(tamanho >= 3 && media > 5){
                        posicoesInicio[qtdIlhasS]=inicio;
                        posicoesFim[qtdIlhasS]=fim;

                        qtdIlhasS++;
                    }
                    cont = j - 1 ;
            }
        }
    return qtdIlhasS;
}
int main (){
    int mapa[TAM_MAX],//Mapa da ilha
        pos[TAM_MAX],//Indice Inicio e Fim de TODAS as ilhas com altitude maxima
        posI[TAM_MAX],//Posição de Inicio
        posF[TAM_MAX];//Posição de Fim
    int tamVetor,//Quantidade de posições preenchidas
        n,//Tamanho do mapa
        total,//Número de ilhas
        i,//Contador tamanho do mapa
        alturaMaxima,//Maior Altura maxima encontrada
        ilhaSuperior;//Recebe ilhas superiores

    printf("\nForneça o tamanho do mapa :\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nForneça a altitude da posição %d do mapa : (Terra: altitude > 0\nÁgua: altitude <= 0)\n",i);
        scanf("%d",&mapa[i]);
    }

    total=contarIlhas(mapa,n);
    alturaMaxima=maiorAlturaMaxima(mapa,n,pos,&tamVetor);
    ilhaSuperior=ilhasSuperiores(mapa,n,posI,posF);

    printf("\nQuantidade de ilhas : %d\n",total);
    printf("\nMaior altura máxima : %d\n",alturaMaxima);
    printf("\nPosições :\n");
    for(int i=0;i<tamVetor;i++){
        printf("%d\n",pos[i]);
    }
    printf("\nQuantidade de Ilhas Superiores : %d\n",ilhaSuperior);

    return 0;
}