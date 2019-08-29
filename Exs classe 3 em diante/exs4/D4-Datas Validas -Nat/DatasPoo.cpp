#include <iostream>

class Data{

  private :
    int dia;
    int mes;
    int ano;

  public:
    Data();
    Data(int, int, int);
    void setDia(int);
    void setMes(int);
    void setAno(int);
    int getDia();
    int getMes();
    int getAno();
    bool isBissexto();
    int isValida();
};

Data :: Data(){
}

Data :: Data(int dia, int mes, int ano){

  this -> setDia(dia);
  this -> setMes(mes);
  this -> setAno(ano);  
  
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

int Data :: getDia (){

  return this->dia; 

}

int Data :: getMes(){

  return this -> mes;

}

int Data :: getAno(){

  return this -> ano;

}


bool Data :: isBissexto(){

  if ( this -> getAno() % 400 == 0 || (this -> getAno() % 100 != 0 && this -> getAno() % 4 ==0)){

      return true;
    }

  return false;
}

int Data :: isValida(){

  if(this -> getDia() < 1 || this -> getDia() > 31 || this -> getMes() < 1 || this -> getMes() > 12 || this -> getAno() < 1 || (this -> getDia() > 29 && this -> getMes() == 2)|| (this -> getDia() == 29 && this -> getMes() == 2 &&  isBissexto() == false )||(this -> getDia() == 31 && (this -> getMes() == 4 || this -> getMes() == 6 || this -> getMes() == 9 || this -> getMes() == 11))){

    std :: cout << "DATA INVALIDA" << std :: endl;
    
    return 0;
  }

   std:: cout << "DATA VALIDA"<< std :: endl;
   return 0;
}


int main () {

  int dia, mes, ano,i;
  Data * data;
  

  std :: cin >> i;

  while(i--){

    std :: cin >> dia >> mes >> ano;

    data = new Data(dia,mes,ano);

    data -> isValida();     


  }



  return 0;
}

