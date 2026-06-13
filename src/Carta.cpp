#include "Carta.hpp"

Carta::Carta(Valor v, Naipe n) : valor(v), naipe(n) {}

Valor Carta::getValor() const{
    return valor;
}

Naipe Carta::getNaipe() const{
    return naipe;
}

std::string Carta::toString() const{
    std::string strNaipe;
    std::string strValor;
    switch(valor){
        case Valor::AS:
            strValor = "As";
            break;
        case Valor::DOIS:
            strValor = "Dois";
            break;
        case Valor::TRES:
            strValor = "Tres";
            break;
        case Valor::QUATRO:
            strValor = "Quatro";
            break;
        case Valor::CINCO:
            strValor = "Cinco";
            break;
        case Valor::SEIS:
            strValor = "Seis";
            break;
        case Valor::SETE:
            strValor = "Sete";
            break;
        case Valor::OITO:
            strValor = "Oito";
            break;
        case Valor::NOVE:
            strValor = "Nove";
            break;
        case Valor::DEZ:
            strValor = "Dez";
            break;
        case Valor::VALETE:
            strValor = "Valete";
            break;
        case Valor::DAMA:
            strValor = "Dama";
            break;
        case Valor::REI:
            strValor = "Rei";
            break;
    }

    switch(naipe){
        case Naipe::COPAS:
            strNaipe = "Copas";
            break;
        case Naipe::ESPADAS:
            strNaipe = "Espadas";
            break;
        case Naipe::OUROS:
            strNaipe = "Ouros";
            break;
        case Naipe::PAUS:
            strNaipe = "Paus";
            break;
    }

    return strValor + " " + "de" + " " + strNaipe;
}