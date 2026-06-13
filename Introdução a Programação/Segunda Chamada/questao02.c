/*Na bela cidade de Alvinópolis , foi criado o jogo AlvinoPlay - um campeonato individual que tomou conta da cidade.
 O prefeito Johnes Cota, em seus 30 anos de mandato(primeiro mandato até hoje) , sempre fez questão de acompanhar 
 semanalmente os melhores jogadores.
 A Secretaria de Esportes mantém , toda semana , uma lista com N jogadores mais bem ranqueados (N varia de 1 a 10 ,
  dependendo da semana).A pontuação é distribuída assim :
  1° Lugar : 10 pontos
  2° Lugar : 9 pontos
  3° Lugar : 8 pontos
  ...
  10° Lugar : 1 ponto
  Se a lista tiver menos de 10 jogadores (ex:apenas 5) os pontos valem a mesma regra 1°:10 pontos,2°:9 pontos ... 5°:6 pontos
  Problema : O estágiário resposável , chamado desatento total , vive enviando listas com nomes duplicados. Você não pode
  aceitar nomes repetidos da mesma lista semanal . Se houver duplicata você deve ignorar a ocorrência repetida (e pedir outro nome
  , até que ele forneça um nome diferente dos já fornecidos).
  Regras importantes :
  AlvinóPolis não possui dois jogadores com o mesmo nome (nomes únicos na cidade) 
  Você tem os dados de todas as semanas dos últimos 30 anos
  O prefeito quer saber : qual(is) jogador(es) acumulou(aram) mais pontos ao longo da história de AlvinoPlay?
  Entrada:
    Um inteiro S(1<S<1560), representando o número de semanas 
    Para cada semana :
    Um inteiro N(1<N<10), representando o número de jogadores daquela semana
    Em seguida N nomes (até 100 caracteres cada)
 Saída:
    Se houver um único vencedor :
    VENCEDOR : <nome>
    PONTOS : <total>
    Se houver empate :
    EMPATE
    PONTOS : <total>
    JOGADORES : <nome1>,<nome2>,<nome3>,...*/
#include <stdio.h>
#include <string.h>
#define TAM_MAX 1560
#define NOME_MAX 100

void comparaNomes(int qtdSemanas, char nomeTemporario[], char nomeUnico[][NOME_MAX], int tamanho){
    int cont,//Contador de semanas;
        numJogadores,
        i,//Contador de jogadores;
        repetido = 0,//Verifica se existe nome repetido
        j,//Percorre o vetor de nome e verifica de é repetido;
        qtdJogadores = 0,//Conta a quantidade de jogadores válidos;
        posicao = -1 ,//Posicao em que está o nome e os pontos;
        pontos[TAM_MAX]={0};//Pontuação;
        
    
    char nomeTp[NOME_MAX],nomeDiferente[TAM_MAX][NOME_MAX],
        jogadores[TAM_MAX][NOME_MAX];

    for(cont=0;cont<qtdSemanas;cont++){

        printf("\nForneça o número de jogadores da semana:\n");
        scanf("%d",&numJogadores);

        for(i=0;i<numJogadores;i++){
            repetido=0;
            limpaBuffer();
            printf("\nForneça o nome do %d° jogador:\n",i);
            fgets(nomeTp,NOME_MAX,stdin);
            nomeTp[strcspn(nomeTp, "\n")] = '\0';
            for(j=0;j<i;j++){
                if(strcmp(nomeTp,nomeDiferente[j])==0){
                    repetido=1;
                    break;
                }
            }
            while(repetido == 1){
                printf("\nNome repetido ! Digite outro :\n");
                fgets(nomeTp,NOME_MAX,stdin);
                nomeTp[strcspn(nomeTp, "\n")] = '\0';
                repetido = 0;

                for(j=0;j<i;j++){
                    if(strcmp(nomeTp,nomeDiferente[j])==0){
                        repetido = 1;
                        break;
                    }
                }
            }
                strcpy(nomeDiferente[i],nomeTp);
                posicao = -1;
                for(j=0;j<qtdJogadores;j++){
                    if(strcmp(nomeTp,jogadores[j])==0){
                        posicao = j;
                        break;
                    }
                }
                if(posicao == -1){
                    strcpy(jogadores[qtdJogadores],nomeTp);
                    pontos[qtdJogadores]= 10 - i;
                    qtdJogadores++;
                }
                else{
                    pontos[posicao] += (10-i);
                }
        }
    }
    int maior = 0,//Verifica qual é a maior pontuação;
        empate = 0;//Verifica se houve empate;

    for(i=1;i<qtdJogadores;i++){
        if(pontos[i]>maior){
            maior = pontos[i];
        }
    }
    for(i=0;i<qtdJogadores;i++){
        if(pontos[i]==maior){
            empate++;
        }
    }
    if(empate == 1){
        for(i=0;i<qtdJogadores;i++){
            if(pontos[i]==maior){
                printf("\nVENCEDOR: %s\n",jogadores[i]);
                printf("\nPONTOS: %d\n",maior);
                break;
            }
        }
    }
    else {
            printf("\nEMPATE\n");
            printf("\nPONTOS: %d\n",maior);
            printf("\nJOGADORES:\n");
                for(i=0;i<qtdJogadores;i++){
                    if(pontos[i]==maior){
                        printf("\n%s\n",jogadores[i]);
                    }
                }
        }

    return;
}
void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c!= EOF);
}
int main(){
    int semanas;
    char nomeTp[NOME_MAX],nomesUnicos[TAM_MAX][NOME_MAX];
    printf("\nForneça o número de semanas:\n");
    scanf("%d",&semanas);

    comparaNomes(semanas,nomeTp,nomesUnicos,NOME_MAX);

    return 0;
}