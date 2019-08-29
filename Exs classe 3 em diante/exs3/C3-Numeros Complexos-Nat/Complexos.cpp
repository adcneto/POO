#include <iostream>
#include <stdlib.h>

using namespace std;

struct tComplex{

  int real;

  int imaginario;

};

struct tComplex complexo(int, int);

struct tComplex soma(struct tComplex, struct tComplex);

struct tComplex sub(struct tComplex, struct tComplex);

struct tComplex mult(struct tComplex, struct tComplex);

struct tComplex div(struct tComplex, struct tComplex);

  
int main(int argc, char ** argv){

  int r1, i1, r2, i2;
  char ops ,dummy;
  
  while(cin >> r1 >> i1 >> dummy >> ops >> r2 >> i2 >> dummy){

    struct tComplex c1, c2, resp;

    c1 = complexo(r1,i1);
    c2 = complexo(r2,i2);

    if(ops == '+' ){
      
      resp = soma(c1,c2);
      
    }

    else if(ops == '-' ){
      
      resp = sub(c1,c2);
      
    }

    else if(ops == '*'){
      
      resp = mult(c1,c2);
      
    }

    else{
      
      resp = div(c1,c2);
      
    }

    if(resp.imaginario >=0){
      
      cout << resp.real << " +" << resp.imaginario <<"i" << endl;
      
    }
    
    else{
      
      cout << resp.real << " " << resp.imaginario << "i" << endl;
      
    }
    
  }

  return 0;
}


struct tComplex complexo(int r, int im){

  struct tComplex numero;

  numero.real = r;
  numero.imaginario = im;

  return numero;

}


struct tComplex soma(struct tComplex c1, struct tComplex c2){

  struct tComplex resp;

  resp.real = c1.real + c2.real;
  resp.imaginario = c1.imaginario + c2.imaginario;

  return resp;
}

struct tComplex sub(struct tComplex c1, struct tComplex c2){

  struct tComplex resp;

  resp.real = c1.real - c2.real;
  resp.imaginario = c1.imaginario - c2.imaginario;

  return resp;
}

struct tComplex mult(struct tComplex c1, struct tComplex c2){

  struct tComplex resp;

  int t1, t2, t3, t4;

  t1 = c1.real * c2.real;
  t2 = c1.real * c2.imaginario;
  t3 = c1.imaginario * c2.real;
  t4 = c1.imaginario * c2.imaginario;

  resp.real = t1 - t4;
  resp.imaginario = t2 + t3;

  return resp;
}

struct tComplex div(struct tComplex c1, struct tComplex c2){

  struct tComplex resp;
  int real, imaginario, quociente;

  real = c1.real * c2.real + c1.imaginario * c2.imaginario;

  imaginario = c2.real * c1.imaginario - c1.real * c2.imaginario;

  quociente = c2.real * c2.real + c2.imaginario * c2.imaginario;

  //cout << quociente << endl; 
   
  resp.real = real / quociente;
  
  resp.imaginario = imaginario/quociente;
  
  return resp;
}
