/*
Crie um programa que cadastre alunos da disciplina de AED para facilitar a
vida do professor nos lançamentos e consultas. Nesse programa deve ser possível
cadastrar cada aluno pelo nome, matricula e curso que está fazendo.
Lembre-se de usar a programação orientada a objeto.
*/

//Aluno: João Pedro Sales da Costa Bezerra
//Matrícula: 251022893
//Professor VINICIUS PEREIRA GONCALVES

#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <vector>
using namespace std;

class CadastroAED {
private: 
    string nome;
    string curso;
    int matricula;

public: 
    
    CadastroAED() {}
    // construtor do cadastro de alunos em AED
    CadastroAED (string nome, string curso, int matricula){
        this -> nome = nome;
        this -> curso = curso;
        this -> matricula = matricula;
    }
    //getMatricula para remover matriculas, caso o aluno tranque a disciplina
    int getMatricula(){
        return matricula;    
    }

    // setcadastro utilizando o construtor CadastroAED
    void setCadastro(string nome, string curso, int matricula){
        this -> nome = nome;
        this -> curso = curso;
        this -> matricula = matricula;
    }
    //Modelo para mostrar os alunos por nome, matrícula e curso referente.
    void mostrarAlunos() {
        cout << "Nome: " << nome << " | Matricula: " << matricula << " | Curso: " << curso << endl;
        cout << "-------------------------------------------------------------\n";
    }
};

class Matricula {
private: 
    vector <CadastroAED> matriculados; // Lista de matriculados em AED;

public: 
    //Adicionar uma nova matrícula
    void adicionarMatricula(string nome, string curso, int matricula) {
        CadastroAED c(nome, curso, matricula);
        matriculados.push_back(c);
        cout << "Aluno matriculado com sucesso!\n";
    }

    void removerMatricula(int matricula) {
        bool alunoEncontrado = false;
        for (size_t i = 0; i < matriculados.size(); i++) {

            if (matriculados[i].getMatricula() == matricula) {
                matriculados.erase(matriculados.begin() + i);
                cout << "Aluno removido com sucesso!\n";
                alunoEncontrado = true;
                break;
            }
        }

        if (!alunoEncontrado) {
            cout << "Aluno com matrícula " << matricula << " não encontrado no sistema.\n";
    }
}
    void listarAlunos(){
        if (matriculados.empty()) {
            cout << "Nenhum aluno matriculado nesta disciplina!\n";
            return;
        }

        cout << "\n---------------------MATRICULADOS---------------------\n";
        for (size_t i = 0; i < matriculados.size(); i++) {
            cout << i + 1 << ". ";
            matriculados[i].mostrarAlunos();
        }
    }

    void interfaceMatricula(){
        cout << "\n========= MATRICULAS AED =========\n";
        cout << "1 - Adicionar matricula.\n";
        cout << "2 - Listar alunos matriculados.\n";
        cout << "3 - Remover alunos matriculados.\n";
        cout << "0 - Sair da aba de matriculas.\n";
        cout << "Escolha uma opcao: ";
    }

};

int main() {
    Matricula matriculas;
    int opcao;
    string nome, curso;
    int matricula;

    while (true) {
        matriculas.interfaceMatricula();
        cin >> opcao;
        cin.ignore();
        system("cls");


        switch (opcao) {
            case 1: 
            cout << "Digite o nome do aluno: ";
            getline(cin, nome);
            cout << "Digite o curso do aluno: ";
            getline(cin, curso);
            cout << "Digite a matrícula do aluno: ";
            cin >> matricula;
            matriculas.adicionarMatricula(nome, curso, matricula);
            Sleep(3000);
            system("cls");

            break;

            case 2: 
            matriculas.listarAlunos();
            break;

            case 3: 
            cout << "Digite a matrícula do aluno a ser removido: ";
            cin >> matricula;
            matriculas.removerMatricula(matricula);
            Sleep(3000);
            system("cls");
            break;

            case 0:
            cout << "Saindo da página de matriculas...\n";
            return 0;

            default :
            cout << "Opção inválida. Tente novamente.\n";
        }


    }
    return 0;
}