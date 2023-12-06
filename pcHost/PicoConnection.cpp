/**
 * *******************************************************************************,
 * File:       PicoConnection.cpp
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
#include "PicoConnection.h"

// Construtor padrão
PicoConnection::PicoConnection() {
    conn = NULL; // Inicializa o ponteiro conn com NULL
    command = ""; // Inicializa a string command com uma string vazia
    response = ""; // Inicializa a string response com uma string vazia
}

// Destrutor
PicoConnection::~PicoConnection() {
    // Não há nada para deletar
}

// Método para enviar um comando pela porta serial, usando uma string como argumento
void PicoConnection::sendCommand(string cmd) {
    command = cmd; // Atribui a string cmd à string command
    conn->send(command); // Chama o método send do objeto apontado por conn, passando a string command como argumento
    handleCommand(); // Chama o método handleCommand
}

// Método para receber uma resposta pela porta serial
void PicoConnection::receiveResponse() {
    response = conn->receive(); // Chama o método receive do objeto apontado por conn e armazena a resposta na string response
    handleResponse(); // Chama o método handleResponse
}

// Método para lidar com o comando enviado, de acordo com o protocolo definido
void PicoConnection::handleCommand() {
    if (command == "T") { // Se o comando é T, significa que quer o tempo total
        // Não há nada para fazer, apenas aguardar a resposta
    }
    else if (command == "D") { // Se o comando é D, significa que quer os dados do Log
        // Não há nada para fazer, apenas aguardar a resposta
    }
    else if (command == "X") { // Se o comando é X, significa que quer sair
        // Não há nada para fazer, apenas aguardar a resposta
    }
    else { // Se o comando é um intervalo de datas
        // Não há nada para fazer, apenas aguardar a resposta
    }
}

// Método para lidar com a resposta recebida, de acordo com o protocolo definido
void PicoConnection::handleResponse() {
    if (response == "OK") { // Se a resposta é OK, significa que a Raspberry Pi Pico está pronta para enviar os dados
        // Não há nada para fazer, apenas aguardar os dados
    }
    else if (response == "NOK") { // Se a resposta é NOK, significa que o intervalo de datas é inválido
        // Não há nada para fazer, apenas informar o usuário
    }
    else { // Se a resposta é um dado ou um número de registros
        // Não há nada para fazer, apenas armazenar ou mostrar o dado
    }
}
