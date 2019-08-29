#include <iostream>
#include <stdexcept>

class ChaveExisteException: public std::runtime_error
{
    public:
            ChaveExisteException():runtime_error("Logic Error: Chave ja existe na Lista.")
            {

            }
};
class ChaveNaoExisteException: public std::runtime_error
{
    public:
            ChaveNaoExisteException():runtime_error("Logic Error: Chave inexistente na Lista.")
            {
                
            }
};
class ListaVaziaException: public std::runtime_error
{
    public:
            ListaVaziaException():runtime_error("Underflow Error: Lista Vazia.")
            {
                
            }
};
class Item
{
    private:
            int valor;
            Item *proximo;
    public:
            Item();
            Item (int);
            void setValor(int);
            void setProximo(Item *);
            int getValor();
            Item *getProximo();
};

Item::Item()
{
    this->setProximo(NULL);
}
Item::Item(int v)
{
    this->setProximo(NULL);
    this->setValor(v);
}

void Item::setValor(int v)
{
    this->valor = v;
}
void Item::setProximo(Item *p)
{
    this->proximo = p;
}
int Item::getValor()
{
    return this->valor;
}
Item *Item::getProximo()
{
    return this->proximo;
}
class Lista
{
    private:
            Item *inicio;
            int quantidade;
    public:
            Lista();
            void setInicio(Item *);
            Item *getInicio();
            void setQuantidade(int);
            int getQuantidade();
            void inserir(Item *i);
            bool vazia();
            bool busca(int);
            void remover(int v);
            void mostrar();
};

Lista::Lista()
{
    this->setInicio(NULL);
    this->setQuantidade(0);
}

void Lista::setInicio(Item *i)
{
    this->inicio = i;
}
Item *Lista::getInicio()
{
    return this->inicio;
}
int Lista::getQuantidade()
{
    return this->quantidade;
}
void Lista::setQuantidade(int q)
{
    this->quantidade = q;
}
bool Lista::vazia()
{
    return this->getQuantidade() == 0;
}
bool Lista::busca(int chave)
{
    Item *i = this->getInicio();
    while(i != NULL)
    {
        if(i->getValor() == chave)
        {
            return true;
        }
        i = i->getProximo();
    }
    delete i;
    return false;
}
void Lista::inserir(Item *i)
{
    if(this->busca(i->getValor())) { throw ChaveExisteException(); return; }
    else if(this->vazia())
    {
        this->setInicio(i);
        this->setQuantidade(this->getQuantidade()+1);
    }   
    else
    {
        Item *ant = NULL, *atual = this->getInicio();

        while(atual != NULL && atual->getValor() < i->getValor())
        {
            ant = atual;
            atual = atual->getProximo();
        }    

        i->setProximo(atual);
        if(ant != NULL)
        {
            ant->setProximo(i);
        }
        else
        {
            this->setInicio(i);
        }
        
        this->setQuantidade(this->getQuantidade()+1);
    }
/* 
    else
    {
        Item *aux = this->getInicio();
        if(aux->getValor() > i->getValor())
        {
            i->setProximo(aux);
            this->setInicio(i);   
        }
        else
        {
            while(aux != NULL)
            {
                if(aux->getProximo() == NULL)
                {
                    std::cout << "Aqui que entra final da fila! "<< ":: " << i->getValor() << std::endl;
                    i->setProximo(NULL);
                    aux->setProximo(i);
                    break;
                }
                else if(aux->getProximo()->getValor() > i->getValor())
                {
                    std::cout << "Aqui que entra " << aux->getValor() << "::" << i->getValor() << std::endl;
                    i->setProximo(aux->getProximo());
                    aux->setProximo(i);
                    break;
                }
    
                aux = aux->getProximo();
            }
        }
        this->setQuantidade(this->getQuantidade()+1);
    
    }*/
    
}
void Lista::remover(int v)
{
    Item *rem = this->getInicio(), *ant = NULL;

    if(rem == NULL) { throw ListaVaziaException(); }
    while(rem != NULL)
    {
        if(rem->getValor() == v)
        {
            if(ant == NULL)
            {
                this->setInicio(rem->getProximo());
            }
            else
            {
                ant->setProximo(rem->getProximo());
            }
            std::cout << "REMOVIDO: " << rem->getValor() << std::endl;
            delete rem;
            this->setQuantidade(this->getQuantidade()-1);
            break;
        }
        ant = rem;
        rem = rem->getProximo();

        if(rem == NULL) { throw ChaveNaoExisteException(); }
    }
}
void Lista::mostrar()
{
    Item *i = this->getInicio();
    if(i == NULL) { throw ListaVaziaException(); }
    while(i != NULL)
    {
        if(i == this->getInicio()) std::cout << i->getValor();
        else std::cout << " " << i->getValor();
        i = i->getProximo();
        if(i == NULL) std::cout << "\n";
    }

    delete i;
}
int main()
{
    Lista *lista = new Lista();
    char op;
    while (std::cin >> op) {
        int chave;

        switch (op) {
            case 'I': std::cin >> chave;
                      try { lista->inserir(new Item(chave));
                      }
                      catch (ChaveExisteException e)
                      {
                          std::cout << e.what() << std::endl;
                      }
                      break;
            case 'R': std::cin >> chave;
                      try { lista->remover(chave);
                      }
                      catch (ChaveNaoExisteException e)
                      {
                          std::cout << e.what() << std::endl;
                      }             
                      catch (ListaVaziaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }                                  
                      break;
            case 'B': std::cin >> chave;
                      try{ if(lista->vazia()) { throw ListaVaziaException(); }
                      std::cout << (lista->busca(chave) == true ? "SIM" : throw ChaveNaoExisteException() )<< std::endl;
                      }
                      catch (ChaveNaoExisteException e)
                      {
                          std::cout << e.what() << std::endl;
                      }                        
                      catch (ListaVaziaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }
                      break;
            case 'M': try {lista->mostrar();
                      }
                      catch (ListaVaziaException e)
                      {
                          std::cout << e.what() << std::endl;
                      }       
                      break;                      
        }    
    } 
    return 0;
}