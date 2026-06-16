/*Questão 04
Imagine uma matriz 5x5 que representa o mapa de um jogo simples. O número 0 representa o
caminho livre, o número 1 representa uma parede intransponível, e o número 2 representa a posição
inicial do nosso personagem. Faça um programa que:
• Inicialize a matriz estaticamente no código com um caminho válido e algumas paredes.
• 2. Peça para o usuário digitar um caractere para mover o personagem: 'W' (para cima), 'S'
(para baixo), 'A' (para esquerda) ou 'D' (para direita).
• 3. O programa deve calcular a nova posição. Se o movimento for em direção a uma parede
(1), exiba a mensagem "Colisão! Movimento inválido." e mantenha o personagem no mesmo lugar.
 Caso contrário, atualize a matriz (a posição antiga vira 0 e a nova vira 2) e mostre o mapa atualizado.*/

#include <stdio.h>
#define NL 4
#define NC 4
int main(){
    int labirinto[NL][NC]={{1,1,1,1},{1,0,0,1},{1,0,0,1},{0,0,1,1}};
    int linhaAtual=1,colunaAtual=2,novaLinha,novaColuna,lin,col;
    labirinto[linhaAtual][colunaAtual]=2;
    char direcao;
    do{
        printf("\nLabirinto Atual\n");
        for(lin=0;lin<NL;lin++){
            for(col=0;col<NC;col++){
                printf("%d\t",labirinto[lin][col]);
            }
            printf("\n");
        }
        printf("w-Para cima\ns-Para baixo\na-Para esquerda\nd-Para direita:\n");
        scanf(" %c",&direcao);
        if(direcao == 'w'){
            novaLinha = linhaAtual - 1;
            novaColuna = colunaAtual;
        }
        else
            if(direcao == 's'){
                novaLinha = linhaAtual + 1;
                novaColuna = colunaAtual;
            }
            else
                if(direcao == 'a'){
                    novaLinha = linhaAtual;
                    novaColuna = colunaAtual - 1;
                }
                else
                    if(direcao == 'd'){
                        novaLinha = linhaAtual;
                        novaColuna = colunaAtual +1;
                    }
        //Verificando se saiu do labirinto
        if(novaLinha == -1 || novaLinha == NL || novaColuna == -1 || novaColuna == NC){
            break;
        }
        //Verificando se é uma posição correta 
        if(labirinto[novaLinha][novaColuna]==0){
            labirinto[linhaAtual][colunaAtual]=0;
            labirinto[novaLinha][novaColuna]=2;
            linhaAtual= novaLinha;
            colunaAtual= novaColuna;
        }
        else
            printf("\nMovimento Impossivel!!\n");
    }while (1);
    printf("\nBingo você saiu do labirinto !!\n");
    
    return 0;
}