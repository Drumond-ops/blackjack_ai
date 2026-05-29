#ifndef JOGO_HPP
#define JOGO_HPP

#include "Dealer.hpp"

class Jogo{
    Baralho baralho;
    Jogador *jogador;
    Jogador *dealer;
    
    void iniciarJogo();
    void imprimirMesa(bool revealDealer = false) const ;
    void turnoJogador() ;
    void turnoDealer();
    void resultado();
public:
    Jogo(const std::string& jogador);
    void iniciarPartida();
    ~Jogo();
};


#endif