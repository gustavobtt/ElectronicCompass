/**
 * *******************************************************************************,
 * File:       Connection.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Implementacao da classe de coneccao
 * 
 * Version:    V1.2             Date:2023-12-06
 * *******************************************************************************
 */
#include "Connection.h"

// Construtor padrão
Connection::Connection() {
    portName = "/dev/ttyUSB0"; // Define o nome da porta serial como /dev/ttyUSB0
    baudRate = 115200; // Define a taxa de transmissao como 115200 bps
    port = NULL; // Inicializa o ponteiro port com NULL
    connected = false; // Inicializa o booleano connected com false
    pico = new PicoConnection(); // Cria um novo objeto da classe PicoConnection e atribui ao ponteiro pico
}

// Destrutor
Connection::~Connection() {
    disconnect(); // Chama o método disconnect
    delete pico; // Deleta o objeto apontado por pico
}

// Método para conectar a porta serial
void Connection::connect() {
    if (!connected) { // Se não esta conectado
        port = new SerialPort(portName.c_str(), baudRate); // Cria um novo objeto da classe SerialPort e atribui ao ponteiro port
        if (port->isConnected()) { // Se o objeto apontado por port esta conectado
            connected = true; // Atribui true ao booleano connected
            cout << "Conexão estabelecida com sucesso." << endl;
        }
        else { // Se o objeto apontado por port não esta conectado
            cout << "Erro ao conectar a porta serial." << endl;
        }
    }
    else { // Se ja esta conectado
        cout << "Voce ja esta conectado." << endl;
    }
}

// Método para desconectar a porta serial
void Connection::disconnect() {
    if (connected) { // Se esta conectado
        delete port; // Deleta o objeto apontado por port
        connected = false; // Atribui false ao booleano connected
        cout << "Conexão encerrada com sucesso." << endl;
    }
}

// Método para enviar uma mensagem pela porta serial
void Connection::send(string message) {
    if (connected) { // Se esta conectado
        port->writeSerialPort(message.c_str(), message.length()); // Chama o método writeSerialPort do objeto apontado por port, passando a mensagem e o seu tamanho como argumentos
    }
}

// Método para receber uma mensagem pela porta serial
string Connection::receive() {
    if (connected) { // Se esta conectado
        char buffer[256]; // Cria um buffer de 256 bytes
        int bytes = port->readSerialPort(buffer, 256); // Chama o método readSerialPort do objeto apontado por port, passando o buffer e o seu tamanho como argumentos, e armazena o número de bytes lidos na variavel bytes
        if (bytes > 0) { // Se o número de bytes lidos é maior que zero
            string message(buffer, bytes); // Cria uma string com o conteúdo do buffer e o número de bytes lidos
            return message; // Retorna a string
        }
    }
    return ""; // Retorna uma string vazia
}

// Método para desativar a conexão e a porta serial
void Connection::exit() {
    if (connected) { // Se está conectado
        send("X"); // Envia o caractere X pela porta serial, indicando que quer sair
        disconnect(); // Chama o método disconnect
    }
    else { // Se não está conectado
        cout << "Você já está desconectado." << endl;
    }
}