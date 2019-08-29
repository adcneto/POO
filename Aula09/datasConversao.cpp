#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class DataJuliana{
	private:
		int diaJuliano;
	public:
		DataJuliana();
                DataJuliana(int);
                void setDiaJuliano(int);
                int getDiaJuliano();
};

class DataGregoriana{
	private:
		int dia, mes, ano;
	public:
		DataGregoriana();
		DataGregoriana(int, int, int);
		DataGregoriana(DataJuliana);
		void setDia(int);
		void setMes(int);
		void setAno(int);
		int getDia();
		int getMes();
		int getAno();
		operator DataJuliana();
};

DataJuliana::DataJuliana(){ };

DataJuliana::DataJuliana(int diaJuliano){
	this->setDiaJuliano(diaJuliano);
}

void DataJuliana::setDiaJuliano(int diaJuliano){
        this->diaJuliano = diaJuliano;

}   

int DataJuliana::getDiaJuliano(){
	return this->diaJuliano;
}


DataGregoriana::DataGregoriana(){ };

DataGregoriana::DataGregoriana(int dia, int mes, int ano){
        this->setDia(dia);
        this->setMes(mes);
        this->setAno(ano);
}

//Casting via construtor
DataGregoriana::DataGregoriana(DataJuliana dj){
	int jd, q, z, w, x, a, b, c, d, e, f, dia, mes, ano;
   	
	jd = dj.getDiaJuliano();
   
	q = jd + 0.5;
	z = q;
	w = (z - 1867216.25)/36524.25;
	x = w/4;
	a = z+1+w-x;
	b = a+1524;
	c = (b-122.1)/365.25;
	d = 365.25*c;
	e = (b-d)/30.6001;
	f = 30.6001*e;
	dia = b-d-f+(q-z);
	mes = e<=12?e-1:e-13;
	ano = mes<3?c-4715:c-4716;
	
	this->setDia(dia);
	this->setMes(mes);
	this->setAno(ano);


}

void DataGregoriana::setDia(int dia){
        this->dia = dia;

}       

void DataGregoriana::setMes(int mes){
        this->mes = mes;

}   

void DataGregoriana::setAno(int ano){
        this->ano = ano;

}

int DataGregoriana::getDia(){
        return this->dia;
}

int DataGregoriana::getMes(){
        return this->mes;
}

int DataGregoriana::getAno(){
        return this->ano;
}


//casting via operator (de dataGregoriana para dataJuliana)
DataGregoriana::operator DataJuliana(){
	int dia, mes, ano, a, b, c, d, e, dj;
   	DataJuliana dtJu;

	dia = this->getDia();
	mes = this->getMes();
	ano = this->getAno();
   
	if(mes < 3){
		ano--;
		mes+=12;
	}
   
	a = ano/100;
	b = a/4;
	c = 2-a+b;
	d = 365.25*(ano+4716);
	e = 30.6001 * (mes+1);
	dj = d+e+dia+0.5+c-1524.5;

	dtJu.setDiaJuliano(dj);
	return dtJu;

}


int main(){
	DataGregoriana dtN(20, 2, 1943), dtD(23, 8, 2019), dtg, dt;
	DataJuliana dtHoje(2458669), dtj1, dtj2, dtj;
	
	dtj1 = dtN;
	dtj2 = dtD;
	
	cout << (dtj2.getDiaJuliano()-dtj1.getDiaJuliano()) << endl;
	dtj = dt;
	dtg = dtHoje;

	cout << dtj.getDiaJuliano() << endl;
	cout << dtg.getDia() << " " << dtg.getMes() << " " << dtg.getAno() << endl;
	return 0;
}
