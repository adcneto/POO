#include <iostream>
#include <stdexcept>

class HoraInvalidaException: public std::runtime_error
{
    public:
            HoraInvalidaException():runtime_error("HORARIO INVALIDO")
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
            void setHora(int);
            void setMinuto(int);
            void setSegundo(int);
            int getHora();
            int getMinuto();
            int getSegundo();
            void incrementa();
            bool isValida();
            Relogio operator ++(int);
};

Relogio::Relogio()
{
    this->setHora(0);
    this->setMinuto(0);
    this->setSegundo(0);
}
Relogio::Relogio(int h, int m, int s)
{
    this->setHora(h);
    this->setMinuto(m);
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
    if(this->getSegundo() == 60)
    {
        this->setSegundo(0);
        this->setMinuto(this->getMinuto()+1);
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
Relogio Relogio::operator ++(int)
{
    Relogio r(this->getHora(), this->getMinuto(), this->getSegundo());
    this->incrementa();
    return r;
}
bool Relogio::isValida()
{
    if((this->getHora() >= 1 && this->getHora() <= 12) && (this->getMinuto() >= 0 && this->getMinuto() <= 59) && (this->getSegundo() >= 0 && this->getSegundo() <= 59))
    {
        std::cout << "HORA VALIDA" << std::endl;
        return true;
    } 
    else
    {
        throw HoraInvalidaException();
    }
    
}
int main()
{
    int h, m, s;
    Relogio *r;
    char op, op2;
    std::string per;
    while(std::cin >> h >> op >> m >> op >> s >> per)
    {
        r = new Relogio(h, m, s);
        try
        {
            r->isValida();
        }
        catch(HoraInvalidaException e)
        {
            std::cout << e.what() << std::endl;
        }
        
    }
    return 0;
}