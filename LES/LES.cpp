#include <iostream>

class LES{
    private:
        int qtd;
        int tamanhoMax;
        int fim, inicio;
        int *itens;
    public:
        LES();
        LES(int);
        ~LES();
        
        int getQtd();
        int getTamanhoMax();
        int getInicio();
        int getFim();
        
        void setQtd(int);
        void setTamanhoMax(int);
        void setFim(int);
        void setInicio(int);
        
        bool isCheia();
        bool isVazia();
        
        void inserir(int);
        int buscaBinariaPosicao(int, int, int);
        void retirar(int);
        void mostrar();
};

LES::LES(){
    this->setInicio(-1);
    this->setFim(-1);
    this->setTamanhoMax(0);
    this->setQtd(0);
}

LES::LES(int tamanhoMax){
    this->setInicio(-1);
    this->setFim(-1);
    this->setTamanhoMax(tamanhoMax);
    this->setQtd(0);   
    this->itens = new int[tamanhoMax];
}

LES::~LES(){
    delete[] this->itens;
}

void LES::setQtd(int qtd){
    this->qtd = qtd;
}

void LES::setTamanhoMax(int tamanhoMax){
    this->tamanhoMax = tamanhoMax;
};

void LES::setFim(int fim){
    this->fim = fim;
}
void LES::setInicio(int inicio){
    this->inicio = inicio;
}

int LES::getQtd(){
    return this->qtd;
}

int LES::getTamanhoMax(){
    return this->tamanhoMax;
}

int LES::getInicio(){
    return this->inicio;
}

int LES::getFim(){
    return this->fim;
}

bool LES::isCheia(){
    return this->getQtd() == this->getTamanhoMax();
}

bool LES::isVazia(){
    return this->getQtd() == 0;
}

void LES::inserir(int valor){
    if(this->isVazia()){
        this->setQtd(this->getQtd() + 1);
        this->setInicio(0);
        this->setFim(0);
        this->itens[this->getInicio()] = valor;
    }
    else if(!this->isCheia()){
        int posicao_insercao = this->buscaBinariaPosicao(valor, this->getInicio(), this->getFim());
        
        if(posicao_insercao == this->getFim() + 1){
            this->itens[posicao_insercao] = valor;
            this->setFim(posicao_insercao);
        }
        else{
            for(int i=this->getFim(); i>=posicao_insercao; i--)
                this->itens[i+1] = this->itens[i];
                
            this->itens[posicao_insercao] = valor;
            this->setFim(this->getFim() + 1);
        }
        this->setQtd(this->getQtd() + 1);
    }
    else return;
}

void LES::retirar(int valor){
    if(!this->isVazia()){
        int posicao_remocao = this->buscaBinariaPosicao(valor, this->getInicio(), this->getFim());
        for(int i=posicao_remocao; i <= this->getFim(); i++)
                this->itens[i] = this->itens[i+1];

        this->setFim(this->getFim() - 1);
        this->setQtd(this->getQtd() - 1);
    }

}

int LES::buscaBinariaPosicao(int valor, int inicio, int fim){
    int meio = inicio + (fim -inicio)/2;
    int posicao = -1;
    
    if(fim>=inicio){
        if(this->itens[meio] > valor)
            posicao = this->buscaBinariaPosicao(valor,inicio, meio-1);
            
        else if(this->itens[meio] < valor)
            posicao = this->buscaBinariaPosicao(valor,meio+1, fim);
            
        else 
            posicao = meio;
    }
    
    if(posicao ==-1)
        posicao = inicio;        
    
    return posicao;
}

void LES::mostrar(){
	int i;
	for(i = 0; i < this->getQtd(); i++)
	{
		std::cout << this->itens[i] << std::endl;
	}
}


int main(){
    int tamanho, i, chave;
    char operacao;
    
    std::cin >> tamanho;
    
    LES lista(tamanho);
    
    for(i=0; i<tamanho; i++){
        std::cin >> operacao >> chave;
        
        if(operacao == 'I')
			lista.inserir(chave);
		else
			lista.retirar(chave);
    }
    lista.mostrar();
    return 0;
}


