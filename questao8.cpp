#include <iostream>
#include <stack>
#include <string>

bool verificaBalanceamento(const std::string& expressao) {
    std::stack<char> pilha;

    for (char caractere : expressao) {
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            pilha.push(caractere);
        } else if (caractere == ')' || caractere == ']' || caractere == '}') {
            if (pilha.empty()) {
                return false; // Não há correspondência para o caractere de fechamento
            }

            char topo = pilha.top();
            pilha.pop();

            // Verifica se o caractere de fechamento corresponde ao caractere de abertura
            if ((caractere == ')' && topo != '(') ||
                (caractere == ']' && topo != '[') ||
                (caractere == '}' && topo != '{')) {
                return false; // Caracteres não correspondem
            }
        }
    }

    // A expressão está balanceada se a pilha estiver vazia no final
    return pilha.empty();
}

int main() {
    std::string expressao;

    std::cout << "Digite uma expressao: ";
    std::getline(std::cin, expressao);

    if (verificaBalanceamento(expressao)) {
        std::cout << "A expressao esta balanceada." << std::endl;
    } else {
        std::cout << "A expressao nao esta balanceada." << std::endl;
    }

    return 0;
}