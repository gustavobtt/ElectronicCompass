/**
 * *******************************************************************************,
 * File:       Connection.h
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Cabecalho da classe para estabelecer conexao
 * 
 * Version:    V1.2             Date:2023-12-06
 * *******************************************************************************
 */
// Classe Connection para habilitar a porta serial e estabelecer a comunicacao pela porta serial USB do computador uma Raspberry Pi Pico
#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include "PicoConnection.h" // Inclui o arquivo de cabeçalho da classe PicoConnection
#include "SerialPort.h" // Inclui o arquivo de cabecalho da classe SerialPort
#include <queue>
using namespace std;

class Connection {
    private:
        SerialPort* port; // Um ponteiro para um objeto da classe SerialPort
        PicoConnection* device; // Um ponteiro para um objeto da classe PicoConnection
        string portName; // Uma string para armazenar o nome da porta serial
        int baudRate; // Um inteiro para armazenar a taxa de transmissao em bits por segundo
        bool connected; // Um booleano para indicar se a conexao esta estabelecida ou nao
    public:
        Connection(); // Construtor padrao
        ~Connection(); // Destrutor
        void connect(); // Metodo para conectar a porta serial
        void disconnect(); // Metodo para desconectar a porta serial
        virtual void send(string message); // Metodo para enviar uma mensagem pela porta serial
        virtual string receive(); // Metodo para receber uma mensagem pela porta serial
//        void totalTime(); // Metodo para solicitar o tempo total em que a Raspberry Pi Pico esta rodando e o numero de records na memoria dela
//        void getData(); // Metodo para solicitar um intervalo ou todos os dados do Log da memoria da Raspberry Pi Pico e transferir para a dataQueue
//        void saveData(); // Metodo para salvar em arquivo .TXT linha a linha os dados da dataQueue
        void exit(); // Metodo para desativar a conexao e a porta serial
        friend class Data; // Declara a classe Data como amiga, para que ela possa acessar os membros privados de Connection
        queue<string> dataQueue; // Uma fila para armazenar os dados recebidos pela porta serial, declarada como pública para que a classe Data possa acessá-la
};

#endif
