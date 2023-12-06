/**
 * *******************************************************************************,
 * File:       TotalTime.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       
 * 
 * Version:    V1.0             Date:2023-12-06
 * *******************************************************************************
 */

#include "TotalTime.h"

// Construtor padrão
TotalTime::TotalTime() {
    totalTime = ""; // Inicializa a string totalTime com uma string vazia
}

// Destrutor
TotalTime::~TotalTime() {
    // Não há nada para deletar
}

// Método para solicitar o tempo total pela porta serial, usando um ponteiro para um objeto da classe Connection como argumento
void TotalTime::getTotalTime(Connection* conn) {
    conn->send("T"); // Chama o método send do objeto apontado por conn, passando o caractere T como argumento, indicando que quer o tempo total
    string response = conn->receive(); // Chama o método receive do objeto apontado por conn e armazena a resposta na string response
    if (!response.empty()) { // Se a resposta não está vazia
        totalTime = response; // Atribui a resposta à string totalTime
    }
    else { // Se a resposta está vazia
        cout << "Erro ao receber o tempo total." << endl;
    }
}

// Método para mostrar o tempo total na tela
void TotalTime::showTotalTime() {
    if (!totalTime.empty()) { // Se a string totalTime não está vazia
        cout << "Tempo total: " << totalTime << endl; // Imprime o tempo total na tela
    }
    else { // Se a string totalTime está vazia
        cout << "Não há tempo total para mostrar." << endl;
    }
}
