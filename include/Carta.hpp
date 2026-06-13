#ifndef CARTA_HPP
#define CARTA_HPP

#include <string>

enum class Naipe{
    COPAS,
    OUROS,
    ESPADAS,
    PAUS
};

enum class Valor{
    AS = 1,
    DOIS = 2, 
    TRES = 3, 
    QUATRO = 4, 
    CINCO = 5,
    SEIS = 6,
    SETE = 7,
    OITO = 8,
    NOVE = 9,
    DEZ = 10,
    VALETE = 11,
    DAMA = 12,
    REI = 13,
};

class Carta{
private: 
    Valor valor;
    Naipe naipe;
public:
    Carta(Valor v, Naipe n);
    Valor getValor() const;
    Naipe getNaipe() const;
    std::string toString() const;
};

#endif