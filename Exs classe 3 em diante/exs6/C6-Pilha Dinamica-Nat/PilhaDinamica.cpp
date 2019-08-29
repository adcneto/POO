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


class Fila : public Lista{
	private:
		Item *primeiro;
	public: 
		Fila();
		void inserir(Item*);
		void remover();	

};

class Pilha : public Lista{
	private:
		Item *primeiro;
	public:
		Pilha();
		void inserir(Item*);
		void remover();
		void mostrar(Item*);

};


Pilha :: Pilha(){

}

void Pilha :: inserir(Item* novo){
	if(this -> isVazia() == false){
		Item *atual = this -> getPrimeiro();
	
		while(atual -> getProximo() != NULL){
			
			atual = atual -> getProximo();
		}

		if(atual != NULL){
			atual -> setProximo(novo);
		}

	}
	

	else {
		this -> setPrimeiro(novo);
	}
}

void Pilha :: remover(){

	if(this -> isVazia() == false){
		
		if(this-> getPrimeiro() -> getProximo() == NULL){
			std :: cout << "[" << this ->getPrimeiro()-> getChave() << "]" << std :: endl;
			this -> setPrimeiro(NULL);
		}
		
		else{
			Item *atual = this -> getPrimeiro(), *anterior = NULL;
	
			while(atual -> getProximo() != NULL){
				anterior = atual;
				atual = atual -> getProximo();
			}

			std :: cout << "[" << atual -> getChave() << "]" << std :: endl;
			anterior -> setProximo(NULL);

		}	

		
	}

}

void Pilha :: mostrar(Item* arg){

	if (arg -> getProximo() == NULL){
		return;
	}
	else{
		arg = arg-> getProximo();
		mostrar(arg);
		std :: cout << arg->getChave() << " ";
	}
}


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

Fila:: Fila(){
}

void Fila :: inserir(Item* novo){
	if(this -> isVazia() == false){
		Item *atual = this -> getPrimeiro();
	
		while(atual -> getProximo() != NULL){
			
			atual = atual -> getProximo();
		}

		if(atual != NULL){
			atual -> setProximo(novo);
		}

	}
	

	else {
		this -> setPrimeiro(novo);
	}	

}

void Fila :: remover(){

	if(this -> getPrimeiro() != NULL){

		std :: cout << "<" << this -> getPrimeiro()-> getChave()  << ">" << std :: endl;

		this -> setPrimeiro(this -> getPrimeiro() -> getProximo());
	}
} 

 

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

    Pilha * pilha = new Pilha();

    int valor;
    char op;

    while(std :: cin >> op){
        
        if (op == 'E'){
            std :: cin >> valor;
            pilha -> inserir(new Item(valor));

        }
        else if(op == 'M'){
			Item* arg = pilha -> getPrimeiro();
			
			if(arg != NULL){
				pilha -> mostrar(arg);
				std :: cout << pilha->getPrimeiro() -> getChave() << std :: endl;
			}
            
			
        }
        
        else{
            
            pilha -> remover();
        }
    }
    return 0;
}
