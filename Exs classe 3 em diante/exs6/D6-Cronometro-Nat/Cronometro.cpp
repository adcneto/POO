#include <iostream>

class Cronometro{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        Cronometro();
        Cronometro(int, int, int);
        void setHora(int);
        void setMinuto(int);
        void setSegundo(int);
        int getHora();
        int getMinuto();
        int getSegundo();
        Cronometro operator ++(int);
        
};


Cronometro :: Cronometro(){
}

Cronometro :: Cronometro(int hora, int minuto, int segundo){
    this -> setHora(hora);
    this -> setMinuto(minuto);
    this -> setSegundo(segundo);

}

void Cronometro :: setHora(int hora){
    this -> hora = hora;
}

void Cronometro :: setMinuto(int minuto){
    this -> minuto = minuto;
}

void Cronometro :: setSegundo(int segundo){
    this -> segundo = segundo;

}

int Cronometro :: getHora(){
    return this -> hora;
}

int Cronometro :: getMinuto(){
    return this -> minuto;
}    

int Cronometro :: getSegundo(){
    return this -> segundo;
}

Cronometro Cronometro :: operator ++ (int qualquer){
	
    Cronometro *retorno = new Cronometro(this -> getHora(), this -> getMinuto(), this -> getSegundo());
    
    if(this -> getSegundo() + 1 == 60){
		this -> setSegundo(0);
		this-> setMinuto(this -> getMinuto() +1);
		
		if(this -> getMinuto() == 60){
			this->setMinuto(0);
			this -> setHora(this->getHora() +1);
		}	
	}

	else{
		this -> setSegundo(this->getSegundo()+1);	
	}

	return *retorno;
}


int main(){

	std :: string tic;
	Cronometro *cron = new Cronometro(0,0,0);

	while(std :: cin >> tic ){
		(*cron)++;		
	}

	std :: cout << cron->getHora()<< ":" << cron->getMinuto() << ":" << cron->getSegundo()<< std :: endl;


	return 0;
}








