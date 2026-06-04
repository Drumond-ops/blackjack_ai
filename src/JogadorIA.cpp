#include "JogadorIA.hpp"
#include <algorithm>

Jogador_IA::Jogador_IA(GerenciadorBD* bd, const std::string& nome, float tx_exp) : Jogador(nome), bancoDados(bd), taxa_exp(tx_exp){
    std::random_device seed;
    gerador = std::mt19937(seed());
    distribuicao = std::uniform_real_distribution<float>(0.0f, 1.0f);
}

bool Jogador_IA::decidir_jogada(int pontosDealer){
    bool decisao;
    
    if(this->getPontos() >= 21) return false;

    //MODO DE EXPLORACAO ALERATORIA
    if(distribuicao(gerador) < taxa_exp){
        std::uniform_int_distribution<int> moeda(0,1);
        decisao = (moeda(gerador) == 1);
    }
    //MODO INTELIGENTE
    else{
        float notaStand = bancoDados->getQValue(this->getPontos(), pontosDealer, 0);
        float notaHit = bancoDados->getQValue(this->getPontos(), pontosDealer, 1);
        decisao = (notaHit > notaStand);
    }

    this->memoria_dealer = pontosDealer;
    this->memoria_pontos = this->getPontos();
    this->memoria_decisao = decisao ? 1 : 0;

    return decisao;
}

void Jogador_IA::receberRecompensa(float recompensa, int novoPonto, bool acabouJogo){
    float maxQf = 0.0f;
    float alpha = 0.1f;
    float gamma = 0.9f;

    float Qatual = bancoDados->getQValue(memoria_pontos, memoria_dealer, memoria_decisao);

    if(!acabouJogo){
        float Qf_hit = bancoDados->getQValue(novoPonto, memoria_dealer, 1);
        float Qf_stand = bancoDados->getQValue(novoPonto, memoria_dealer, 0);
        maxQf = std::max(Qf_hit, Qf_stand);
    }

    float novoQ = Qatual + alpha*(recompensa + (gamma*maxQf) - Qatual);
    bancoDados->Q_update(memoria_pontos, memoria_dealer, memoria_decisao, novoQ);

}

void Jogador::receberRecompensa(float recompensa, int novoPonto, bool acabouJogo) {
}