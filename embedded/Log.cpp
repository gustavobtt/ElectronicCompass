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
 * Version:    V1.0             Date:2023-11-17
 * *******************************************************************************
 */
#include "Log.h"
#include "pico/stdlib.h"  // Certifique-se de que essa biblioteca está correta para a Raspberry Pi Pico

Log::Log() {
    // Inicialize conforme necessário, se houver alguma inicialização específica
}

Log::~Log() {
    // A fila será destruída automaticamente quando o objeto for destruído
}

temp Log::addLog(int ID, const char* timestamp, const char* data) {
    // Crie uma instância de LogData
    LogData logEntry = {ID, timestamp, data};

    // Adicione o log à fila
    return logQueue.Enqueue(logEntry);
}

size_t Log::getLogSize() const {
    // Obtenha o tamanho da fila
    return logQueue.Size();
}

void Log::clearLog() {
    // Limpe a fila
    logQueue.Clear();
}

Log::LogData Log::getNextLog() {
    // Remova e retorne o próximo log da fila
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
