#include <iostream>


class OutOfBoundsException : public std :: runtime_error
{
    public:
        OutOfBoundsException(): runtime_error("HORARIO INVALIDO")
        {}

};


class t24H {
private :
  int hora;
  int minuto;
  int segundo;

public:
  t24H();
  t24H(int, int, int);
  void setHora(int);
  void setMinuto(int);
  void setSegundo(int);
  int getHora();
  int getMinuto();
  int getSegundo();
  

  
};



t24H :: t24H(){
}


t24H :: t24H(int h, int m, int s){
  this -> setHora(h);
  this -> setMinuto(m);
  this -> setSegundo(s);
}


void t24H:: setHora(int h){
  if(h < 0 || h >= 24){
    throw OutOfBoundsException();
  }
  this -> hora = h;
}


void t24H :: setMinuto(int m){
  if(m < 0 || m >= 60){
    throw OutOfBoundsException();
  }
  this -> minuto = m;
}

void t24H :: setSegundo(int s){
  if(s < 0 || s >= 60){
    throw OutOfBoundsException();
  }
  this -> segundo = s;
}

int t24H :: getHora(){
  return this -> hora;
}


int t24H :: getMinuto(){
  return this -> minuto;
}





int main(){

  std :: string horario;

  while(std :: cin >> horario){
    try{
        t24H* horas = new t24H(((int)(horario[0]*10-480)+(int)(horario[1]-48)),((int)(horario[3]*10-480)+(int)(horario[4]-48)),((int)(horario[6]*10-480)+(int)(horario[7]-48))); 

        std :: cout << "HORA VALIDA" << std :: endl;        
    }
    catch(OutOfBoundsException e){
        std :: cout << e.what() << std :: endl;
    
    }
    
  }

  return 0;
}








    

  


  
  
  
