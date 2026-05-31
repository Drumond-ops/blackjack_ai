/*#include "Jogo.hpp"
#include <iostream>
#include <string>


int main() {
    std::string nome;
    std::cout << "Bem-vindo ao Cassino C++!\n";
    std::cout << "Digite o seu nome: ";
    std::getline(std::cin, nome);

    Jogo mesaBlackjack(nome);
    
    char jogarNovamente;
    do {
        mesaBlackjack.iniciarPartida();
        
        std::cout << "\nDeseja jogar mais uma partida? (S/N): ";
        std::cin >> jogarNovamente;
        
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    std::cout << "Obrigado por jogar!\n";
    
    return 0;
}*/

#include <iostream>
#include "GerenciadorBD.hpp"

int main() {
    std::cout << "Iniciando teste do Banco de Dados SQLite..." << std::endl;

    // 1. Instancia o gerenciador (Isso deve disparar o CREATE TABLE)
    // Vamos usar um nome especifico para esse teste
    GerenciadorBD bd("teste_ai.db");

    // 2. Definindo um estado fictício
    int pontos_jogador = 16;
    int carta_dealer = 10;
    int acao_escolhida = 1; // 1 para Hit (Pedir Carta)
    float valor_aprendido = 8.75f;

    // 3. Gravando o dado no banco
    std::cout << "\nTentando gravar Valor Q: " << valor_aprendido << "..." << std::endl;
    bd.Q_update(pontos_jogador, carta_dealer, acao_escolhida, valor_aprendido);

    // 4. Lendo o dado de volta
    std::cout << "Lendo os dados gravados..." << std::endl;
    float valor_lido = bd.getQValue(pontos_jogador, carta_dealer, acao_escolhida);

    // 5. Validando o resultado
    std::cout << "\n=== RESULTADO DO TESTE ===" << std::endl;
    std::cout << "Valor Esperado: " << valor_aprendido << std::endl;
    std::cout << "Valor Retornado: " << valor_lido << std::endl;

    if (valor_lido == valor_aprendido) {
        std::cout << "\n[SUCESSO] O Banco de Dados esta funcionando perfeitamente!" << std::endl;
    } else {
        std::cout << "\n[FALHA] Os valores nao bateram." << std::endl;
    }

    return 0;
}

