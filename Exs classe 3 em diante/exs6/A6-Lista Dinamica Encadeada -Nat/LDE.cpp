#include <iostream>
#include <stdlib.h>

class Item{
    private:
        int chave;
        Item *proximo;

    public:
        Item();
        Item(int);
        void setChave(int);
        void setProximo(Item*);
        int getChave();
        Item *getProximo();
};

Item :: Item(){
}

Item :: Item(int chave){
    this -> setChave(chave);
    this -> setProximo(NULL);
}

void Item :: setChave(int key){
    this -> chave = key;
}

void Item:: setProximo(Item * proximo){
    this -> proximo = proximo;

}

int Item :: getChave(){
    return this -> chave;
}

Item* Item :: getProximo(){
    return this -> proximo;
}

class Lista{
    private:
        Item *primeiro;
    public:
        Lista();
        void setPrimeiro(Item *);
        Item* getPrimeiro();
        void inserir(Item*);
        void remover(int);
        bool buscar(int);
        void mostrar();
        bool isVazia();

};

Lista :: Lista(){
    this -> setPrimeiro(NULL);
}

void Lista :: setPrimeiro(Item* primeiro){
    this -> primeiro = primeiro;

}

Item*  Lista ::  getPrimeiro(){
    return this -> primeiro;
}

void Lista :: inserir(Item *novo){

    if (buscar(novo -> getChave()) == false ){
        Item *atual = this -> getPrimeiro(), *ant = NULL;

        while(atual != NULL && atual -> getChave() < novo-> getChave()){
            ant = atual;
            atual = atual -> getProximo();

        }

        novo -> setProximo(atual);
        
        if(ant != NULL){
            ant->setProximo(novo);
        }
        else{
            this -> setPrimeiro(novo);
        }
    }
}

void Lista :: remover(int tchau){

    if(isVazia() == true){
        return;
    }

    Item* atual = this -> getPrimeiro(), *ant = NULL;

    if(atual->getChave() == tchau){

        this -> setPrimeiro(atual -> getProximo());
    }
    else{
        while(atual != NULL && atual -> getChave() != tchau){
        ant = atual;
        atual = atual -> getProximo();
        }

        if(atual != NULL){
            ant -> setProximo(atual -> getProximo());
            free(atual);

        }   
    }
} 

bool Lista:: buscar(int tgt){
    Item* it = this -> getPrimeiro();

    while(it!=NULL && it->getChave() != tgt ){
        it = it -> getProximo();
    }    

    return !(it == NULL);

}



bool Lista :: isVazia(){
    return this -> getPrimeiro() == NULL;
}


void Lista:: mostrar(){

    if(isVazia() == true){
        return;        
    }

    Item * it = this -> getPrimeiro();

    while(it -> getProximo() != NULL){
        std :: cout << it -> getChave() <<" ";
        it = it -> getProximo();
    }

    std :: cout << it -> getChave() << std :: endl;

}



int main(){

    Lista * lista = new Lista();
    int valor,tgt;
    char op;

    while(std :: cin >> op){
        
        if (op == 'I'){
            std :: cin >> valor;
            lista -> inserir(new Item(valor));

        }
        else if(op == 'L'){
            lista -> mostrar();
        }
        else if(op == 'B'){
            std :: cin >> tgt;
            if( lista -> buscar(tgt)== true){
                std :: cout << "SIM" << std :: endl;
            }

            else{
                std :: cout << "NAO"<< std :: endl;
            }

        }
        else{
            std :: cin >> tgt;
            lista -> remover(tgt);
        }
    }
    return 0;
}