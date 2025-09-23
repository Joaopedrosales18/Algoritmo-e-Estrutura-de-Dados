/*
Crie um programa que cadastre alunos da disciplina de AED para facilitar a
vida do professor nos lançamentos e consultas. Nesse programa deve ser possível
cadastrar cada aluno pelo nome, matricula e curso que está fazendo.
Lembre-se de usar a programação orientada a objeto.
*/

//Aluno: João Pedro Sales da Costa Bezerra
//Matrícula: 251022893
//Professor VINICIUS PEREIRA GONCALVES

#include <iostream>   // biblioteca para entrada e saída de dados (cin, cout)
#include <string>     // biblioteca para manipulação de strings
#include <stdlib.h>   // biblioteca para funções do sistema (system("cls"))
#include <windows.h>  // biblioteca do Windows (para usar Sleep)
#include <vector>     // biblioteca para usar vetores dinâmicos
using namespace std;  // evita escrever std:: antes dos comandos do C++

// Classe que representa o cadastro de um aluno
class CadastroAED {
private: 
    string nome;       // armazena o nome do aluno
    string curso;      // armazena o curso do aluno
    int matricula;     // armazena o número da matrícula
    float nota;        // nova variável para armazenar a nota do aluno
    int faltas;        // nova variável para armazenar o número de faltas

public: 

    // Construtor com parâmetros para inicializar nome, curso e matrícula
    CadastroAED (string nome, string curso, int matricula){
        this -> nome = nome;           // "this" diferencia variável da classe do parâmetro
        this -> curso = curso;
        this -> matricula = matricula;
        this -> nota = 0.0;            // inicializa nota como 0
        this -> faltas = 0;            // inicializa faltas como 0
    }

    // Retorna o valor da matrícula (necessário para remover ou identificar aluno)
    int getMatricula(){
        return matricula;    
    }

    // Define um novo cadastro de aluno usando os parâmetros recebidos
    void setCadastro(string nome, string curso, int matricula){
        this -> nome = nome;
        this -> curso = curso;
        this -> matricula = matricula;
    }

    // Novo método para atribuir nota e faltas ao aluno
    void setNotaEFaltas(float nota, int faltas){
        this -> nota = nota;      // atribui a nota recebida
        this -> faltas = faltas;  // atribui o número de faltas recebido
    }

    // Exibe todas as informações do aluno
    void mostrarAlunos() {
        cout << "\n | Nome: " << nome 
             << "\n | Matricula: " << matricula 
             << "\n | Curso: " << curso
             << "\n | Nota: " << nota 
             << "\n | Faltas: " << faltas;
        cout << "\n---------------------------\n";
    }
};

// Classe responsável por gerenciar os alunos matriculados
class Matricula {
private: 
    vector <CadastroAED> matriculados; // vetor que armazena todos os alunos matriculados

public: 
    // Adiciona uma nova matrícula no vetor
    void adicionarMatricula(string nome, string curso, int matricula) {
        CadastroAED c(nome, curso, matricula);  // cria objeto "CadastroAED" com os dados recebidos
        matriculados.push_back(c);              // insere esse objeto no vetor
        cout << "Aluno matriculado com sucesso!\n";  // confirma operação
    }

    // Remove um aluno pela matrícula
    void removerMatricula(int matricula) {
        bool alunoEncontrado = false;  // variável para verificar se o aluno existe

        // percorre todo o vetor de matriculados
        for (size_t i = 0; i < matriculados.size(); i++) {
            // verifica se a matrícula do aluno na posição i é igual à informada
            if (matriculados[i].getMatricula() == matricula) {
                matriculados.erase(matriculados.begin() + i);  // remove o aluno da lista
                cout << "Aluno removido com sucesso!\n";
                alunoEncontrado = true;  // marca que o aluno foi encontrado
                break;                   // interrompe o loop
            }
        }

        // caso nenhum aluno tenha sido encontrado
        if (!alunoEncontrado) {
            cout << "Aluno com matrícula " << matricula << " não encontrado no sistema.\n";
        }
    }

