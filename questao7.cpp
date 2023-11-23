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

void exibirPilha(std::stack<double> pilha) {
    while (!pilha.empty()) {
        std::cout << pilha.top() << " ";
        pilha.pop();
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
        pilhaA.push(numero);
    }

    ordenarPilha(pilhaA, pilhaB);

    std::cout << "Pilha A ordenada: ";
    exibirPilha(pilhaB);

    return 0;
}