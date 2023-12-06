/**
 * *******************************************************************************,
 * File:       ClockCalendar.cpp
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
#include "ClockCalendar.hpp"

ClockCalendar::ClockCalendar(int t_day, int t_month, int t_year, int t_hr, int t_min, int t_sec, int t_isPm)
    : Clock(t_hr, t_min, t_sec, t_isPm), Calendar(t_day, t_month, t_year) {
    // O construtor de ClockCalendar chama explicitamente os construtores de Clock e Calendar
}

void ClockCalendar::advance() {
    bool wasPM = m_isPM;
    Clock::advance(); // Chama a função advance() da classe base Clock
    if (wasPM && !m_isPM) {
        Calendar::advance(); // Chama a função advance() da classe base Calendar
    }
}
