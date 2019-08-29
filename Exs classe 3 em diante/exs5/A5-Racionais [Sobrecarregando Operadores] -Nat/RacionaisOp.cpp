#include <iostream>
#include <stdlib.h>

class tRacional{
private :
  int numerador;
  int denominador;

public :
  tRacional();
  tRacional(int, int);
  ~tRacional();
  void setNumerador(int);
  void setDenominador(int);
  int getNumerador();
  int getDenominador();
  int mdc(int, int);
  void simplifica(tRacional*);
  tRacional operator + (tRacional);
  tRacional operator - (tRacional);
  tRacional operator * (tRacional);
  tRacional operator / (tRacional);

};

tRacional :: tRacional(){
}


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

tRacional tRacional :: operator + (tRacional q){
  tRacional r;

  r.setNumerador(this -> getNumerador()* q.getDenominador() + this-> getDenominador() * q.getNumerador());

  r.setDenominador(this -> getDenominador() * q.getDenominador());

  return r;


}

tRacional tRacional :: operator - (tRacional q){

  tRacional r;

  r.setNumerador (this -> getNumerador() * q.getDenominador() - this -> getDenominador() * q.getNumerador());

  r.setDenominador(this -> getDenominador() * q.getDenominador());

  return r;

}


tRacional tRacional :: operator * (tRacional q){

  tRacional r;

  r.setNumerador( this -> getNumerador() * q.getNumerador());

  r.setDenominador( this -> getDenominador() * q.getDenominador());

  return r;
}

tRacional tRacional :: operator / (tRacional q){

  tRacional r;
  
  r.setNumerador(this -> getNumerador() * q.getDenominador());

  r.setDenominador( this -> getDenominador() * q.getNumerador());

  return r;

}

int main(){

  int n1,d1,n2,d2;
  char op;
  //tRacional r1, r2 -- construtor vazio;

  while(std :: cin >> n1 >> d1 >> op >> n2 >> d2){

    tRacional r1(n1,d1), r2(n2,d2), r3;
      

    if(op == '+'){

      r3 = r1 + r2;
      r3.simplifica(&r3);
    }

    else if (op == '-'){
      r3 = r1 - r2;
      r3.simplifica(&r3);
    }

    else if (op == '*'){
      r3 = r1 * r2;
      r3.simplifica(&r3);
    }

    else if (op == '/'){
      r3 = r1 / r2;
      r3.simplifica(&r3);
    }

    std :: cout << r3.getNumerador() << " " << r3.getDenominador() << std :: endl;

  }
  



  return 0;
}


  


