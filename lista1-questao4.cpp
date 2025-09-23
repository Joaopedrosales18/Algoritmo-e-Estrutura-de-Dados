/*
Você é um programador que foi contratado por uma empresa de
estacionamento rotativos de Brasília.
Essa empresa está passando por algumas dificuldades de controle dos carros que
entram e saem, dificultando até a devolução do carro para o proprietário.
Seu trabalho é construir um programa em que seja possível cadastrar os donos e os
carros.
Os donos devem informar: Nome
Telefone
Marca
Placa
Cor
Após esse cadastro, o programa deve imprimir na tela todos os dados dos carros
cadastrados.
*/

//Aluno: Joao Pedro Sales da Costa Bezerra
//Matrícula: 251022893
//Professor VINICIUS PEREIRA GONCALVES

#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <vector>
using namespace std;

class Estacionamento {
private:
    string telefone;
    string marca;
    string placa;
    string cor;

public: 
    //construtor da classe Estacionamento, recebendo os parametros
    Estacionamento (string telefone, string marca, string placa, string cor) {
        this -> telefone = telefone;
        this -> marca = marca; 
        this -> placa = placa;
        this -> cor = cor;
    }
    //setters do estacionamento
    void setEstacionamento (string telefone, string marca, string placa, string cor) {
        this -> telefone = telefone;
        this -> marca = marca; 
        this -> placa = placa;
        this -> cor = cor;
    }
    //modelo para listagem dos atributos dos carros
    void listarCarros() {
        cout << "Telefone do Dono: " << telefone << " | Marca: " << marca << " | Placa: " << placa << " | Cor: " << cor << endl;
        cout << "-----------------------------------------------------------------------------------------------------\n";
    }
};

class Carros {
private: 
    //vetor carro da classe anterior
    vector <Estacionamento> carro;
public: 
    //funcao para cadastrar carros no estacionamento e na listagem
    void cadastroCarro(string telefone, string marca, string placa, string cor) {
        Estacionamento c(telefone, marca, placa, cor);
        carro.push_back(c);
        cout << "Carro cadastrado com sucesso pelo sistema.\n";
    }
    //lista de carros no estacionamento
    void listaCarros(){
        if (carro.empty()){
            //logica para conferir se ha carros cadastrados
            cout << "Nenhum carro cadastrado no estacionamento!\n";
            return;
        }
        //modelo para mostrar os carros cadastrados no sistema
        cout << "------------------------------------Carros Cadastrados no Sistema------------------------------------\n";
        for (size_t i = 0; i < carro.size(); i++) {
            cout << i + 1 << ". ";
            carro[i].listarCarros();
    }
}
    //menu do sistema do estacionamento
    void menuSistema() {
        cout << "\n-------Bem Vindo ao Estacionamento Rotativo-------\n";
        cout << "1 - Cadastrar Carro ao Estacionamento.\n";
        cout << "2 - Listar carros cadastrados.\n";
        cout << "0 - Sair do sistema.\n";
        cout << "Escolha uma opcao: ";
    }
};

int main() {
    Carros cadastro;
    string telefone;
    string marca;
    string placa;
    string cor;
    int opcoes;

    while (true) {
        cadastro.menuSistema();
        cin >> opcoes;
        cin.ignore();
        system("cls");
    
        switch (opcoes) {
            //caso o usuario queira cadastrar um carro
            case 1: 
            cout << "Digite o telefone(Ex.: (XX) XXXX-XXXX): ";
            getline(cin, telefone);
            cout << "Digite a marca de carro: ";
            getline(cin, marca);
            cout << "Digite a placa do carro: ";
            getline(cin, placa);
            cout << "Digite a cor do carro: ";
            getline(cin, cor);
            cadastro.cadastroCarro(telefone, marca, placa, cor);
            Sleep(3000);
            system("cls");
            break;

            case 2:
            //caso o usuario queira listar todos os carros cadastrados
            cadastro.listaCarros();
            break;

            case 0:
            //caso o usuario queira sair do programa
            cout << "Saindo do sistema...\n";
            Sleep(3000);
            return 0;

            default: 
            cout << "Opção inválida! Tente novamente.\n";
        }   
    }
    return 0;
}