void exibirMemoria(int memoria[], int tamanho){
    int livres = 0,ocupados = 0;

    //Percorre o vetor memória
    for(int i = 0; i < tamanho; i++){
        printf("[%d] ",memoria[i]);

        //Verificando se existe espaço livre
        if(memoria[i] == 0){
            livres++;
        }else
            ocupados++;
    }
    printf("\nQuantidade de blocos livres : %d\n",livres);
    printf("\nQuantidade de blocos ocupados : %d\n",ocupados);

}
//Função para verificar se existe um PID
int verificaPID(int memoria[],int tamanho,int pid){
    //Percorre o vetor memória , e retorna 1 se o PID for existente
    for(int i = 0; i < tamanho ; i++){
        if(memoria[i] == pid){
            return 1;
        }
    }
    return 0;
}

int alocarFirstFit(int memoria[],int tamanho,int pid,int quantidade){
    int blocosLivres = 0, totalLivres = 0;
    //Percorre o vetor de memória , verfica se o PID já existe , incrementa TotalLivres se necessário
    for(int i = 0; i < tamanho ; i++){
        if(verificaPID(memoria,tamanho,pid) == 1){
            printf("PID já existente");
            return 0;
        }
        if(memoria[i] == 0){
            totalLivres++;
        }
    }

    if(totalLivres < quantidade){
        printf("\nEspaço Insuficiente\n");
        return 0;
    }
    //Percorre o vetor , incrementa blocosLivres
    for(int i = 0; i < tamanho ; i++){
        if(memoria[i] == 0){
            blocosLivres++;
        } else{
            blocosLivres = 0;
        }

        if(blocosLivres == quantidade){
            int inicio = i - quantidade + 1;
            //Procura o primeiro bloco consecutivo válido e atribui PID
            for(int j = inicio; j <= i; j++){
                memoria[j] = pid;
            }

            printf("Processo alocado com sucesso\n");
            return 1;
        }
    }

    printf("Fragmentacao externa\n");
    return 0;
}

int alocarBestFit(int memoria[],int tamanho,int pid,int quantidade){

    

}
int alocarWorstFit(int memoria[],int tamanho,int pid,int quantidade){
        

}

int liberarProcesso(int memoria[],int tamanho,int pid){
       

}

void compactarMemoria(int memoria[],int tamanho){
        

}

void relatorioMemoria(int memoria[],int tamanho){
      

}

void relatorioEficiencia(int alocacoes[],int desperdicios[]){
     

}

int maiorBlocoLivre(int memoria[],int tamanho){

}

int contarFragmentos(int memoria[],int tamanho){

}

int buscarPID(int memoria[],int tamanho,int pid){

}