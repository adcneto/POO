#include <iostream>

class Item
{
    private:
            int chave;
            Item *proximo;
    public:
            Item(int);
            void setChave(int);
            void setProximo(Item *);
            int getChave();
            Item *getProximo();
};

Item::Item(int c)
{
    this->setProximo(NULL);
    this->setChave(c);
}

void Item::setChave(int c)
{
    this->chave = c;
}
void Item::setProximo(Item *i)
{
    this->proximo = i;
}

int Item::getChave()
{
    return this->chave;
}
Item *Item::getProximo()
{
    return this->proximo;
}


class Estrutura
{
    private:
            int quantidade;
            Item *inicio;
            int tipo;
    public:
            Estrutura();
            void setQuantidade(int);
            void setInicio(Item *);
            int getQuantidade();
            Item *getInicio();
            virtual void mostrar();
            virtual bool vazia();

            void setTipo(int);
            int getTipo();
            
            //Fila

            virtual void setFinal(Item *i){}
            virtual Item *getFinal(){ return NULL;}
            virtual void enfileira(Item *i){}
            virtual Item *desinfileira(){ return NULL; }

            //LDE
            virtual void inserir(Item *i){}
            virtual bool busca(int c){}
            virtual void remover(int c){}

            //Pilha
            virtual void empilhar(Item *i){}
            virtual Item *desempilhar(){ return NULL; }

};

Estrutura::Estrutura()
{
    this->setInicio(NULL);
    this->setQuantidade(0);
}
void Estrutura::setQuantidade(int q)
{
    this->quantidade = q;
}
void Estrutura::setTipo(int t)
{
    this->tipo = t;
}
int Estrutura::getTipo()
{
    return this->tipo;
}
void Estrutura::setInicio(Item *i)
{
    this->inicio = i;
}
int Estrutura::getQuantidade()
{
    return this->quantidade;
}
Item *Estrutura::getInicio()
{
    return this->inicio;
}
bool Estrutura::vazia()
{
    return this->getQuantidade() == 0;
}
void Estrutura::mostrar()
{
    Item *it = this->getInicio();
    while(it != NULL)
    {
        if(it == this->getInicio()) { std::cout << it->getChave(); }
        else { std::cout << " " << it->getChave(); }
        it = it->getProximo();
        if(it == NULL) std::cout << "\n";
    }
    delete it;
}

class Fila: public Estrutura
{
    private:
            Item *final;
    public:
            Fila();
            void setFinal(Item *);
            Item *getFinal();
            bool vazia();
            void enfileira(Item *i);
            Item *desinfileira();

};

Fila::Fila()
{
    this->setFinal(NULL);
}

void Fila::setFinal(Item *i)
{
    this->final = i;
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
        std::cout << "REMOVIDO: " << aux->getChave() << std::endl;
        return aux;
    }
    return NULL;
}
class Lista: public Estrutura
{
    public:
            Lista();
            void inserir(Item *);
            bool busca(int);
            void remover(int);
};
Lista::Lista()
{

}
bool Lista::busca(int chave)
{
    Item *i = this->getInicio();
    while(i != NULL)
    {
        if(i->getChave() == chave)
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
    if(this->busca(i->getChave())) { return; }
    else if(this->vazia())
    {
        this->setInicio(i);
        this->setQuantidade(this->getQuantidade()+1);
    }   
    else
    {
        Item *ant = NULL, *atual = this->getInicio();

        while(atual != NULL && atual->getChave() < i->getChave())
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
}
void Lista::remover(int v)
{
    Item *rem = this->getInicio(), *ant = NULL;
    while(rem != NULL)
    {
        if(rem->getChave() == v)
        {
            if(ant == NULL)
            {
                this->setInicio(rem->getProximo());
            }
            else
            {
                ant->setProximo(rem->getProximo());
            }
            std::cout << "REMOVIDO: " << rem->getChave() << std::endl;
            delete rem;
            this->setQuantidade(this->getQuantidade()-1);
            break;
        }
        ant = rem;
        rem = rem->getProximo();
    }
}

class Pilha: public Estrutura
{
    public:
            Pilha();
            void empilhar(Item *);
            Item *desempilhar();
            void mostrar();
};

Pilha::Pilha()
{

}
void Pilha::empilhar(Item *i)
{
    if(this->vazia())
    {
        this->setQuantidade(1);
        i->setProximo(this->getInicio());
        this->setInicio(i);
    }
    else
    {
        i->setProximo(this->getInicio());
        this->setInicio(i);
        this->setQuantidade(this->getQuantidade()+1);
    }
    
}
Item *Pilha::desempilhar()
{
    if(this->vazia()) return NULL;
    Item *aux = this->getInicio();
    this->setInicio(aux->getProximo());
    this->setQuantidade(this->getQuantidade()-1);
    std::cout << "REMOVIDO: " << aux->getChave() << std::endl;
    return aux;

}

void Pilha::mostrar()
{
    Item *it = this->getInicio();
    Item *aux[this->getQuantidade()];
    int i = 0;
    while(it != NULL)
    {
        aux[i] = it;
        it = it->getProximo();
        i++;
    }
    for (int j = i-1; j >=0; j--)
    {
        if(j == i-1) { std::cout << aux[j]->getChave(); }
        else { std::cout << " " << aux[j]->getChave(); }
        if(j == 0) std::cout << "\n";
    }
    delete it;
}
int main()
{
    int n;
    std::cin >> n;
    Estrutura *e[n];
    std::string tipo;
    for(int i = 0; i < n; i++)
    {
        std::cin >> tipo;
        if(tipo.compare("LDE") == 0)
        {
            e[i] = new Lista();
            e[i]->setTipo(1);
        }
        else if(tipo.compare("FILA") == 0)
        {
            e[i] = new Fila();
            e[i]->setTipo(2);
        }
        else if(tipo.compare("PILHA") == 0)
        {
            e[i] = new Pilha();
            e[i]->setTipo(3);
        }
    }
    int pos_ed, chave;
    char op;

    while(std::cin >> pos_ed >> op)
    {
        switch (op){

            case 'I': std::cin >> chave;
                if(e[pos_ed]->getTipo() == 1) { e[pos_ed]->inserir(new Item(chave)); }
                else if(e[pos_ed]->getTipo() == 2) { e[pos_ed]->enfileira(new Item(chave)); }
                else { e[pos_ed]->empilhar(new Item(chave)); }
                break;
        
            case 'R': 
                if(e[pos_ed]->getTipo() == 1) { std::cin >> chave; e[pos_ed]->remover(chave); }
                else if(e[pos_ed]->getTipo() == 2) { e[pos_ed]->desinfileira(); }
                else { e[pos_ed]->desempilhar(); }
                break;
            case 'M': e[pos_ed]->mostrar();
                break;    
        }
    }
    return 0;
}