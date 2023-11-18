/**
 * *******************************************************************************
 * File:       DirectionCalc.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       RASCUNHO Implementacao dos metodos para a classe de processamento 
 *             DirectionCalc
 * 
 * Version:    V0.0             Date:2023-11-17
 * *******************************************************************************
 */
#include "DirectionCalc.h"
#include "Log.h"  // Incluindo a definicao completa da classe Log

// Construtor que inicializa a referencia ao objeto Log
DirectionCalc::DirectionCalc(Log& log) : log(log), rawX(0.0), rawY(0.0) {
    // Inicializar outros membros, se necessario
}

// Metodo para calcular a direcao com base nos dados brutos
void DirectionCalc::calculateDirection() {
    // Simulacao de calculos SUBSTITUIR DEPOIS PELOS CALCULOS REAIS
    rawX = 1.0;  
    rawY = 2.0;

    // Realizar calculos para obter a direcao
    // (substituir com a logica real)
    double calculatedDirection = rawX + rawY;

    // Atualizar o log com dados 
    updateLog("Direction calculated: " + std::to_string(calculatedDirection));
}

// Metodo para obter a direcao calculada
double DirectionCalc::getDirection() const {
    return rawX + rawY;  // Substitua com a logica real, se necessario
}

// Metodo para atualizar o log com dados 
void DirectionCalc::updateLog(const std::string& logData) {
    log.addLog(1, "timestamp", logData);  // Substiir com a logica real, se necessario
}

// Metodo privado para obter dados brutos do MagnetometerDriver
void DirectionCalc::getRawData() {
    // Simulacao de obtencao de dados brutos - substitua com a logica real
    rawX = 1.0;
    rawY = 2.0;
}