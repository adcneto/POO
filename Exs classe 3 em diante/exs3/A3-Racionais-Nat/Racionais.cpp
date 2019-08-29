#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct tRacional{
  
  int numerador;
  
  int denominador;
  
};

struct tRacional racional(int, int);

struct tRacional negativo(struct tRacional);

struct tRacional soma(struct tRacional, struct tRacional);

struct tRacional mult(struct tRacional, struct tRacional);

struct tRacional div(struct tRacional, struct tRacional);

struct tRacional reduz(struct tRacional);

int mdc(int, int);


int main (int argc, char ** argv){
  
  int n1, d1, n2, d2;
  
  char op;
  
  while(cin >> n1 >> d1 >> op >> n2 >> d2){

    struct tRacional r1, r2, resp;

    r1 = racional(n1,d1);
    
    r2 = racional(n2,d2);

    if(op == '+'){
      
      resp = soma(r1, r2);
      
    }

    else if( op == '-'){
      
      resp = soma(r1,negativo(r2));
      
    }

    else if( op == '*'){
      
      resp = mult(r1,r2);
      
    }

    else{
      
      resp = div(r1,r2);
      
    }

    cout << resp.numerador << " " << resp.denominador << endl;  

    
  }

  return 0;
} 


struct tRacional racional(int numerador, int denominador){

  struct tRacional r;

  r.numerador = numerador;
  
  r.denominador = denominador;

  return r;

} 

struct tRacional negativo(struct tRacional numero){

  struct tRacional inverso;

  inverso.numerador = -1 * numero.numerador;
  
  inverso.denominador = numero.denominador;
  
  return inverso;

} 


struct tRacional soma(struct tRacional r1, struct tRacional r2){

  struct tRacional resp;

  resp.denominador  = r1.denominador * r2.denominador;
  
  resp.numerador = r1.numerador*r2.denominador + r2.numerador*r1.denominador;

  resp = reduz(resp);

  return resp;

}

struct tRacional mult(struct tRacional r1, struct tRacional r2){

  struct tRacional resp;

  resp.denominador  = r1.denominador * r2.denominador;
  
  resp.numerador = r1.numerador * r2.numerador;

  resp = reduz(resp);

  return resp;

}

struct tRacional div(struct tRacional r1, struct tRacional r2){

  struct tRacional resp;

  resp.denominador  = r1.denominador * r2.numerador;
  
  resp.numerador = r1.numerador * r2.denominador;

  resp = reduz(resp);

  
  return resp;

}

int mdc(int a, int b){

  if(b==0){
    
    return a;
    
  }

  return abs( mdc(b,a%b));

}

struct tRacional reduz(struct tRacional resp){

  struct tRacional reduzido;

  int fatorDeReducao = mdc(resp.numerador,resp.denominador);

  reduzido.numerador = resp.numerador/fatorDeReducao;
  
  reduzido.denominador = resp.denominador/fatorDeReducao;

  return reduzido;


}
  
