/**
 * *******************************************************************************
 * File:       HeadingDisplay.h
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Cabecalho da Classe de 2a camada de Aplication/Control
 * 
 * Version:    V1.0             Date:2023-11-17
 * *******************************************************************************
 */
#ifndef HEADINGDISPLAY_H
#define HEADINGDISPLAY_H

#include "DirectionCalc.h"  // Incluindo a classe DirectionCalc
#include "GPIOdriver.h"           // Incluindo a classe GPIOdriver

class HeadingDisplay {
public:
    // Construtor que aceita um DirectionCalc e um GPIOdriver como parametros
    HeadingDisplay(DirectionCalc& directionCalc, GPIOdriver& gpioDriver);

    // Metodos de acesso
    double getCurrentDirection() const;
    void setCurrentHeading(double heading);

    // Metodo para mostrar a direcao atual
    void showCurrentHeading() const;

private:
    // Atributo para armazenar a direcao atual
    double currentHeading;

    // Associacao com a classe DirectionCalc (ponteiro, pois nao eh proprietaria)
    DirectionCalc* directionCalc;

    // Associacao com a classe GPIOdriver (ponteiro, pois nao eh proprietaria)
    GPIOdriver* gpioDriver;
};

#endif // HEADINGDISPLAY_H
