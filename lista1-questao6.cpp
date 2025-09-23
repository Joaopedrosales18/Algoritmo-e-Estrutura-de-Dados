/*
Utilizando os métodos getters e setters, faça um programa de gestão de
pessoas para um hospital, em que deve-se cadastrar:
- nome
- telefone
- tipo sanguíneo
- idade
Após o cadastro, o seu programa deve separar todos os doadores universais, pois o
hospital está cheio e necessita preencher seu banco de sangue.
*/

//Aluno: João Pedro Sales da Costa Bezerra
//Matrícula: 251022893
//Professor VINICIUS PEREIRA GONCALVES

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;

class Paciente {
private:    
    string nome;
    string telefone;
    string tipo_sanguineo;
    int idade;
     
public: 
    //setters da classe Paciente
    void setNome(string nome) { this -> nome = nome; }
    void setTelefone(string telefone) { this -> telefone = telefone; }
    void setTipoSanguineo(string tipo_sanguineo) { this -> tipo_sanguineo = tipo_sanguineo; }
    void setIdade(int idade) { this -> idade = idade; }

    //getters
    string getNome() { return nome; }
    string getTelefone() { return telefone; }
    string getTipoSanguineo() { return tipo_sanguineo; }
    int getIdade() { return idade; }

    
    //verificador de pacientes doadores universais
    bool EDoadorUniversal() {
        return (tipo_sanguineo ==  "O-" || tipo_sanguineo == "o-");
    }

    //modelo para mostrar cada paciente com dados de cadastro 
    void mostrar_status(){
        cout << "------------------------------------"<< endl;
        cout << "NOME: " << nome << endl;
        cout << "IDADE: " << idade << endl;
        cout << "TELEFONE: " << telefone << endl;
        cout << "TIPO SANGUÍNEO: " << tipo_sanguineo << endl;
        cout << "------------------------------------"<< endl;

    }

};

int main(){
Paciente hospital;
vector <Paciente> pacientesGeral; //Lista geral para os pacientes em geral
vector <Paciente> doadoresUniversais; // Lista especifica de doadores universais do hospital
int opcao;
string nome;
string telefone;
string tipoSangue;
int idade;

    while (true){
        //menu do hospital
        cout << "\n===== MENU HOSPITAL =====\n";
        cout << "1. Cadastrar pacientes\n";
        cout << "2. Listar todos os pacientes\n";
        cout << "3. Listar doadores universais\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();
        system("cls");

        switch (opcao) {

            
            case 1: 
            //cadastro geral
            cout << "\nCadastro de pacientes:\n";
            cout << "Nome: ";
            getline(cin, nome);
            hospital.setNome(nome);
            
            cout << "Telefone: ";
            getline(cin, telefone);
            hospital.setTelefone(telefone);
            
            cout << "Tipo sanguineo: ";
            getline(cin, tipoSangue);
            hospital.setTipoSanguineo(tipoSangue);
            
            cout << "Idade: ";
            cin >> idade;
            hospital.setIdade(idade);
            cin.ignore();
            
            //adicionar às listas
            pacientesGeral.push_back(hospital);
            //adiciona primeiro às listas gerais para depois verificar a possibiidade de ser doador universal
            if (hospital.EDoadorUniversal()) {
                doadoresUniversais.push_back(hospital);
            }
            //cadastro bem-sucedido
            cout << "\nPaciente cadastrado com sucesso!\n";
            Sleep(3000);
            system("cls");
            break;
            
            case 2:
            //Listagem geral dos pacientes do hospital
            cout << "---------- Lista de todos os pacientes ----------\n\n";
            if (pacientesGeral.empty()) {
                cout << "Nenhum paciente cadastrado no sistema.\n";
            } else {
                //for para passar em cada posição do vetor, listando os status de cada paciente 
                for (size_t i = 0; i < pacientesGeral.size(); i++) {
                    pacientesGeral[i].mostrar_status();                    
                }
            }
            system ("pause");
            system("cls");
            break;

            case 3: 
            //Listagem exclusiva do doadores universais
            cout << "\n---------- Lista de doadores universais ----------\n\n";
            if (doadoresUniversais.empty()) { //Se nao houver nenhum paciente sendo doador universal
                cout << "Nenhum doador universal encontrado no sistema.\n";
            } else {
                //Percorre o vetor exibindo apenas os doadores universais
                for (size_t i = 0; i < doadoresUniversais.size(); i++) {
                    doadoresUniversais[i].mostrar_status(); 
                    }
            }
            system ("pause");
            system("cls");   
            break;


            case 4:
            cout << "Saindo do sistema...\n";
            Sleep(3000);
            return 0;

            default:
            cout << "Opcao invalida! Tente novamente.\n";
        }
    }
return 0;
}