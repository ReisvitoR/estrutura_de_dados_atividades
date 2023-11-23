// considerando as expressões lógicas infixas completamente parentesiadas, representadas por cadeias compostas exclusivamente por:
// Operandos, representados pelas letras V(verdade) e F(falso).
// Operadores, representados pelos caracteres ~(não), &(e) e | (ou).
// Parênteses, que muda as prioridades dos operadores (~ >3, & >2 e | >1).
// crie uma função que devolve a posfixa de uma expressão lógica infixa

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Estrutura da pilha
typedef struct {
    char items[MAX_SIZE];
    int top;
} Pilha;

// Inicializa a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->top = -1;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return pilha->top == -1;
}

// Verifica se a pilha está cheia
int pilhaCheia(Pilha *pilha) {
    return pilha->top == MAX_SIZE - 1;
}

// Empilha um caractere na pilha
void empilhar(Pilha *pilha, char caractere) {
    if (!pilhaCheia(pilha)) {
        pilha->items[++pilha->top] = caractere;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
}

// Desempilha um caractere da pilha
char desempilhar(Pilha *pilha) {
    if (!pilhaVazia(pilha)) {
        return pilha->items[pilha->top--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

// Retorna a precedência do operador
int precedencia(char operador) {
    switch (operador) {
        case '~':
            return 3;
        case '&':
            return 2;
        case '|':
            return 1;
        default:
            return 0;
    }
}

// Converte expressão lógica infixa para posfixa
void infixaParaPosfixa(const char *infixa, char *posfixa) {
    Pilha pilha;
    inicializarPilha(&pilha);
    int i, j;

    for (i = 0, j = 0; infixa[i] != '\0'; i++) {
        char caractere = infixa[i];

        if (isalpha(caractere)) {
            // Operandos (V ou F) vão diretamente para a saída
            posfixa[j++] = caractere;
        } else if (caractere == '(') {
            // Abre parênteses
            empilhar(&pilha, caractere);
        } else if (caractere == ')') {
            // Fecha parênteses
            while (!pilhaVazia(&pilha) && pilha.items[pilha.top] != '(') {
                posfixa[j++] = desempilhar(&pilha);
            }
            desempilhar(&pilha); // Desempilhar '('
        } else {
            // É um operador
            while (!pilhaVazia(&pilha) && precedencia(caractere) <= precedencia(pilha.items[pilha.top])) {
                posfixa[j++] = desempilhar(&pilha);
            }
            empilhar(&pilha, caractere);
        }
    }

    // Desempilhar operadores restantes
    while (!pilhaVazia(&pilha)) {
        posfixa[j++] = desempilhar(&pilha);
    }

    posfixa[j] = '\0'; // Adiciona o caractere nulo ao final da string
}

int main() {
    const char *infixa = "(V|F)&(V|F)";
    char posfixa[MAX_SIZE];

    infixaParaPosfixa(infixa, posfixa);

    printf("Expressão Infixa: %s\n", infixa);
    printf("Expressão Posfixa: %s\n", posfixa);

    return 0;
}
