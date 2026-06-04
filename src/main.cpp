#include "Jogo.hpp"
#include "GerenciadorBD.hpp"
#include "JogadorIA.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    GerenciadorBD DataBank("memoria_robo.db");

    // Cria os dois jogadores
    Jogador_IA* jarvis = new Jogador_IA(&DataBank, "Jarvis", 0.05f); // 5% de exploração no treino
    Jogador* humano = new Jogador("Voce");

    // === MODO TREINO (Só o Jarvis joga) ===
    std::vector<Jogador*> mesaDeTreino = {jarvis};
    Jogo academia(mesaDeTreino);
    
    DataBank.iniciarTransacao();
    academia.modoTreino(100000);
    DataBank.finalizarTransacao();

    jarvis->setTaxaExploracao(0.0f);
    // === MODO JOGO (Você e o Jarvis contra a Banca) ===
    std::vector<Jogador*> mesaOficial = {humano, jarvis};
    Jogo banca_blackjack(mesaOficial);
    
    bool continuar;
    char opc;
    do{
        std::cout << "\n\n======================== BLACK JACK ROBOTICO =============================\n\n" << std::endl;
        banca_blackjack.iniciarPartida();
        
        std::cout << "\nDeseja jogar mais um jogo? (s/n): ";
        std::cin >> opc;
        continuar = (opc == 's' || opc == 'S');
    }while(continuar);

    // Boa prática: limpar a memória no final
    delete jarvis;
    delete humano;

    return 0;
}