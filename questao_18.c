//crie a função recursiva igual(A,B) que verifica se a lista A é igual a lista B. Por exemplo, se I aponta [1,2,3], J aponta [1,2,3] e K aponta [1,3,2] as chamadas igual(I,J) e igual(I,K) devem devolver 1 e 0, respectivamente

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

// Função recursiva para verificar se duas listas são iguais
int igualRecursivo(Node* A, Node* B) {
    // Se ambas são NULL, são iguais
    if (A == NULL && B == NULL) {
        return 1;
    }

    // Se uma delas é NULL e a outra não, são diferentes
    if (A == NULL || B == NULL) {
        return 0;
    }

    // Verificar se os elementos são iguais e chamar recursivamente para o restante
    return (A->data == B->data) && igualRecursivo(A->next, B->next);
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
    // Criando listas [1, 2, 3]
    Node* lista1 = NULL;
    lista1 = inserirNoInicio(lista1, 3);
    lista1 = inserirNoInicio(lista1, 2);
    lista1 = inserirNoInicio(lista1, 1);

    Node* lista2 = NULL;
    lista2 = inserirNoInicio(lista2, 3);
    lista2 = inserirNoInicio(lista2, 2);
    lista2 = inserirNoInicio(lista2, 1);

    Node* lista3 = NULL;
    lista3 = inserirNoInicio(lista3, 2);
    lista3 = inserirNoInicio(lista3, 3);
    lista3 = inserirNoInicio(lista3, 1);

    // Imprimindo as listas
    printf("Lista 1: ");
    imprimirLista(lista1);
    printf("Lista 2: ");
    imprimirLista(lista2);
    printf("Lista 3: ");
    imprimirLista(lista3);

    // Verificando se as listas são iguais
    printf("Igual Lista1 e Lista2: %d\n", igualRecursivo(lista1, lista2));
    printf("Igual Lista1 e Lista3: %d\n", igualRecursivo(lista1, lista3));

    // Liberando a memória alocada para as listas
    liberarLista(lista1);
    liberarLista(lista2);
    liberarLista(lista3);

    return 0;
}