    // Lista todos os alunos matriculados
    void listarAlunos(){
        if (matriculados.empty()) {  // verifica se a lista está vazia
            cout << "Nenhum aluno matriculado nesta disciplina!\n";
            return;  // sai do método
        }

        cout << "\n-MATRICULADOS-\n";
        // percorre todo o vetor e chama o método mostrarAlunos de cada aluno
        for (size_t i = 0; i < matriculados.size(); i++) {
            cout << i + 1 << ". ";      // mostra índice do aluno (posição na lista)
            matriculados[i].mostrarAlunos();
        }
    }

    // Novo método: atribuir nota e faltas a um aluno específico
    void atribuirNotaEFaltas(int matricula, float nota, int faltas){
        bool alunoEncontrado = false;  // verifica se o aluno foi localizado

        // percorre o vetor procurando o aluno pela matrícula
        for (size_t i = 0; i < matriculados.size(); i++) {
            if (matriculados[i].getMatricula() == matricula) {
                matriculados[i].setNotaEFaltas(nota, faltas);  // define nota e faltas
                cout << "Nota e faltas atribuídas com sucesso!\n";
                alunoEncontrado = true;
                break;
            }
        }

        // se não encontrar o aluno
        if (!alunoEncontrado) {
            cout << "Aluno com matrícula " << matricula << " não encontrado.\n";
        }
    }

    // Exibe o menu de opções para o usuário
    void interfaceMatricula(){
        cout << "\n========= MATRICULAS AED =========\n";
        cout << "1 - Adicionar matricula.\n";
        cout << "2 - Listar alunos matriculados.\n";
        cout << "3 - Remover alunos matriculados.\n";
        cout << "4 - Atribuir nota e faltas.\n";   // nova opção no menu
        cout << "0 - Sair da aba de matriculas.\n";
        cout << "Escolha uma opcao: ";
    }
};

// Função principal do programa
int main() {
    Matricula matriculas;   
    int opcao;              
    string nome, curso;     
    int matricula;          
    float nota;             
    int faltas;             

    // laço infinito para manter o programa rodando até que o usuário escolha sair
    while (true) {
        matriculas.interfaceMatricula();  // mostra menu
        cin >> opcao;                     // lê opção escolhida
        cin.ignore();                     // limpa buffer do teclado
        system("cls");                    // limpa a tela do console

        // estrutura switch para tratar cada opção do menu
        switch (opcao) {
            case 1: // adicionar aluno
                cout << "Digite o nome do aluno: ";
                getline(cin, nome);                // lê nome completo
                cout << "Digite o curso do aluno: ";
                getline(cin, curso);               // lê curso
                cout << "Digite a matrícula do aluno: ";
                cin >> matricula;                  // lê matrícula
                matriculas.adicionarMatricula(nome, curso, matricula); // chama método para cadastrar
                Sleep(3000);   // pausa 3 segundos
                system("cls"); // limpa tela
                break;

            case 2: // listar alunos
                matriculas.listarAlunos();
                system ("pause");
                system("cls");
                break;

            case 3: // remover aluno
                cout << "Digite a matrícula do aluno a ser removido: ";
                cin >> matricula;
                matriculas.removerMatricula(matricula); // chama método para remover
                Sleep(3000);
                system("cls");
                break;

            case 4: // atribuir nota e faltas
                cout << "Digite a matrícula do aluno: ";
                cin >> matricula;
                cout << "Digite a nota do aluno: ";
                cin >> nota;
                cout << "Digite a quantidade de faltas do aluno: ";
                cin >> faltas;
                matriculas.atribuirNotaEFaltas(matricula, nota, faltas); // chama método
                Sleep(3000);
                system("cls");
                break;

            case 0: // sair do programa
                cout << "Saindo da página de matriculas...\n";
                return 0; // encerra execução

            default: // caso usuário digite opção inválida
                cout << "Opção inválida. Tente novamente.\n";
        }
    }
    return 0; // fim da função principal
}
