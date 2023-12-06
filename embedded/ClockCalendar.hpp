/**
 * *******************************************************************************,
 * File:       ClockCalendar.hpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       
 * 
 * Version:    V1.0             Date:2023-12-06
 * *******************************************************************************
 */

//Classe de data e hora derivada de Clock e Calendar

#include "ClockCalendar.hpp"

ClockCalendar::ClockCalendar(int t_day, int t_month, int t_year, int t_hr, int t_min, int t_sec, int t_isPm)
    : Clock(t_hr, t_min, t_sec, t_isPm), Calendar(t_day, t_month, t_year) {
    // Inicializa a classe base Clock com os parâmetros relacionados ao tempo
    // Inicializa a classe base Calendar com os parâmetros relacionados à data
}

void ClockCalendar::advance() {
    // Implementação da função advance para a classe ClockCalendar
    // Esta função pode chamar as funções advance() das classes base Clock e Calendar conforme necessário
}
