//crie a função recursiva substitui(x,y,L), que substitui toda ocorrencia do item x pelo item y na lista L. Por exemplo, se L aponta a lista [b,o,b,o], após a chamada substitui('o','a',L), L deverá apontar a lista [b,a,b,a].

#include <stdio.h>
#include <stdlib.h>

// Node é uma estrutura que representa um nó de uma lista encadeada. Uma lista encadeada é uma estrutura de dados na qual os elementos são armazenados em nós, e cada nó possui uma referência para o próximo nó na sequência.

typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Função para inserir um caractere no início da lista
Node* inserirNoInicio(Node* head, char value) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->data = value;
    novoNo->next = head;

    return novoNo;
}

// Função recursiva para substituir ocorrências de 'x' por 'y' na lista
void substituiRecursivo(Node* head, char x, char y) {
    // Caso base: lista vazia
    if (head == NULL) {
        return;
    }

    // Substituir 'x' por 'y' se necessário
    if (head->data == x) {
        head->data = y;
    }

    // Chamada recursiva para o restante da lista
    substituiRecursivo(head->next, x, y);
}

// Função para imprimir os elementos da lista
void imprimirLista(Node* head) {
    while (head != NULL) {
        printf("%c ", head->data);
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
    // Criando uma lista [b, o, b, o]
    Node* lista = NULL;
    lista = inserirNoInicio(lista, 'o');
    lista = inserirNoInicio(lista, 'b');
    lista = inserirNoInicio(lista, 'o');
    lista = inserirNoInicio(lista, 'b');

    // Imprimindo a lista original
    printf("Lista Original: ");
    imprimirLista(lista);

    // Substituindo 'o' por 'a'
    substituiRecursivo(lista, 'o', 'a');

    // Imprimindo a lista após a substituição
    printf("Lista Após Substituição: ");
    imprimirLista(lista);

    // Liberando a memória alocada para a lista
    liberarLista(lista);

    return 0;
}
