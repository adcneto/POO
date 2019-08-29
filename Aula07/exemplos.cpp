#include <iostream>

class PrimeiraClasse{ };


class Data{
    public:
        int dia, mes, ano;


};


class Porta{

    bool aberta;
    public:
        void abrir();
        void fechar();
        void situacao();
};

void Porta::abrir(){

    aberta =true;
}
void Porta::fechar(){

    aberta = false;
}

void Porta::situacao(){

    std::cout << "A porta estah " << (aberta?"aberta":"fechada") << std::endl;
}


int main(){
    Porta sala1;
    
    sala1.situacao();
    sala1.abrir();
    sala1.situacao();
    sala1.fechar();
    sala1.situacao();
    
    PrimeiraClasse *primeiroObjeto = new PrimeiraClasse();
    PrimeiraClasse *SegundoObjeto;
    SegundoObjeto = new PrimeiraClasse();
    //Data *aniversario = new Data();
    Data aniversario, *aniversario1 = new Data();
    
    aniversario1->dia = 3;
    aniversario1->mes = 11;
    aniversario1->ano = 2012;
    std::cout << aniversario1->dia << '/'<< aniversario1->mes << '/' << aniversario1->ano <<".\n";
 
    aniversario.dia = 2;
    aniversario.mes = 11;
    aniversario.ano = 2001;
    
    std::cout << aniversario.dia << '/'<< aniversario.mes << '/' << aniversario.ano <<".\n";
    
    return 0;
    
}










        
        
