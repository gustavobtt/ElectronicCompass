/**
 * *******************************************************************************
 * File:       menu.h
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Cabecalho da Classe de menu para o Host PC
 * 
 * Version:    V1.2             Date:2023-12-06
 * *******************************************************************************
 */
// Classe Menu para imprimir na tela as opcoes disponiveis e receber a entrada do usuario
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "Connection.h" // Inclui o arquivo de cabecalho da classe Connection
#include "Data.h" // Inclui o arquivo de cabeçalho da classe Data
#include "TotalTime.h" // Inclui o arquivo de cabeçalho da classe TotalTime
using namespace std;

class Menu {
    private:
        Connection* conn; // Um ponteiro para um objeto da classe Connection
        string input; // Uma string para armazenar a entrada do usuario
        Data* data; // Um ponteiro para um objeto da classe Data
        TotalTime* totalTime; // Um ponteiro para um objeto da classe TotalTime
    public:
        Menu(); // Construtor padrao
        ~Menu(); // Destrutor
        void show(); // Metodo para mostrar o menu na tela
        void handleInput(); // Metodo para lidar com a entrada do usuario
};

#endif
