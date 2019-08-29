#include <iostream>

class Data
{
    private:
        int dia, mes, ano;
    public:
        Data(int, int, int);
        bool isBissexto();
        void decrementa();
        // M�todos modificadores e m�todos de acesso:
        void setDia (int);
        void setMes (int);
        void setAno (int);
        int getDia ();
        int getMes ();
        int getAno ();
        Data operator - (int);

};

Data::Data(int dia, int mes, int ano)
{
    this->setDia(dia);
    this->setMes(mes);
    this->setAno(ano);
}

bool Data::isBissexto () {
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

void Data::setDia(int dia)
{
    this->dia = dia;
}
void Data::setMes(int mes)
{
    this->mes = mes;
}
void Data::setAno(int ano)
{
    this->ano = ano;
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

void Data::decrementa()
{
    this->setDia(this->getDia() - 1);

    if(this->getDia() == 0)
    {
        this->setMes(this->getMes() - 1);

        if(this->getMes() == 2)
        {
            if(this->isBissexto()) { this->setDia(29); }
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
Data Data::operator - (int dias)
{
  Data d(this->getDia(), this->getMes(), this->getAno());
  for(int i = 0; i < dias; i ++)
  {
    d.decrementa();
  }
  return d;
}
int main ()
{
    int dia, mes, ano, dias;
    while(std::cin >> dia >> mes >> ano >> dias)
    {
      Data d(dia, mes, ano);
      d = d - dias;
      std::cout << d.getDia() << " " << d.getMes() << " " << d.getAno() << std::endl;
    }
    return 0;
}
