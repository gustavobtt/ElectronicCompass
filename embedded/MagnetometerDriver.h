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
 * note:       Cabecalho da Classe de driver do magnetometro da 4a camada de external
 *             driver layer
 * 
 * Version:    V1.1             Date:2023-11-18
 * *******************************************************************************
 */
#ifndef MAGNETOMETERDRIVER_H
#define MAGNETOMETERDRIVER_H

#include <cstdint>

class MagnetometerDriver {
public:
    // Construtor que aceita os pinos SPI como parametros
    MagnetometerDriver(uint8_t spiBus, uint8_t spiCs, uint8_t spiSclk, uint8_t spiMiso);

    // Método para ler dados do magnetometro via SPI
    void read();

    // Metodos para obter os dados brutos do magnetometro
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
