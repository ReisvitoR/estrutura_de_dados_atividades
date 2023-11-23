//crie a função recursiva soma(L), que devolve a soma dos itensda lista L. Por exemplo, para L apontando a lista [3,1,5,4], a função deve devolver 13

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para inserir um elemento no início da lista
Node* inserirNoInicio(Node* head, int value) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->data = value;
    novoNo->next = head;

    return novoNo;
}

// Função recursiva para calcular a soma dos elementos da lista
int soma(Node* head) {
    // Caso base: lista vazia
    if (head == NULL) {
        return 0;
    }

    // Chamada recursiva para o restante da lista
    // Soma do elemento atual com a soma do restante
    return head->data + soma(head->next);
}

// Função para imprimir os elementos da lista
void imprimirLista(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Função para liberar a memória alocada para a lista
void liberarLista(Node* head) {
    Node* atual = head;
    Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }
}

int main() {
    // Criando uma lista [3, 1, 5, 4]
    Node* lista = NULL;
    lista = inserirNoInicio(lista, 4);
    lista = inserirNoInicio(lista, 5);
    lista = inserirNoInicio(lista, 1);
    lista = inserirNoInicio(lista, 3);

    // Imprimindo a lista
    printf("Lista: ");
    imprimirLista(lista);

    // Calculando a soma dos elementos
    int resultado = soma(lista);

    // Exibindo o resultado
    printf("Soma dos elementos: %d\n", resultado);

    // Liberando a memória alocada para a lista
    liberarLista(lista);

    return 0;
}
