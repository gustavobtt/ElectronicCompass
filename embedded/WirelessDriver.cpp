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
 * note:       
 * 
 * Version:    V1.0             Date:2023-11-17
 * *******************************************************************************
 */
#include "WirelessDriver.h"
#include "pico/stdlib.h"

WirelessDriver::WirelessDriver(Wireless& wireless) : wireless(wireless) {
    // Inicializar configurações do módulo wireless, se necessário
}

void WirelessDriver::establishConnection() {
    // Estabelecer a conexão wireless (simulação - substitua com lógica real)
    wireless.connectTo("SSID", "password");
}

void WirelessDriver::requestData() {
    // Solicitar dados via conexão wireless (simulação - substitua com lógica real)
    wireless.getLogRequest();
}

void WirelessDriver::deliverData(const char* data) {
    // Entregar dados via conexão wireless (simulação - substitua com lógica real)
    wireless.serveLogData();
}
