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
		//Declaramos extrato() como VIRTUAL para que objetos das subclasses
		//que forem referenciado por ponteiros do tipo da superclasse
		//possam acessar suas proprias versoes de extrato()
		virtual void extrato();
		
		//Aqui implementamos correcao como um METODO VIRTUAL PURO.
		//Assumimos o compomissos de implementá-lo nas subclasses em que
		//esse metodo for necessario (nas suas diferentes versoes).
		virtual void correcao() = 0;
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

void ContaPoupanca::correcao(){	
    if(!(this->isBloqueada()))
        this->setSaldo(this->getSaldo()*1.02);

}



void ContaPoupanca::extrato(){
	Conta::extrato();
	std::cout << "ANIVERSARIO: " << this->getAniversario().getDia() << std::endl;

    std::cout << "===========================================" << std:: endl;
}


class ContaInvestimento : public Conta
{
    private:
        float taxaRendimento;
        float taxaAdministracao;
    public:
        ContaInvestimento(std::string, std::string, float);
        void setTaxaRendimento(float);
        float getTaxaRendimento();
        void setTaxaAdministracao(float);
        float getTaxaAdministracao();
        void correcao();
        void extrato();
};

ContaInvestimento::ContaInvestimento(std::string nome, std::string cpf, float taxa) : Conta(nome, cpf)
{
	this->setTaxaRendimento(taxa);
	this->setTaxaAdministracao(0);
}

void ContaInvestimento::setTaxaRendimento(float taxa)
{
	this->taxaRendimento = taxa;
}

void ContaInvestimento::setTaxaAdministracao(float taxa)
{
	this->taxaAdministracao = taxa;
}

float ContaInvestimento::getTaxaRendimento()
{
	return this->taxaRendimento;
}

float ContaInvestimento::getTaxaAdministracao()
{
	return this->taxaAdministracao;
}

void ContaInvestimento::correcao(){
    if(!this->isBloqueada())
        this->setSaldo(this->getSaldo()*(1+this->getTaxaRendimento()/100));
}

void ContaInvestimento::extrato()
{
	Conta::extrato();
	std::cout << "TAXA DE RENDIMENTO: " << this->getTaxaRendimento() << "\%a.m." << std::endl;
	std::cout << "TAXA DE ADMINISTRACAO: " << this->getTaxaAdministracao() << "\%a.m." << std::endl;
	std::cout << "===========================================" << std::endl;
}

int main()
{
    Conta *agencia[10];
    int i;
    
    for(i=0; i<10; i++)
    {
        if(i%2==0)
            agencia[i] = new ContaPoupanca("123", "Fulano", 12, 7, 2016, 10);
        else
            agencia[i] = new ContaInvestimento("456", "Beltrano", 10);
            
        agencia[i]->deposito(100);
 
    }
    for(i=0; i<10; i++)
        agencia[i]->correcao();
        
    for(i=0; i<10; i++){
        std::cout << "Conta " << i+1 <<std::endl;
        agencia[i]->extrato();
        if(i<9)
            std::cout <<"\n"<<std::endl;
    }
    
    //A declaracao abaixo nao funcionaria pois Conta é classe abstrata,
    //já que nela há pelo menos um metodo virtual puro.
    //Nao se pode instanciar objeto de classes abstratas. Só ponteiros.

/*    Conta teste_bobo("123", "Fulanóidesson");
    std::cout << teste_bobo.getCpf() << std::endl;
*/
    return 0;

}
