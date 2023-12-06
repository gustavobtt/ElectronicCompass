/**
 * *******************************************************************************,
 * File:       TotalTime.h
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
// Classe TotalTime para lidar com o tempo total de funcionamento e entregar para exibir na tela do Menu
#ifndef TOTALTIME_H
#define TOTALTIME_H

#include <string>
#include "Connection.h" // Inclui o arquivo de cabeçalho da classe Connection
using namespace std;

class TotalTime {
    private:
        string totalTime; // Uma string para armazenar o tempo total
    public:
        TotalTime(); // Construtor padrão
        ~TotalTime(); // Destrutor
        void getTotalTime(Connection* conn); // Método para solicitar o tempo total pela porta serial, usando um ponteiro para um objeto da classe Connection como argumento
        void showTotalTime(); // Método para mostrar o tempo total na tela
};

#endif