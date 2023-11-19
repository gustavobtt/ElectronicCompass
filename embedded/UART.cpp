/**
 * *******************************************************************************
 * File:       UART.cpp
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
#include "UART.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"

UART::UART(uint uartId, uint baudRate, uint txPin, uint rxPin) 
    : uartId(uartId), baudRate(baudRate), txPin(txPin), rxPin(rxPin) {
    // Configura funcoes dos pinos como UART
    gpio_set_function(txPin, GPIO_FUNC_UART);
    gpio_set_function(rxPin, GPIO_FUNC_UART);

    // Configura UART
    uart_init(uartId, baudRate);
    
    // Configura pinos TX e RX da UART
    uart_set_pin(uartId, txPin, rxPin, UART_PIN_DISCONNECTED, UART_PIN_DISCONNECTED);

    // Habilita a UART
    uart_set_hw_flow(uartId, false, false);  // Desativa controle de fluxo
    uart_set_format(uartId, 8, 1, UART_PARITY_NONE);  // 8 bits de dados, 1 bit de parada, sem paridade
    uart_set_fifo_enabled(uartId, false);  // Desativa buffer FIFO

    // Configura dados da instancia da UART
    uartData.txBuffer = new char[UART_BUFFER_SIZE];
    uartData.rxBuffer = new char[UART_BUFFER_SIZE];
    uartData.txIndex = 0;
    uartData.rxIndex = 0;
}

UART::~UART() {
    delete[] uartData.txBuffer;
    delete[] uartData.rxBuffer;
}

void UART::init() {
    // Inicializa a UART
}

void UART::read() {
    // Le dados da UART
    while (uart_is_readable(uartId)) {
        char data = uart_getc(uartId);
        // armazena dados em buffer
    }
}

void UART::print(const char* data) {
    // Envia dados pela UART
    for (size_t i = 0; i < strlen(data); i++) {
        uart_putc(uartId, data[i]);
    }
}

void UART::requestData() {
    // Editar a solicitacao de dados
    print("Data request");
}

void UART::deliverData(const char* data) {
    // editar o envio de dados
    print("Delivering data: ");
    print(data);
}
