#include <iostream>
#include <cmath>

class Ponto{
	private:
		float x, y;
	public:
		Ponto();
		Ponto(float, float);
		static float distancia(Ponto, Ponto);
		float getX() const;
		float getY() const;
		void setX(float);
		void setY(float);

};


Ponto::Ponto(){ }

Ponto::Ponto(float x, float y){
	this->setX(x);
	this->setY(y);
}

float Ponto::getX()const{
	return this->x;
}

float Ponto::getY()const{
	return this->y;
}

void Ponto::setX(float x){
	this->x = x;
}

void Ponto::setY(float y){
	this->y = y;
}

float Ponto::distancia(Ponto p1, Ponto p2){
	return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(),2));
}

int main(){
	int xP,yP, xQ,yQ;
	std::cin >> xP >> yP >> xQ >> yQ;
	Ponto p(xP,yP), q(xQ,yQ);

	std::cout << "A distancia entre P("<<p.getX() <<","<<p.getY()<< ") e Q("<< q.getX()<<","<< q.getY() << ") é: "<< Ponto::distancia(p,q) << std::endl;
	//As seguintes chamadas de metodo funcionam, mas nao sao recomendadas:
/*
	std::cout << "A distancia entre P("<<p.getX() <<","<<p.getY()<< ") e Q("<< q.getX()<<","<< q.getY() << ") é: "<< p.distancia(p,q) << std::endl;
	std::cout << "A distancia entre P("<<p.getX() <<","<<p.getY()<< ") e Q("<< q.getX()<<","<< q.getY() << ") é: "<< q.distancia(p,q) << std::endl;
*/



	return 0;
}
