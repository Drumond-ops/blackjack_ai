#include "GerenciadorBD.hpp"

GerenciadorBD::GerenciadorBD(const std::string& nomeArquivo){
    sqlite3_open(("data/" + nomeArquivo).c_str(), &Data);
    criarQTable();
}

GerenciadorBD::~GerenciadorBD(){
    sqlite3_close(Data);
}

void GerenciadorBD::criarQTable(){
    std::string sql = "CREATE TABLE IF NOT EXISTS QTable ("
                      "score INT, "
                      "dealer INT, "
                      "choice INT, "
                      "Qvalue FLOAT, "
                      "PRIMARY KEY (score, dealer, choice)"
                      ");";
    
    char *erro = nullptr;
    
    int retorno = sqlite3_exec(this->Data, sql.c_str(), nullptr, nullptr, &erro);

    if(retorno != SQLITE_OK){
        std::cerr << "[ERRO!] Falha ao criar a tabela: " << erro << std::endl;
        sqlite3_free(erro);
    }
    else{
        std::cout << "[BD] Tabela Q-Learning foi criada" << std::endl;
    }

}

float GerenciadorBD::getQValue(int score, int dealer, int choice){
    std::string sql = "SELECT Qvalue FROM Qtable WHERE score = ? AND dealer = ? AND choice = ?;";
    sqlite3_stmt *stmt;
    float resultado = 0.0f;

    if(sqlite3_prepare_v2(Data, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK){
        sqlite3_bind_int(stmt, 1, score);
        sqlite3_bind_int(stmt, 2, dealer);
        sqlite3_bind_int(stmt, 3, choice);

        if(sqlite3_step(stmt) == SQLITE_ROW){
            resultado = static_cast<float>(sqlite3_column_double(stmt, 0));
        }
    }
    else{
        std::cerr << "Erro ao preparar o SELECT: " << sqlite3_errmsg(Data) << std::endl;
    }
    sqlite3_finalize(stmt);
    return resultado;
}

void GerenciadorBD::Q_update(int score, int dealer, int choice, float Qvalue) {
    std::string sql = "INSERT OR REPLACE INTO QTable (score, dealer, choice, Qvalue) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(Data, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
       
        sqlite3_bind_int(stmt, 1, score);
        sqlite3_bind_int(stmt, 2, dealer);
        sqlite3_bind_int(stmt, 3, choice);

        sqlite3_bind_double(stmt, 4, static_cast<double>(Qvalue));

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "[Erro BD] Falha ao gravar valor Q: " << sqlite3_errmsg(Data) << std::endl;
        }
    } else {
        std::cerr << "[Erro BD] Falha ao preparar INSERT: " << sqlite3_errmsg(Data) << std::endl;
    }
    sqlite3_finalize(stmt);
}