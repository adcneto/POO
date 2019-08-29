#include <iostream>
#include <cstdlib>

int main(){
    std::srand(time(NULL));
	std::string numero = "";
	int n;
	std::cout << "Informe um comprimento de string: ";
	std::cin >> n;
	for(int i=0; i<n; i++){
	    do{
	        numero += (std::rand()%10) + 48;
	        std::cout << std::isdigit(numero[i]) <<std::endl;
	    }while(!(std::isdigit(numero[i])));
	}
	
	std::cout << "A string sorteada é: " << numero <<std::endl;
	
	for(int i=0; i<numero.length(); i++){
	    
		std::cout << numero[i] <<" é digito? Resposta: " <<std::isdigit(numero[i]) << std::endl;
	}
	return 0;
}
