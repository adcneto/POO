#include <iostream>

class Pai
{
	public:
		Pai()
		{
			std::cout << "ESTOU NO CONSTRUTOR VAZIO DE PAI\n";
		}
		Pai(int x)
		{
			std::cout << "ESTOU NO CONSTRUTOR INT ("<< x << ") DE PAI\n";
		}
};

class Filho : public Pai
{
	public:
	    Filho(){
	        std::cout << "ESTOU NO CONSTRUTOR VAZIO DE FILHO\n";    
	    }
	    
		Filho(double x)
		{
			std::cout << "ESTOU NO CONSTRUTOR DOUBLE DE FILHO\n";
		}
		
		Filho(int x):Pai(x)
		{
			std::cout << "ESTOU NO CONSTRUTOR INT DE FILHO\n";
		}
};

int main()
{
	Filho obj1, obj(666), obj2(666.0);
	return 0;
	/*
	O OUTPUT EH:
        ESTOU NO CONSTRUTOR VAZIO DE PAI
        ESTOU NO CONSTRUTOR VAZIO DE FILHO
        ESTOU NO CONSTRUTOR INT (666) DE PAI
        ESTOU NO CONSTRUTOR INT DE FILHO
        ESTOU NO CONSTRUTOR VAZIO DE PAI
        ESTOU NO CONSTRUTOR DOUBLE DE FILHO

	*/
}
