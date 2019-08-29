// g++ FilaPOO.cpp -o FilaPOO.exe

#include <iostream>

// Veja slides do prof. Monael (p.63):
// https://drive.google.com/file/d/0B8CRSer5hSU6MFlOSzhUQnhJTlk/view

class FilaCheiaException:public std::runtime_error
{
    public:
        FilaCheiaException():runtime_error("Runtime Error: Fila Cheia.")
        {

        }
};
class FilaVaziaException:public std::runtime_error
{
    public:
        FilaVaziaException():runtime_error("Runtime Error: Fila Vazia.")
        {

        }
};
class Fila {
    private:
        int *itens;
        int inicio, fim;
        int tamanho;

    public:
        Fila(int);
        ~Fila();

        /* M�todos setters e getters */
        void setTamanho (int);
        void setInicio (int);
        void setFim (int);
        void setItens (int, int);
        int getTamanho ();
        int getInicio ();
        int getFim ();
        int getItens (int);

        void enfileirar(int);
        int desenfileirar(); /* vazia quando remover o ultimo*/

        bool isVazia();
        bool isCheia();
};

// Voce deve terminar de implementar o seu codigo...

Fila::Fila(int tamanho) {
    this->itens = new int[tamanho];
    this->setTamanho(tamanho);
    this->setInicio(-1);
    this->setFim(-1);
}

Fila::~Fila() {
    delete itens;
}

void Fila::setTamanho (int tamanho) {
    this->tamanho = tamanho;
}

void Fila::setInicio (int inicio) {
    this->inicio = inicio;
}

void Fila::setFim (int fim) {
    this->fim = fim;
}

void Fila::setItens (int posicao, int item) {
    this->itens[posicao] = item;
}

int Fila::getTamanho () {
    return this->tamanho;
}

int Fila::getInicio () {
    return this->inicio;
}

int Fila::getFim () {
    return this->fim;
}

int Fila::getItens (int posicao) {
    return this->itens[posicao];
}

bool Fila::isVazia() {
    if(this->getInicio() == -1 || this->getInicio() > this->getFim())
    {
      return true;
    }
    return false;
}

bool Fila::isCheia() {
    return this->getFim() == (this->getTamanho()-1);
}

void Fila::enfileirar(int item) {
    if(!this->isCheia()) {
      if(this->isVazia()) { this->setInicio(0); }
      this->setFim(this->getFim()+1);
      this->setItens(this->getFim(), item);
    }
    else
    {
        throw FilaCheiaException();
    }
    
}

int Fila::desenfileirar() { /* vazia quando remover o ultimo*/
    int item = 0;
    if(!this->isVazia())
    {
      item = this->getItens(this->getInicio());
      this->setInicio(this->getInicio()+1);
      if(this->getInicio() > this->getFim()) this->setFim(-1);
      std::cout << item << std::endl;
    }
    else
    {
        throw FilaVaziaException();
    }
    
    return item;
}



int main() {

    int n, i;
    std::cin >> n;

    Fila fila(n);

    char op;
    while (std::cin >> op) {
        int item;

        switch (op) {
            case 'E': std::cin >> item;
                      try{
                        fila.enfileirar(item);
                      }
                      catch(FilaCheiaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }
                      break;
            case 'D': 
                      try{ fila.desenfileirar(); }
                      catch(FilaVaziaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }
                      break;
        }
    }

    return 0;
}
