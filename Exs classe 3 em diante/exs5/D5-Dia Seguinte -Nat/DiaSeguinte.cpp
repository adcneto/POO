#include <iostream>

class tData {
private :
  int dia;
  int mes;
  int ano;
public:
  tData();
  tData(int, int, int);
  void setDia(int);
  void setMes(int);
  void setAno(int);
  int getDia();
  int getMes();
  int getAno();
  bool isBissexto(int);
  void  seguinte();
  tData operator ++();
  tData operator ++(int);
  
};


tData :: tData(){
}

tData :: tData(int d, int m, int a){

  this -> setDia(d);
  this -> setMes(m);
  this -> setAno(a);
  
}

void tData :: setDia(int d){

  this -> dia = d;
}

void tData :: setMes(int m){

  this -> mes = m;
}

void tData :: setAno(int a){

  this -> ano = a;
}

int tData :: getDia(){

  return this -> dia;
}

int tData :: getMes(){

  return this -> mes;
}

int tData :: getAno() {

  return this -> ano;
}

bool tData :: isBissexto(int ano){
  
  return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);  
}
  

void tData :: seguinte(){

  tData seguinte;

  if ( this -> getDia() == 31){
    seguinte.setDia(1);
    
    if (this -> getMes() == 12){      
      seguinte.setMes(1);
      seguinte.setAno(this -> getAno() + 1);
    }

    else{
      seguinte.setMes(this -> getMes() +1);
      seguinte.setAno(this -> getAno());
    }
  }

  else if (this -> getDia() == 30){

    seguinte.setAno( this -> getAno());

    if(this -> getMes() == 1 || this -> getMes() == 3 ||this -> getMes() == 5 || this -> getMes() == 7 || this -> getMes() == 8 || this -> getMes() == 10 || this -> getMes() == 12){
      seguinte.setDia(31);
      seguinte.setMes(this -> getMes());
     		      
    }
    else{
      seguinte.setDia(1);
      seguinte.setMes(this -> getMes() + 1);

    }
  }

  else if (this -> getDia() == 29 && this -> getMes() == 2){
    seguinte.setDia(1);
    seguinte.setMes(3);
    seguinte.setAno(this -> getAno());
  }

  else if (this -> getDia() == 28 && this->getMes() == 2){
    seguinte.setAno(this -> getAno());
    
    if( this -> isBissexto(this -> getAno()) == true){
      seguinte.setDia(29);
      seguinte.setMes(this-> getMes());
    }
    else{
      seguinte.setDia(1);
      seguinte.setMes(3);
    }
  }

  else{
    seguinte.setDia(this -> getDia() + 1);
    seguinte.setMes(this -> getMes());
    seguinte.setAno(this -> getAno());
  }

  this -> setDia(seguinte.getDia());
  this -> setMes(seguinte.getMes());
  this -> setAno(seguinte.getAno());
  
}

tData tData :: operator ++ (){
  this -> seguinte();

  return *this;

}

tData tData :: operator ++ (int){

  tData novo(this -> getDia(), this -> getMes(), this -> getAno());

  this -> seguinte();

  return novo;

}

int main(){

  int d,m,a;

  std :: cin >> d >> m >> a;
  
  tData data(d,m,a);

  data ++;

  std :: cout << data.getDia() << " " << data.getMes() << " " << data.getAno() << std :: endl;


  return 0;
}





 
