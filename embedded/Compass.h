/**
 * *******************************************************************************
 * File:       Compass.h
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Cabecalho da Classe Compass da Layer User Interaction, a mais externa
 * 
 * Version:    V1.1             Date:2023-11-17
 * *******************************************************************************
 */
#ifndef COMPASS_H //diretiva de pre-processador garantem inclusao apenas uma vez
#define COMPASS_H

#include <string>

// Declarando a classe Compass
class Compass {
public:
    // Construtor que aceita um ID como parametro
    Compass(int id);

    // Metodos de acesso p obter ID, Heading, Data
    int getID() const;
    double getHeading() const;
    std::string getData() const;

    // Metodos para conexao
    void connectUART();
    void connectWiFi();

private:
    // Atributos da classe
    int ID;                // Identificacao da bussola eletronica
    double heading;        // Direcao da bussola
    std::string log;       // Log de dados
    bool UARTconnection;   // Estado da conexao UART
    bool WIFIconnection;   // Estado da conexao WiFi
};

#endif // Fecha a diretiva #ifndef de COMPASS_H
