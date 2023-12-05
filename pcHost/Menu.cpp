/**
 * *******************************************************************************,
 * File:       Menu.cpp
 * 
 * Author:     Gustavo Batistell
 * Email:      gustavobtt@gmail.com
 * 
 *             UFSC - Universidade Federal de Santa Catarina
 *             EEL7323-08235 Programacao C++ para Sistemas Embarcados
 * 
 * note:       Implementacao do Menu
 * 
 * Version:    V1.0             Date:2023-11-22
 * *******************************************************************************
 */
#include "Menu.h"

// Construtor padrão
Menu::Menu() {
    conn = new Connection(); // Cria um novo objeto da classe Connection e atribui ao ponteiro conn
    input = ""; // Inicializa a string input com uma string vazia
}

// Destrutor
Menu::~Menu() {
    delete conn; // Deleta o objeto apontado por conn
}

// Metodo para mostrar o Menu na tela
void Menu::show() {
    cout << "#############################################################" << endl;
    cout << "                                                                      BUSSOLA ELETRONICA" << endl;
    cout << endl;
    cout << "Digite/selecione um numero da lista abaixo e pressione ENTER:" << endl;
    cout << endl;
    cout << "(1)   Conectar" << endl;
    cout << "(2)   Ver tempo total" << endl;
    cout << "(3)   Listar dados do intervalo" << endl;
    cout << "(4)   Salvar dados do intervalo" << endl;
    cout << "(X)   Sair" << endl;
    cout << endl;
    cout << "#############################################################" << endl;
}

// Metodo para lidar com a entrada do usuario
void Menu::handleInput() {
    cin >> input; // Lê a entrada do usuario e armazena na string input
    if (input == "1") { // Se o usuario digitou 1
        conn->connect(); // Chama o metodo connect do objeto apontado por conn
    }
    else if (input == "2") { // Se o usuario digitou 2
        conn->totalTime(); // Chama o metodo totalTime do objeto apontado por conn
    }
    else if (input == "3") { // Se o usuario digitou 3
        conn->getData(); // Chama o metodo getData do objeto apontado por conn
    }
    else if (input == "4") { // Se o usuario digitou 4
        conn->saveData(); // Chama o metodo saveData do objeto apontado por conn
    }
    else if (input == "X" || input == "x") { // Se o usuario digitou X ou x
        conn->exit(); // Chama o metodo exit do objeto apontado por conn
    }
    else { // Se o usuario digitou algo invalido
        cout << "Opção invalida. Por favor, digite novamente." << endl;
    }
}
