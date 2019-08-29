#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <math.h>

class Binary{
private:
  std :: string num;
public:
  Binary();
  Binary(std :: string);
  void setBinary(std::string);
  std :: string getBinary();
  // Binary DecToBin(Decimal);
};

class Decimal{
private:
  unsigned long long int num;
public:
  Decimal();
  Decimal(unsigned long long int);
  void setDecimal(unsigned long long int);
  unsigned long long int getDecimal();
  Decimal BinToDec(Binary);
}; 

  
Binary :: Binary(){
}

Decimal :: Decimal(){
}

Binary :: Binary(std :: string num){
  this -> setBinary(num);
}

Decimal :: Decimal(unsigned long long int num){
  this -> setDecimal(num);
}

void Binary :: setBinary(std::string num){
  this -> num = num;
}

void Decimal :: setDecimal(unsigned long long int num){
  this -> num = num;
}

std:: string Binary:: getBinary(){
  return this -> num;
}

unsigned long long int Decimal :: getDecimal(){
  return this -> num;
}


/*Binary Binary :: DecToBin(Decimal target){
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
  
  }*/

Decimal Decimal :: BinToDec(Binary tgt){
  

  unsigned long long int resp = 0;

  std::string str = tgt.getBinary();
  std::reverse(str.begin(),str.end());

  for(int i = 0; i < str.length(); i++){
    // std::cout<<"->" << (int)str[i]-48<<" <- \n";
    if((int)str[i]-48 == 1){
      resp += ((unsigned long long int)pow(2, i));
    }
  }
  
  
  Decimal resposta(resp);

  return resposta;
  
}



int main(){
 
  
  std :: string bin;
  
  while(std :: cin >> bin ){
    Binary binario(bin);
    Decimal dec;
    
    dec = dec.BinToDec(binario);

    std :: cout << dec.getDecimal() << std :: endl;
    
  }


  return 0;
}
