/*
Você está projetando um sistema para um restaurante de fast food, o sistema deve permitir 
criar um pedido, com número e opções de alimento, e deve permitir servir o pedido na 
ordem em que foram solicitados, utilize o conceito de filas na sua solução.

Aluno: João Pedro Sales da Costa Bezerra
Matrícula 251022893
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class FastFood {
private: 
queue<string> orders;

public:

void display() {
    cout << "1. COMBO X-BACON C/ FRITAS E REFRIGERANTE - R$ 39.90\n";
    cout << "2. COMBO X-SALADA C/ FRITAS - R$ 30.90\n";
    cout << "3. COMBO VEGANO C/ FRITAS E REFRIGERANTE - R$ 32.90\n";
    cout << "4. BATATAS RUSTICAS - R$ 3.50\n";
    cout << "5. PORÇÃO 6 NUGGETS - R$ 5.00\n\n";
    cout << "SEU PEDIDO: ";
}

void registOrder (int num) {
    if (num == 1) {
        cout << "Pedido cadastrado com sucesso!\n";
        orders.push("1. COMBO X-BACON C/ FRITAS E REFRIGERANTE - R$ 39.90\n");
    }
    
    if (num == 2) {
        cout << "Pedido cadastrado com sucesso!\n";
        orders.push("2. COMBO X-SALADA C/ FRITAS - R$ 30.90\n");
    }
    
    if (num == 3) {
        cout << "Pedido cadastrado com sucesso!\n";
        orders.push("3. COMBO VEGANO C/ FRITAS E REFRIGERANTE - R$ 32.90\n");
    }
    
    if (num == 4) {
        cout << "Pedido cadastrado com sucesso!\n";
        orders.push("4. BATATAS RUSTICAS - R$ 3.50\n");
    }
    
    if (num == 5) {
        cout << "Pedido cadastrado com sucesso!\n";
        orders.push("5. PORÇÃO 6 NUGGETS - R$ 5.00\n");
        
        
    }   
    
}

void queueFoods() {
    if (orders.empty()){
        cout << "Nenhum pedido na Fila\n";
        return;
    }
    queue<string> auxQueue = orders;
    while (!auxQueue.empty()){
        cout << auxQueue.front();
        auxQueue.pop();
    }   
}

void serveOrder() {
    if (orders.empty()){
        cout << "Nenhum pedido na Fila!\n";
        return;
    }
    else {
        cout << "Servindo agora: " << orders.front() <<"\n";
        orders.pop();
        cout << "Pedido Servido!\n";
    }
}
};

int main(){
FastFood food;
int escolha = -1;
int pedido;

    while (escolha != 0) {
        cout << "FAST-FOOD\n";
        cout << "1. FAZER NOVO PEDIDO\n";
        cout << "2. SERVIR PEDIDO\n";
        cout << "3. MOSTRAR FILA DE PEDIDOS\n";
        cout << "0. SAIR\n";
        cin >> escolha;
        system("cls");

        switch (escolha) {
            case 1 :
            food.display();
            cin >> pedido;
            food.registOrder(pedido);
            system("pause");
            system("cls");
            break;

            case 2 :
            food.serveOrder();
            system("pause");
            system("cls");
            break;

            case 3 :
            food.queueFoods();
            system("pause");
            system("cls");
            break;

            default :
            cout << "Não existe essa opção no cardápio!\n";
            break;
            
        }
    }
    return 0;
};
