/**
 * *******************************************************************************
 * File:       WirelessDriver.h
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Cabecalho da Classe de driver wireless da 5a camada de onboard driver layer
 * 
 * Version:    V1.1             Date:2023-11-18
 * *******************************************************************************
 */
#ifndef WIRELESSDRIVER_H
#define WIRELESSDRIVER_H

#include "Wireless.h"

class WirelessDriver {
public:
    // Construtor que aceita uma instancia de Wireless como parametro
    WirelessDriver(Wireless& wireless);

    // Metodos para interagir com a conexao wireless
    void establishConnection();
    void requestData();
    void deliverData(const char* data);

private:
    // Referencia de associacao para a classe Wireless
    Wireless& wireless;
};

#endif // WIRELESSDRIVER_H
