//crie a função recursiva enesimo(n,L), que devolve o n-ésimo item da lista L. Por exemplo, para L apontando a lista [a,b,c,d] a chamada enesimo (3,L) deve devolver o tem c. Pata n inválido, a função deve parar com erro fatal

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista
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

// Função recursiva para obter o n-ésimo item da lista
char enesimoRecursivo(Node* head, int n) {
    // Caso base: lista vazia ou n inválido
    if (head == NULL || n <= 0) {
        printf("Erro: N-ésimo inválido.\n");
        exit(EXIT_FAILURE);
    }

    // Caso base: alcançou o n-ésimo item
    if (n == 1) {
        return head->data;
    }

    // Chamada recursiva para o restante da lista
    return enesimoRecursivo(head->next, n - 1);
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
    // Criando uma lista [a, b, c, d]
    Node* lista = NULL;
    lista = inserirNoInicio(lista, 'd');
    lista = inserirNoInicio(lista, 'c');
    lista = inserirNoInicio(lista, 'b');
    lista = inserirNoInicio(lista, 'a');

    // Imprimindo a lista
    printf("Lista: ");
    imprimirLista(lista);

    // Obtendo o terceiro item da lista
    char terceiroItem = enesimoRecursivo(lista, 3);

    // Imprimindo o resultado
    printf("Terceiro Item: %c\n", terceiroItem);

    // Liberando a memória alocada para a lista
    liberarLista(lista);

    return 0;
}
