/*
Em um centro logístico altamente movimentado, os pacotes chegam constantemente para 
serem armazenados em uma pilha, e também são retirados dessa pilha para transporte. 
Cada pacote tem um peso (um número inteiro positivo). A cada operação, o sistema pode 
realizar uma das seguintes ações: 
PACOTE – um pacote de peso P chega e é colocado no topo da pilha. 
ENVIO – o pacote que está no topo da pilha é retirado para envio. 
LEVE – o gerente consulta o sistema para saber qual o pacote mais leve que ainda está na 
pilha. 
O gerente não pode prever os próximos pacotes que irão chegar, apenas consultar o mais 
leve até o momento.

Aluno: João Pedro Sales da Costa Bezerra
Matrícula 251022893
*/

#include <iostream>
#include <string>
#include <stack>
#include <windows.h>
using namespace std;

class CentroLogistico {
private:
    stack<int> packs;
    stack<int> lightPacks;
    int peso;
public:

    void addPacks(int peso) {
        if (peso <= 0){
            cout << "O peso do pacote deve ser um número positivo!\n";
            return;
        }
        else {
            packs.push(peso);

            if (lightPacks.empty() || peso <= lightPacks.top()){
                lightPacks.push(peso);
            }

            cout << "Pacote de peso " << peso << " foi cadastrado com sucesso!\n";
        } 
        
    }

    void sendPacks() {
        if (packs.empty()){
            cout << "Nenhum pacote no Centro Logístico para envio!\n";
            return;
        }
        
        int removedWeight = packs.top();

        if (removedWeight == lightPacks.top()){
            lightPacks.pop();
        }
        packs.pop();
        cout << "Pacote de peso " << removedWeight << " foi enviado!\n";
    }

    void checkLightPacks() {

        if (lightPacks.empty()){
            cout << "Nenhum pacote no Centro Logístico para consulta!\n";
            return;
        }
        else {
            cout << "O pacote mais leve do Centro é de peso: " << lightPacks.top() << endl;
        }

    }

    void display() {
        cout << "BEM VINDO AO CENTRO LOGISTICO!\n";
        cout << "1. Adicionar Pacote (PACOTE)" << endl;
        cout << "2. Enviar Pacote do Topo (ENVIO)" << endl;
        cout << "3. Consultar Pacote Mais Leve (LEVE)" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
    }



};

int main() {
CentroLogistico sistema;
int peso = 0;
int escolha;

    while (escolha != 0) {
        sistema.display();
        cin >> escolha;
        system("cls");

        switch (escolha) {
            case 1: 
            cout << "Qual é o peso do pacote? ";
            cin >> peso;
            sistema.addPacks(peso);
            Sleep(3000);
            system("cls");
            break;

            case 2:
            sistema.sendPacks();
            Sleep(3000);
            system("cls");
            break;

            case 3:

            sistema.checkLightPacks();
            Sleep(3000);
            system("cls");
            break;

            case 0:
            cout << "Saindo do sistema...\n";
            Sleep(3000);
            break;

            default:

            cout << "Escolha inválida! Tente novamente!\n";
            break;
            
        }
    }
    return 0;    
}