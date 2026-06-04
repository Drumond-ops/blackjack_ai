#include "Jogo.hpp"

int Jogo::cont = 0;

Jogo::Jogo(std::vector<Jogador*> players, bool modo){
    this->jogadores = players;
    this->dealer = new Dealer("dealer");
    this->modoRapido = modo;
}

Jogo::~Jogo(){
    delete this->dealer;
}

void Jogo::iniciarJogo(){
    for(auto* jogador : jogadores){
        jogador->resetMao();
    }
    dealer->resetMao();
    this->baralho.resetar();
    this->baralho.Embaralhar();
    for(int i = 0; i < 2; i++){
        for(auto* jogador : jogadores){
            jogador->receberCarta(this->baralho.darCarta());
        }
        this->dealer->receberCarta(this->baralho.darCarta());
    }  
}

void Jogo::imprimirMesa(bool revealDealer) const{
    int i = 1;
    for(auto* jogador : jogadores){
        std::cout << "=======JOGADOR " << i << "=======\n"
              << "Cartas do Jogador " << i << " (" << jogador->getNome() << "): \n"
              << std::endl;
        for(const auto& carta : jogador->getMao()){
            std::cout << carta.toString() << std::endl;
        }
              
        std::cout << "Pontucao do jogador " << i << ": " << jogador->getPontos() << "\n\n"
              << std::endl;
        i++;
    }

    std::cout << "=======DEALER=======\n"
              << "Cartas da Banca (" << dealer->getNome() << "): \n" 
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

    int pontoDealer = static_cast<int>(dealer->getMao()[0].getValor());
    for(auto* jogador : jogadores){
        while(jogador->decidir_jogada(pontoDealer)){
            jogador->receberCarta(baralho.darCarta());
            if(!modoRapido) this->imprimirMesa();

            int scoreAtual = jogador->getPontos();
            bool estouro = (scoreAtual > 21);

            jogador->receberRecompensa(estouro ? -1.0f : 0.0f, scoreAtual, estouro);
        }
    }
   
}

void Jogo::turnoDealer(){
    this->imprimirMesa(true);
    while(dealer->decidir_jogada(0)){
        std::cout << "\n ---- A BANCA VAI COMPRAR..." << std::endl;
        dealer->receberCarta(baralho.darCarta());
        if(dealer->getPontos() > 21){
            std::cout << "---- A BANCA ESTOUROU!!!" << std::endl;
        }
    }
}

void Jogo::resultado(){
    int i = 1;
    for(auto* jogador : jogadores){
        float nota = 0.0f;
        if(jogador->getPontos() > 21){
            if(!modoRapido) {
                std::cout << "Jogador " << i << " (" << jogador->getNome() << ")" << " estourou com " << jogador->getPontos() << " pontos\n" 
                          << "A banca VENCEU!"
                          << std::endl;
            }
        }
        else if(dealer->getPontos() > 21){
            if(!modoRapido){
                std::cout << "Banca estourou com " << dealer->getPontos() << " pontos\n" 
                          << "Jogador " << i << " (" << jogador->getNome() << ")" << " VENCEU!"
                          << std::endl;
            }
            nota = 1.0f;
            jogador->receberRecompensa(nota, jogador->getPontos(), true);
        }
        else if(dealer->getPontos() > jogador->getPontos()){
            if(!modoRapido){
                std::cout << "Jogador " << i << " (" << jogador->getNome() << ") " << "fez " << jogador->getPontos() << " pontos\n"
                          << "Banca fez " << dealer->getPontos() << " pontos\n" 
                          << "A banca VENCEU!"
                          << std::endl;
            }
            nota = -1.0f;
            jogador->receberRecompensa(nota, jogador->getPontos(), true);
        }
        else if(dealer->getPontos() < jogador->getPontos()){
            if(!modoRapido){
                std::cout << "Jogador " << i << " (" << jogador->getNome() << ") " << "fez " << jogador->getPontos() << " pontos\n"
                          << "Banca fez " << dealer->getPontos() << " pontos\n" 
                          << "Jogador " << i << " (" << jogador->getNome() << ")" << " VENCEU!"
                          << std::endl;
            }
            nota = 1.0f;
            jogador->receberRecompensa(nota, jogador->getPontos(), true);
        }
        else{
            if(!modoRapido){
                std::cout << "A banca e o jogador " << i << " (" << jogador->getNome() << ") " << "fizeram " << jogador->getPontos() << " pontos\n"
                          << "EMPATE!"
                          << std::endl;
                }
            nota = 0.0f;
            jogador->receberRecompensa(nota, jogador->getPontos(), true);
        }
        i++;
    }
}

void Jogo::iniciarPartida(){
    std::cout << "Embaralhando e distribuindo as cartas...\n";
    this->iniciarJogo();
    this->imprimirMesa();

    std::cout << "\n\n----TURNO DOS JOGADORES----\n" << std::endl;
    this->turnoJogador();

    bool todosPerderam = true;
    for(auto* jogador: jogadores){
        if(jogador->getPontos() <= 21){
            todosPerderam = false;
            break;
        }
    }
    
    if (!todosPerderam) {
        std::cout << "\n\n----TURNO DA BANCA(" << dealer->getNome() << ")... \n" << std::endl;
        this->turnoDealer();
    }

    std::cout << "======= RESULTADO FINAL ======" << std::endl;
    this->resultado();
}

void Jogo::modoTreino(int partidas){
    this->modoRapido = true;
    std::cout << "\n[Motor] Iniciando treinamento de " << partidas << " partidas em fast-forward..." << std::endl;

    

    for(int i = 0; i < partidas; i++){
        bool todosPerderam = true;
        this->iniciarJogo();
        this->turnoJogador();
        for(auto* jogador : jogadores){
            if(jogador->getPontos() <= 21){
            todosPerderam = false;
            break;
            }
        }
        if(!todosPerderam){
            while(dealer->decidir_jogada(0)){
                dealer->receberCarta(baralho.darCarta());
            }
        }
        cont++;
        if((cont % 1000) == 0){
            std::cout << cont << "Partidas jogadas\n" << std::endl;
        }
        this->resultado();  
    }
    std::cout << "[Motor] Treinamento concluído com sucesso!" << std::endl;
    this->modoRapido = false;
}