/*Programa que tenha como entrada a nota de cada um dos 3 alunos de uma turma.
 Mostrar a média da turma e o número de alunos com nota maior ou igual a média*/

 #include <stdio.h>
 int main(){
    float nota1,nota2,nota3,media;
    int cont=0;
    printf("\nForneça as três notas:\n");
    scanf("%f %f %f, &nota1,&nota2,&nota3");
    media=(nota1+nota2+nota3)/3;
    printf("\nMédia da turma = %.1f\n",media);

    if(nota1>=media) cont++;
    if(nota2>=media) cont++;
    if(nota3>=media) cont++;
    
    printf("\nNúmero de alunos com nota >= média = %d\n",cont);
    return 0;
 }