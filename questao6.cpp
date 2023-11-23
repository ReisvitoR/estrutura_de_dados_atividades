#include <iostream>
#include <stack>
#include <sstream>

void inverterOrdemLetras(const std::string& frase) {
    std::stack<char> pilhaLetras;

    for (char letra : frase) {
        if (letra != ' ') {
            pilhaLetras.push(letra);
        } else {
            while (!pilhaLetras.empty()) {
                std::cout << pilhaLetras.top();
                pilhaLetras.pop();
            }
            std::cout << ' '; // Imprimir espaço entre as palavras
        }
    }

    // Imprimir as letras da última palavra
    while (!pilhaLetras.empty()) {
        std::cout << pilhaLetras.top();
        pilhaLetras.pop();
    }

    std::cout << std::endl;
}

int main() {
    std::string frase;

    std::cout << "Digite uma frase: ";
    std::getline(std::cin, frase);

    std::cout << "Frase com letras invertidas: ";
    inverterOrdemLetras(frase);

    return 0;
}