//crie a função recursiva binarySearch(x,v,p,u) que faz uma busca binária para verificar se o numero inteiro x está no vetor v, indexado de p até u.

#include <stdio.h>

int binarySearch(int x, int v[], int p, int u) {
    if (p > u) {
        return -1; // Elemento não encontrado
    }

    int meio = (p + u) / 2;

    if (v[meio] == x) {
        return meio; // Elemento encontrado, retorna o índice
    } else if (v[meio] > x) {
        // O elemento está à esquerda do meio
        return binarySearch(x, v, p, meio - 1);
    } else {
        // O elemento está à direita do meio
        return binarySearch(x, v, meio + 1, u);
    }
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int elemento = 6;

    int resultado = binarySearch(elemento, vetor, 0, tamanho - 1);

    if (resultado != -1) {
        printf("Elemento encontrado no índice %d\n", resultado);
    } else {
        printf("Elemento não encontrado\n");
    }

    return 0;
}
