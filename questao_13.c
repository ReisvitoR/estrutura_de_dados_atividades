//simule a execução do código a seguir e indique a saída exibida em video:

#include <stdio.h>

// Fila F - fila(5); Cria uma fila F com capacidade para armazenar 5 elementos.
// enfileira(1,F); Enfileira o valor 1 na fila F.
// enfileira(2,F); Enfileira o valor 2 na fila F.
// enfileira(3,F); Enfileira o valor 3 na fila F.
// enfileira(desenfileira(F),F); |Desenfileira um elemento da fila F (removendo o 1) e enfileira esse elemento novamente (1). Agora, a fila F contém [2, 3, 1].
// enfileira(desenfileira(F),F); |Desenfileira um elemento da fila F (removendo o 2) e enfileira esse elemento novamente (2). Agora, a fila F contém [3, 1, 2].
// printf("%d\n",desenfileira(F)); |Desenfileira um elemento da fila F (removendo o 3) e imprime o valor desenfileirado, que é 3.
//A saída final será: 3 Isso ocorre porque a fila foi manipulada para conter os valores [3, 1, 2] e, em seguida, o primeiro elemento desenfileirado é 3.
