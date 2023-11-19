/**
 * *******************************************************************************
 * File:       MagnetometerDriver.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Implementacao da Classe de driver do magnetometro da 4a camada de external
 *             driver layer
 * 
 * Version:    V1.0             Date:2023-11-17
 * *******************************************************************************
 */
#include "MagnetometerDriver.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"

MagnetometerDriver::MagnetometerDriver(uint8_t spiBus, uint8_t spiCs, uint8_t spiSclk, uint8_t spiMiso)
    : spiBus(spiBus), spiCs(spiCs), spiSclk(spiSclk), spiMiso(spiMiso), rawX(0.0), rawY(0.0) {
    // Configurar o hardware SPI
    spi_init(spiBus, 100 * 1000 * 1000);  // 100 MHz
    gpio_set_function(spiCs, GPIO_FUNC_SPI);
    gpio_set_function(spiSclk, GPIO_FUNC_SPI);
    gpio_set_function(spiMiso, GPIO_FUNC_SPI);

    // Configurar o pino de chip select
    gpio_init(spiCs);
    gpio_set_dir(spiCs, GPIO_OUT);
    gpio_put(spiCs, 1);  // Desativar inicialmente o chip select
}

void MagnetometerDriver::read() {
    // Ativar o chip select para iniciar a comunicação SPI
    gpio_put(spiCs, 0);

    // Configurar a transação SPI
    spi_transaction_t transaction = {};
    transaction.tx_buffer = nullptr;
    transaction.rx_buffer = nullptr;
    transaction.length = 16;  // 16 bits

    // Realizar a transação SPI
    spi_transaction_blocking(spiBus, &transaction);

    // Desativar o chip select para finalizar a comunicação SPI
    gpio_put(spiCs, 1);

    // Processar os dados brutos recebidos (simulação - substitua com lógica real)
    rawX = 1.0;
    rawY = 2.0;
}

double MagnetometerDriver::getRawX() const {
    return rawX;
}

double MagnetometerDriver::getRawY() const {
    return rawY;
}
