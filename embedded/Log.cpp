/**
 * *******************************************************************************
 * File:       Log.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       
 * 
 * Version:    V1.2             Date:2023-11-18
 * *******************************************************************************
 */
#include "Log.h"
#include "pico/stdlib.h"  // conferir biblioteca da Raspberry Pi Pico

Log::Log() {
    // Inicializa conforme necessario
}

Log::~Log() {
    // A fila sera destruida automaticamente quando o objeto for destruido
}

temp Log::addLog(int ID, const char* timestamp, const char* data) {
    // Cria instancia de LogData
    LogData logEntry = {ID, timestamp, data};

    // Adiciona o log na fila
    return logQueue.Enqueue(logEntry);
}

size_t Log::getLogSize() const {
    // Obtem o tamanho da fila
    return logQueue.Size();
}

void Log::clearLog() {
    // Limpa a fila
    logQueue.Clear();
}

Log::LogData Log::getNextLog() {
    // Remove e retorna o proximo log da fila
    return logQueue.Dequeue();
}

/* #include "Log.h"

// Construtor
Log::Log() : m_pStart(nullptr), m_pEnd(nullptr) {}

// Destrutor
Log::~Log() {
    while (m_pStart != nullptr) {
        LogNode* aux = m_pStart;
        m_pStart = m_pStart->next;
        delete aux;
    }
}

// Adiciona um log à fila
temp Log::addLog(int ID, const char* timestamp, const char* data) {
    LogNode* auxNode = new LogNode{ID, timestamp, data, nullptr};
    if (auxNode == nullptr) {
        return ESP_ERR_NO_MEM;
    }

    if (m_pStart == nullptr) {
        m_pStart = auxNode;
        m_pEnd = m_pStart;
    } else {
        m_pEnd->next = auxNode;
        m_pEnd = auxNode;
    }

    return ESP_OK;
}

// Obtém o tamanho da fila
size_t Log::getLogSize() const {
    size_t size = 0;
    LogNode* current = m_pStart;

    while (current != nullptr) {
        size++;
        current = current->next;
    }

    return size;
} */

// Limpa a fila
void Log::clearLog() {
    while (m_pStart != nullptr) {
        LogNode* aux = m_pStart;
        m_pStart = m_pStart->next;
        delete aux;
    }

    m_pEnd = nullptr;
}
