//Qual a saída exibida pelo programa a seguir? Por quê? 
#include <stdio.h> 
#include "../ed/pilha.h" // pilha de float 
int main(void) {
  Pilha Ppilha (100); 
  empilha (8, P); 
  while(topo (P)>0) empilha (topo (P)/2, P); 
  while(!vaziap(P)) printf("%f\n", desempilha(P)); 
  return 0;
}

//Deve sair uma sequência de números que
//representam a divisão por 2 de cada elemento
//do topo do contato anterior.