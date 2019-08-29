#include <iostream>
#include <stdexcept>




class VectorForaLimite : public std::runtime_error{
    public:
        VectorForaLimite() : runtime_error("runtime error: indice fora dos limites do vetor."){}
    
};

class VetorSeguro{
    private:
        int tamanho;
        int *elementos;
    public:
  
        VetorSeguro(int);
        int getElemento(int);
        int getTamanho();
        void setElemento(int, int);
        void setTamanho(int);

};

VetorSeguro::VetorSeguro(int tamanho){
    this->setTamanho(tamanho);
    this->elementos = new int[tamanho];
}

int VetorSeguro::getElemento(int posicao){
   if(posicao < 0 || posicao >= tamanho ){
        throw VectorForaLimite();
    }
    else{
        return this->elementos[posicao];
    }
}

int VetorSeguro::getTamanho(){
    return this->tamanho;
}

void VetorSeguro::setElemento(int posicao, int valor){
    this->elementos[posicao] = valor;
}

void VetorSeguro::setTamanho(int tamanho){
    this->tamanho = tamanho;
}




int main(){
    int elemento, tamanho, posicao;
    std::cin >> tamanho;
    VetorSeguro v(tamanho);
    
    for(int i=0; i<tamanho; i++){
        std::cin >> elemento;
        v.setElemento(i, elemento);
    }
    
    while(std::cin >> posicao){
        try{
            std::cout << v.getElemento(posicao) << std::endl;
        }
        catch(VectorForaLimite e){
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
    
}

