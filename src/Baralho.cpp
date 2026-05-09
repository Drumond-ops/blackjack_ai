#include "Carta.hpp"
#include "Baralho.hpp"


void Baralho::montarBaralho(){
    Naipe listaNaipes[] = {Naipe::COPAS, Naipe::OUROS, Naipe::ESPADAS, Naipe::PAUS};

    for (Naipe n : listaNaipes){
        for(int v = 1; v <=13; v++){
            cartas.emplace_back(static_cast<Valor>(v), n);
        }
    }
}

Baralho::Baralho(){
    montarBaralho();
    std::random_device semente;
    gerador = std::mt19937(semente());
}

Carta Baralho::darCarta(){
    Carta c = cartas.back();
    cartas.pop_back();
    return c;
}

void Baralho::devolveCarta(const Carta &carta){
    cartas.insert(cartas.begin(), carta);
}

int Baralho::cartas_restantes() const{
    return cartas.size();
}

void Baralho::Embaralhar(){
    std::shuffle(cartas.begin(), cartas.end(), gerador);
}

void Baralho::resetar(){
    cartas.clear();
    montarBaralho();
}