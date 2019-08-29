#include <iostream>

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

class Data{
    private:
        int dia;
        int mes;
        int ano;
        bool bissexto;
    public:
        Data();
        Data(int,int,int);
        //set and get
        int getDia();
        int getMes();
        int getAno();
        bool getBissexto();
        void setBissexto();
        void setDia(int);
        void setMes(int);
        void setAno(int);
};

Data::Data(){}

Data::Data(int dia, int mes, int ano){
    this->setDia(dia);
    this->setMes(mes);
    this->setAno(ano);
    this->setBissexto();
}

int Data::getDia(){
    return this->dia;
}

int Data::getMes(){
    return this->mes;
}

int Data::getAno(){
    return this->ano;
}

bool Data::getBissexto(){
    return this->bissexto;
}

void Data::setBissexto(){
    if(this->getAno()%400==0){
        this->bissexto = true;
    }
    else if(this->getAno()%4==0 && this->getAno()%100 != 0 ){
        this->bissexto = true;
    }
    else{
        this->bissexto = false;
    }
}

void Data::setDia(int dia){
    this->dia = dia;
}

void Data::setMes(int mes){
    this->mes = mes;
}

void Data::setAno(int ano){
    this->ano = ano;
}

class dataPrecisa : public Data , public Horas{
    public:
        dataPrecisa(int,int,int,int,int,int);
        void incrementa();
        void proximoDia();
};

dataPrecisa::dataPrecisa(int dia, int mes, int ano, int horas, int min, int seg):Data(dia,mes,ano),Horas(seg,min,horas){

}

void dataPrecisa::incrementa(){
    this->setSegundos(this->getSegundos()+1);
    if(this->getSegundos()>=60){
        this->setSegundos(0);
        this->setMinutos(this->getMinutos()+1);
        if(this->getMinutos()>=60){
            this->setMinutos(0);
            this->setHoras(this->getHoras()+1);
            if(this->getHoras()>=24){
                this->setHoras(0);
                this->proximoDia();
            }
        }
    }
}

void dataPrecisa::proximoDia(){
    if(this->getMes()==2){
        this->setDia(this->getDia()+1);
        if(this->getBissexto()==true){
            if(this->getDia()>29){
                this->setDia(1);
                this->setMes(this->getMes()+1);
            }
        }
        else{
            if(this->getDia()>28){
                this->setDia(1);
                this->setMes(this->getMes()+1);
            }
        }
    }
    else if(this->getMes()==1||this->getMes()==3||this->getMes()==5||this->getMes()==7||this->getMes()==8||this->getMes()==10||this->getMes()==12){
        this->setDia(this->getDia()+1);
        if(this->getDia()>31){
            this->setDia(1);
            this->setMes(this->getMes()+1);
            if(this->getMes()>12){
                this->setMes(1);
                this->setAno(this->getAno()+1);
            }
        }
    }
    else{
        this->setDia(this->getDia()+1);
        if(this->getDia()>30){
            this->setDia(1);
            this->setMes(this->getMes()+1);
        }
    }
}

int main(){
    int dia,mes,ano,hora,min,seg;
    std::cin >> dia >> mes >> ano >> hora >> min >> seg;
    dataPrecisa nova(dia,mes,ano,hora,min,seg);
    std::string op;
    std::cin >> op;
    for(int i=0 ; i<op.size() ; i++){
        if(op[i]=='+'){
            nova.incrementa();
        }
    }
    std::cout << nova.getDia() << "/" << nova.getMes() << "/" << nova.getAno() << " " << nova.getHoras() << ":" << nova.getMinutos() << ":" << nova.getSegundos() << std::endl;
    return 0;
}