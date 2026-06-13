#include "Jogador.hpp"

Jogador::Jogador(const std::string &name) : nome(name) {}

void Jogador::receberCarta(const Carta c){
    mao.push_back(c);
}

std::string Jogador::getNome() const{
    return this->nome;
}

std::vector<Carta> Jogador::getMao() const{
    return this->mao;
}

void Jogador::resetMao(){
    mao.clear();
}

int Jogador::getPontos() const{
    int pontos = 0;
    int carta_atual_int, numeroAs = 0;
    Valor carta_atual;
    for(const auto& c : mao){
        carta_atual_int = static_cast<int>(c.getValor());
        carta_atual = c.getValor();
        if(carta_atual == Valor::AS) numeroAs++;
        if(carta_atual == Valor::REI || carta_atual == Valor::DAMA || carta_atual == Valor::VALETE){
            pontos += 10;
        }
        else{
            pontos += carta_atual_int;
        }
    }
    int aux = pontos + 10;
    if((numeroAs > 0) && (aux <= 21)){
        pontos += 10;
    }
    
    return pontos;    
}

bool Jogador::decidir_jogada(int pontosDealer) {
    char opc;
    if(this->getPontos() <= 21){
        std::cout << "Pedir mais uma carta?(S/N)" << std::endl;
        std::cin >> opc;
        return(opc == 's' || opc == 'S');
    }
    else{
        std::cout << "Voce estourou!\n" << std::endl;
        return false;
    }
}

Jogador::~Jogador() {}