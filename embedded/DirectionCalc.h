/**
 * *******************************************************************************
 * File:       DirectionCalc.h
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Cabecalho da 3a Classe, de processamento, para calculo de direction
 *             a partir das componentes brutas rawX e rawY 
 * 
 * Version:    V1.0             Date:2023-11-17
 * *******************************************************************************
 */
#ifndef DIRECTIONCALC_H
#define DIRECTIONCALC_H

#include <string>

// Forward declaration
class Log;

class DirectionCalc {
public:
    // Construtor que aceita um objeto Log como parâmetro
    DirectionCalc(Log& log);

    // Métodos para lidar com os dados brutos e calcular a direção
    void calculateDirection();
    double getDirection() const;
    void updateLog(const std::string& logData);

private:
    // Atributos para armazenar os dados brutos
    double rawX;
    double rawY;

    // Referência à classe Log (associação)
    Log& log;

    // Método privado para obter dados brutos do MagnetometerDriver
    void getRawData();
};

#endif // DIRECTIONCALC_H
