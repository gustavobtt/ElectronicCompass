/**
 * *******************************************************************************
 * File:       UART.h
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Cabecalho da Classe de comunicacao serial 2a camada de Aplication/Control
 * 
 * Version:    V1.0             Date:2023-11-17
 * *******************************************************************************
 */
#ifndef UARTUSB_H
#define UARTUSB_H

#include "Compass.h"  // Incluindo a classe Compass
#include "UARTdriver.h"         // Incluindo a classe UARTdriver
#include "Log.h"                // Incluindo a classe Log

class UARTUSB {
public:
    // Construtor p objetos Compass e UARTdriver como parametros
    UARTUSB(Compass& compass, UARTdriver& uartDriver, Log& log);

    // Metodo para conectar a UART a um dispositivo
    void connectTo(UARTdevice& uartDevice);

    // Metodos para interagir com o log
    void viewLog() const;
    void downloadLog() const;
    void clearLog();

private:
    // Atributo para armazenar o dispositivo conectado a UART
    UARTdevice* UARTconnectedDevice;

    // Agregacao com a classe Compass (objeto, pois eh proprietaria)
    Compass compass;

    // Associacao com a classe UARTdriver (ponteiro, pois nao eh proprietaria)
    UARTdriver* uartDriver;

    // Associacao com a classe Log (referencia, pois nao eh proprietaria)
    Log& log;
};

#endif // UARTUSB_H
