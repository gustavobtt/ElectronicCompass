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
 * note:       
 * 
 * Version:    V1.0             Date:2023-11-17
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
    // Solicitar dados (simulação - substitua com lógica real)
    uart.print("Data request");
}

void UARTdriver::deliverData(const char* data) {
    // Entregar dados (simulação - substitua com lógica real)
    uart.print("Delivering data: ");
    uart.print(data);
}
