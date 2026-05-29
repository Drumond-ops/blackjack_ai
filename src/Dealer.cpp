#include "Dealer.hpp"

Dealer::Dealer(const std::string& nome) : Jogador(nome){}

bool Dealer::decidir_jogada() const{
    return (getPontos() < 17);
}
