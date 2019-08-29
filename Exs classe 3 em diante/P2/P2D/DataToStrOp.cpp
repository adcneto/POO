#include <iostream>
#include <sstream>

class Data
{
    private:
        int dia, mes, ano;
    public:
        Data(int, int, int);
        bool isBissexto();
        // M�todos modificadores e m�todos de acesso:
        void setDia (int);
        void setMes (int);
        void setAno (int);
        int getDia ();
        int getMes ();
        int getAno ();
        operator std::string();

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

Data::operator std::string()
{
  std::string mes;
  std::stringstream re;
  if(this->getMes() == 1) { mes = "Janeiro"; }
  else if(this->getMes() == 2) { mes = "Fevereiro"; }
  else if(this->getMes() == 3) { mes = "Marco"; }
  else if(this->getMes() == 4) { mes = "Abril"; }
  else if(this->getMes() == 5) { mes = "Maio"; }
  else if(this->getMes() == 6) { mes = "Junho"; }
  else if(this->getMes() == 7) { mes = "Julho"; }
  else if(this->getMes() == 8) { mes = "Agosto"; }
  else if(this->getMes() == 9) { mes = "Setembro"; }
  else if(this->getMes() == 10) { mes = "Outubro"; }
  else if(this->getMes() == 11) { mes = "Novembro"; }
  else if(this->getMes() == 12) { mes = "Dezembro"; }
  if(this->getDia() < 10)
  {
    re << "0"<< this->getDia() << " de " << mes << " de " << this->getAno();
  }
  else
  {
    re << this->getDia() << " de " << mes << " de " << this->getAno();
  }

  return re.str();
}
int main ()
{
    int dia, mes, ano;
    std::string convert;
    while(std::cin >> dia >> mes >> ano)
    {
      Data d(dia, mes, ano);
      convert = d;
      std::cout << convert << std::endl;
    }
    return 0;
}
