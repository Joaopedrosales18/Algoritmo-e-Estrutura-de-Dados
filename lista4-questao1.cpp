/*
Criar um programa que utilize pilha para escrever uma FRASE ao contrário 
Exemplo: "Olá mundo" -> "odnum álO" 
E utilizar um método na classe FraseContrario para fazer isso, e depois mostrar o resultado 
na main.


Aluno: João Pedro Sales da Costa Bezerra
Matrícula 251022893
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class FraseContrario {
public:

string inverterFrase(string fraseOriginal){
    stack <char> pilha;
    string fraseInvertida = "";

    for (char c : fraseOriginal) {
        pilha.push(c);
    }

    while (!pilha.empty()){
        fraseInvertida += pilha.top();
        pilha.pop();
    }

    return fraseInvertida;
}

};

int main() {
FraseContrario invertida;
string frase;
cout << "Digite a frase que queira inverter: ";
getline(cin, frase);
cout << endl;
string resultado = invertida.inverterFrase(frase);

cout << "Resultado\n";
cout << "Frase Original: " << frase << endl;
cout << "Frase Invertida: " << resultado;

return 0;
}