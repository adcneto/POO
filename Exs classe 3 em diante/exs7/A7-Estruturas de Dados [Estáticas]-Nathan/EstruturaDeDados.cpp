#include <iostream>

class Estrutura
{
    private:
            long int *itens;
            int tipo, tamanho, inicio;
    public:
            Estrutura(int);
            virtual bool isVazia() = 0;
            virtual bool isCheia() = 0; 
            virtual void mostrar() = 0;             
            /* M�todos setters e getters */
            void setTamanho (int);
            void setInicio (int);
            void setItens (int, long int);
            int getTamanho ();
            int getInicio ();
            long int getItens (int);            
            void setTipo(int);
            int getTipo();

            //LES
            virtual void setQuantidade(int t) {}
            virtual int getQuantidade() { return 0; }
            virtual int busca(long int t) { return 0; }
            virtual void inserir(long int t ) { }
            virtual long int remover(long int t){ return 0; }

            //Fila
            virtual int getFim() { return 0; }
            virtual void setFim(int f) {}
            virtual void enfileirar(long int t) {}
            virtual long int desenfileirar() { return 0; }

            //Pilha
            virtual void empilhar(long int t) { }
            virtual long int desempilhar() { return 0; }


};
Estrutura::Estrutura(int t)
{
    this->itens = new long int[t];
    this->setTamanho(t);
    this->setInicio(-1);
}
void Estrutura::setTamanho(int tamanho) {
    this->tamanho = tamanho;
}

void Estrutura::setInicio (int inicio) {
    this->inicio = inicio;
}

void Estrutura::setItens (int posicao, long int item) {
    this->itens[posicao] = item;
}
void Estrutura::setTipo(int t)
{
    this->tipo = t;
}
int Estrutura::getTamanho () {
    return this->tamanho;
}

int Estrutura::getInicio () {
    return this->inicio;
}
int Estrutura::getTipo()
{
    return this->tipo;
}
long int Estrutura::getItens (int posicao) {
    return this->itens[posicao];
}
class Lista: public Estrutura
{
    private:
            int quantidade;
    public:
            Lista(int);
            void setQuantidade(int);
            int getQuantidade();

            bool isCheia();
            bool isVazia();
            int busca(long int);
            void inserir(long int);
            long int remover(long int);
            void mostrar();

};
Lista::Lista(int t):Estrutura(t)
{
    this->setQuantidade (0);
}
void Lista::setQuantidade(int t)
{
    this->quantidade = t;
}

int Lista::getQuantidade()
{
    return this->quantidade;
}

int Lista::busca (long int item) {
    int n = this->getQuantidade(), i;
    for (i = 0; i < n && this->getItens(i) < item; i++);
    return i;
}
bool Lista::isCheia () {
    return this->getQuantidade() == this->getTamanho();
}

bool Lista::isVazia () {
    return this->getQuantidade() == 0;
}
void Lista::mostrar () {
  int n = this->getQuantidade(), i;
  for (i = 0; i < n; i++)
  {
      if(i == 0) { std::cout << this->getItens(i); }
      else { std::cout << " " << this->getItens(i); }
      if(i == n-1) std::cout << "\n";
  }
}
void Lista::inserir (long int item) {
    int n = this->getQuantidade(), i = 0, j;
    if (!this->isCheia()) {
        i = this->busca(item);
        if (i < n) {
            if (this->getItens(i) == item)
                return;
            for (j = n; j > i; j--)
                this->setItens(j,this->getItens(j-1));
        }
        this->setItens(i, item);
        this->setQuantidade(this->getQuantidade() + 1);
    }
}

long int Lista::remover (long int item) {
    int n = this->getQuantidade(), i, j;
    i = this->busca(item);
    if (i < n && this->getItens(i) == item) {
        std::cout << "REMOVIDO: " << item << std::endl;
        for (j = i; j < n-1; j++)
            this->setItens(j,this->getItens(j+1));
        this->setQuantidade(this->getQuantidade() - 1);
    }
}
class Fila: public Estrutura{
    private:
            int fim;
    public:
            Fila(int);
            int getFim();
            void setFim(int);
            void mostrar();
            void enfileirar(long int);
            long int desenfileirar(); 
            bool isVazia();
            bool isCheia();            
};
Fila::Fila(int t):Estrutura(t)
{
    this->setFim(-1);
}
int Fila::getFim()
{
    return this->fim;
}
void Fila::setFim(int f)
{
    this->fim = f;
}

void Fila::mostrar () {
  if(!this->isVazia())
  {
    int n = this->getFim(), i;
    for (i = this->getInicio(); i <= n; i++)
    {
        if(i == this->getInicio()) { std::cout << this->getItens(i); }
        else { std::cout << " " << this->getItens(i); }
        if(i == n) std::cout << "\n";
    }
  }
}
bool Fila::isVazia() {
    if(this->getInicio() == -1)
    {
      return true;
    }
    return false;
}

bool Fila::isCheia() {
    return this->getFim() == (this->getTamanho()-1);
}

void Fila::enfileirar(long int item) {
    if(!this->isCheia()) {
      if(this->isVazia()) { this->setInicio(0); }
      this->setFim(this->getFim()+1);
      this->setItens(this->getFim(), item);
    }
    
}

long int Fila::desenfileirar() { 
    long int item = 0;
    if(!this->isVazia())
    {
      item = this->getItens(this->getInicio());
      this->setInicio(this->getInicio()+1);
      if(this->getInicio() > this->getFim()) { this->setFim(-1); this->setInicio(-1); }
      std::cout << "REMOVIDO: " << item << std::endl;
    }
    return item;
}

