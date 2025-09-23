#include <iostream>
#include <cmath>   // para sqrt e funções trigonométricas
using namespace std;

// Classe Complexo
class Complexo {
private:
    double real;   // parte real
    double imag;   // parte imaginária

public:
    // Construtor (padrão: número 0 + 0i)
    Complexo(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Métodos de acesso
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Soma de complexos: (a+bi) + (c+di) = (a+c) + (b+d)i
    Complexo soma(const Complexo& c) const {
        return Complexo(real + c.real, imag + c.imag);
    }

    // Subtração: (a+bi) - (c+di) = (a-c) + (b-d)i
    Complexo subtracao(const Complexo& c) const {
        return Complexo(real - c.real, imag - c.imag);
    }

    // Multiplicação: (a+bi)(c+di) = (ac - bd) + (ad+bc)i
    Complexo multiplicacao(const Complexo& c) const {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complexo(r, i);
    }

    // Divisão: (a+bi)/(c+di) = [(ac+bd) + (bc-ad)i] / (c²+d²)
    Complexo divisao(const Complexo& c) const {
        double denom = c.real * c.real + c.imag * c.imag;
        if (denom == 0) {
            cout << "Erro: divisao por zero!\n";
            return Complexo(0,0);
        }
        double r = (real * c.real + imag * c.imag) / denom;
        double i = (c.real * imag - real * c.imag) / denom;
        return Complexo(r, i);
    }

    // Elevar ao quadrado: (a+bi)²
    Complexo aoQuadrado() const {
        return multiplicacao(*this); // multiplica o número por ele mesmo
    }

    // Raiz quadrada (usando forma polar: √z = √|z|(cos(θ/2)+i·sen(θ/2)))
    Complexo raiz() const {
        double modulo = sqrt(sqrt(real*real + imag*imag)); // √|z|
        double angulo = atan2(imag, real) / 2;             // θ/2
        return Complexo(modulo * cos(angulo), modulo * sin(angulo));
    }

    // Imprimir número complexo no formato: a + bi
    void imprimir() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << fabs(imag) << "i";
    }
};


int main() {
    Complexo c1, c2, resultado;
    double r, i;
    int opcao;

    do {
        // Menu da calculadora de numeros complexos
        cout << "\n==== CALCULADORA DE NUMEROS COMPLEXOS ====\n";
        cout << "1 - Soma\n";
        cout << "2 - Subtracao\n";
        cout << "3 - Multiplicacao\n";
        cout << "4 - Divisao\n";
        cout << "5 - Raiz quadrada\n";
        cout << "6 - Elevar ao quadrado\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: // Soma
                cout << "Digite a parte real do primeiro numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c1 = Complexo(r, i);

                cout << "Digite a parte real do segundo numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c2 = Complexo(r, i);

                resultado = c1.soma(c2);
                cout << "Resultado: ";
                resultado.imprimir();
                cout << endl;
                break;

            case 2: // Subtração
                cout << "Digite a parte real do primeiro numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c1 = Complexo(r, i);

                cout << "Digite a parte real do segundo numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c2 = Complexo(r, i);

                resultado = c1.subtracao(c2);
                cout << "Resultado: ";
                resultado.imprimir();
                cout << endl;
                break;

            case 3: // Multiplicação
                cout << "Digite a parte real do primeiro numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c1 = Complexo(r, i);

                cout << "Digite a parte real do segundo numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c2 = Complexo(r, i);

                resultado = c1.multiplicacao(c2);
                cout << "Resultado: ";
                resultado.imprimir();
                cout << endl;
                break;

            case 4: // Divisão
                cout << "Digite a parte real do primeiro numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c1 = Complexo(r, i);

                cout << "Digite a parte real do segundo numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c2 = Complexo(r, i);

                resultado = c1.divisao(c2);
                cout << "Resultado: ";
                resultado.imprimir();
                cout << endl;
                break;

            case 5: // Raiz quadrada
                cout << "Digite a parte real do numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c1 = Complexo(r, i);

                resultado = c1.raiz();
                cout << "Raiz principal: ";
                resultado.imprimir();
                cout << endl;
                break;

            case 6: // Ao quadrado
                cout << "Digite a parte real do numero: ";
                cin >> r;
                cout << "Digite a parte imaginaria: ";
                cin >> i;
                c1 = Complexo(r, i);

                resultado = c1.aoQuadrado();
                cout << "Ao quadrado: ";
                resultado.imprimir();
                cout << endl;
                break;

            case 0: // Sair
                cout << "Encerrando programa...\n";
                break;

            default: // Caso inválido
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
