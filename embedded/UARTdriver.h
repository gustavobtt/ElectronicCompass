/**
 * *******************************************************************************
 * File:       UARTdriver.h
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
#ifndef UARTDRIVER_H
#define UARTDRIVER_H

#include "UART.h"

class UARTdriver {
public:
    // Construtor que aceita uma instância de UART como parâmetro
    UARTdriver(UART& uart);

    // Métodos para interagir com a UART
    void readSerial();
    void printSerial(const char* data);
    void requestData();
    void deliverData(const char* data);

private:
    // Referência à classe UART (associação)
    UART& uart;
};

#endif // UARTDRIVER_H
