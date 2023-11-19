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
 * Version:    V1.1             Date:2023-11-18
 * *******************************************************************************
 */
#ifndef UARTDRIVER_H
#define UARTDRIVER_H

#include "UART.h"

class UARTdriver {
public:
    // Construtor com instancia de UART como parametro
    UARTdriver(UART& uart);

    // Metodos para interagir com a UART
    void readSerial();
    void printSerial(const char* data);
    void requestData();
    void deliverData(const char* data);

private:
    // Referencia de associacao da classe UART
    UART& uart;
};

#endif // UARTDRIVER_H
