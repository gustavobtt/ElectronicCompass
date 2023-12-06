/**
 * *******************************************************************************,
 * File:       PicoConnection.h
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
// Classe PicoConnection para garantir a comunicação com a Raspberry Pi Pico via UART conectada na porta COM do computador
#ifndef PICOCONNECTION_H
#define PICOCONNECTION_H

#include <string>
#include "Connection.h" // Inclui o arquivo de cabeçalho da classe Connection
using namespace std;

class PicoConnection {
    private:
        Connection* conn; // Um ponteiro para um objeto da classe Connection
        string command; // Uma string para armazenar o comando enviado pela porta serial
        string response; // Uma string para armazenar a resposta recebida pela porta serial
    public:
        PicoConnection(); // Construtor padrão
        ~PicoConnection(); // Destrutor
        void sendCommand(string cmd); // Método para enviar um comando pela porta serial, usando uma string como argumento
        void receiveResponse(); // Método para receber uma resposta pela porta serial
        void handleCommand(); // Método para lidar com o comando enviado, de acordo com o protocolo definido
        void handleResponse(); // Método para lidar com a resposta recebida, de acordo com o protocolo definido
};

#endif
