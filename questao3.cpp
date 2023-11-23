#include <iostream>
#include <queue>

class PilhaComDuasFilas {
private:
    std::queue<int> filaEntrada;
    std::queue<int> filaAuxiliar;

public:
    // Procedimento para empilhar um elemento na pilha
    void empilhar(int elemento) {
        // Entra na fila principal
        filaEntrada.push(elemento);
    }

    // Procedimento para desempilhar um elemento da pilha
    int desempilhar() {
        if (filaEntrada.empty()) {
            std::cerr << "Erro: A pilha está vazia." << std::endl;
            return -1; // Valor inválido, pois a pilha está vazia
        }

        // Transfere elementos para a fila auxiliar, exceto o último
        while (filaEntrada.size() > 1) {
            filaAuxiliar.push(filaEntrada.front());
            filaEntrada.pop();
        }

        // Obtém o último elemento da fila principal (que será o topo da pilha)
        int topo = filaEntrada.front();
        filaEntrada.pop();

        // Troca o conteúdo da fila principal com a auxiliar
        std::swap(filaEntrada, filaAuxiliar);

        return topo;
    }

    // Procedimento fictício para verificar se a pilha está cheia
    // Neste exemplo, assumimos que as filas têm tamanho dinâmico
    bool pilhaCheia() const {
        return false;
    }

    // Procedimento fictício para verificar se a pilha está vazia
    bool pilhaVazia() const {
        return filaEntrada.empty();
    }
};

int main() {
    PilhaComDuasFilas pilha;

    pilha.empilhar(1);
    pilha.empilhar(2);
    pilha.empilhar(3);

    std::cout << "Elemento desempilhado: " << pilha.desempilhar() << std::endl;
    std::cout << "Elemento desempilhado: " << pilha.desempilhar() << std::endl;

    pilha.empilhar(4);
    std::cout << "Elemento desempilhado: " << pilha.desempilhar() << std::endl;
    std::cout << "Elemento desempilhado: " << pilha.desempilhar() << std::endl; // Deve imprimir erro

    return 0;
}
