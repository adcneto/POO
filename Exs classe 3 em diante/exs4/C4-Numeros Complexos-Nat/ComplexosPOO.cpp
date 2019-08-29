#include <iostream>
#include <stdlib.h>

class Complexo {

  private:
    int real;
    int imaginario;

  public :
    Complexo(int, int);
    Complexo();
    void setReal(int);
    void setImaginario(int);
    int getReal();
    int getImaginario();
    void soma(Complexo *);
    void sub(Complexo *);
    void mult(Complexo *);
    void div(Complexo *);

};

Complexo :: Complexo(int r,int i){
  
  this -> setReal(r);
  this -> setImaginario(i);

}

Complexo :: Complexo(){

}

void Complexo :: setReal(int r){
  this -> real = r;

}


void Complexo :: setImaginario(int im){
  this -> imaginario = im;

}

int Complexo:: getReal(){

  return this -> real;

}

int Complexo:: getImaginario(){
  
  return this -> imaginario;
  
}


void Complexo:: soma(Complexo *sum){

  this -> setReal(this ->real + sum -> real);
  this -> setImaginario(this->imaginario + sum -> imaginario);


}

void Complexo:: sub(Complexo * sub){
  this -> setReal (this-> real - sub -> real);
  this -> setImaginario (this -> imaginario - sub -> imaginario);

}

void Complexo:: mult(Complexo * mult){

  int aux = getReal();
  
  this -> setReal(this ->getReal() * mult -> real - this-> getImaginario() * mult -> imaginario);

  this -> setImaginario(this-> imaginario * mult -> real + aux * mult -> imaginario );

}

void Complexo:: div(Complexo *div){

  int real, imaginario, quociente;

  real = this -> getReal() * div -> real + this -> getImaginario() * div -> imaginario;

  imaginario = this -> getImaginario() * div -> real - this -> getReal() * div -> imaginario;

  quociente = div -> real * div -> real + div -> imaginario * div -> imaginario;

  this -> setReal (real / quociente);

  this -> setImaginario (imaginario / quociente);  

}



int main(){

  int r1,i1,r2,i2;
  char op, s;
  Complexo *n1;
  Complexo *n2;

  while(std :: cin >> r1 >> i1 >> s >> op >> r2 >> i2 >>s ){
    n1 = new Complexo(r1,i1);
    n2 = new Complexo(r2,i2);

    // std :: cout << n1 -> getReal() << " " << n1 -> getImaginario() <<std:: endl;
    //std :: cout << n2 -> getReal() << " " << n2 -> getImaginario() << std::endl;

    if (op =='+'){
      n1 -> soma(n2);
    }
    else if (op == '-'){
      n1 -> sub(n2);
    }
    else if (op == '*') {
      n1 -> mult(n2);
    }
    else {
      n1 -> div(n2);
    }

    if(n1->getImaginario() < 0){

      std :: cout << n1 -> getReal() << " " << n1 -> getImaginario()<<"i" << std :: endl;
    }

    else{
      std :: cout << n1 -> getReal() << " +" << n1 -> getImaginario()<<"i" << std :: endl;

    }


  }



  return 0;
  
}
