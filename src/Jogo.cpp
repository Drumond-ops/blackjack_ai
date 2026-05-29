#include "Jogo.hpp"

Jogo::Jogo(const std::string& jogador){
    this->jogador = new Jogador(jogador);
    this->dealer = new Dealer("dealer");
}

Jogo::~Jogo(){
    delete this->jogador;
    delete this->dealer;
}

void Jogo::iniciarJogo(){
    jogador->resetMao();
    dealer->resetMao();
    this->baralho.resetar();
    this->baralho.Embaralhar();
    for(int i = 0; i < 2; i++){
        this->jogador->receberCarta(this->baralho.darCarta());
        this->dealer->receberCarta(this->baralho.darCarta());
    }  
}

void Jogo::imprimirMesa(bool revealDealer) const{

    std::cout << "=======JOGADOR=======\n"
              << "Cartas do jogador(" << jogador->getNome() << "): \n"
              << std::endl;
    for(const auto& carta : jogador->getMao()){
        std::cout << carta.toString() << std::endl;
    }
    std::cout << "Pontuacao do jogador: " << jogador->getPontos() << "\n\n" << std::endl;

    std::cout << "=======DEALER=======\n"
              << "Cartas da Banca(" << dealer->getNome() << "): \n" 
              << std::endl;
    if(revealDealer){
        for(const auto& carta : dealer->getMao()){
        std::cout << carta.toString() << std::endl;
        }
        std::cout << "Pontuacao da banca: " << dealer->getPontos() << std::endl;
    }
    else{
        std::cout << dealer->getMao()[0].toString() << "\n" << std::endl;
    }   
}

void Jogo::turnoJogador(){
    while(jogador->decidir_jogada()){
        jogador->receberCarta(baralho.darCarta());
        this->imprimirMesa();
    }
}

void Jogo::turnoDealer(){
    this->imprimirMesa(true);
    while(dealer->decidir_jogada()){
        std::cout << "\n ---- A BANCA VAI COMPRAR..." << std::endl;
        dealer->receberCarta(baralho.darCarta());
        if(dealer->getPontos() > 21){
            std::cout << "---- A BANCA ESTOUROU!!!" << std::endl;
        }
    }
}

void Jogo::resultado(){
    if(jogador->getPontos() > 21){
        std::cout << "Jogador estourou com " << jogador->getPontos() << " pontos\n" 
                  << "A banca VENCEU!"
                  << std::endl;
    }
    else if(dealer->getPontos() > 21){
        std::cout << "Banca estourou com " << dealer->getPontos() << " pontos\n" 
                  << "Voce VENCEU!"
                  << std::endl;
    }
    else if(dealer->getPontos() > jogador->getPontos()){
        std::cout << "Jogador fez " << jogador->getPontos() << " pontos\n"
                  << "Banca fez " << dealer->getPontos() << " pontos\n" 
                  << "A banca VENCEU!"
                  << std::endl;
    }
    else if(dealer->getPontos() < jogador->getPontos()){
        std::cout << "Jogador fez " << jogador->getPontos() << " pontos\n"
                  << "Banca fez " << dealer->getPontos() << " pontos\n" 
                  << "voce VENCEU!"
                  << std::endl;
    }
    else{
        std::cout << "A banca e o jogador fizeram " << jogador->getPontos() << " pontos\n"
                  << "EMPATE!"
                  << std::endl;
    }
}

void Jogo::iniciarPartida(){
    std::cout << "Embaralhando e distribuindo as cartas...\n";
    this->iniciarJogo();
    this->imprimirMesa();

    std::cout << "\n\n----TURNO DO JOGADOR(" << jogador->getNome() << ")... \n" << std::endl;
    this->turnoJogador();
    
    if (jogador->getPontos() <= 21) {
        std::cout << "\n\n----TURNO DA BANCA(" << dealer->getNome() << ")... \n" << std::endl;
        this->turnoDealer();
    }

    std::cout << "======= RESULTADO FINAL ======" << std::endl;
    this->resultado();
}