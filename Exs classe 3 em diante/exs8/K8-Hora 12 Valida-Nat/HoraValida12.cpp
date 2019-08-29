#include <iostream>

class OutOfRangeException: public std:: runtime_error{
    public :
        OutOfRangeException():runtime_error("HORARIO INVALIDA"){}

};


class t12H {
private :
  int hora;
  int minuto;
  int segundo;
  std :: string m;

public :
  t12H();
  t12H(int, int, int, std::string);
  void setHora(int);
  void setMinuto(int);
  void setSegundo(int);
  void setMeridium(std::string);
  int getHora();
  int getMinuto();
  int getSegundo();
  std::string getMeridium();
  
};


t12H :: t12H(){
}

t12H :: t12H(int h, int m, int s, std :: string o){
  this -> setHora(h);
  this -> setMinuto(m);
  this -> setSegundo(s);
  this -> setMeridium(o);
}


void t12H :: setHora(int h){
    if(h >12 || h < 1){
      throw OutOfRangeException();
    }
  this -> hora = h;
}



void t12H :: setMinuto(int m){
     if(m > 59 || m < 0){
      throw OutOfRangeException();
    }
  this -> minuto = m;
}


void t12H :: setSegundo(int s){
    if(s > 59 || s < 0){
      throw OutOfRangeException();
    }
  this -> segundo = s;
}



void t12H :: setMeridium( std:: string m){
    if(m != "AM" && m != "PM"){
        throw OutOfRangeException();
    }
  this -> m = m;
}

int t12H :: getHora(){
  return this -> hora;
}


int t12H :: getMinuto(){
  return this -> minuto;
}


int t12H :: getSegundo(){
  return this -> segundo;
}


std::string t12H :: getMeridium(){
  return this -> m;
}


int main(){

  int h,m,s;
  std:: string horario,E;

  while(std :: cin >> horario>>E){
    try{
        t12H* horas = new t12H(((int)(horario[0]*10-480)+(int)(horario[1]-48)),((int)(horario[3]*10-480)+(int)(horario[4]-48)),((int)(horario[6]*10-480)+(int)(horario[7]-48)),E);
        std :: cout << "HORA VALIDA"<<std::endl;
        
    }
    catch(OutOfRangeException e){
    
        std :: cout << e.what() << std :: endl;    
    }

  }

  return 0;
}








    

  


  
  
  
