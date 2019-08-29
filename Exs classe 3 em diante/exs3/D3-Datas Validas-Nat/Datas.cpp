#include <iostream>
using namespace std;


struct tData{
  int dia;
  int mes;
  int ano;

};

int ehBissexto(struct tData data) {
	
	if(data.ano%400 == 0 || (data.ano%4 ==0 && data.ano%100 != 0) ){
		return 1;
	}
	
	return 0;
}



int main() {
	
  struct tData data;
  int nIt;

  cin >> nIt;
	
  while(nIt){
    cin >> data.dia >>data.mes >>data.ano;

    if(data.dia < 1 || data.dia > 31 ||data.mes < 1 || data.mes > 12 || data.ano < 1 ||(data.dia >29 && data.mes == 2)){
      cout << "DATA INVALIDA" << endl;
	
    }
		
    else if (data.dia == 29 && data.mes == 2){
      
      if(ehBissexto(data)==1){
	
	cout << "DATA VALIDA" << endl;
	
      }
      
      else{
	
	cout << "DATA INVALIDA"<< endl;
	
      }
	
    }
		
    else if(data.dia == 31 && (data.mes == 1 ||data.mes == 3 || data.mes == 5 || data.mes ==7 || data.mes == 8 || data.mes == 10 || data.mes == 12) ){
      
      cout << "DATA VALIDA" << endl;
      
    }
    		
    else if (data.dia == 31 && (data.mes ==2 || data.mes ==4 || data.mes == 6 || data.mes == 9 || data.mes == 11)){
      cout << "DATA INVALIDA" << endl;
    }
		
    else{
      cout << "DATA VALIDA" << endl;
    }

    nIt --;
		
  }
	

  return 0;
}
