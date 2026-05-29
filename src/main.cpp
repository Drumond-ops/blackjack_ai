#include "Jogo.hpp"
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
}