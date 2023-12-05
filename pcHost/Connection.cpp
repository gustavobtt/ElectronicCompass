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
 * Version:    V1.0             Date:2023-11-22
 * *******************************************************************************
 */
#include "Connection.h"

// Construtor padrão
Connection::Connection() {
    portName = "/dev/ttyUSB0"; // Define o nome da porta serial como /dev/ttyUSB0
    baudRate = 115200; // Define a taxa de transmissão como 115200 bps
    port = NULL; // Inicializa o ponteiro port com NULL
    connected = false; // Inicializa o booleano connected com false
}

// Destrutor
Connection::~Connection() {
    disconnect(); // Chama o método disconnect
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

// Método para solicitar o tempo total em que a Raspberry Pi Pico esta rodando e o número de records na memória dela
void Connection::totalTime() {
    if (connected) { // Se esta conectado
        send("T"); // Envia o caractere T pela porta serial, indicando que quer o tempo total
        string response = receive(); // Recebe a resposta pela porta serial e armazena na string response
        if (!response.empty()) { // Se a resposta não esta vazia
            cout << "Tempo total: " << response << endl; // Imprime o tempo total na tela
        }
        else { // Se a resposta esta vazia
            cout << "Erro ao receber o tempo total." << endl;
        }
    }
    else { // Se não esta conectado
        cout << "Voce precisa se conectar primeiro." << endl;
    }
}
// Método para salvar em arquivo .TXT linha a linha os dados da dataQueue
void Connection::saveData() {
    if (connected) { // Se esta conectado
        if (!dataQueue.empty()) { // Se a fila dataQueue não esta vazia
            ofstream file; // Cria um objeto da classe ofstream para manipular o arquivo
            file.open("data.txt"); // Abre o arquivo data.txt
            if (file.is_open()) { // Se o arquivo esta aberto
                while (!dataQueue.empty()) { // Enquanto a fila dataQueue não esta vazia
                    string data = dataQueue.front(); // Obtém o elemento da frente da fila dataQueue e armazena na string data
                    file << data << endl; // Escreve a string data no arquivo, seguida de uma quebra de linha
                    dataQueue.pop(); // Remove o elemento da frente da fila dataQueue
                }
                file.close(); // Fecha o arquivo
                cout << "Dados salvos com sucesso." << endl;
            }
            else { // Se o arquivo não esta aberto
                cout << "Erro ao abrir o arquivo." << endl;
            }
        }
        else { // Se a fila dataQueue esta vazia
            cout << "Não ha dados para salvar." << endl;
        }
    }
    else { // Se não esta conectado
        cout << "Voce precisa se conectar primeiro." << endl;
    }
}
// Método para solic