#include <stdio.h>
#define TAM 15
int verificaIlhas(int vMapa[],int tamanho,int *maiorIlha,int *inicio,int *fim){
    int i,cont,numeroIlhas=0;
    *maiorIlha = -1;
    for(i=0;i<tamanho;i++){
        if(vMapa[i]==1){
            cont = 0;
            
            while(i<tamanho && vMapa[i]==1){
                i++;
                cont++;
            }
            //verificando se é uma ilha 
            if(cont>=3){
               numeroIlhas++;
               if(cont>*maiorIlha){
                  *maiorIlha = cont;
                  *fim = i-1;
                  *inicio = i-cont;
                  
               }
            }
        }
    }
    return numeroIlhas;
}
int main(){
    int mapa[TAM]={0,0,1,1,1,1,0,0,1,1,0,1,1,1,1},
    indiceInicio,indiceFim,maior,qtdeIlhas;
    qtdeIlhas = verificaIlhas(mapa,TAM,&maior,&indiceInicio,&indiceFim);
    if(qtdeIlhas>0){
       printf("\nNúmero de Ilhas = %d\n",qtdeIlhas) ;
       printf("\nComprimento da maior ilha = %d\n",maior);
       printf("\nInício da Ilha = %d e Fim = %d\n",indiceInicio,indiceFim);
    }
    else
        printf("\nNenhuma Ilha Encontrada!!!\n");
    return 0;
}
