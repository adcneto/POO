#include <iostream>

class DataInvalidaException: public std::runtime_error
{
    public:
            DataInvalidaException():runtime_error("DATA INVALIDA.")
            {
                
            }
};
class Data
{
    private:
            int dia, mes, ano;
    public:
            Data();
            Data(int, int, int);
            void setDia(int);
            void setMes(int);
            void setAno(int);
            int getDia();
            int getMes();
            int getAno();
            bool bissexto();
            bool isValida();
            void incrementa();
            void decrementa();
};

Data::Data()
{   }

Data::Data(int d, int m, int a)
{
    this->setDia(d);
    this->setMes(m);
    this->setAno(a);
}

void Data::setDia(int d)
{
    this->dia = d;
}

void Data::setMes(int m)
{
    this->mes = m;
}

void Data::setAno(int a)
{
    this->ano = a;
}

int Data::getDia()
{
    return this->dia;
}

int Data::getMes()
{
    return this->mes;
}

int Data::getAno()
{
    return this->ano;
}

bool Data::bissexto () {
  if (this->getAno() % 400 == 0) {
    return true;
  }
  else if ((this->getAno() % 4 == 0) && (this->getAno() % 100 != 0)) {
    return true;
  }
  else {
    return false;
  }
}
void Data::incrementa()
{
    this->setDia(this->getDia() + 1);

    if(this->getMes() == 2)
    {
        if(this->getDia() > 29){ this->setMes(this->getMes()+1); this->setDia(1); }
        else if(this->getDia() > 28)
        {
            if(this->bissexto()) {}
            else { this->setMes(this->getMes()+1); this->setDia(1); }
        }
    }
    else if(this->getMes() == 4 || this->getMes() == 6 || this->getMes() == 9 || this->getMes() == 11)
    {
        if(this->getDia() > 30){ this->setMes(this->getMes() + 1); this->setDia(1); }
    }

    if(this->getDia() > 31) { this->setMes(this->getMes() + 1); this->setDia(1); }

    if(this->getMes() > 12)
    {
        this->setMes(1);
        this->setAno(this->getAno() +1);
    }
}
bool Data::isValida () {
  if(this->ano < 0) return false;
  if(this->dia < 1 || this->dia > 31) return false;
  if(this->mes > 12 || this->mes < 1) return false;
  if(this->mes == 4 || this->mes == 6 || this->mes == 9 || this->mes == 11)
  {
    if(this->dia > 30) return false;
  }
  if(this->mes == 2)
  {
    if(this->dia > 29) return false;
    if(this->dia > 28)
    {
      if(this->bissexto()) return true;
      else return false;
    }
  }
  return true;
}
void Data::decrementa()
{
    this->setDia(this->getDia() - 1);

    if(this->getDia() == 0)
    {
        this->setMes(this->getMes() - 1);

        if(this->getMes() == 2)
        {
            if(this->bissexto()) { this->setDia(29); }
            else { this->setDia(28); }
        }
        else if(this->getMes() == 4 || this->getMes() == 6 || this->getMes() == 9 || this->getMes() == 11)
        {
            this->setDia(30);
        }
        else if(this->getMes() == 0)
        {
            this->setDia(31);
            this->setMes(12);
            this->setAno(this->getAno() -1);
        }
        else { this->setDia(31); }
    }
}
class HoraInvalidaException: public std::runtime_error
{
    public:
            HoraInvalidaException():runtime_error("HORA INVALIDA.")
            {

            }
};
class Relogio
{
    private:
            int hora, minuto, segundo;
    public:
            Relogio();
            Relogio(int, int, int);

            //modificadores
            void setHora(int);
            void setMinuto(int);
            void setSegundo(int);
            int getHora();
            int getMinuto();
            int getSegundo();
            void incrementa();
            void decrementa();
            bool isValida();
            
};

Relogio::Relogio() { }
Relogio::Relogio(int hora, int min, int s)
{
    this->setHora(hora);
    this->setMinuto(min);
    this->setSegundo(s);
}

void Relogio::setHora(int h)
{
    this->hora = h;
}
void Relogio::setMinuto(int m)
{
    this->minuto = m;
}
void Relogio::setSegundo(int s)
{
    this->segundo = s;
}

