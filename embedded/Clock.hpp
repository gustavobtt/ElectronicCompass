/**
 * *******************************************************************************,
 * File:       Clock.hpp
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

//classe do relogio
#ifndef _CLOCK_HPP_
#define _CLOCK_HPP_

class Clock {
public:
    Clock(int t_hr, int t_min, int t_sec, bool t_isPm);
    ~Clock();
    void setClock(int t_hr, int t_min, int t_sec, bool t_isPm);
    void readClock(int& t_hr, int& t_min, int& t_sec, bool& t_isPm);
    void advance();

protected:
    int m_hr;
    int m_min;
    int m_sec;
    bool m_isPM;
};

#endif /* _CLOCK_HPP_ */
