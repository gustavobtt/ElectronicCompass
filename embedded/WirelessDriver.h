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
 * note:       
 * 
 * Version:    V1.0             Date:2023-11-17
 * *******************************************************************************
 */
#ifndef WIRELESSDRIVER_H
#define WIRELESSDRIVER_H

#include "Wireless.h"

class WirelessDriver {
public:
    // Construtor que aceita uma instância de Wireless como parâmetro
    WirelessDriver(Wireless& wireless);

    // Métodos para interagir com a conexão wireless
    void establishConnection();
    void requestData();
    void deliverData(const char* data);

private:
    // Referência à classe Wireless (associação)
    Wireless& wireless;
};

#endif // WIRELESSDRIVER_H
