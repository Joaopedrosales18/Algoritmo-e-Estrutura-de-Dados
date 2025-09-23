/*
Crie um programa que represente uma agenda telefônica, com atributos
de telefone e nome privados e métodos que imprimam os dados.
*/

//Aluno: João Pedro Sales da Costa Bezerra
//Matrícula: 251022893
//Professor VINICIUS PEREIRA GONCALVES

#include <iostream> 
#include <string>
#include <vector>
#include <stdlib.h>
#include <windows.h>
using namespace std;

class Contato {
private: 
    string nome; 
    string telefone;
public:

     Contato() {}

     //Construtor
     Contato (string nome, string telefone){
        this -> nome = nome;
        this -> telefone = telefone;    
}
    //Método para definir valores
    void setContato(string nome, string telefone){
        this -> nome = nome;
        this -> telefone = telefone;
    }

    //Método para imprimir os contatos
    void printContato() {
        cout << "Nome: " << nome << " | Telefone: " << telefone << "\n";
        cout << "------------------------\n";
    }
};

class Agenda {
private:
    vector <Contato> contatos; // Lista de contatos da agenda

public: 
    //adicionar um novo contato à agenda
    void cadastrarContato(string nome, string telefone){
        Contato c(nome, telefone);
        contatos.push_back(c);
        cout << "Contato adicionado à Agenda!\n";
    }

    //Listar todos os contatos

    void listarContatos() {
        if (contatos.empty()) {
            cout << "Agenda Vazia!\n";
            return;
        }
        cout << "\n--- Lista de Contatos ---\n\n";
        for (size_t i = 0; i < contatos.size(); i++) {
            cout << i + 1 << ". ";
            contatos[i].printContato();
        }
        
    }

    void menuAgenda() {
        cout << "\n==== AGENDA TELEFONICA ====\n";
        cout << "1 - Adicionar contato\n";
        cout << "2 - Listar contatos\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
    }
};

int main() {
    Agenda agenda;
    int opcao;
    string nome, telefone;

    while (true) {
        agenda.menuAgenda();
        cin >> opcao;
        cin.ignore();
        system("cls");

        switch (opcao) {
            case 1: 
            cout << "Digite seu nome: ";
            getline(cin, nome);
            cout << "Digite seu telefone: ";
            getline(cin, telefone);
            agenda.cadastrarContato(nome, telefone);
            Sleep(3000);
            system("cls");

            break;

            case 2:
            agenda.listarContatos();
            break;

            case 0: 
            cout << "Encerrando o programa...\n";
            return 0;

            default:
            cout << "Opção inválida!\n";
        }
    }

    return 0;
    }
    
