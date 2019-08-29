#include <iostream>
#include <string>

class Horas{
    private:
        int segundos, minutos, horas;
        std::string AMPM;
    public:
        Horas();
        Horas(int,int,int, std::string);
        int getSegundos();
        int getMinutos();
        int getHoras();
        std::string getAMPM();
        void setSegundos(int);
        void setMinutos(int);
        void setHoras(int);
        void setAMPM(std::string);
        void incrementa();
        void incrementa(int);
};

Horas::Horas(){
    this->setSegundos(0);
    this->setMinutos(0);
    this->setHoras(12);
    this->setAMPM("AM");
}

Horas::Horas(int seg,int min,int hor, std::string op){
    this->setSegundos(seg);
    this->setMinutos(min);
    this->setHoras(hor);
    this->setAMPM(op);
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

std::string Horas::getAMPM(){
    return this->AMPM;
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

void Horas::setAMPM(std::string x){
    this->AMPM = x;
}

void Horas::incrementa(){
    this->setSegundos(this->getSegundos()+1);
    if(this->getSegundos()>=60){
        this->setSegundos(0);
        this->setMinutos(this->getMinutos()+1);
        if(this->getMinutos()>=60){
            this->setMinutos(0);
            this->setHoras(this->getHoras()+1);
            if(this->getHoras()>12){
                this->setHoras(1);
            }
            else if(this->getHoras()==12){
                if(this->getAMPM().compare("AM")==0){
                    this->setAMPM("PM");
                }
                else{
                    this->setAMPM("AM");
                }
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
                if(this->getHoras()>12){
                    this->setHoras(1);
                }
                else if(this->getHoras()==12){
                    if(this->getAMPM().compare("AM")==0){
                        this->setAMPM("PM");
                    }
                    else{
                        this->setAMPM("AM");
                    }
                }
            }
        }
    }
}

int main(){
    std::string tic;
    std::string op;
    int seg,min,horas;
    std::cin >> horas >> min >> seg >> op;
    Horas relogio(seg,min,horas,op);
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
    std::cout << relogio.getHoras()  << ":" << relogio.getMinutos() << ":" << relogio.getSegundos() << " " << relogio.getAMPM() << std::endl;
    return 0;
}