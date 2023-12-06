/**
 * *******************************************************************************,
 * File:       Clock.cpp
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
#include "Clock.hpp"

Clock::Clock(int t_hr, int t_min, int t_sec, bool t_isPm) : m_hr(t_hr), m_min(t_min), m_sec(t_sec), m_isPM(t_isPm) {
    // Inicializa os membros da classe com os valores fornecidos nos parâmetros do construtor
}

Clock::~Clock() {
    // O destrutor é vazio, pois não há necessidade de liberar recursos manualmente
}

void Clock::setClock(int t_hr, int t_min, int t_sec, bool t_isPm) {
    // Atualiza os valores do relógio com os valores fornecidos nos parâmetros
    m_hr = t_hr;
    m_min = t_min;
    m_sec = t_sec;
    m_isPM = t_isPm;
}

void Clock::readClock(int& t_hr, int& t_min, int& t_sec, bool& t_isPm) {
    // Retorna os valores do relógio nos parâmetros fornecidos por referência
    t_hr = m_hr;
    t_min = m_min;
    t_sec = m_sec;
    t_isPm = m_isPM;
}

void Clock::advance() {
    // Avança o relógio em um segundo, manipulando horas, minutos e período (AM/PM) conforme necessário
    m_sec++;
    if (m_sec > 59) {
        m_sec = 0;
        m_min++;
        if (m_min > 59) {
            m_min = 0;
            m_hr++;
            if (m_hr == 12) {
                if (m_isPM) {
                    m_hr = 0;
                    m_isPM = false;
                }
                else {
                    m_isPM = true;
                }
            }
            else if (m_hr > 12) {
                m_hr = 1;
            }
        }
    }
}
