#include <iostream>
#include "Baralho.hpp"
#include "Jogador.hpp"



int main(){
    Baralho b1;
    std::cout << "BARALHO CRU: \n" << std::endl;
    for(const auto& c : b1){
        std::cout << c.toString() << "\n" << std::endl;
    }

    std::cout << "BARALHO EMBARALHADO: \n" << std::endl;
    b1.Embaralhar();
    for(const auto& c : b1){
        std::cout << c.toString() << "\n" << std::endl;
    }
    std::cout << "\n" << std::endl;
    std::cout << "CARTAS NO BARALHO: " << b1.cartas_restantes() << std::endl;
    
    std::cout << "TESTE DO DEALER: \n" << std::endl;
    b1.Embaralhar();
    std::vector<Carta> cartas_tiradas;
    while(b1.cartas_restantes() > 0){
        Carta carta_tirada = b1.darCarta();
        cartas_tiradas.push_back(carta_tirada);
        std::cout << carta_tirada.toString() << "\n" 
                  << "Cartas restantes: " << b1.cartas_restantes() << "\n" 
                  << std::endl;
    }

    std::cout << "TESTE DE RECOLOCAR CARTA: " << b1.cartas_restantes() << std::endl;
    while(b1.cartas_restantes() < 52){
        Carta carta_devolvida = cartas_tiradas.back();
        cartas_tiradas.pop_back();
        b1.devolveCarta(carta_devolvida);
        std::cout << "Cartas restantes: " << b1.cartas_restantes() << "\n" << std::endl;
    }

    std::cout << "BARALHO APOS TER TODAS AS CARTAS DEVOLVIDAS.\n" << std::endl;
    for(const auto& c : b1){
        std::cout << c.toString() << "\n" << std::endl;
    }

    std::cout << "TESTE DE RESETAR: \n" << std::endl;
    b1.resetar();
    std::cout << "BARALHO APOS RESET.\n" << std::endl;
    for(const auto& c : b1){
        std::cout << c.toString() << "\n" << std::endl;
    }

    return 0;
}