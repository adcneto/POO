#include <iostream>

class Data{
private:
  int dia;
  int mes;
  int ano;

public:
  Data();
  Data(int,int,int);
  void setDia(int);
  void setMes(int);
  void setAno(int);
  int getDia();
  int getMes();
  int getAno();
  bool isBissexto(int);
  void anterior();
  Data operator --();
  Data operator --(int);

};

Data :: Data(){
}

Data :: Data(int d, int m, int a){
  this -> setDia(d);
  this -> setMes(m);
  this -> setAno(a);
}

void Data :: setDia(int d){
  this -> dia = d;
}

void Data :: setMes (int m){
  this -> mes = m;
}

void Data :: setAno (int a){
  this -> ano = a;
}

int Data :: getDia(){
  return this -> dia;
}

int Data :: getMes(){
  return this -> mes;
}

int Data :: getAno(){
  return this -> ano;
}

bool Data :: isBissexto(int ano){
   return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);  
}

void Data :: anterior(){
  Data anterior;

  if( this -> getDia() == 1){

    if (this -> getMes() == 1){

	anterior.setDia(31);
	anterior.setMes(12);
	anterior.setAno(this -> getAno() -1);
    }

    else if (this -> getMes() == 2 || this -> getMes() == 4 || this -> getMes() == 6 || this -> getMes() == 8 || this -> getMes() == 9 || this -> getMes() == 11 ){
      anterior.setDia(31);
      anterior.setMes(this -> getMes() - 1);
      anterior.setAno(this -> getAno());
    }
    else if(this -> getMes() != 3) {
      anterior.setDia(30);
      anterior.setMes(this -> getMes()-1);
      anterior.setAno(this -> getAno());
    }
  

    else if(this -> getMes() == 3){

      if(this -> isBissexto(this -> getAno()) == true ){
	anterior.setDia(29);
	
      }

      else{
	anterior.setDia(28);
      }

      anterior.setMes(2);
      anterior.setAno( this -> getAno());
    }
  }

  else{
    anterior.setDia(this -> getDia() - 1);
    anterior.setMes(this -> getMes());
    anterior.setAno(this -> getAno());
  }

  this -> setDia(anterior.getDia());
  this -> setMes(anterior.getMes());
  this -> setAno(anterior.getAno());
  
}

Data Data :: operator -- (){
  this -> anterior();

  return *this;
}

Data Data :: operator -- (int){
  Data novo(this -> getDia(), this -> getMes(), this -> getAno());

  this -> anterior();

  return novo;
}

int main(){
  int d,m,a;

  std :: cin >> d >> m >> a;

  Data data(d,m,a);

  data--;

  std :: cout << data.getDia() << " " << data.getMes() << " " << data.getAno() << std :: endl;

  return 0;

}
  
      
