#include <iostream>

class Pilha {
  private:
    int * itens;
    int quantidade;
    int tamanho;

  public:
    Pilha();
    Pilha(int);
    ~Pilha();
    void setTamanho(int);
    void setQuantidade(int);
    void setItens(int,int);
    int getItens(int);
    int getQuantidade();
    int getTamanho();
    bool isEmpty();
    bool isFull();
    void inserir(int);
    void remover();
    void mostrarTopo();
    void mostrarBase();
};

Pilha :: Pilha(){

}

Pilha :: Pilha(int tamanho){
  this -> setTamanho(tamanho);
  this -> setQuantidade(0);
  this -> itens = new int[this->getTamanho()];
}


Pilha :: ~Pilha(){
  delete this -> itens;
}

void Pilha :: setTamanho(int tam){
  this -> tamanho = tam;
}

void Pilha:: setQuantidade(int qtd){
  this -> quantidade = qtd;
}

void Pilha :: setItens(int posicao, int item){
  this -> itens[posicao] =item;
}

int Pilha :: getTamanho(){
  return this -> tamanho;
}

int Pilha :: getQuantidade(){
  return this -> quantidade;
}

int Pilha :: getItens(int posicao){
  return this -> itens[posicao];
}


bool Pilha :: isEmpty(){
  return this -> getQuantidade() == 0;
}

bool Pilha :: isFull(){
  return this -> getQuantidade() == this -> getTamanho();

}

void Pilha :: inserir(int item){

  if(this -> isFull() == false){

    for(int i= this -> getQuantidade() -1; i >= 0; i--){
      this -> setItens(i+1, this -> getItens(i));
    }
    
    this -> setQuantidade(this -> getQuantidade() + 1);
    this -> setItens(0, item);
    
  }

}

void Pilha :: remover(){

  if(this -> isEmpty() == false){
    //std :: cout << this -> getItens(0) << std :: endl;
    
    for(int i = 1 ; i < this -> getQuantidade(); i++){
      this -> setItens(i-1,this -> getItens(i));
    }
    
     this -> setQuantidade(this -> getQuantidade() - 1);
     
  }  

}

void Pilha :: mostrarTopo(){
  int i;

  for( i=0; i< this -> getQuantidade(); i++){
    std :: cout << this -> getItens(i) << std :: endl;

  }
  //std :: cout << this -> getQuantidade();
  
}

void Pilha :: mostrarBase(){
  int i;

  for( i=this ->getQuantidade() -1 ; i>= 0; i--){
    std :: cout << this -> getItens(i) << std :: endl;

  }
  //std :: cout << this -> getQuantidade();
  
}  

int main(){

  int tam,item;
  Pilha *pilha;
  char op;

  std :: cin >> tam;
  pilha = new Pilha(tam);
  //pilha -> mostrar();
  
  while(std :: cin >> op){

    if(op == 'E'){
      std :: cin >> item;
      pilha -> inserir(item);
      //fila -> mostrar();
    }

    else if (op == 'D'){
      pilha -> remover();
      //fila -> mostrar();
    }

    else if (op == 'T'){
      pilha -> mostrarTopo();
    }

    else if ( op == 'B'){
      pilha -> mostrarBase();
    }
    
  
  }



  return 0;
}

