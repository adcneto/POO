#include <iostream>

class tComplexo{
private:
  int real;
  int imaginario;

public:
  tComplexo();
  tComplexo(int,int);
  void setReal(int);
  void setImaginario(int);
  int getReal();
  int getImaginario();
  tComplexo operator + (tComplexo);
  tComplexo operator - (tComplexo);
  tComplexo operator * (tComplexo);
  tComplexo operator / (tComplexo);

};

tComplexo :: tComplexo(){

}

tComplexo :: tComplexo(int real, int imaginario){
  
  this ->setReal(real);
  this ->setImaginario(imaginario);
  
}

void tComplexo :: setReal(int real){
  
  this -> real = real;

}

void tComplexo ::  setImaginario(int imaginario){
  
  this -> imaginario = imaginario;
}

int tComplexo :: getReal(){
  
  return this -> real;
}

int tComplexo :: getImaginario(){

  return this -> imaginario;

}

tComplexo tComplexo :: operator + (tComplexo q){

  tComplexo r;

  r.setReal( this -> getReal() + q.getReal() );
  r.setImaginario (this -> getImaginario() + q.getImaginario());

  return r;

}

tComplexo tComplexo :: operator - (tComplexo q){

  tComplexo r;

  r.setReal(this -> getReal() - q.getReal());
  r.setImaginario(this -> getImaginario() -  q.getImaginario());

  return r;
}

tComplexo tComplexo :: operator * (tComplexo q){

  tComplexo r;

  int aux = this -> getReal();
  
  r.setReal(this ->getReal() * q.getReal() - this-> getImaginario() * q.getImaginario());

  r.setImaginario(this-> getImaginario() * q.getReal() + aux * q.getImaginario());

  return r;
  
}

tComplexo tComplexo :: operator / (tComplexo q){

  tComplexo r;

  int real, imaginario, quociente;

  real = this -> getReal() * q.getReal() + this -> getImaginario() * q.getImaginario();

  imaginario = this -> getImaginario() * q.getReal() - this -> getReal() * q.getImaginario();

  quociente = q.getReal() * q.getReal() + q.getImaginario() * q.getImaginario();

  r.setReal (real / quociente);

  r.setImaginario (imaginario / quociente);

  return r;

}

int main(){

  int r1, i1, r2, i2;
  char op,i;

  while(std :: cin >> r1 >> i1 >> i >> op >> r2 >> i2 >>i){

    tComplexo c1(r1,i1) , c2(r2,i2), resp;

    if(op == '+'){
      resp = c1 + c2;
    }

    else if (op == '-'){
      resp = c1 - c2;
    }

    else if (op == '*'){
      resp = c1 * c2;
    }

    else if (op == '/'){
      resp = c1 / c2;
    }

    if(resp.getImaginario() < 0){
	
	std :: cout << resp.getReal() << " " << resp.getImaginario()<<"i" << std :: endl;
    }

    else {
     	std :: cout << resp.getReal() << " +" << resp.getImaginario()<<"i" << std :: endl;
    }
      

  }

    


    


};







  
