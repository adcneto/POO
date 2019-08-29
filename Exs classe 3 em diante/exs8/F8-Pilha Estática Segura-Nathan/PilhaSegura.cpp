// g++ PilhaPOO.cpp -o PilhaPOO.exe

#include <iostream>
#include <stdexcept>

// Veja slides do prof. Monael (p.42):
// https://drive.google.com/file/d/0B8CRSer5hSU6QUVTbWc1VEVqbkU/view
class PilhaCheiaException: public std::runtime_error
{
    public:
            PilhaCheiaException():runtime_error("Runtime Error: Pilha Cheia.")
            {

            }
};
class PilhaVaziaException: public std::runtime_error
{
    public:
            PilhaVaziaException():runtime_error("Runtime Error: Pilha Vazia.")
            {

            }        
};
class Pilha {

    private:
        int *itens;
        int tamanho;
        int topo;

    public:
        Pilha(int);
        ~Pilha();

        /* metodos setters e getters */
        void setTamanho (int);
        void setTopo (int);
        void setItens (int, int);
        int getTamanho ();
        int getTopo ();
        int getItens (int);

        bool isVazia();
        bool isCheia();

        void printTopDown();
        void printBottomUp();

        void empilhar(int);
        int desempilhar();
};


Pilha::Pilha (int tamanho) {
    this->itens = new int[tamanho];
    this->setTamanho (tamanho);
    this->setTopo (-1);
}

Pilha::~Pilha () {
    delete itens;
}

void Pilha::setTamanho (int tamanho) {
    this->tamanho = tamanho;
}

void Pilha::setTopo (int topo) {
    this->topo = topo;
}

void Pilha::setItens (int posicao, int item) {
    this->itens[posicao] = item;
}

int Pilha::getTamanho () {
    return this->tamanho;
}

int Pilha::getTopo () {
    return this->topo;
}

int Pilha::getItens (int posicao) {
    return this->itens[posicao];
}

bool Pilha::isVazia () {
  return this->getTopo() == -1;
}

bool Pilha::isCheia () {
  if(this->getTopo() == (this->getTamanho()-1)) return true;
  return false;
}

void Pilha::printTopDown () {
    if(this->isVazia()) { throw PilhaVaziaException(); }    
    int t = this->getTopo(), i;
    for (i = t; i >= 0; i--) {
        std::cout << this->getItens(i) << "\n";
    }
}

void Pilha::printBottomUp () {
    if(this->isVazia()) { throw PilhaVaziaException(); }
    int t = this->getTopo(), i;
    for (i = 0; i <= t; i++) {
        std::cout << this->getItens(i) << "\n";
    }
}

void Pilha::empilhar (int item) {
  if(!this->isCheia())
  {
    this->setTopo(this->getTopo()+1);
    this->setItens(this->getTopo(), item);
  }
  else
  {
      throw PilhaCheiaException();
  }
  
}

int Pilha::desempilhar () {
    int item = 0;
    if(!this->isVazia())
    {
      item = this->getItens(this->getTopo());
      this->setTopo(this->getTopo()-1);
    }
    else
    {
        throw PilhaVaziaException();
    }
    
    return item;
}

int main() {

    int n, i;
    std::cin >> n;

    Pilha pilha (n);

    char op;
    while (std::cin >> op) {
        int item;

        switch (op) {
            case 'E': std::cin >> item;
                      try{ pilha.empilhar (item);}
                      catch(PilhaCheiaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }
                      break;
            case 'D': try { pilha.desempilhar (); }
                      catch(PilhaVaziaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }                      
                      break;
            case 'T': try { pilha.printTopDown ();}
                      catch(PilhaVaziaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }                
                      break;
            case 'B': try { pilha.printBottomUp (); }
                      catch(PilhaVaziaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }                
                      break;
        }
    }

    return 0;
}
