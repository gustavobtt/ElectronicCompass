/**
 * *******************************************************************************
 * File:       GPIOdriver.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Implementacao da Classe de driver GPIO da 5a camada de onboard
 *             driver layer
 * 
 * Version:    V1.1             Date:2023-11-18
 * *******************************************************************************
 */
#include "MagnetometerDriver.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"

MagnetometerDriver::MagnetometerDriver(uint8_t spiBus, uint8_t spiCs, uint8_t spiSclk, uint8_t spiMiso)
    : spiBus(spiBus), spiCs(spiCs), spiSclk(spiSclk), spiMiso(spiMiso), rawX(0.0), rawY(0.0) {
    // Configura o hardware SPI
    spi_init(spiBus, 100 * 1000 * 1000);  // 100 MHz
    gpio_set_function(spiCs, GPIO_FUNC_SPI);
    gpio_set_function(spiSclk, GPIO_FUNC_SPI);
    gpio_set_function(spiMiso, GPIO_FUNC_SPI);

    // Configura o pino de chip select
    gpio_init(spiCs);
    gpio_set_dir(spiCs, GPIO_OUT);
    gpio_put(spiCs, 1);  // Desativa inicialmente o chip select
}

void MagnetometerDriver::read() {
    // Ativa o chip select para iniciar a comunicacao SPI
    gpio_put(spiCs, 0);

    // Configura a SPI
    spi_transaction_t transaction = {};
    transaction.tx_buffer = nullptr;
    transaction.rx_buffer = nullptr;
    transaction.length = 16;  // 16 bits

    // Realiza a SPI
    spi_transaction_blocking(spiBus, &transaction);

    // Desativa o chip select para finalizar a comunicacao SPI
    gpio_put(spiCs, 1);

    // Implementar o destino dos dados aqui
    rawX = 1.0;
    rawY = 2.0;
}

double MagnetometerDriver::getRawX() const {
    return rawX;
}

double MagnetometerDriver::getRawY() const {
    return rawY;
}
