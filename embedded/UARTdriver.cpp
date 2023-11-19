/**
 * *******************************************************************************
 * File:       UARTdriver.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Implementacao da Classe de driver serial 5a camada de onboard
 *             driver layer
 * 
 * Version:    V1.1             Date:2023-11-18
 * *******************************************************************************
 */
#include "UARTdriver.h"
#include "pico/stdlib.h"

UARTdriver::UARTdriver(UART& uart) : uart(uart) {
    // Inicializar a UART
    uart.init();
}

void UARTdriver::readSerial() {
    // Ler dados da porta serial
    uart.read();
}

void UARTdriver::printSerial(const char* data) {
    // Enviar dados para a porta serial
    uart.print(data);
}

void UARTdriver::requestData() {
    // Implementar conforme funcao requestData()
    uart.print("Data request");
}

void UARTdriver::deliverData(const char* data) {
    // Implementar conforme funcao deliveryData()
    uart.print("Delivering data: ");
    uart.print(data);
}
