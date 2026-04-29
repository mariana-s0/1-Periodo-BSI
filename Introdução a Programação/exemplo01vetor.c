/*Programa que tenha como entrada a nota de cada um dos 300 alunos de uma turma.
 Mostrar a média da turma e o número de alunos com nota maior ou igual a média*/

 #include <stdio.h>
 #define NUMERO_ALUNOS 300
 int main(){

    float vNotas[NUMERO_ALUNOS],media;
    int i,cont=0;

    for(i=0;i<NUMERO_ALUNOS;i++){
        printf("\nForneça a nota do %d:\n",i+1);
        scanf("%f",&vNotas[i]);
        media=media+vNotas[i];

    }

    media=media / NUMERO_ALUNOS;
    printf("\nMédia da turma = %.1f\n",media);

    //Verificando os alubos com nota >=media

    for(i=0;i<NUMERO_ALUNOS;i++){
        if(vNotas[i]>=media)
        cont++;
    } 
    printf("\nNúmero de alunos com nota >= média = %d\n",cont);
    return 0;
 }