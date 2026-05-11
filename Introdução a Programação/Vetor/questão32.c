/*Questão 32
Implemente uma função que receba como parâmetros dois vetores de números inteiros e seus 
respectivos tamanhos. O objetivo da função é identificar se o primeiro vetor (denominado subvetor) 
está integralmente contido dentro do segundo vetor (vetor geral). Para que a presença seja validada, 
os elementos do subvetor devem aparecer no vetor geral exatamente na mesma sequência e de 
forma consecutiva. A função deve retornar um valor booleano ou inteiro (1 para verdadeiro e 0 para 
falso) indicando o sucesso da busca. No programa principal, o usuário deve inserir os dados de 
ambos os vetores, e o resultado da verificação deve ser exibido de forma clara na saída padrão.*/

#include <stdio.h>
#define TAMANHO 10

int verificaPadrao(int vetOriginal[], int tamOriginal,int subVetor[],int tamSub){
    int i,k,cont;
    for(i=0;i<=tamOriginal-tamSub;i++){
        cont=0;
        for(k=0;k<tamSub;k++){
            if(vetOriginal[i+k]==subVetor[k]){
                cont++;
            }else
                break;
        }
        //Verificando se o padrão foi encontrado
        if(cont==tamSub)
        return 1;
    }
    return 0;
}

int main(){
    
    return 0;
}