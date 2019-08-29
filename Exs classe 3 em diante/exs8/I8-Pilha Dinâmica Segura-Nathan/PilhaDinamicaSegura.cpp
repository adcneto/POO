#include <iostream>
class PilhaVaziaException:public std::runtime_error
{
    public:
            PilhaVaziaException():runtime_error("Underflow Error: Pilha Vazia.")
            {

            }
};
class Item
{
    private:
        int chave;
        Item *proximo;
    public:
        Item();    
        Item(int);
        void setProximo(Item *);
        void setChave(int);
        int getChave();
        Item *getProximo();

};

Item::Item(int chave)
{
    this->setChave(chave);
}

void Item::setProximo(Item *i)
{
    this->proximo = i;
}

void Item::setChave(int c)
{
    this->chave = c;
}

int Item::getChave()
{
    return this->chave;
}
Item *Item::getProximo()
{
    return this->proximo;
}

class Pilha
{
    private:
            int quantidade;
            Item *topo;
    public:
            Pilha();
            Pilha(Item *);
            void setTopo(Item *);
            Item *getTopo();
            void empilhar(Item *);
            Item *desempilhar();
            void setQuantidade(int);
            bool vazia();
            int getQuantidade();
            void printTopDown();
};

Pilha::Pilha()
{   
    this->setTopo(NULL);
    this->setQuantidade(0);
}
Pilha::Pilha(Item *i)
{
    this->setQuantidade(1);
    i->setProximo(NULL);
    this->setTopo(i);
}
void Pilha::setQuantidade(int q)
{
    this->quantidade = q;
}
int Pilha::getQuantidade()
{
    return this->quantidade;
}
bool Pilha::vazia()
{
    return this->quantidade == 0;
}
void Pilha::setTopo(Item *i)
{
    this->topo = i;
}
void Pilha::empilhar(Item *i)
{
    if(this->vazia())
    {
        this->setQuantidade(1);
        i->setProximo(this->getTopo());
        this->setTopo(i);
    }
    else
    {
        i->setProximo(this->getTopo());
        this->setTopo(i);
        this->setQuantidade(this->getQuantidade()+1);
    }
    
}
Item *Pilha::desempilhar()
{
    if(this->vazia()) { throw PilhaVaziaException(); return NULL; }
    Item *aux = this->getTopo();
    this->setTopo(aux->getProximo());
    this->setQuantidade(this->getQuantidade()-1);
    std::cout << "[" << aux->getChave() << "]\n";
    return aux;

}
Item *Pilha::getTopo()
{
    return this->topo;
}

void Pilha::printTopDown () {
    Item *it = this->getTopo();
    if(it == NULL) {  throw PilhaVaziaException(); }
    while(it != NULL)
    {
        if(it == this->getTopo()) { std::cout << it->getChave(); }
        else { std::cout << " " << it->getChave(); }
        it = it->getProximo();
        if(it == NULL) std::cout << "\n";
    }
    delete it;
}

int main()
{
    Pilha *pilha = new Pilha();
    char op;
    while (std::cin >> op) {
        int chave;

        switch (op) {
            case 'E': std::cin >> chave;
                      pilha->empilhar (new Item(chave));
                      break;
            case 'D': try{ pilha->desempilhar (); }
                      catch(PilhaVaziaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }
                      break;
            case 'M': try{ pilha->printTopDown (); }
                      catch(PilhaVaziaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }            
                      break;
        }    
    } 
}