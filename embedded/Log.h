/**
 * *******************************************************************************
 * File:       Log.h
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Cabecalho da Classe de Log/fila da 2a camada de Aplication/Control
 * 
 * Version:    V1.1             Date:2023-11-17
 * *******************************************************************************
 */
#ifndef LOG_H
#define LOG_H

#include <queue>
#include <string>
#include "Compass.h"  // Incluindo a classe Compass
#include "DirectionCalc.h" // Incluindo a classe DirectionCalc
#include "UART.h"             // Incluindo a classe UART/USB
#include "Wireless.h"            // Incluindo a classe Wireless

class Log {
public:
    // Construtor que aceita objetos relacionados como parametros
    Log(Compass& compass, DirectionCalc& directionCalc, UART& uart, Wireless& wireless);

    // Metodo para adicionar um log a fila
    void addLog(int ID, const std::string& timestamp, const std::string& data);

    // Metodo para obter o tamanho da fila de logs
    size_t getLogSize() const;

    // Metodo para limpar a fila de logs
    void clearLog();

private:
    // Fila de logs
    std::queue<std::string> logQueue;

    // Associacao de agregacao com a classe Compass (objeto, pois eh proprietaria)
    Compass compass;

    // Associacao com a classe DirectionCalc (ponteiro, pois nao e proprietaria)
    DirectionCalc* directionCalc;

    // Associacao com a classe UART (ponteiro, pois nao e proprietaria)
    UART* uart;

    // Associacao com a classe Wireless (ponteiro, pois nao e proprietaria)
    Wireless* wireless;
};

#endif // LOG_H