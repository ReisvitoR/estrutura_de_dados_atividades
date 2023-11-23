// supondo que os operandos de uma expressão infixa são representados por letras, crie uma função para converter essa expressão para a forma posfixa. Por exemplo a conversão de "A*B+C/D" deve resultar em "AB*CD/+)". Dica: a função isalpha(c), declarada em ctype.h, verifica se um caracter c é letra.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if (operador == '+' || operador == '-') {
        return 1;
    } else if (operador == '*' || operador == '/') {
        return 2;
    }
    return 0; // Para parênteses ou operadores desconhecidos
}

// Converte expressão infixa para posfixa
void infixaParaPosfixa(const char *infixa, char *posfixa) {
    Pilha operadores;
    inicializarPilha(&operadores);
    int i, j;

    for (i = 0, j = 0; infixa[i] != '\0'; i++) {
        char caractere = infixa[i];

        if (isalnum(caractere)) {
            posfixa[j++] = caractere; // Operandos vão diretamente para a saída
        } else if (caractere == '(') {
            empilhar(&operadores, caractere);
        } else if (caractere == ')') {
            // Desempilhar operadores até encontrar '('
            while (!pilhaVazia(&operadores) && operadores.items[operadores.top] != '(') {
                posfixa[j++] = desempilhar(&operadores);
            }
            desempilhar(&operadores); // Desempilhar '('
        } else {
            // É um operador
            while (!pilhaVazia(&operadores) && precedencia(caractere) <= precedencia(operadores.items[operadores.top])) {
                posfixa[j++] = desempilhar(&operadores);
            }
            empilhar(&operadores, caractere);
        }
    }

    // Desempilhar operadores restantes
    while (!pilhaVazia(&operadores)) {
        posfixa[j++] = desempilhar(&operadores);
    }

    posfixa[j] = '\0'; // Adiciona o caractere nulo ao final da string
}

int main() {
    const char *infixa = "A*B+C/D";
    char posfixa[MAX_SIZE];

    infixaParaPosfixa(infixa, posfixa);

    printf("Expressão Infixa: %s\n", infixa);
    printf("Expressão Posfixa: %s\n", posfixa);

    return 0;
}
