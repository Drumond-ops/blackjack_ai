#ifndef DEALER_HPP
#define DEALER_HPP

#include "Jogador.hpp"

class Dealer : public Jogador{
    public:
    Dealer(const std::string &nome);
    bool decidir_jogada(int pontoDealer);
};


#endif