#include <iostream>
#include <stack>

class FilaComDuasPilhas {
private:
    std::stack<int> pilhaEntrada;
    std::stack<int> pilhaSaida;

public:
    // Procedimento para entrar na fila
    void entrarNaFila(int elemento) {
        // Simplesmente empilha o elemento na pilha de entrada
        pilhaEntrada.push(elemento);
    }

    // Procedimento para sair da fila
    int sairDaFila() {
        // Se a pilha de saída estiver vazia, transfere elementos da pilha de entrada
        if (pilhaSaida.empty()) {
            while (!pilhaEntrada.empty()) {
                pilhaSaida.push(pilhaEntrada.top());
                pilhaEntrada.pop();
            }
        }

        // Se a pilha de saída ainda estiver vazia, a fila está vazia
        if (pilhaSaida.empty()) {
            std::cerr << "Erro: A fila está vazia." << std::endl;
            return -1; // Valor inválido, pois a fila está vazia
        }

        // Desempilha e retorna o elemento da pilha de saída
        int frente = pilhaSaida.top();
        pilhaSaida.pop();
        return frente;
    }

    // Procedimento para verificar se a fila está vazia
    bool filaVazia() const {
        return pilhaEntrada.empty() && pilhaSaida.empty();
    }

    // Procedimento fictício para verificar se a fila está cheia
    // Neste exemplo, assumimos que as pilhas têm tamanho dinâmico
    bool filaCheia() const {
        return false;
    }
};

int main() {
    FilaComDuasPilhas fila;

    fila.entrarNaFila(1);
    fila.entrarNaFila(2);
    fila.entrarNaFila(3);

    std::cout << "Elemento removido da fila: " << fila.sairDaFila() << std::endl;
    std::cout << "Elemento removido da fila: " << fila.sairDaFila() << std::endl;

    fila.entrarNaFila(4);
    std::cout << "Elemento removido da fila: " << fila.sairDaFila() << std::endl;
    std::cout << "Elemento removido da fila: " << fila.sairDaFila() << std::endl; // Deve imprimir erro

    return 0;
}
