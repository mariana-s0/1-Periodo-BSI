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
    #define TAM_MAX 1560
    #define NOME_MAX 100
    #define PONTOS_MAX 1560
    void alvinoPlay(int semanas,int tamanho,char nomeUni[NOME_MAX][TAM_MAX]){
        int i,//Contador de semanas
            numJog,//Numero de jogadores
            j,//Contador de jogadores
            repetido,//Verifica se tem repetido 
            n,//Contador de nomes
            posicao=-1,//Posição em que está o nome e os pontos
            qtdJog,//Quantidade de jogadores
            pontos[PONTOS_MAX];//Pontos Máximos
        char nomeGeral[NOME_MAX],jogadores[NOME_MAX][TAM_MAX];
        for(i=0;i<semanas;i++){
            printf("\nForneça o número de jogadores:\n");
            scanf("%d",&numJog);
            for(j=0;j<numJog;j++){
                repetido=0;
                limpaBuffer();
                printf("\nForneça o nome do %d jogador :\n",j);
                fgets(nomeGeral,NOME_MAX,stdin);
                for(n=0;n<j;n++){
                    if(strcmp(nomeGeral,nomeUni[n])==0){
                        repetido=1;
                        break;
                    }
                }
                while(repetido == 1){
                    printf("\nNome repetido! Forneça um nome válido:\n");
                    fgets(nomeGeral,NOME_MAX,stdin);
                    repetido=0;
                    for(n=0;n<j;n++){
                        if(strcmp(nomeGeral,nomeUni[n])==0){
                            repetido=1;
                            break;
                        }
                    }
                }
                strcpy(nomeUni[j],nomeGeral);
                posicao=-1;
                for(j=0;j<qtdJog;j++){
                    if(strcmp(nomeGeral,jogadores[n])==0){
                        posicao=n;
                        break;
                    }
                }
                if(posicao == -1){
                    strcpy(jogadores[qtdJog],nomeGeral);
                    pontos[qtdJog]=10-j;
                    qtdJog++;
                }
                else{
                        pontos[posicao] += (10-j);
                }
            }
        }
        int maior =0,//Verifica qual é a maior pontuação;
            empate =0;//Verifica se houve empate;
        for(int i=0;i<qtdJog;i++){
            if(pontos[i]>maior){
                maior=pontos[i];
            }
        }
        for(int i=0;i<qtdJog;i++){
            if(pontos[i]==maior){
                empate++;
            }
        }
        if(empate ==1){
            for(int i=0;i<qtdJog;i++){
                if(pontos[i]==maior){
                    printf("\nVENCEDOR: %s\n",jogadores[i]);
                    printf("\nPONTOS: %d\n",maior);
                    break;
                }
            }
        }
        else{
            printf("\nEMPATE\n");
            printf("\nPONTOS: %d\n",maior);
            printf("\nJOGADORES:\n");
            for(int i=0;i<qtdJog;i++){
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
        char nomeUnico[NOME_MAX][TAM_MAX];

        printf("\nForneça o número de semanas:\n");
        scanf("%d",&semanas);

        alvinoPlay(semanas,TAM_MAX,nomeUnico,NOME_MAX);

        return 0;
    }