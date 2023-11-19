/**
 * *******************************************************************************
 * File:       WirelessDriver.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Implementacao da classe WirelessDriver da 5a camada de onboard
 *             driver layer
 * 
 * Version:    V1.1             Date:2023-11-18
 * *******************************************************************************
 */
#include "WirelessDriver.h"
#include "pico/stdlib.h"

WirelessDriver::WirelessDriver(Wireless& wireless) : wireless(wireless) {
    // Inicializar configuracoes do modulo wireless
}

void WirelessDriver::establishConnection() {
    // Implementar aqui a parte que estabelece conexao wireless
    wireless.connectTo("SSID", "password");
}

void WirelessDriver::requestData() {
    // Implementar aqui requestData()
    wireless.getLogRequest();
}

void WirelessDriver::deliverData(const char* data) {
    // // Implementar aqui deliveryData()
    wireless.serveLogData();
}
