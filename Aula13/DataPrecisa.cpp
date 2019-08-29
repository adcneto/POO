#include <iostream>

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
		bool isValida();
		bool isBissexto();
		void incrementa();
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
		bool isValida();
		void incrementa();		
};

class DataPrecisa : public Data, public Relogio
{
	public:
		DataPrecisa();
		DataPrecisa(Data, Relogio);
		DataPrecisa operator++(int);
};

DataPrecisa::DataPrecisa()
{	}

DataPrecisa::DataPrecisa(Data dt, Relogio rel) :
	Data(dt.getDia(), dt.getMes(), dt.getAno()),
	Relogio(rel.getHora(), rel.getMinuto(), rel.getSegundo())
{	}

DataPrecisa DataPrecisa::operator++(int)
{
	DataPrecisa objRet(Data(this->getDia(), this->getMes(), this->getAno()), Relogio(this->getHora(), this->getMinuto(), this->getSegundo()));
	
	//aqui, temos que especificar qual metodo incrementa() queremos,
	//se é o de Data ou de Relogio:
	this->Relogio::incrementa();
	if(this->getHora() > 23)
	{
		this->setHora(0);
		//aqui, temos que especificar qual metodo incrementa() queremos,
		//se é o de Data ou de Relogio:
		this->Data::incrementa();
	}
	return objRet;
}

Relogio::Relogio()
{	}

Relogio::Relogio(int hora, int minuto, int segundo)
{
	this->setHora(hora);
	this->setMinuto(minuto);
	this->setSegundo(segundo);
}

void Relogio::setHora(int hora)
{
	this->hora = hora;
}

void Relogio::setMinuto(int minuto)
{
	this->minuto = minuto;
}

void Relogio::setSegundo(int segundo)
{
	this->segundo = segundo;
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

bool Relogio::isValida()
{
	if(this->getSegundo() < 0 || this->getSegundo() > 59)
		return false;
	if(this->getMinuto() < 0 || this->getMinuto() > 59)
		return false;
	return true;
}

void Relogio::incrementa()
{
	this->setSegundo(this->getSegundo() + 1);
	if(!this->isValida())
	{
		this->setSegundo(0);
		this->setMinuto(this->getMinuto() + 1);
		if(!this->isValida())
		{
			this->setMinuto(0);
			this->setHora(this->getHora() + 1);
		}
	}
}

Data::Data()
{	}

Data::Data(int dia, int mes, int ano)
{
	this->setDia(dia);
	this->setMes(mes);
	this->setAno(ano);
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

bool Data::isValida()
{
	if(this->getDia() < 1 || this->getDia() > 31)
		return false;
	if(this->getMes() < 1 || this->getMes() > 12)
		return false;
	if(this->getDia() > 30 && (this->getMes() == 4 || this->getMes() == 6 || this->getMes() == 9 || this->getMes() == 11 ))
		return false;
	if(this->getMes() == 2 && this->getDia() == 29 && !this->isBissexto())
		return false;
	if(this->getMes() == 2 && this->getDia() > 29)
		return false;
	return true;
}

bool Data::isBissexto()
{
	return this->getAno()%400 == 0 || this->getAno()%100 != 0 && this->getAno()%4 == 0;
}
void Data::incrementa()
{
	this->setDia(this->getDia() + 1);
	if(!this->isValida())
	{
		this->setDia(1);
		this->setMes(this->getMes() + 1);
		if(!this->isValida())
		{
			this->setMes(1);
			this->setAno(this->getAno() + 1);
		}
	}
}

int main()
{
	DataPrecisa dtp;
	int dia, mes, ano, hora, min, seg;
	while(std::cin >> dia >>  mes >> ano >> hora >> min >> seg)
	{
		dtp.setDia(dia);
		dtp.setMes(mes);
		dtp.setAno(ano);
		dtp.setHora(hora);
		dtp.setMinuto(min);
		dtp.setSegundo(seg);
		dtp++;
		std::cout << dtp.getDia() << " " << dtp.getMes() << " " << dtp.getAno() << " " << dtp.getHora() << " " << dtp.getMinuto() << " " << dtp.getSegundo() << std::endl;
	}
	return 0;
}

/*
int main()
{
	Relogio rel;
	int h, m, s;
	while(std::cin >> h >> m >> s)
	{
		rel.setHora(h);
		rel.setMinuto(m);
		rel.setSegundo(s);
		for(int i=0; i<10; i++)
		{
			rel.incrementa();
			std::cout <<  rel.getHora() << " " << rel.getMinuto() << " " << rel.getSegundo() << std::endl;
		}
	}
	return 0;
}
*/
/*
int main()
{
	Data data;
	int dia, mes, ano;
	while(std::cin >> dia >> mes >> ano)
	{
		data.setDia(dia);
		data.setMes(mes);
		data.setAno(ano);
		for(int i=0; i<10; i++)
		{
			data.incrementa();
			std::cout <<  data.getDia() << " " << data.getMes() << " " << data.getAno() << std::endl;
		}
	}
	return 0;
}
*/
