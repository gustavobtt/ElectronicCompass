/**
 * *******************************************************************************
 * File:       Wirelless.h
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Cabecalho da Classe de comunicacao Wireless 2a camada de Aplication/Control
 * 
 * Version:    V1.1             Date:2023-11-18
 * *******************************************************************************
 */
#ifndef WIRELESS_H
#define WIRELESS_H

#include "Compass.h"           // Incluindo a classe Compass
#include "Log.h"               // Incluindo a classe Log
#include "WirelessDriver.h"    // Incluindo a classe WirelessDriver

class Wireless {
public:
    // Construtor que aceita um objeto Compass, um objeto Log e um objeto WirelessDriver como parametros
    Wireless(Compass& compass, Log& log, WirelessDriver& wirelessDriver);

    // Metodo para conectar a dispositivo sem fio
    void connectTo(WirelessDevice& wirelessDevice);

    // Metodos para solicitar e enviar dados de log
    void getLogRequest() const;
    void serveLogData() const;

private:
    // Atributo para armazenar o dispositivo conectado sem fio
    WirelessDevice* wirelessConnectedDevice;

    // Agregacao com a classe Compass (objeto, pois eh proprietaria)
    Compass compass;

    // Associacao com a classe Log (referencia, pois nao eh proprietaria)
    Log& log;

    // Associacao com a classe WirelessDriver (ponteiro, pois nao eh proprietaria)
    WirelessDriver* wirelessDriver;
};

#endif // WIRELESS_H
