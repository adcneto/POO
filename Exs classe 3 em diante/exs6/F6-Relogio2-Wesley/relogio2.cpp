#include <iostream>
#include <string>

class Horas{
    private:
        int segundos, minutos, horas;
    public:
        Horas();
        Horas(int,int,int);
        int getSegundos();
        int getMinutos();
        int getHoras();
        void setSegundos(int);
        void setMinutos(int);
        void setHoras(int);
        void incrementa();
        void incrementa(int);
};

Horas::Horas(){
    this->setSegundos(0);
    this->setMinutos(0);
    this->setHoras(0);
}

Horas::Horas(int seg,int min,int hor){
    this->setSegundos(seg);
    this->setMinutos(min);
    this->setHoras(hor);
}

int Horas::getSegundos(){
    return this->segundos;
}

int Horas::getMinutos(){
    return this->minutos;
}

int Horas::getHoras(){
    return this->horas;
}

void Horas::setSegundos(int x){
    this->segundos = x;
}

void Horas::setMinutos(int x){
    this->minutos = x;
}

void Horas::setHoras(int x){
    this->horas = x;
}

void Horas::incrementa(){
    this->setSegundos(this->getSegundos()+1);
    if(this->getSegundos()>=60){
        this->setSegundos(0);
        this->setMinutos(this->getMinutos()+1);
        if(this->getMinutos()>=60){
            this->setMinutos(0);
            this->setHoras(this->getHoras()+1);
            if(this->getHoras()>=24){
                this->setHoras(0);
            }
        }
    }
}

void Horas::incrementa(int x){
    for(int i=0 ; i<x ; i++){
        this->setSegundos(this->getSegundos()+1);
        if(this->getSegundos()>=60){
            this->setSegundos(0);
            this->setMinutos(this->getMinutos()+1);
            if(this->getMinutos()>=60){
                this->setMinutos(0);
                this->setHoras(this->getHoras()+1);
                if(this->getHoras()>=24){
                    this->setHoras(0);
                }
            }
        }
    }
}

int main(){
    std::string tic;
    Horas relogio;
    while(std::cin >> tic ){
        if(tic.compare("tic")==0){
            relogio.incrementa();
        }
        if(tic.compare("tac")==0){
            relogio.incrementa(60);
        }
        if(tic.compare("toc")==0){
            relogio.incrementa(3600);
        }

    }
    std::cout << relogio.getHoras()  << ":" << relogio.getMinutos() << ":" << relogio.getSegundos() << std::endl;
    return 0;
}