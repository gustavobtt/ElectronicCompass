/**
 * *******************************************************************************
 * File:       HeadingDisplay.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Implementacao da classe HeadingDisplay que vai mostrar o apontamento
 *             da bussola eletronica
 * 
 * Version:    V1.0             Date:2023-11-18
 * *******************************************************************************
 */
#include "HeadingDisplay.h"
#include <iostream>  // Ajustr conforme a biblioteca disponivel na Raspberry Pi Pico

HeadingDisplay::HeadingDisplay(DirectionCalculator& directionCalculator)
    : currentHeading(0.0), directionCalculator(directionCalculator) {}

void HeadingDisplay::showCurrentHeading() {
    // Logica para exibir direcao a ser ajustada
    std::cout << "Current Heading: " << getCurrentDirection() << " degrees" << std::endl;
}

double HeadingDisplay::getCurrentDirection() const {
    return currentHeading;
}

void HeadingDisplay::setCurrentHeading(double heading) {
    currentHeading = heading;
}