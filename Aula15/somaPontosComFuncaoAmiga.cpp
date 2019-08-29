#include <iostream>

class Ponto
{
	private:
		int x, y;
	public:
		Ponto()
		{	}
		
		Ponto(int x, int y)
		{
			this->setX(x);
			this->setY(y);
		}

		void setX(int x)
		{
			this->x = x;
		}

		void setY(int y)
		{
			this->y = y;
		}

		int getX()
		{
			return this->x;
		}

		int getY()
		{
			return this->y;
		}

		Ponto operator+(Ponto p)
		{
			return Ponto(this->getX()+p.getX(), this->getY()+p.getY());
		}

		Ponto operator+(int c)
		{
			return Ponto(this->getX()+c, this->getY()+c);
		}

		//friend Ponto operator+(int, Ponto);
};

Ponto operator+(int c, Ponto p)
{
	return Ponto(p.getX()+c, p.getY()+c);
}

int main()
{
	Ponto p(10, 5), q(2, 4), resul, resul2, resul3;
	
	resul = p + q;
	std::cout << "resul: (" << resul.getX() << ", " << resul.getY() << ")" << std::endl;

	resul2 = p + 5;
	std::cout << "resul2: (" << resul2.getX() << ", " << resul2.getY() << ")" << std::endl;

	resul3 = 5 + p;
	std::cout << "resul3: (" << resul3.getX() << ", " << resul3.getY() << ")" << std::endl;

	return 0;
}
