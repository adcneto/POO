#include <iostream>

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
  //void converte24(t12H*);
};


class t12H {
private :
  int hora;
  int minuto;
  int segundo;
  char m;

public :
  t12H();
  t12H(int, int, int, char);
  void setHora(int);
  void setMinuto(int);
  void setSegundo(int);
  void setMeridium(char);
  int getHora();
  int getMinuto();
  int getSegundo();
  char getMeridium();
  void converte12(t24H*);
};


t12H :: t12H(){
}
t24H :: t24H(){
}


t12H :: t12H(int h, int m, int s, char o){
  this -> setHora(h);
  this -> setMinuto(m);
  this -> setSegundo(s);
  this -> setMeridium(o);
}

t24H :: t24H(int h, int m, int s){
  this -> setHora(h);
  this -> setMinuto(m);
  this -> setSegundo(s);
}

void t12H :: setHora(int h){
  this -> hora = h;
}

void t24H:: setHora(int h){
  this -> hora = h;
}

void t12H :: setMinuto(int m){
  this -> minuto = m;
}

void t24H :: setMinuto(int m){
  this -> minuto = m;
}

void t12H :: setSegundo(int s){
  this -> segundo = s;
}

void t24H :: setSegundo(int s){
  this -> segundo = s;
}

void t12H :: setMeridium( char m){
  this -> m = m;
}

int t12H :: getHora(){
  return this -> hora;
}

int t24H :: getHora(){
  return this -> hora;
}

int t12H :: getMinuto(){
  return this -> minuto;
}

int t24H :: getMinuto(){
  return this -> minuto;
}

int t12H :: getSegundo(){
  return this -> segundo;
}

int t24H :: getSegundo(){
  return this -> segundo;
}

char t12H :: getMeridium(){
  return this -> m;
}

void t12H :: converte12(t24H* militar){
  if(militar -> getHora() < 12){

    if(militar -> getHora() == 0){
      this -> setHora(12);
    }
    
    else{
      this -> setHora(militar -> getHora());
      
    }
    this -> setMeridium('A');
    
  }
  else{
    if(militar -> getHora() == 12){
      this -> setHora(militar -> getHora());
    }

    else{
      this -> setHora(militar -> getHora() -12);
    }

    this -> setMeridium('P');
  }
  this -> setMinuto(militar -> getMinuto());
  this -> setSegundo(militar -> getSegundo());
  
}


/*void t24H :: converte24(t12H* civil){
  t24H resp;

  resp.setMinuto(civil -> getMinuto());
  resp.setSegundo(civil -> getSegundo());

  if(civil -> getMeridium() == 'P'){
    if(civil -> getHora() == 12){
      resp.setHora(12);
    }
    else{
      resp.setHora(civil -> getHora() + 12);
    }
  }
  else{
    if(civil -> getHora() == 12){
      resp.setHora(0);
    }
    else{
      resp.setHora(civil -> getHora());
    }
  }
  
  this -> setHora(resp.getHora());
  this -> setMinuto(resp.getMinuto());
  this -> setSegundo(resp. getSegundo());
  
  }*/

int main(){

  int h,m,s;
  
  while(std :: cin >> h >> m >> s ){

    t24H hora(h,m,s);

    t12H *convertido;

    convertido = new t12H();

    convertido -> converte12(&hora);

    std :: cout << convertido->getHora() <<  ":" << convertido->getMinuto() << ":"<< convertido->getSegundo() <<" "<< convertido -> getMeridium()<<"M"<< std :: endl;
  }

  return 0;
}








    

  


  
  
  
