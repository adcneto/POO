#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

class Decimal{
private:
  long long int num;
public:
  Decimal();
  Decimal(long long int);
  void setDecimal(long long int);
  long long int getDecimal();
}; 



class Binary{
private:
  std :: string num;
public:
  Binary();
  Binary(std :: string);
  void setBinary(std::string);
  std :: string getBinary();
  Binary DecToBin(Decimal);
};
  
Binary :: Binary(){
}

Decimal :: Decimal(){
}

Binary :: Binary(std :: string num){
  this -> setBinary(num);
}

Decimal :: Decimal(long long int num){
  this -> setDecimal(num);
}

void Binary :: setBinary(std::string num){
  this -> num = num;
}

void Decimal :: setDecimal(long long int num){
  this -> num = num;
}

std:: string Binary:: getBinary(){
  return this -> num;
}

long long int Decimal :: getDecimal(){
  return this -> num;
}


Binary Binary :: DecToBin(Decimal target){
  std :: string resp = "0";

  Binary resposta(resp);
  
  if(target.getDecimal() == 0){
    return resposta;
  }
  
  std::ostringstream os;
  while(target.getDecimal() > 0){
    os << target.getDecimal()%2;    
    target.setDecimal(target.getDecimal()/2);
  }

  resp = os.str();
  std::reverse(resp.begin(),resp.end());

  resposta.setBinary(resp);
  
  return resposta;
  
}


int main(){
 
  long long int num;
  
  while(std :: cin >> num ){
    Decimal dec(num);
    Binary bin("");
    
    bin = bin.DecToBin(dec);

    std :: cout << bin.getBinary() << std :: endl;
    
  }


  return 0;
}
