#include <iostream>
#include <cstdlib>
#include <stdexcept>

class FilaCheiaException : public std::runtime_error{
    public :
        FilaCheiaException():runtime_error("Runtime Error: Fila Cheia."){}
};

class FilaVaziaException : public std::runtime_error {
    public :
        FilaVaziaException():runtime_error("Runtime Error: Fila Vazia."){}
};

class Fila{
    private:
        int inicio;
        int fim;
        int *itens;
        int tamanho;
    public:
        void enfilerar(int) throw (FilaCheiaException);
        int desinfilerar() throw (FilaVaziaException);
        Fila();
        Fila(int);
        //get and set
        void setInicio(int);
        void setFim(int);
        void setItens(int,int);
        void setTamanho(int);
        int getInicio();
        int getFim();
        int getItens(int);
        int getTamanho();
};

Fila::Fila(){};

Fila::Fila(int qnt){
    this->itens = (int*) malloc(sizeof(int)*qnt);
    this->setTamanho(qnt);
    this->setInicio(-1);
    this->setFim(-1);
}

void Fila::setInicio(int inic){
    this->inicio = inic;
}

void Fila::setFim(int fim){
    this->fim = fim;
}

void Fila::setItens(int i, int valor){
    this->itens[i] = valor;
}

void Fila::setTamanho(int tam){
    this->tamanho = tam;
}

int Fila::getInicio(){
    return this->inicio;
}

int Fila::getFim(){
    return this->fim;
}

int Fila::getItens(int i){
    return this->itens[i];
}

int Fila::getTamanho(){
    return this->tamanho;
}

void Fila::enfilerar(int valor) throw (FilaCheiaException){
    if(this->getFim() < this->getTamanho()-1){
        if(this->getInicio() == -1 && this->getFim() == -1){
            this->setInicio(0);
            this->setFim(0);
            this->setItens(0,valor);
        }
        else{
            if(this->getFim() < this->getTamanho()-1){
                this->setFim(this->getFim()+1);
                this->setItens(this->getFim(),valor);
            }
        }
    }
    else{
        throw FilaCheiaException();
    }
}

int Fila::desinfilerar() throw (FilaVaziaException){
    int aux;
    if(this->getFim() != -1){
        if(this->getFim() == this->getInicio() && this->getFim()!= -1){
            aux = this->getItens(this->getFim());
            this->setInicio(-1);
            this->setFim(-1);
            return aux;
        }
        else{
            if(this->getInicio() != this->getFim()){
                aux = this->getItens(this->getInicio());
                this->setInicio(this->getInicio()+1);
                return aux;
            }
        }
        return -1;
    }
    else{
        throw FilaVaziaException();
    }

}

int main(){
    int n,valor,aux;
    char op;
    std::cin >>n;
    Fila filaTeste(n);
    while(std::cin >> op){
        if(op == 'E'){
            std::cin >> valor;
            try{
                filaTeste.enfilerar(valor);
            }
            catch(FilaCheiaException e){
                std::cout << e.what() << std::endl;
            }
        }
        else if(op == 'D'){
            try{
                aux = filaTeste.desinfilerar();
                if(aux != -1){
                    std::cout << aux << std::endl;
                }
            }
            catch(FilaVaziaException e){
                std::cout << e.what() << std::endl;
            }
        }
    }
    return 0;
}