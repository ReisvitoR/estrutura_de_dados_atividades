#include <iostream>
#include <stack>

void ordenarPilha(std::stack<double>& pilhaA, std::stack<double>& pilhaB) {
    while (!pilhaA.empty()) {
        double temp = pilhaA.top();
        pilhaA.pop();

        while (!pilhaB.empty() && pilhaB.top() > temp) {
            pilhaA.push(pilhaB.top());
            pilhaB.pop();
        }

        pilhaB.push(temp);
    }
}

void exibirPilha(const std::stack<double>& pilha) {
    std::stack<double> pilhaTemp = pilha;

    while (!pilhaTemp.empty()) {
        std::cout << pilhaTemp.top() << " ";
        pilhaTemp.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<double> pilhaA;
    std::stack<double> pilhaB;

    int n;
    std::cout << "Digite a quantidade de números a serem ordenados: ";
    std::cin >> n;

    double numero;
    std::cout << "Digite os números (separados por espaço): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> numero;

        // Garante que o número inserido é maior que todos os números já presentes na pilhaA
        if (pilhaA.empty() || numero > pilhaA.top()) {
            pilhaA.push(numero);
        } else {
            std::cout << "Número inválido! Insira um número maior que os anteriores." << std::endl;
            --i; // Para permitir a entrada de um novo número válido
        }
    }

    ordenarPilha(pilhaA, pilhaB);

    std::cout << "Pilha A ordenada: ";
    exibirPilha(pilhaB);

    return 0;
}
