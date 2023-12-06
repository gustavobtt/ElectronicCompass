/**
 * *******************************************************************************
 * File:       Log.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Implementacao da Classe de Log/fila da 2a camada de Aplication/Control
 * 
 * Version:    V1.3             Date:2023-12-06
 * *******************************************************************************
 */
#include "Log.h"
#include "pico/stdlib.h"  // conferir biblioteca da Raspberry Pi Pico

// Implementação do construtor (mantido conforme necessário)
Log::Log(Compass& compass, DirectionCalc& directionCalc, UART& uart, Wireless& wireless)
    : compass(compass), directionCalc(&directionCalc), uart(&uart), wireless(&wireless) {
    // Inicialização conforme necessário
}

// Implementação da sobrecarga do operador <<
Log& Log::operator<<(const std::string& logData) {
    // Adiciona o log na fila
    logQueue.push(logData);
    return *this;
}

// Implementação do método para obter o tamanho da fila de logs
size_t Log::getLogSize() const {
    return logQueue.size();
}

// Implementação do método para limpar a fila de logs
void Log::clearLog() {
    while (!logQueue.empty()) {
        logQueue.pop();
    }
}