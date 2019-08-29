#include <iostream>
#include <stdexcept>

class FilaVaziaException:public std::runtime_error
{
    public:
            FilaVaziaException():runtime_error("Underflow Error: Fila Vazia.")
            {

            }
};
class Item
{
        private:
                int valor;
                Item *proximo;
        public:
                Item(int);
                void setValor(int);
                int getValor();
                void setProximo(Item *);
                Item *getProximo();
};
Item::Item(int v)
{
    this->setValor(v);
    this->setProximo(NULL);
}
void Item::setValor(int v)
{
    this->valor = v;
}
int Item::getValor()
{
    return this->valor;
}

void Item::setProximo(Item *i)
{
    this->proximo = i;
}
Item *Item::getProximo()
{
    return this->proximo;
}
class Fila
{
    private:
            Item *inicio;
            Item *final;
    public:
            Fila();
            void setInicio(Item *);
            void setFinal(Item *);
            Item *getInicio();
            Item *getFinal();
            bool vazia();
            void enfileira(Item *i);
            Item *desinfileira();
            void mostrar();

};
Fila::Fila()
{
    this->setInicio(NULL);
    this->setFinal(NULL);
}

void Fila::setInicio(Item *i)
{
    this->inicio = i;
}
void Fila::setFinal(Item *i)
{
    this->final = i;
}
Item *Fila::getInicio()
{
    return this->inicio;
}
Item *Fila::getFinal()
{
    return this->final;
}
bool Fila::vazia()
{
    return (this->getInicio() == NULL && this->getFinal() == NULL);
}
void Fila::enfileira(Item *i)
{
    if(this->vazia())
    {
        this->setInicio(i);
        this->setFinal(i);
    }
    else
    {
        this->getFinal()->setProximo(i);
        this->setFinal(i);
    }
    
}
Item *Fila::desinfileira()
{
    if(!this->vazia())
    {
        Item *aux = this->getInicio();
        this->setInicio(aux->getProximo());
        if(this->getInicio() == NULL) this->setFinal(NULL);
        std::cout << "<" << aux->getValor() << ">" << std::endl;
        return aux;
    }
    else
    {
        throw FilaVaziaException();
    }
    
    return NULL;
}
void Fila::mostrar()
{
    Item *aux = this->getInicio();
    if(aux == NULL) { throw FilaVaziaException(); }
    while(aux != NULL)
    {
        if(aux == this->getInicio()) std::cout << aux->getValor();
        else std::cout << " " << aux->getValor();
        aux = aux->getProximo();
        if(aux == NULL) std::cout << "\n";
    } 
    delete aux;
}
int main()
{
    Fila *fila = new Fila();
    char op;
    
    while(std::cin >> op)
    {
        int v;
        switch (op){

            case 'E': std::cin >> v;
                fila->enfileira(new Item(v));
                break;
        
            case 'D': try { fila->desinfileira(); }
                catch(FilaVaziaException e)
                {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 'M': try { fila->mostrar(); }
                catch(FilaVaziaException e)
                {
                    std::cout << e.what() << std::endl;
                }
                break;    
        }
    }
    return 0;
}