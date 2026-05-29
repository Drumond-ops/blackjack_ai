#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Carta.hpp"
#include "Baralho.hpp"
#include <iostream>
#include <string>
#include <vector>

class Jogador {
private:
    std::string nome;
    std::vector<Carta> mao;
public:
    Jogador(const std::string& name);
    void receberCarta(const Carta c);
    int getPontos() const;
    std::string getNome() const;
    std::vector<Carta> getMao() const;
    virtual bool decidir_jogada() const;
    void resetMao();
    virtual ~Jogador();
};

#endif