class Pilha: public Estrutura
{
    public:
            Pilha(int);
            void empilhar(long int);
            long int desempilhar();
            bool isVazia();
            bool isCheia(); 
            void mostrar();           
};
Pilha::Pilha(int t):Estrutura(t)
{

}
bool Pilha::isVazia () {
  return this->getInicio() == -1;
}

bool Pilha::isCheia () {
  if(this->getInicio() == (this->getTamanho()-1)) return true;
  return false;
}
void Pilha::mostrar () {
    int t = this->getInicio(), i;
    for (i = 0; i <= t; i++) 
    {
      if(i == 0) { std::cout << this->getItens(i); }
      else { std::cout << " " << this->getItens(i); }
      if(i == t) std::cout << "\n";
    }

}
void Pilha::empilhar (long int item) {
  if(!this->isCheia())
  {
    this->setInicio(this->getInicio()+1);
    this->setItens(this->getInicio(), item);
  }
}

long int Pilha::desempilhar () {
    long int item = 0;
    if(!this->isVazia())
    {
      item = this->getItens(this->getInicio());
      this->setInicio(this->getInicio()-1);
      std::cout << "REMOVIDO: " << item << std::endl;
    }
    return item;
}

class Circular:public Estrutura
{
    private:
            int fim;
    public:
            Circular(int);
            int getFim();
            void setFim(int);

            void enfileirar(long int);
            long int desenfileirar(); 
            bool isVazia();
            bool isCheia();    
            void mostrar();   
};
Circular::Circular(int t):Estrutura(t)
{
    this->setFim(0);
    this->setInicio(0);
}
int Circular::getFim()
{
    return this->fim;
}
void Circular::setFim(int f)
{
    this->fim = f;
}
bool Circular::isVazia() {
    return this->getInicio() == this->getFim();
}
void Circular::mostrar () {
  if(!this->isVazia())
  {
    int n = this->getFim(), i;
    bool aux = false;
    if(this->getFim() < this->getInicio())
    {
        
        for(i = this->getInicio(); i < this->getTamanho(); i ++)
        {
            //std::cout << "Por aqui!!" << std::endl;
            aux = true;
            if(i == this->getInicio()) { std::cout << this->getItens(i); }
            else { std::cout << " " << this->getItens(i); }       
        }
        for(i = 0; i < this->getFim(); i ++)
        {
            if(i == 0 && aux == false) { std::cout << this->getItens(i); }
            else { std::cout << " " << this->getItens(i); }          
        } 
        std::cout << "\n";           
    }
    else
    {
        
        for (i = this->getInicio(); i < n; i++)
        {
            if(i == this->getInicio()) { std::cout << this->getItens(i); }
            else { std::cout << " " << this->getItens(i); }
            if(i == n-1) std::cout << "\n";
        }
    }
    

  }
}
bool Circular::isCheia() {
    int novo_fim = (this->getFim()+1) % this->getTamanho();
    return novo_fim == this->getInicio();
}

void Circular::enfileirar(long int item) {
    int novo_fim = (this->getFim()+1) % this->getTamanho();

    if(!this->isCheia())
    {
        this->setItens(this->getFim(), item);
        this->setFim(novo_fim);
    }
}

long int Circular::desenfileirar() { /* vazia quando remover o ultimo*/
    long int item = 0;
    if(!this->isVazia())
    {
        std::cout << "REMOVIDO: " << this->getItens(this->getInicio()) << std::endl;
        int novo_inicio = (this->getInicio() + 1) % this->getTamanho();
        this->setInicio(novo_inicio);
    }
    return item;
}
int main()
{
    int n, tamanho;
    std::cin >> n;
    Estrutura *e[n];
    std::string tipo;
    for(int i = 0; i < n; i++)
    {
        std::cin >> tipo >> tamanho;
        if(tipo.compare("LES") == 0)
        {
            e[i] = new Lista(tamanho);
            e[i]->setTipo(1);
        }
        else if(tipo.compare("FILA") == 0)
        {
            e[i] = new Fila(tamanho);
            e[i]->setTipo(2);
        }
        else if(tipo.compare("PILHA") == 0)
        {
            e[i] = new Pilha(tamanho);
            e[i]->setTipo(3);
        }
        else if(tipo.compare("CIRCULAR") == 0)
        {
            e[i] = new Circular(tamanho);
            e[i]->setTipo(4);
        }        
    }
    int pos_ed;
    long int chave;
    char op;

    while(std::cin >> pos_ed >> op)
    {
        switch (op){

            case 'I': std::cin >> chave;
                if(e[pos_ed]->getTipo() == 1) { e[pos_ed]->inserir(chave); }
                else if(e[pos_ed]->getTipo() == 2 || e[pos_ed]->getTipo() == 4) { e[pos_ed]->enfileirar(chave); }
                else if (e[pos_ed]->getTipo() == 3) { e[pos_ed]->empilhar(chave); }
                break;
        
            case 'R': 
                if(e[pos_ed]->getTipo() == 1) { std::cin >> chave; e[pos_ed]->remover(chave); }
                else if(e[pos_ed]->getTipo() == 2 || e[pos_ed]->getTipo() == 4) { e[pos_ed]->desenfileirar(); }
                else if (e[pos_ed]->getTipo() == 3) { e[pos_ed]->desempilhar(); }
                break;
            case 'M': e[pos_ed]->mostrar();
                break;    
        }
    } 
    return 0;
}