int Relogio::getHora()
{
    return this->hora;
}
int Relogio::getMinuto()
{
    return this->minuto;
}
int Relogio::getSegundo()
{
    return this->segundo;
}
void Relogio::incrementa()
{
    this->setSegundo(this->getSegundo()+1);
    if(this->getSegundo () == 60)
    {
        this->setMinuto(this->getMinuto()+1);
        this->setSegundo(0);
    }
    if(this->getMinuto() == 60)
    {
        this->setMinuto(0);
        this->setHora(this->getHora()+1);
    }
    if(this->getHora() == 24)
    {
        this->setHora(0);
    }
}
void Relogio::decrementa()
{
    this->setSegundo(this->getSegundo()-1);
    if(this->getSegundo () == -1)
    {
        this->setMinuto(this->getMinuto()-1);
        this->setSegundo(0);
    }
    if(this->getMinuto() == -1)
    {
        this->setMinuto(0);
        this->setHora(this->getHora()-1);
    }
    if(this->getHora() == -1)
    {
        this->setHora(23);
    }
}
bool Relogio::isValida()
{
    if((this->getHora() >= 0 && this->getHora() <= 23) && (this->getMinuto() >= 0 && this->getMinuto() <= 59) && (this->getSegundo() >= 0 && this->getSegundo() <= 59))
    {
        return true;
    } 
    else
    {
        return false;
    }
}
class DataHoraInvalidasException: public std::runtime_error
{
    public:
            DataHoraInvalidasException():runtime_error("DATA E HORA INVALIDAS.")
            {

            }
};
class DataPrecisa: public Data, public Relogio
{
    private:
            bool regressivo;
    public:
            DataPrecisa();
            DataPrecisa(int, int, int, int, int, int);
            DataPrecisa(Data);
            DataPrecisa(Data, Relogio);
            void setRegressivo(bool);
            bool isRegressivo();
            DataPrecisa operator ++(int);
            DataPrecisa operator --(int);
            bool isValida();
};

DataPrecisa::DataPrecisa() { }

DataPrecisa::DataPrecisa(int d, int m, int a, int h, int min, int s)
{
    this->setDia(d);
    this->setMes(m);
    this->setAno(a);
    this->setHora(h);
    this->setMinuto(min);
    this->setSegundo(s);
    this->setRegressivo(false);
}
DataPrecisa::DataPrecisa(Data dt):Data(dt.getDia(), dt.getMes(), dt.getAno())
{
    this->setHora(0);
    this->setMinuto(0);
    this->setSegundo(0);
    this->setRegressivo(false);
}
DataPrecisa::DataPrecisa(Data dt, Relogio r):Data(dt.getDia(), dt.getMes(), dt.getAno()), Relogio(r.getHora(), r.getMinuto(), r.getSegundo())
{
    this->setRegressivo(false);
}
void DataPrecisa::setRegressivo(bool r)
{
    this->regressivo = r;
}
bool DataPrecisa::isRegressivo()
{
    return this->regressivo;
}
bool DataPrecisa::isValida()
{
    if(this->Data::isValida() && this->Relogio::isValida())
    {
        std::cout << "DATA E HORA VALIDAS." << std::endl;
    }
    else if(!this->Data::isValida() && !this->Relogio::isValida())
    {
        throw DataHoraInvalidasException();
    }
    else if(this->Data::isValida() && !this->Relogio::isValida())
    {
        throw HoraInvalidaException();
    }
    else if(!this->Data::isValida() && this->Relogio::isValida())
    {
        throw DataInvalidaException();
    }    
}
DataPrecisa DataPrecisa:: operator ++(int)
{
    DataPrecisa dtp(this->getDia(), this->getMes(), this->getAno(), this->getHora(), this->getMinuto(), this->getSegundo());
    this->setSegundo(this->getSegundo()+1);
    if(this->getSegundo () == 60)
    {
        this->setMinuto(this->getMinuto()+1);
        this->setSegundo(0);
    }
    if(this->getMinuto() == 60)
    {
        this->setMinuto(0);
        this->setHora(this->getHora()+1);
    }
    if(this->getHora() == 24)
    {
        this->setHora(0);
        this->Data::incrementa();
    }
    return dtp;
}
DataPrecisa DataPrecisa:: operator --(int)
{
    DataPrecisa dtp(this->getDia(), this->getMes(), this->getAno(), this->getHora(), this->getMinuto(), this->getSegundo());
    this->Data::decrementa();
    this->Data::decrementa();
    return dtp;
}
int main()
{
    int d, m, a, h, min, s;
    char op, op2, op3,op4;
    while(std::cin >> d >> op >> m >> op2 >> a >> h >> op3 >> min >> op4 >> s)
    {
        Data D(d, m ,a);
        Relogio R(h, min, s);
        DataPrecisa dtp(D, R);

        try{ 
            dtp.isValida();
        }
        catch(HoraInvalidaException e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(DataInvalidaException e)
        {
            std::cout << e.what() << std::endl;
        }        
        catch(DataHoraInvalidasException e)
        {
            std::cout << e.what() << std::endl;
        }        
    }
    return 0;
}