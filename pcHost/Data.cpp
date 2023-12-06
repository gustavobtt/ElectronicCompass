#include "Data.h"

// Construtor padrão
Data::Data() {
    // nada para inicializar
}

// Destrutor
Data::~Data() {
    // nada para deletar
}

// Método para solicitar os dados pela porta serial, usando um ponteiro para um objeto da classe Connection como argumento
void Data::getData(Connection* conn) {
    conn->send("D"); // Chama o método send do objeto apontado por conn, passando o caractere D como argumento, indicando que quer os dados do Log
    string response = conn->receive(); // Chama o método receive do objeto apontado por conn e armazena a resposta na string response
    if (!response.empty()) { // Se a resposta não está vazia
        if (response == "OK") { // Se a resposta é OK, significa que a Raspberry Pi Pico está pronta para enviar os dados
            cout << "Digite o intervalo de datas que deseja obter os dados, no formato DD/MM/AAAA-DD/MM/AAAA, ou digite T para obter todos os dados." << endl;
            string interval; // Cria uma string para armazenar o intervalo de datas
            cin >> interval; // Lê o intervalo de datas da entrada do usuário
            conn->send(interval); // Chama o método send do objeto apontado por conn, passando o intervalo de datas como argumento
            response = conn->receive(); // Chama o método receive do objeto apontado por conn e armazena a resposta na string response
            if (!response.empty()) { // Se a resposta não está vazia
                if (response == "NOK") { // Se a resposta é NOK, significa que o intervalo de datas é inválido
                    cout << "Intervalo de datas inválido. Por favor, digite novamente." << endl;
                }
                else { // Se a resposta não é NOK, significa que é o número de registros que serão enviados
                    int n = stoi(response); // Converte a resposta para um inteiro e armazena na variável n
                    cout << "Recebendo " << n << " registros." << endl;
                    for (int i = 0; i < n; i++) { // Para cada registro
                        response = conn->receive(); // Chama o método receive do objeto apontado por conn e armazena a resposta na string response
                        if (!response.empty()) { // Se a resposta não está vazia
                            dataQueue.push(response); // Adiciona a resposta na fila dataQueue
                            dataList.push_back(response); // Adiciona a resposta na lista dataList
                        }
                    }
                    cout << "Dados recebidos com sucesso." << endl;
                }
            }
            else { // Se a resposta está vazia
                cout << "Erro ao receber o número de registros." << endl;
            }
        }
        else { // Se a resposta não é OK, significa que houve algum erro na Raspberry Pi Pico
            cout << "Erro ao solicitar os dados do Log." << endl;
        }
    }
    else { // Se a resposta está vazia
        cout << "Erro ao receber a confirmação." << endl;
    }
}

// Método para salvar os dados da lista em um arquivo .TXT
void Data::saveData() {
    if (!dataList.empty()) { // Se a lista dataList não está vazia
        ofstream file; // Cria um objeto da classe ofstream para manipular o arquivo
        file.open("data.txt"); // Abre o arquivo data.txt
        if (file.is_open()) { // Se o arquivo está aberto
            for (string data : dataList) { // Para cada elemento da lista dataList
                file << data << endl; // Escreve o elemento no arquivo, seguido de uma quebra de linha
            }
            file.close(); // Fecha o arquivo
            cout << "Dados salvos com sucesso." << endl;
        }
        else { // Se o arquivo não está aberto
            cout << "Erro ao abrir o arquivo." << endl;
        }
    }
    else { // Se a lista dataList está vazia
        cout << "Não há dados para salvar." << endl;
    }
}

// Método para mostrar os dados da lista na tela
void Data::showData() {
    if (!dataList.empty()) { // Se a lista dataList não está vazia
        for (string data : dataList) { // Para cada elemento da lista dataList
            cout << data << endl; // Imprime o elemento na tela, seguido de uma quebra de linha
        }
    }
    else { // Se a lista dataList está vazia
        cout << "Não há dados para mostrar." << endl;
    }
}
