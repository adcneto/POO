#include <iostream>
#include <cstdlib>
#include <stdexcept>

class PilhaCheiaException : public std::runtime_error{
    public :
        PilhaCheiaException():runtime_error("Runtime Error: Pilha Cheia."){}
};

class PilhaVaziaException : public std::runtime_error {
    public :
        PilhaVaziaException():runtime_error("Runtime Error: Pilha Vazia."){}
};

class Pilha{
    private:
        int tamanho;
        int *itens;
        int topo;
    public:
        Pilha();
        Pilha(int);
        void empilha (int) throw (PilhaCheiaException);
        void desempilha() throw (PilhaVaziaException);
        void topoBase() throw (PilhaVaziaException);
        void baseTopo() throw (PilhaVaziaException);
        //set get
        void setTamanho(int);
        void setItens(int,int);
        void setTopo(int);
        int getTamanho();
        int getItens(int);
        int getTopo();
};

Pilha::Pilha(){}

void Pilha::setTamanho(int tam){
    this->tamanho = tam;
}

void Pilha::empilha (int vlr) throw (PilhaCheiaException){
    if(this->getTopo()!= this->getTamanho()-1){
        this->setTopo(this->getTopo()+1);
        this->setItens(this->getTopo(),vlr);
    }
    else{
        throw PilhaCheiaException();
    }
}

void Pilha::desempilha() throw (PilhaVaziaException){
    if(this->getTopo()!=-1){
        this->setTopo(this->getTopo()-1);
    }
    else{
        throw PilhaVaziaException();
    }
}

void Pilha::topoBase() throw (PilhaVaziaException){
    if(this->getTopo()>=0){
        for(int i=this->getTopo() ; i >= 0 ; i--){
            std::cout << this->getItens(i) << std::endl;
        }
    }
    else{
        throw PilhaVaziaException();
    }
}

void Pilha::baseTopo() throw (PilhaVaziaException){
    if(this->getTopo()>=0){
        for(int i=0 ; i <= this->getTopo() ; i++){
            std::cout << this->getItens(i) << std::endl;
        }
    }
    else{
        throw PilhaVaziaException();
    }
}

void Pilha::setItens(int i, int vlr){
    this->itens[i] = vlr;
}

void Pilha::setTopo(int topo){
    this->topo = topo;
}

int Pilha::getTamanho(){
    return this->tamanho;
}

int Pilha::getItens(int ind){
    return this->itens[ind];
}

int Pilha::getTopo(){
    return this->topo;
}

Pilha::Pilha(int tam){
    this->setTamanho(tam);
    this->itens = (int*) malloc(sizeof(int)*tamanho);
    this->setTopo(-1);
}

int main(){
    int vlr,qnt;
    char op;
    std::cin >> qnt;
    Pilha P(qnt);
    while(std::cin >> op){
        switch (op){
            case 'E':{
                std::cin >> vlr;
                try{
                    P.empilha(vlr);
                }
                catch(PilhaCheiaException e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 'D':{
                try{
                    P.desempilha();
                }
                catch(PilhaVaziaException e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 'T':{
                try{
                    P.topoBase();
                }
                catch(PilhaVaziaException e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 'B':{
                try{
                    P.baseTopo();
                }
                catch(PilhaVaziaException e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            default:{
                break;
            }
        }
    }
    return 0;
}