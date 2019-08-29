#include <iostream>
#include <sstream>

class Data
{
    private:
        int dia, mes, ano;
    public:
        Data(int, int, int);
        Data(std::string);
        bool isBissexto();
        // M�todos modificadores e m�todos de acesso:
        void setDia (int);
        void setMes (int);
        void setAno (int);
        int getDia ();
        int getMes ();
        int getAno ();
        void operator = (std::string);

};

Data::Data(int dia, int mes, int ano)
{
    this->setDia(dia);
    this->setMes(mes);
    this->setAno(ano);
}

Data::Data(std::string str)
{
  std::string aux;
  int pos;
  if(str.substr(0, 1). compare("0") == 0)
  {
    this->setDia(str[1] - '0');
  }
  else
  {
    this->setDia(((str[0] - '0')*10) + (str[1] - '0'));
  }

  if(str.find("Janeiro") != std::string::npos) { pos = 17; this->setMes(1); }
  else if(str.find("Fevereiro") != std::string::npos) { pos = 19; this->setMes(2); }
  else if(str.find("Marco") != std::string::npos) { pos = 15; this->setMes(3); }
  else if(str.find("Abril") != std::string::npos) { pos = 15; this->setMes(4); }
  else if(str.find("Maio") != std::string::npos) { pos = 14; this->setMes(5); }
  else if(str.find("Junho") != std::string::npos) { pos = 15; this->setMes(6); }
  else if(str.find("Julho") != std::string::npos) { pos = 15;this->setMes(7); }
  else if(str.find("Agosto") != std::string::npos) { pos = 16; this->setMes(8); }
  else if(str.find("Setembro") != std::string::npos) { pos = 18; this->setMes(9); }
  else if(str.find("Outubro") != std::string::npos) { pos = 17; this->setMes(10); }
  else if(str.find("Novembro") != std::string::npos) { pos = 18; this->setMes(11); }
  else if(str.find("Dezembro") != std::string::npos) { pos = 18; this->setMes(12); }

   aux = str.substr(pos,4);
  this->setAno(((aux[0] - '0')*1000) + ((aux[1] - '0')*100) + ((aux[2] - '0')*10) + (aux[3] - '0'));
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

void Data::operator  = (std::string str)
{
    std::string aux;
    int pos;
    if(str.substr(0, 1). compare("0") == 0)
    {
      this->setDia(str[1] - '0');
    }
    else
    {
      this->setDia(((str[0] - '0')*10) + (str[1] - '0'));
    }

    if(str.find("Janeiro") != std::string::npos) { pos = 17; this->setMes(1); }
    else if(str.find("Fevereiro") != std::string::npos) { pos = 19; this->setMes(2); }
    else if(str.find("Marco") != std::string::npos) { pos = 15; this->setMes(3); }
    else if(str.find("Abril") != std::string::npos) { pos = 15; this->setMes(4); }
    else if(str.find("Maio") != std::string::npos) { pos = 14; this->setMes(5); }
    else if(str.find("Junho") != std::string::npos) { pos = 15; this->setMes(6); }
    else if(str.find("Julho") != std::string::npos) { pos = 15;this->setMes(7); }
    else if(str.find("Agosto") != std::string::npos) { pos = 16; this->setMes(8); }
    else if(str.find("Setembro") != std::string::npos) { pos = 18; this->setMes(9); }
    else if(str.find("Outubro") != std::string::npos) { pos = 17; this->setMes(10); }
    else if(str.find("Novembro") != std::string::npos) { pos = 18; this->setMes(11); }
    else if(str.find("Dezembro") != std::string::npos) { pos = 18; this->setMes(12); }

     aux = str.substr(pos,4);
    this->setAno(((aux[0] - '0')*1000) + ((aux[1] - '0')*100) + ((aux[2] - '0')*10) + (aux[3] - '0'));

}
int main ()
{
    std::string dia, op1, mes, op2, ano;
    std::stringstream data;
    while(std::cin >> dia >> op1 >> mes >> op2 >> ano)
    {
      data.str("");
      data.clear();
      data << dia << " " << op1 << " " << mes << " " << op2 << " " << ano;
      Data d(data.str());
      d = data.str();
      std::cout << d.getDia() << " " << d.getMes() << " " << d.getAno() << std::endl;
    }
    return 0;
}
