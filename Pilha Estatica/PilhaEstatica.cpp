#include <iostream>

class PilhaEstatica{
    private:
        int *itens;
        int tamanho;
        int topo;

    public:
        PilhaEstatica();
        PilhaEstatica(int);
        ~PilhaEstatica();
    
        int getTopo();
        int getTamanho();
        
        void setTamanho(int);
        void alocaVetor(int);
        void setNovoTopo(int);

        void empilhar(int);
        int desempilhar();
        
        bool vazia();
        bool cheia();
        void printBottomUp();
        void printTopDown();
};

void testeCheia(bool t){
    if (t==true)
        std::cout << "A pilha está cheia!" << std::endl;
    else
        std::cout << "Não se preocupe, pois a pilha ainda não está cheia." << std::endl;

}

void testeVazia(bool t){
    if (t==true)
        std::cout << "Vaziasinha da Silva!" << std::endl;
    else
        std::cout << "Tem coisa empilhada aí!" << std::endl;

}

PilhaEstatica::PilhaEstatica(){
    this->topo = -1;
    this->setTamanho(0);
}

PilhaEstatica::PilhaEstatica(int tamanho){
    this->topo =-1;
    this->setTamanho(tamanho);
}

PilhaEstatica::~PilhaEstatica(){
    delete[] this->itens;
}

int PilhaEstatica::getTopo(){
    return this->topo;
}

int PilhaEstatica::getTamanho(){
    return this->tamanho;
}

void PilhaEstatica::setTamanho(int tamanho){
    this->tamanho = tamanho;
    this->itens = new int[this->getTamanho()];
}

void PilhaEstatica::setNovoTopo(int valor){
    if(valor < this->getTamanho())
        this->topo = valor;
}

void PilhaEstatica::empilhar(int valor){
    if( !(this->cheia()) ){
        this->setNovoTopo(this->getTopo() + 1);
        this->itens[this->getTopo()] = valor;
    }
}

int PilhaEstatica::desempilhar(){
    if( !(this->vazia()) ){
        int topo_velho = this->itens[this->getTopo()];
        this->setNovoTopo(this->getTopo() - 1);
        return topo_velho;
    }
}

bool PilhaEstatica::vazia(){
    if(this->getTopo() == -1)
        return true;
    return false;
}

bool PilhaEstatica::cheia(){
    if(this->getTamanho() == this->getTopo() + 1)
        return true;
    return false;
}

void PilhaEstatica::printBottomUp(){
    for(int i= 0; i<= this->getTopo(); i++)
        std::cout << "itens["<<i<<"] = " << this->itens[i] << std::endl;

}

void PilhaEstatica::printTopDown(){
    for(int i= this->getTopo(); i>=0; i--)
        std::cout << "itens["<<i<<"] = " << this->itens[i] << std::endl;
}



int main(){
    PilhaEstatica p(10);
    testeCheia(p.cheia());
    testeVazia(p.vazia());
    int novoItem;
    while(!(p.cheia()) && (std::cin >> novoItem) ){
        p.empilhar(novoItem);
            
    }
    
    p.printBottomUp();
    testeCheia(p.cheia());
    testeVazia(p.vazia());
    std::cout <<"\n"<<std::endl;

    
    p.printTopDown();
    testeCheia(p.cheia());
    testeVazia(p.vazia());
    std::cout <<"\n"<<std::endl;

    
    int x = p.desempilhar();
    p.printBottomUp();
    testeCheia(p.cheia());
    testeVazia(p.vazia());
    std::cout << "O elemento  "<< x << " foi desempilhado" << "\n"<<std::endl;

    x = p.desempilhar();
    p.printBottomUp();
    testeCheia(p.cheia());
    testeVazia(p.vazia());
    std::cout << "O elemento "<< x << " foi desempilhado" <<"\n"<<std::endl;

    
    p.empilhar(12345);
    p.printBottomUp();
    testeCheia(p.cheia());
    testeVazia(p.vazia());

    
    return 0;
}
