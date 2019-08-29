#include <iostream>
#include <string>
#include <cstdlib>
#include <typeinfo>

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
        Item* getProximo();
};

class EstruturaDinamica{
    private:
        Item *primeiro;
        Item *ultimo;
    public:
        EstruturaDinamica();
     	void setPrimeiro(Item*);
        void setUltimo(Item*);
        Item* getPrimeiro();
        Item* getUltimo();
        virtual void inserir(Item*);
        void remover(int);
        virtual void remover();
        virtual void mostrar();
		virtual void mostrarPilha(Item*);
        bool isVazia();
        bool buscar(int);
        virtual std :: string minhaClasse();
};

class Lista : public EstruturaDinamica{
    private:
        Item *primeiro;
        
    public:
        Lista();
        std :: string minhaClasse();
};


class Fila : public EstruturaDinamica{
	private:
		Item *primeiro;
	public: 
		Fila();
		void inserir(Item*);
		void remover();	
        std :: string minhaClasse();

};

class Pilha : public EstruturaDinamica{
	private:
		Item *primeiro;
	public:
		Pilha();
		void inserir(Item*);
		void remover();
		void mostrarPilha(Item*);
        std :: string minhaClasse();

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

void Item :: setProximo(Item *proximo){
    this -> proximo = proximo;
}

int Item :: getChave(){
    return this -> chave;
}

Item* Item :: getProximo(){
    return this -> proximo;
}

EstruturaDinamica :: EstruturaDinamica(){
    this -> setPrimeiro(NULL);
    this -> setUltimo(NULL);
}

void EstruturaDinamica :: setPrimeiro(Item* item){
    this -> primeiro = item;
}

void EstruturaDinamica :: setUltimo(Item* item){
    this -> ultimo = item;
}

Item* EstruturaDinamica :: getPrimeiro(){
    return this-> primeiro;
}

Item* EstruturaDinamica :: getUltimo(){
    return this -> ultimo;
}

std :: string EstruturaDinamica :: minhaClasse(){
    return "";
}
 void EstruturaDinamica :: mostrarPilha(Item* wtv){
}

void EstruturaDinamica  :: inserir(Item *novo){

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

void EstruturaDinamica :: remover(){

}

void EstruturaDinamica  :: remover(int tchau){

    if(isVazia() == true){
        return;
    }

    Item* atual = this -> getPrimeiro(), *ant = NULL;

    if(atual->getChave() == tchau){
		std :: cout << "REMOVIDO: " << atual->getChave() << std :: endl;
        this -> setPrimeiro(atual -> getProximo());
    }
    else{
        while(atual != NULL && atual -> getChave() != tchau){
        ant = atual;
        atual = atual -> getProximo();
        }

        if(atual != NULL){
			std :: cout << "REMOVIDO: " << atual->getChave() << std :: endl;
            ant -> setProximo(atual -> getProximo());
            free(atual);

        }   
    }
} 

bool EstruturaDinamica :: buscar(int tgt){
    Item* it = this -> getPrimeiro();

    while(it!=NULL && it->getChave() != tgt ){
        it = it -> getProximo();
    }    

    return !(it == NULL);

}



bool EstruturaDinamica  :: isVazia(){
    return this -> getPrimeiro() == NULL;
}


void EstruturaDinamica :: mostrar(){

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


Lista :: Lista(){

}

std :: string Lista :: minhaClasse(){
    return "Lista";
}

Pilha :: Pilha(){

}

std :: string Pilha :: minhaClasse(){
    return "Pilha";
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
			std :: cout << "REMOVIDO: " << this -> getPrimeiro() -> getChave() << std :: endl;
			this -> setPrimeiro(NULL);
		}
		
		else{
			Item *atual = this -> getPrimeiro(), *anterior = NULL;
	
			while(atual -> getProximo() != NULL){
				anterior = atual;
				atual = atual -> getProximo();
			}

			std :: cout << "REMOVIDO: " << atual -> getChave() << std :: endl;
			anterior -> setProximo(NULL);

		}	

		
	}

}

void Pilha :: mostrarPilha(Item* arg){

	if (arg -> getProximo() == NULL){
		return;
	}
	else{
		arg = arg-> getProximo();
		mostrarPilha(arg);
		std :: cout << arg->getChave() << " ";
	}
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

		std :: cout << "REMOVIDO: " << this -> getPrimeiro()-> getChave() << std :: endl;

		this -> setPrimeiro(this -> getPrimeiro() -> getProximo());
	}
} 

std :: string Fila :: minhaClasse(){
    return "Fila";
}
 


int main(){

    int n, indx, it, val;
    std :: string tipo;
    char op;

    std :: cin >> n;

    EstruturaDinamica *estruct[n];

    for(int i =0; i< n; i++){
        std :: cin >> tipo;

        if(tipo == "LDE"){
            estruct[i] = new Lista();
        }
        
        else if(tipo == "FILA"){
            estruct[i] = new Fila();
        } 

        else if(tipo == "PILHA"){
            estruct[i] = new Pilha();
        }
    }

    while(std :: cin >> indx >> op){
        
        if( op == 'I'){
            std :: cin >> it;
            Item *novo = new Item(it);
            estruct[indx]->inserir(novo);
        }

        else if(op == 'M'){
			estruct[indx] -> mostrar();
			           
        }

        else{
            if(estruct[indx]->minhaClasse() == "Lista"){
                std :: cin >> val;
                estruct[indx] ->remover(val);
            }
            else{
                estruct[indx]->remover();
            }
        }

        
    }


    return 0;
}
