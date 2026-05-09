#ifndef BARALHO_HPP
#define BARALHO_HPP

#include <vector>
#include <algorithm>
#include <random>
#include "Carta.hpp"

class Baralho{
private:
    std::vector<Carta> cartas;
    std::random_device semente;
    std::mt19937 gerador;
    void montarBaralho();
public:
    Baralho();
    Carta darCarta();
    void devolveCarta(const Carta &carta);
    void Embaralhar();
    int cartas_restantes() const;
    void resetar();
    std::vector<Carta>::const_iterator begin() const { return cartas.begin(); }
    std::vector<Carta>::const_iterator end() const { return cartas.end(); }
};
#endif