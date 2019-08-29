#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

//using namespace std;

class Data{
	private:
		int dia, mes, ano;
	public:
		Data();
		Data(int, int, int);
		void setDia(int);
		void setMes(int);
		void setAno(int);
		int getDia();
		int getMes();
		int getAno();

};

Data::Data(){ }

Data::Data(int dia, int mes, int ano){
        this->setDia(dia);
        this->setMes(mes);
        this->setAno(ano);
}

void Data::setDia(int dia){
    this->dia = dia;
}

void Data::setMes(int mes){
    this->mes = mes;
}

void Data::setAno(int ano){
    this->ano = ano;
}

int Data::getDia(){
    return this->dia;
}

int Data::getMes(){
    return this->mes;
}

int Data::getAno(){
    return this->ano;
}

class Conta{
	private:
		std::string numero;
		std::string titular;
		std::string cpf;
		bool bloqueada;
		float saldo;
	public:
		Conta();
		Conta(std::string, std::string);
		void setNumero(std::string);
		void setTitular(std::string);
		void setCpf(std::string);
		void setBloqueada(bool);
		void setSaldo(float);
		std::string getNumero();
		std::string getTitular();
		std::string getCpf();
		bool isBloqueada();
		float getSaldo();
		bool saque(float);
		bool deposito(float);
		void extrato();
		static std::string geraNumero(int);

};


Conta::Conta(){ }

Conta::Conta(std::string cpf, std::string nome){
	this->setNumero(Conta::geraNumero(10));
	this->setCpf(cpf);
	this->setTitular(nome);
	this->setSaldo(0);
}

void Conta::setBloqueada (bool status_de_bloqueio){
    this->bloqueada = status_de_bloqueio;
}

void Conta::setSaldo(float novo_saldo){
    this->saldo = novo_saldo;
}

void Conta::setNumero(std::string novo_numero){
    this->numero = novo_numero;
}

void Conta::setTitular(std::string novo_titular){
    this->titular = novo_titular;
}

void Conta::setCpf(std::string novo_cpf){
    this->cpf = novo_cpf;
}

std::string Conta::getNumero(){
    return this->numero;
}

std::string Conta::getTitular(){
    return this->titular;
}

std::string Conta::getCpf(){
    return this->cpf;
}

bool Conta::isBloqueada(){
    return this->bloqueada;
}

float Conta::getSaldo(){
    return this->saldo;
}

std::string Conta::geraNumero(int n){
    std::string numero ="";
    int i;
	std::srand(time(NULL));
	
	//gerando caracteres ASCII correspondentes a digitos de 0 a 9
	for(i=0; i<n; i++){
	    do{
	        numero += (std::rand()%10) + 48;
	    }while(!(std::isdigit(numero[i])));
	}
	
	return numero;
}

bool Conta::saque(float valor){
    if(valor <= this->getSaldo() && !(this->isBloqueada())){
        this->setSaldo(this->getSaldo() - valor);
        return true;
    }
    return false;
}

bool Conta::deposito(float valor){
    if(!(this->isBloqueada())){
        this->setSaldo(this->getSaldo() + valor);
        return true;
    }
    return false;
}

void Conta::extrato()
{
    std::cout << "===========================================" << std:: endl;
    std::cout << "CONTA : " << this->getNumero() << std:: endl;
    std::cout << "CPF ..: " << this->getCpf() << std::endl;
    std::cout << "NOME .: " << this->getTitular() << std::endl;
    std::cout << "SALDO : R$" << this->getSaldo() << std::endl;
    std::cout << "===========================================" << std:: endl;
}

class ContaPoupanca : public Conta{
    private:
        Data aniversario;
        float taxa;
    public:
		ContaPoupanca(std::string, std::string, int, int, int, float);
		void setAniversario(Data);
		void setTaxa(float);
		Data getAniversario();
		float getTaxa();
		void correcao();
		void extrato();        
};

ContaPoupanca::ContaPoupanca(std::string cpf, std::string nome, int dia, int mes, int ano, float taxa):Conta(cpf, nome){
	this->setAniversario(Data(dia, mes, ano));
	this->setTaxa(taxa);
}

void ContaPoupanca::setAniversario(Data data){
	this->aniversario = data;
}

void ContaPoupanca::setTaxa(float taxa){
	this->taxa = taxa;
}

Data ContaPoupanca::getAniversario(){
	return this->aniversario;
}

float ContaPoupanca::getTaxa(){
	return this->taxa;
}

void ContaPoupanca::correcao()
{	}

void ContaPoupanca::extrato(){
	Conta::extrato();
	std::cout << "ANIVERSARIO: " << this->getAniversario().getDia() << std::endl;

    std::cout << "===========================================" << std:: endl;
}

int main()
{
	ContaPoupanca ctp("22388645633", "Monael", 18, 7, 2019, 10);
	std::cout << "CONTA POUPANCA\n";
	ctp.extrato();
	ctp.deposito(500);
	ctp.extrato();
	std::cout << "\n\n" << std::endl;
	std::cout << "CONTA PADRAO\n";
	Conta cta("24937797387", "Washington");
    cta.extrato();
    cta.deposito(100);
    cta.extrato();
    std::cout << "\n\n" << std::endl;
    
    //Exemplo de Casting entre classes:   
    int i, num_contas;
    std::cout << "Digite o numero de contas que deseja cadastrar: ";
    std::cin >> num_contas;
    Conta *agencia[num_contas];
    //Conta agencia[num_contas];

    std::string cpf, nome;
    for(i=0; i<num_contas; i++){
        std::cin >> cpf >> nome;
        /*aqui o Casting de ContaPoupanca para Conta eh implicito. Em geral, todo objeto de uma subclasse é implicitamente convertido para objeto da superclasse.*/
        agencia[i] = new ContaPoupanca(cpf, nome, 10, 10, 2014, 10);
        //agencia[i] = ContaPoupanca(cpf, nome, 10, 10, 2014, 10);
    }
    for(i=0; i<num_contas; i++){
        agencia[i]->extrato();
        //agencia[i].extrato();
    }
    
	return 0;
}
