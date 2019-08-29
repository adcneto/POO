#include <iostream>


class Data{
    private:
        int ano, mes, dia;
    public:
        Data();;
        Data(int, int, int, int)
        
        int getAno();
        void setAno(int);
        int getMes();
        void setMes(int);
        int getDia(int);
        void setDia(int);
        
        bool bissexto();
        bool isValida();
        
        void incrementa();
        void decrementa();
};
