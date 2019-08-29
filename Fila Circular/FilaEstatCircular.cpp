#include <iostream>

class FilaEstatica{
    private:
        int *itens;
        int tamanho;
        int fim, inicio;

    public:
        FilaEstatica();
        FilaEstatica(int);
        ~FilaEstatica();
    
        int getFim();
        int getInicio();
        int getTamanho();
        
        void setTamanho(int);
        void alocaVetor(int);
        void setNovoInicio(int);
        void setNovofim(int);

        void enfileirar(int);
        int desenfileirar();
        
        bool vazia();
        bool cheia();
        void printBottomUp();
        void printTopDown();
};

class FilaEstatCircular : private FilaEstatica {
    public:
        FilaEstatCircular();
        FilaEstatCircular(int);
        
        //Metodos redefinidos:
        void enfileirar(int);
        int desenfileirar();
        bool vazia();
        bool cheia();
};

FilaEstatCircular::FilaEstatCircular() { }

bool FilaEstatCircular::vazia(){
    
}
void testeCheia(bool t){
    if (t==true)
        std::cout << "A fila está cheia!" << std::endl;
    else
        std::cout << "Não se preocupe, pois a fila ainda não está cheia." << std::endl;

}

void testeVazia(bool t){
    if (t==true)
        std::cout << "Vaziasinha da Silva!" << std::endl;
    else
        std::cout << "Tem coisa enfileirada aí!" << std::endl;

}

FilaEstatica::FilaEstatica(){
    this->fim = -1;
    this->inicio = -1;
    this->setTamanho(0);
}

FilaEstatica::FilaEstatica(int tamanho){
    this->fim =-1;
    this->inicio =-1;
    this->setTamanho(tamanho);
}

FilaEstatica::~FilaEstatica(){
    delete[] this->itens;
}

int FilaEstatica::getFim(){
    return this->fim;
}

int FilaEstatica::getInicio(){
    return this->inicio;
}

int FilaEstatica::getTamanho(){
    return this->tamanho;
}

void FilaEstatica::setTamanho(int tamanho){
    this->tamanho = tamanho;
    this->itens = new int[this->getTamanho()];
}

void FilaEstatica::setNovofim(int valor){
    if(valor < this->getTamanho())
        this->fim = valor;
}

void FilaEstatica::setNovoInicio(int valor){
    if(valor >=0)
        this->inicio = valor;
}

void FilaEstatica::enfileirar(int valor){
    if( !(this->cheia()) ){
        this->setNovofim(this->getFim() + 1);
        this->itens[this->getFim()] = valor;
    }
}

int FilaEstatica::desenfileirar(){
    if( !(this->vazia()) ){
        int fim_velho = this->itens[this->getFim()];
        this->setNovofim(this->getFim() - 1);
        return fim_velho;
    }
}

bool FilaEstatica::vazia(){
    if(this->getFim() == -1)
        return true;
    return false;
}

bool FilaEstatica::cheia(){
    if(this->getTamanho() == this->getFim() + 1)
        return true;
    return false;
}

void FilaEstatica::printBottomUp(){
    for(int i= 0; i<= this->getFim(); i++)
        std::cout << "itens["<<i<<"] = " << this->itens[i] << std::endl;

}

void FilaEstatica::printTopDown(){
    for(int i= this->getFim(); i>=0; i--)
        std::cout << "itens["<<i<<"] = " << this->itens[i] << std::endl;
}



int main(){

    FilaEstatCircular f;
    std::cout << f.getTamanho() << std::endl;
    
    return 0;
}



