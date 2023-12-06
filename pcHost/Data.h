/**
 * *******************************************************************************,
 * File:       Data.h
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
// Classe Data para pegar os dados da Queue vindos da Raspberry Pi Pico e armazenar na Lista do computador, em arquivo de texto ou entregar para exibir na tela do Menu em RealTime
#ifndef DATA_H
#define DATA_H

#include <string>
#include <queue>
#include <list>
#include <fstream>
#include "Connection.h" // Inclui o arquivo de cabeçalho da classe Connection
using namespace std;

class Data {
    private:
//        queue<string> dataQueue; // Uma fila para armazenar os dados recebidos pela porta serial
        list<string> dataList; // Uma lista para armazenar os dados da fila
    public:
        Data(); // Construtor padrão
        ~Data(); // Destrutor
        void getData(Connection* conn); // Método para solicitar os dados pela porta serial, usando um ponteiro para um objeto da classe Connection como argumento
        void saveData(); // Método para salvar os dados da lista em um arquivo .TXT
        void showData(); // Método para mostrar os dados da lista na tela
        friend class Connection; // Declara a classe Connection como amiga, para que ela possa acessar os membros privados de Data
};

#endif
