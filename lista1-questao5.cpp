/*
Crie um programa que ajude em contas matemáticas de área, volume e
comprimento de círculos e cubos.
O programa deve ter métodos privados que serão:
1- Cálculo do comprimento da circunferência.
2- Cálculo da área da circunferência.
3- Cálculo da área lateral do cubo.
4- Cálculo da área total do cubo.
5- Cálculo do volume do cubo.

Deve também conter métodos Públicos:
1- Definir as dimensões do círculo.
2- Definir as dimensões do cubo.
3- Imprimir os cálculos do círculo e do cubo.
*/

//Aluno: João Pedro Sales da Costa Bezerra
//Matrícula: 251022893
//Professor VINICIUS PEREIRA GONCALVES

#include <iostream> 
#include <string>
#include <windows.h>
using namespace std;

class Calculadora {
private: 
    double raio;
    double aresta;
    double pi = 3.1415;
    double comprimentoCirc() {return 2 * raio * pi;}
    double areaCirc() {return pi * raio * raio;}
    double volumeCubo() {return aresta * aresta * aresta;}
    double areaTotalCubo() {return 6 * aresta * aresta;}
    double areaLatCubo() {return aresta * aresta * 4;}

public: 

    void menuCalculadora() {
        cout << "==============CALCULADORA===============" << endl;
        cout << "Digite 1 para calcular o círculo. "<< endl;
        cout << "Digite 2 para calcular o cubo. "<< endl;
        cout << "Digite 3 para calcular ambos. "<< endl;
        cout << "Digite 0 para sair. " << endl;
        cout << "========================================" << endl;
        cout << "Escolha sua opção: ";
    }

    void definicaoCirculo (double raio) {
        this -> raio = raio;
    }

    void definicaoCubo (double aresta) {
        this -> aresta = aresta;
    }

    void imprimirCirculo(){
        cout << "\n=== Resultados do Círculo ===\n";
        cout << "Comprimento da Circunferência: " << comprimentoCirc() << endl;
        cout << "Área da Circunferencia: " << areaCirc() << endl;
    }

    void imprimirCubo(){
        cout << "\n=== Resultados do Cubo ===\n";
        cout << "Area Lateral do Cubo: " << areaLatCubo() << endl;
        cout << "Area Total do Cubo: " << areaTotalCubo() << endl;
        cout << "Volume do Cubo: " << volumeCubo() << endl;
    }

    }
;

int main(){
Calculadora calculos;
int opcoesCalc;
double raio, aresta; 

    while (true){
        calculos.menuCalculadora();
        cin >> opcoesCalc;
        
        switch (opcoesCalc){
            case 1 : 
            cout << "Digite o raio do círculo: ";
            cin >> raio;
            calculos.definicaoCirculo(raio);
            calculos.imprimirCirculo();
            break;
        
            case 2 :
            cout << "Digite a aresta do cubo: ";
            cin >> aresta;
            calculos.definicaoCubo(aresta);
            calculos.imprimirCubo();
            cout << "\n";
            break;
        
            case 3 :
            cout << "Digite o raio do círculo: ";
            cin >> raio;
            calculos.definicaoCirculo(raio);
            cout << "Digite a aresta do cubo: ";
            cin >> aresta;
            calculos.definicaoCubo(aresta);
            calculos.imprimirCirculo();
            calculos.imprimirCubo();
            cout << "\n";
            break;

            case 0 :
            cout << "Encerrando o programa...\n";
            Sleep(3000);
            return 0;

            default :
            cout << "Opção inválida! Tente novamente.\n";
        }

    }
    return 0;
}