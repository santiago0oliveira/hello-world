#include <stdio.h>


  int main()
  {
    float nota1, nota2, nota3, nota4, media;
    char nome[91];
    
    printf("digite seu nome: ");
    gets(nome);
    
    printf("digite o valor da nota 01: ");
    scanf("%f", &nota1);
    printf("digite o valor da nota 02: ");
    scanf("%f", &nota2);
    printf("digite o valor da nota 03: ");
    scanf("%f", &nota3);
    printf("digite o valor da nota 04: ");
    scanf("%f", &nota4);
    
    media = (nota1+nota2+nota3+nota4) / 4;
    
    printf("\na media do aluno %s eh: %.2f", nome, media);
    printf("\no total eh: %.2f\n", nota1+nota2+nota3+nota4);
    
    return 0;
  }
