#include <stdio.h>
//Esqueleto de Vetor
    int i;

    for(i = 0; i < N; i++)
    {
        // processar vetor
    }
//Contar alguma coisa
    int contador = 0;

    for(i = 0; i < N; i++)
    {
        if(condicao)
        {
            contador++;
        }
    }
//Somar alguma coisa
    int soma = 0;

    for(i = 0; i < N; i++)
    {
        soma += vetor[i];
    }
//Achar o maior
    int maior = vetor[0];

    for(i = 1; i < N; i++)
    {
        if(vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
//Procurar algo no vetor
    int posicao = -1;

    for(i = 0; i < tamanho; i++)
    {
        if(condicao)
        {
            posicao = i;
            break;
        }
    }
//Verificar nome repetido
    int repetido = 0;

    for(i = 0; i < quantidade; i++)
    {
        if(strcmp(nome, nomes[i]) == 0)
        {
            repetido = 1;
            break;
        }
    }
//Inicio de um Grupo
    if(vetor[i] > 0 &&(i == 0 || vetor[i-1] <= 0)){
        // começou um grupo
    }
//Percorrer um Grupo
    j = i;

    while(j < N && condicao)
    {
        // processa grupo

        j++;
    }
//Guardar vários resultados
    resultado[qtd] = valor;
    qtd++;
//Função com ponteiro
    void funcao(int *quantidade)
    {
        *quantidade = 10;
    }

    int qtd;

    funcao(&qtd);