/**
 * *******************************************************************************
 * File:       MagnetometerDriver.h
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
#ifndef MAGNETOMETERDRIVER_H
#define MAGNETOMETERDRIVER_H

#include <cstdint>

class MagnetometerDriver {
public:
    // Construtor que aceita os pinos SPI como parâmetros
    MagnetometerDriver(uint8_t spiBus, uint8_t spiCs, uint8_t spiSclk, uint8_t spiMiso);

    // Método para ler dados do magnetômetro via SPI
    void read();

    // Métodos para obter os dados brutos do magnetômetro
    double getRawX() const;
    double getRawY() const;

private:
    // Atributos para armazenar os pinos SPI
    uint8_t spiBus;
    uint8_t spiCs;
    uint8_t spiSclk;
    uint8_t spiMiso;

    // Atributos para armazenar os dados brutos do magnetômetro
    double rawX;
    double rawY;
};

#endif // MAGNETOMETERDRIVER_H
