#include <iostream>
#include <cmath>

class Racional {

private:
    int numerador;
    int denominador;

public:
    Racional();
    Racional(int, int);
    void setNumerador(int);
    void setDenominador(int);
    int getNumerador();
    int getDenominador();
    void simplifica();
    Racional operator + (Racional);
    Racional operator - (Racional);
    Racional operator * (Racional);
    Racional operator / (Racional);
};

Racional::Racional() {}

Racional::Racional(int numerador, int denominador) {
    this->setNumerador(numerador);
    this->setDenominador(denominador);
}

void Racional::setNumerador(int numerador) {
    this->numerador = numerador;
}

void Racional::setDenominador(int denominador) {
    this->denominador = denominador;
}

int Racional::getNumerador() {
    return this->numerador;
}

int Racional::getDenominador() {
    return this->denominador;
}

void Racional::simplifica() {
    int a, b;
    if(this->getNumerador() > this->getDenominador()) {
        a = this->getNumerador();
        b = this->getDenominador();
    }else{
        a = this->getDenominador();
        b = this->getNumerador();
    }

    while(b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }

    a = std::abs(a);
    this->setNumerador(this->getNumerador() / a);
    this->setDenominador(this->getDenominador() / a);
}

Racional Racional::operator + (Racional racional) {
    Racional saida;
    saida.setNumerador(this->getNumerador() * racional.getDenominador() + this->getDenominador() * racional.getNumerador());
    saida.setDenominador(this->getDenominador() * racional.getDenominador());
    return saida;
}

Racional Racional::operator - (Racional racional) {
    Racional saida;
    saida.setNumerador(this->getNumerador() * racional.getDenominador() - this->getDenominador() * racional.getNumerador());
    saida.setDenominador(this->getDenominador() * racional.getDenominador());
    return saida;
}

Racional Racional::operator * (Racional racional) {
    Racional saida;
    saida.setNumerador(this->getNumerador() * racional.getNumerador());
    saida.setDenominador(this->getDenominador() * racional.getDenominador());
    return saida;
}

Racional Racional::operator / (Racional racional) {
    Racional saida;
    saida.setNumerador(this->getNumerador() * racional.getDenominador());
    saida.setDenominador(this->getDenominador() * racional.getNumerador());
    return saida;
}

int main() {
    int a, b, c, d;
    std::string operador;
    while(std::cin >> a >> b >> operador >> c >> d) {
        Racional r1 = Racional(a, b);
        Racional r2 = Racional(c, d);
        Racional saida;

        if(operador == "+") {
            saida = r1 + r2;
        }
        if(operador == "-") {
            saida = r1 - r2;
        }
        if(operador == "*") {
            saida = r1 * r2;
        }
        if(operador == "/") {
            saida = r1 / r2;
        }

        saida.simplifica();
        std::cout << saida.getNumerador() << " " << saida.getDenominador() << std::endl;
    }
    return 0;
}
