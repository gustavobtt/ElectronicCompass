/**
 * *******************************************************************************,
 * File:       Calendar.hpp
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

//classe de dia, mes e ano

#ifndef _CALENDAR_HPP_
#define _CALENDAR_HPP_

class Calendar {
public:
    Calendar(int t_day, int t_month, int t_year);
    ~Calendar();
    void setCalendar(int t_day, int t_month, int t_year);
    void readCalendar(int& t_day, int& t_month, int& t_year);
    void advance();

protected:
    int m_day;
    int m_month;
    int m_year;
};

#endif /* _CALENDAR_HPP_ */
