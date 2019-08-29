#include <iostream>
#include <stdlib.h>
#include <math.h>


class tRacional{
  private:
    int numerador;
    int denominador;
  public: 
	 tRacional(int,int);
	~tRacional();
	void setNumerador(int);
	void setDenominador(int);
	int getNumerador();
	int getDenominador();
	void negativo();
	void soma(tRacional*);
	void produto(tRacional*);
	void quociente(tRacional*);
        int mdc(int, int);
	void simplifica(tRacional*);
};

tRacional :: tRacional(int numerador, int denominador){
	
	this -> setNumerador(numerador);
	this -> setDenominador(denominador);
}

void tRacional :: setNumerador(int numerador){

	this -> numerador = numerador;

}

void tRacional :: setDenominador(int denominador){

	this -> denominador = denominador;

}

tRacional :: ~tRacional(){

}

int tRacional :: getNumerador(){
	
	return this -> numerador;	

}

int tRacional :: getDenominador(){

	return this -> denominador;

}

void tRacional :: negativo(){
	
	this -> numerador = (-1) * this -> numerador;
	
}

void tRacional :: soma(tRacional *rac1){
	
	this -> setNumerador (this -> numerador * rac1->denominador + this -> denominador * rac1->numerador);

	this -> setDenominador (this -> denominador * rac1->denominador);

}

void tRacional :: produto(tRacional *rac1){
	
	this -> setNumerador(this -> numerador * rac1 -> numerador);
	this -> setDenominador(this -> denominador * rac1 -> denominador);


}

void tRacional :: quociente(tRacional *rac1){
	
	this -> setNumerador(this -> numerador * rac1 -> denominador);
	this -> setDenominador(this -> denominador * rac1 -> numerador);


}

int tRacional :: mdc(int a, int b){

  
  if(b==0){
    
    return a;
    
  }

  return abs( mdc(b,a%b));
  
}

void tRacional :: simplifica (tRacional *rac1){

  int fatorReducao = mdc(this -> numerador, this -> denominador);
  this ->setNumerador (this -> numerador / fatorReducao);
  this ->setDenominador(this -> denominador / fatorReducao);  

}


int main (int argc, char ** argv){
  
  int n1, d1, n2, d2;
  
  char op;

  tRacional *r1;
  tRacional *r2;
  
  while(std :: cin >> n1 >> d1 >> op >> n2 >> d2){

    r1 = new tRacional(n1,d1);
	r2 = new tRacional(n2,d2);


    if(op == '+'){
      
      r1->soma(r2);
      r1 -> simplifica(r1);
      
    }
	
	else if (op == '-'){
	  r2 -> negativo();
	  r1 -> soma(r2);
	  r1 -> simplifica(r1);
	}

	else if (op == '*'){

	  r1 -> produto(r2);
	  r1 -> simplifica(r1);
	}

	else if (op == '/'){

	  r1 -> quociente(r2);
	  r1 -> simplifica(r1);
	}

    
    std :: cout << r1-> getNumerador() << " " << r1->getDenominador() << std :: endl;  

    
  }

  return 0;
} 




































