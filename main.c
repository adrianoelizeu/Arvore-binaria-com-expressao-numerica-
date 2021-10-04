#include <stdio.h>

/*Ilustre uma árvore que represente a seguinte expressão matemática ((10+21)*4−4)/(30−9)+3 (atenção, considere a estrutura de parênteses). Implemente uma função que realize o cálculo de seu valor resultante */


typedef struct arvore{
  char op;
  int n;                        //Árvore binaria
  struct arvore *esquerda, *direita;
} Arvore;


int funcao_calculo(Arvore *a){ //Função para o cáculo da árvore
  int x,y, soma;
  if (a->esquerda == NULL){
    return a->n;
  }
  if(a->direita == NULL){
    return a->n;
  }
  else{
    x = funcao_calculo(a->esquerda);
    y = funcao_calculo(a->direita);
    switch (a->op) {
    case '+': soma = x + y; break;
    case '-': soma = x - y; break;
    case '*': soma = x * y; break;
    case '/': soma= x / y; break;
    case ')': soma = y; break;
    case '(': soma = x; break;
  }
  }
  return soma;
}

int main(){

  Arvore no[19] = {

    {'/',0, &no[1], &no[2]}, 

    {'*',0, &no[3], &no[4]}, 
    {'+',0, &no[5], &no[6]}, 

    {'+',0, &no[7], &no[8]}, 
    {'-',0, &no[9], &no[10]}, 
    {'-',0, &no[11], &no[12]}, 
    {' ',3, NULL,NULL},

    {' ',10, &no[13], NULL},
    {' ',21, NULL, &no[14]},
 
    {' ',4, NULL,NULL},
    {' ',4, NULL, &no[15]},

    {' ',30,&no[16],NULL}, 
    {' ',9,NULL,&no[17]}, 

    {'(',0,&no[16], NULL},
          
    {')',0,NULL, NULL},
    {')',0,NULL, NULL},

    {'(',0,NULL, NULL},
    {')',0,NULL, NULL},

    {'(',0,NULL, NULL},
    
  }; 

  int resultado;
  resultado = funcao_calculo(&no[0]);
  printf(":::RESULTADO DA ESPRESSÃO MATEMÁTICA: %d", resultado);
    
}