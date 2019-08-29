#include <iostream>

int main(){
	int *itens, tam;
	std::cout << "Digite o tamanho da array: ";
	std::cin >> tam;
	itens = new int[tam];
	for(int i=0; i<tam; i++){
		itens[i] = i;
		std::cout << "Tamanho atual: "<<sizeof(itens)/sizeof(*itens)<<std::endl;
	}
	return 0;
}
