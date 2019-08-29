#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Racional{
	private:
		int numerador, denominador;
		string r;

	public:
		Racional();
		Racional(int, int);
		string getRacional();
		int getNumerador();
		int getDenominador();
		void setRacional(int, int);
		Racional operator + (Racional);
		operator float();
		operator double();
		void operator =(int);
		void operator =(float);
		
};

Racional::Racional(){ }


Racional::Racional(int numerador, int denominador){

	this->setRacional(numerador,denominador);
}

string Racional::getRacional(){
	return this->r;
}

int Racional::getNumerador(){
	return this->numerador;
}

int Racional::getDenominador(){
        return this->denominador;
}

void Racional::setRacional(int numerador, int denominador){
	this->numerador = numerador;
	this->denominador = denominador;
	int divisor = denominador;
	while(divisor>=2){
		while((this->numerador)%divisor==0 && (this->denominador)%divisor==0 && divisor>1){
			this->numerador = this->numerador/divisor;
			this->denominador = this->denominador/divisor;

			if(this->denominador < divisor)
				divisor = this->denominador;
			
		}
		divisor--;
	}

	//Conversao numero para string:

	stringstream streamDenom, streamNume;
	string denomStr, numeStr;

	streamDenom << this->denominador;
	streamNume << this->numerador;

	denomStr = streamDenom.str();
	numeStr = streamNume.str();
	
	
	this->r = numeStr + "/" + denomStr;
}

Racional Racional::operator + (Racional q){
	Racional soma;
	int novoDenom, novoNume;
	novoNume = this->numerador*q.getDenominador() + q.getNumerador()*this->denominador;
	novoDenom = this->denominador * q.getDenominador();
	soma.setRacional(novoNume, novoDenom);
	return soma;
}

Racional::operator float(){
	return this->getNumerador()/(float)(this->getDenominador());
}

Racional::operator double(){
        return this->getNumerador()/(double)(this->getDenominador());
}

void Racional::operator =(int inteiro_original){
	this->setRacional(inteiro_original, 1);
}

void Racional::operator=(float num_float){
	string s;
	s = num_float;
	
}


int main(){
	int n, d;

	cout <<"Informe o numerador A: ";
	cin >> n;
	cout << "Informe o denominador A: ";
	cin >> d;

	Racional R1(n,d);

	cout <<"Informe o numerador B: ";
        cin >> n;
        cout << "Informe o denominador B: ";
	cin >> d;
	Racional R2(n,d), soma;
	soma = R1 + R2;
	
	
	cout << "A soma dos racionais A e B é: " << soma.getRacional() <<endl;

	float f; f = R1;
	double db; db = R1;
	
	cout << "A conversao do raciona A para float é: " << f <<endl;
	cout << "A conversao de racional A para double é: " << db <<endl;

        f = R2;
        db = R2;

        cout << "A conversao do raciona B para float é: " << f <<endl;
        cout << "A conversao de racional B para double é: " << db <<endl;

	cout << "O soma original é: " << soma.getRacional() << endl;

	int inteiro_original;
	cout << "Digite um valor inteiro: ";
	cin >> inteiro_original;
	
	Racional inteiro_convertido_para_racional;
	inteiro_convertido_para_racional = inteiro_original;

	cout << "O inteiro original convertido para racional é: " << inteiro_convertido_para_racional.getRacional() << endl;

	return 0;
}
