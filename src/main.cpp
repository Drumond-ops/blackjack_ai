#include <iostream>
#include "Jogo.hpp"
#include "JogadorIA.hpp"
#include "GerenciadorBD.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;
using std::vector;

int main() {
    cout << "========================================== CASSINO C++ =============================================\n"
         << "====================================== MESA DE BLACKJACK ===========================================\n"
         << endl;

    GerenciadorBD cerebro("Banco");
    Jogador *robo = new Jogador_IA(&cerebro);
    string nome;
    cout << "Entre com o seu nome: " << endl;
    getline(cin, nome);
    Jogador *humano = new Jogador(nome);
    vector<Jogador*> IA = {robo};
    

    {//modo treino da IA
        cerebro.iniciarTransacao();
        Jogo Treinamento_IA(IA);
        cout << "===== Modo de treinamento da IA inciado \n" << endl;
        Treinamento_IA.modoTreino(15000000);
        cerebro.finalizarTransacao();
    }//Fim do modo treino*/
    
    //iniciando jogo
    robo->setTaxaExploracao(0.0f);
    
    vector<Jogador*> jogadores = {humano, robo};
    Jogo blackJack(jogadores);
    char opc;
    do{
        blackJack.iniciarPartida();
        cout << "Jogar mais uma partida? (s/n): " << endl;
        cin >> opc;
    }while(opc == 's' || opc == 'S');

    cout << "\n\n ------ Encerrando programa... --------\n\n" << endl;
}