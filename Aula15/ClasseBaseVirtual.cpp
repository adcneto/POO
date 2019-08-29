#include <iostream>

class ClasseA
{
    public:
        int a, b, c;
        ClasseA() {
            std::cout<<"Classe A"<<std::endl;
        }
};
class ClasseB : virtual public ClasseA
{
    public:
        int d, e, f;
        ClasseB() {
            std::cout<<"Classe B"<<std::endl;
        }
};
class ClasseC : virtual public ClasseA
{
    public:
        int g, h, i;
        ClasseC() {
            std::cout<<"Classe C"<<std::endl;
        }
};

class ClasseD : public ClasseC, public ClasseB
{
    public:
        int j, k, l;
        ClasseD() {
            std::cout<<"Classe D"<<std::endl;
        }
};
/*
COM A DEFINICAO DE ClasseD ACIMA, TEMOS O SEGUINTE OUTPUT:
Classe A
Classe C
Classe B
Classe D
*/


/*======================================================================
COM A SEGUINTE DEFINICAO:                                               |
class ClasseD : public ClasseB, public ClasseC                          |
{                                                                       |
    public:                                                             |
        int j, k, l;                                                    |
        ClasseD() {                                                     |
            std::cout<<"Classe D"<<std::endl;                           |
        }                                                               |
};                                                                      |
                                                                        |
TERIAMOS O SEGUINTE OUTPUT:                                             |
Classe A                                                                |
Classe B                                                                |
Classe C                                                                |
Classe D                                                                |
=======================================================================*/

int main()
{
    ClasseD objD;
    objD.a = 10;
    
    return 0;
}
