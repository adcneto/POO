#include <iostream>

class Cronometro{
    protected:
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

class Relogio : public Cronometro{
	private:
		Cronometro *relogio;
	public:
		Relogio();
		Relogio(Cronometro*);
		void setRelogio(Cronometro*);
		Cronometro* getRelogio();
		Relogio operator ++(int);

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

Relogio :: Relogio(){
}

Relogio :: Relogio(Cronometro *clock){
	this -> setRelogio(clock);	
}

void Relogio :: setRelogio(Cronometro *clock){
	this -> relogio = clock;
}

Cronometro* Relogio :: getRelogio(){
	return this -> relogio;
}

Relogio Relogio :: operator ++(int qualquer){
	
    Relogio *retorno = new Relogio(this -> getRelogio());
    
	Cronometro *it = this -> getRelogio();
	(*it)++;
	it->setHora(it->getHora() % 24);

	this -> setRelogio(it);

	return *retorno;

}


int main(){

	std :: string tic;
	Cronometro * clock = new Cronometro(0,0,0);
	Relogio *relogio = new Relogio(clock);

	while(std :: cin >> tic ){
		(*relogio)++;		
	}

	std :: cout << relogio-> getRelogio()->getHora()<< ":" << relogio->getRelogio()->getMinuto() << ":" << relogio->getRelogio()->getSegundo()<< std :: endl;


	return 0;
}








