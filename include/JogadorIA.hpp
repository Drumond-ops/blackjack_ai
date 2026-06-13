#ifndef JOGADORIA_HPP
#define JOGADORIA_HPP

#include "Dealer.hpp"
#include "GerenciadorBD.hpp"
#include <random>

class Jogador_IA : public Jogador{
private:
    GerenciadorBD* bancoDados;
    float taxa_exp;
    std::mt19937 gerador;
    std::uniform_real_distribution<float> distribuicao;
    int memoria_pontos;
    int memoria_decisao;
    int memoria_dealer;
public:
    Jogador_IA(GerenciadorBD* bd, const std::string& nome = "Jarvis", float tx_exp = 0.1f);
    void receberRecompensa(float recompensa, int novoPonto, bool acabouJogo);
    bool decidir_jogada(int pontosDealer) override;
    void setTaxaExploracao(float novaTaxa) { this->taxa_exp = novaTaxa; };
};

#endif