// considerando as expressões lógicas infixas completamente parentesiadas, representadas por cadeias compostas exclusivamente por:
// Operandos, representados pelas letras V(verdade) e F(falso).
// Operadores, representados pelos caracteres ~(não), &(e) e | (ou).
// Parênteses, que muda as prioridades dos operadores (~ >3, & >2 e | >1).
//  crie um programa que lê uma expressão lógica infixa e exibe sua forma posfixa e seu valor

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

// Avalia expressão lógica posfixa
int avaliarPosfixa(const char *posfixa) {
    Pilha pilha;
    inicializarPilha(&pilha);

    for (int i = 0; posfixa[i] != '\0'; i++) {
        char caractere = posfixa[i];

        if (isalpha(caractere)) {
            // Operandos (V ou F) vão diretamente para a pilha
            empilhar(&pilha, caractere == 'V' ? 1 : 0);
        } else {
            // É um operador
            int op2 = desempilhar(&pilha);
            int op1 = desempilhar(&pilha);

            switch (caractere) {
                case '&':
                    empilhar(&pilha, op1 && op2);
                    break;
                case '|':
                    empilhar(&pilha, op1 || op2);
                    break;
                case '~':
                    empilhar(&pilha, !op2);
                    break;
                default:
                    printf("Erro: Operador desconhecido\n");
                    exit(EXIT_FAILURE);
            }
        }
    }

    // O resultado final deve ser o único elemento restante na pilha
    return desempilhar(&pilha);
}

int main() {
    char infixa[MAX_SIZE];
    char posfixa[MAX_SIZE];

    printf("Digite uma expressao logica infixa completamente parentesiada: ");
    scanf("%s", infixa);

    infixaParaPosfixa(infixa, posfixa);
    int resultado = avaliarPosfixa(posfixa);

    printf("Expressao Infixa: %s\n", infixa);
    printf("Expressao Posfixa: %s\n", posfixa);
    printf("Resultado: %d\n", resultado);

    return 0;
}