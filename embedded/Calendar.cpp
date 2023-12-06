/**
 * *******************************************************************************,
 * File:       Calendar.cpp
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
#include "Calendar.hpp"

Calendar::Calendar(int t_day, int t_month, int t_year) : m_day(t_day), m_month(t_month), m_year(t_year) {
    // Construtor da classe Calendar.
    // Inicializa os membros de dados m_day, m_month e m_year com os valores fornecidos.
}

Calendar::~Calendar() {
    // Destrutor da classe Calendar.
    // Não há operações específicas de destruição a serem realizadas aqui.
}

void Calendar::setCalendar(int t_day, int t_month, int t_year) {
    // Método para definir a data do calendário com novos valores.
    m_day = t_day;
    m_month = t_month;
    m_year = t_year;
}

void Calendar::readCalendar(int& t_day, int& t_month, int& t_year) {
    // Método para obter a data do calendário.
    // Os valores são passados por referência nos parâmetros para retornar múltiplos valores.
    t_day = m_day;
    t_month = m_month;
    t_year = m_year;
}

void Calendar::advance() {
    // Método para avançar a data do calendário.
    m_day++;
    if (m_day > 30) {
        m_day = 1;
        m_month++;
        if (m_month > 12) {
            m_month = 1;
            m_year++;
        }
    }
    // Esta implementação assume um calendário simples com meses de 30 dias.
    // Pode ser ajustada conforme a lógica do calendário real que está sendo modelado.
}
