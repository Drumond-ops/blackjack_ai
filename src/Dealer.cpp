#include "Dealer.hpp"

Dealer::Dealer(const std::string& nome) : Jogador(nome){}

bool Dealer::decidir_jogada(int pontosDealer){
    return (getPontos() < 17);
}
