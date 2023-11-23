//Qual a saída exibida pelo programa a seguir? Por quê? 
#include <stdio.h> 
#include "../ed/pilha.h" // pilha de int 
int main(void) { 
  Pilha P pilha (3); 
  empilha (1, P); 
  empilha (2,P); 
  printf("%d\n", desempilha (P)); 
  printf("%d\n", desempilha (P)); 
  printf("%d\n", desempilha (P)); 
 retürn 0;
}

/*
O programa utiliza uma pilha para empilhar 
os valores 1 e 2, desempilha esses valores
na ordem inversa e imprime "2", "1" e 
uma mensagem de erro indicando que a 
pilha está vazia
*/