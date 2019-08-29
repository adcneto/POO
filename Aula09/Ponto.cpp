#include <iostream>
#include <typeinfo>

using namespace std;

class Ponto{
	private:
		float x, y;
	public:
		Ponto();
		Ponto(float, float);
		void setX(float);
		void setY(float);
		float getX();
		float getY();
		Ponto operator ++(int);
		Ponto operator ++();
		
};

Ponto::Ponto(){ }

Ponto::Ponto(float x, float y){
	setX(x);
	setY(y);
}

void Ponto::setX(float x){
	this->x = x; 

}

void Ponto::setY(float y){
        this->y = y;

}

float Ponto::getX(){
	return this->x;
}

float Ponto::getY(){

	return this->y;
}

//Pre-fixado
Ponto Ponto::operator ++(){
	this->setX(this->getX()+1);
	this->setY(this->getY()+1);
	return *this;
}

//Pos-fixado
Ponto Ponto::operator ++(int){
	Ponto aux;
	aux = *this;
	this->setX(this->getX()+1);
        this->setY(this->getY()+1);
        return aux;
}

int main(){
	Ponto p1(2,3), p2(5,9), pr1, pr2;
	pr1 = p1++;
	cout << "p1(" << p1.getX() << "," << p1.getY() << ")" << endl;
	cout << "pr1(" << pr1.getX() << "," << pr1.getY() << ")" << endl;
	pr2 = ++p2;
	cout << "p2(" << p2.getX() << "," << p2.getY() << ")" << endl;
	cout << "pr2(" << pr2.getX() << "," << pr2.getY() << ")" << endl;
	int a=5, b=2;

	float divReal = a/b;
	cout << divReal << " " << typeid(divReal).name() << endl;

	divReal = a/((float)(b));
	cout << divReal << " " << typeid(divReal).name() << endl;

	divReal = ((float)(a))/b;
        cout << divReal << " " << typeid(divReal).name() << endl;

	return 0;

}

