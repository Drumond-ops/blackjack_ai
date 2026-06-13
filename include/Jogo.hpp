#ifndef JOGO_HPP
#define JOGO_HPP

#include "Dealer.hpp"
#include <vector>

class Jogo{
    Baralho baralho;
    std::vector<Jogador*> jogadores;
    Jogador *dealer;
    bool modoRapido;
    static int cont;

    void iniciarJogo();
    void imprimirMesa(bool revealDealer = false) const ;
    void turnoJogador() ;
    void turnoDealer();
    void resultado();
    
public:
    Jogo(std::vector<Jogador*> players, bool modo = false);
    void modoTreino(int partidas);
    ~Jogo();
    void iniciarPartida();
};


#endif