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
    conn = new Connection(); // Cria um novo objeto da classe Connection e atribui ao ponteiro conn
    command = ""; // Inicializa a string command com uma string vazia
    response = ""; // Inicializa a string response com uma string vazia
}

// Destrutor
PicoConnection::~PicoConnection() {
    delete conn; // Deleta o objeto apontado por conn
}

// Método para enviar um comando pela porta serial, usando uma string como argumento
void PicoConnection::sendCommand(string cmd) {
    command = cmd; // Atribui a string cmd à string command
    send(command); // / Chama o método send, passando a string command como argumento
//    handleCommand(); // Chama o método handleCommand
}

// Método para receber uma resposta pela porta serial
void PicoConnection::receiveResponse() {
    response = receive(); // Chama o método receive e atribui o retorno à string response
//    handleResponse(); // Chama o método handleResponse
}

// Método para lidar com o comando enviado, de acordo com o protocolo definido
void PicoConnection::handleCommand() {
     switch (command[0]) { // Verifica o primeiro caractere da string command
         case 'T': // Se for T, significa que quer o tempo total
             cout << "Solicitando o tempo total em que a Raspberry Pi Pico está rodando e o número de records na memória dela." << endl;
             break;
         case 'D': // Se for D, significa que quer os dados do Log
             cout << "Solicitando um intervalo ou todos os dados do Log da memória da Raspberry Pi Pico e transferir para a dataQueue." << endl;
             break;
         case 'X': // Se for X, significa que quer sair
             cout << "Desativando a conexão e a porta serial." << endl;
             break;
         default: // Se for qualquer outro caractere, significa que é um comando inválido
             cout << "Comando inválido." << endl;
             break;
     }
}

// Método para lidar com a resposta recebida, de acordo com o protocolo definido
void PicoConnection::handleResponse() {
    if (response == "OK") { // Se a resposta é OK, significa que a Raspberry Pi Pico está pronta para enviar os dados
        cout << "Raspberry Pi Pico pronta para enviar os dados." << endl;
    }
    else if (response == "NOK") { // Se a resposta é NOK, significa que o intervalo de datas é inválido
        cout << "Intervalo de datas inválido. Por favor, digite novamente." << endl;
    }
    else { // Se a resposta é um dado ou um número de registros
        cout << "Recebendo um dado do Log: " << response << endl;
        conn->dataQueue.push(response); // Adiciona o dado na fila dataQueue da classe Connection, usando o ponteiro conn
    }
}

// Método para enviar um comando pela porta serial
 void PicoConnection::send(string message) override {
     conn->send(message); // Chama o método send do objeto apontado por conn, passando a mensagem como argumento
 }
 
 // Método para receber uma resposta pela porta serial
 string PicoConnection::receive() override {
     return conn->receive(); // Chama o método receive do objeto apontado por conn e retorna o resultado
 }
