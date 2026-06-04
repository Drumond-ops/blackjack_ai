#ifndef GERENCIADOR_BD_HPP
#define GERENCIADOR_BD_HPP

#include <sqlite3.h>
#include <iostream>
#include <string>


class GerenciadorBD {
    sqlite3* Data;

    void criarQTable();
public:

    GerenciadorBD(const std::string& nomeArquivo = "qlearning.db");
    ~GerenciadorBD();
    void iniciarTransacao();
    void finalizarTransacao();
    float getQValue(int score, int dealer, int choice);
    void Q_update(int score, int dealer, int choice, float Qvalue);

};

#endif