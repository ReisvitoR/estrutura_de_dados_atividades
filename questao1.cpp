#include <iostream>
#include <stack>
#include <unordered_map>

// Classe que encapsula a lógica de verificação de delimitadores
class VerificadorDelimitadores {
public:
    // Função para verificar se os delimitadores na expressão estão corretos
    std::string verificar(const std::string& expressao) {
        std::stack<char> pilha; // Usamos uma pilha para rastrear os delimitadores de abertura encontrados
        std::unordered_map<char, char> delimitadores = {{'(', ')'}, {'{', '}'}, {'[', ']'}}; // Mapeamento de delimitadores

        // Iteramos sobre cada caractere na expressão
        for (char c : expressao) {
            // Se encontrarmos um delimitador de abertura, o colocamos na pilha
            if (delimitadores.find(c) != delimitadores.end()) {
                pilha.push(c);
            } else {
                // Se encontrarmos um delimitador de fechamento
                // Procuramos pelo correspondente de abertura no nosso mapa
                std::unordered_map<char, char>::iterator it = delimitadores.begin();
                while (it != delimitadores.end() && it->second != c) {
                    ++it;
                }

                // Se encontrarmos o correspondente no mapa
                if (it != delimitadores.end()) {
                    // Verificamos se a pilha está vazia ou se o delimitador de abertura no topo não coincide
                    if (pilha.empty() || it->first != pilha.top()) {
                        return "ERRADO"; // Se não coincidir, retornamos "ERRADO"
                    }
                    pilha.pop(); // Se coincidir, removemos o delimitador de abertura da pilha
                }
            }
        }

        // Se a pilha estiver vazia, significa que todos os delimitadores foram casados corretamente
        // Caso contrário, alguns delimitadores não foram fechados corretamente
        return pilha.empty() ? "CERTO" : "ERRADO";
    }
};

int main() {
    VerificadorDelimitadores verificador; // Criamos uma instância da classe VerificadorDelimitadores

    // Exemplos de uso da função com saídas correspondentes
    std::cout << verificador.verificar("((A+B) ou A+B(") << std::endl;  // Saída: ERRADO
    std::cout << verificador.verificar("{)A+B( – C ou (A+B))}– (C + D") << std::endl;  // Saída: ERRADO
    std::cout << verificador.verificar("{m +(x+5)+3}") << std::endl;  // Saída: CERTO
    std::cout << verificador.verificar("m +x+5+3}") << std::endl;  // Saída: ERRADO

    return 0;
}
