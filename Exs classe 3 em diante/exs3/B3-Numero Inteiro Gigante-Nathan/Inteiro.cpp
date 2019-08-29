#include <iostream>
//nova versão
struct tInteiro
{
	std::string numero;
};
struct tInteiro inteiro (std::string num);
struct tInteiro soma (struct tInteiro i1, struct tInteiro i2);
struct tInteiro mult (struct tInteiro i1, struct tInteiro i2);
struct tInteiro sub (struct tInteiro i1, struct tInteiro i2);
int passar (int num);
int pegar1 (int num);
std::string qzero (int k);
std::string rzero(std::string s);
int main()
{

	std::string sa;
	while (std::cin >> sa) {
			std::string sb;
			char op;
			std::cin >> op >> sb;
			struct tInteiro i1, i2, i3;
			i1 = inteiro(sa);
			i2 = inteiro(sb);
	        switch (op) {
	            case '+': i3 = soma(i1, i2);
	                       break;
	            case '-': i3 = sub(i1, i2);
	                       break;
	            case '*': i3 = mult(i1, i2);
	                       break;
	        }
	        std::cout << i3.numero << "\n";

	   }

	    return 0;
}
struct tInteiro inteiro(std::string num)
{
	struct tInteiro i;
	i.numero = num;
	return i;
}
struct tInteiro soma(struct tInteiro i1, struct tInteiro i2)
{
	int aux = i1.numero.length();
	int d1 = 0;
	int d2 = 0;
	int d3 = 0;
	bool passa1 = false;
	std::string soma = i1.numero;
	int s;
	if(i1.numero.length() < i2.numero.length())
	{
			aux = i1.numero.length();
			soma = i2.numero;
			d2 = i2.numero.length() - i1.numero.length();
			d1 = 0;
			d3 = d2;
	}
	else if(i1.numero.length() > i2.numero.length())
	{
		aux = i2.numero.length();
		soma = i1.numero;
		d1 = i1.numero.length() - i2.numero.length();
		d2 = 0;
		d3 = d1;
	}
	for(int i = aux-1; i >= 0; i--)
	{
		if (passa1 == false) s = (i1.numero[i+d1] - '0') + (i2.numero[i+d2] - '0');
		else { s = (i1.numero[i+d1] - '0') + (i2.numero[i+d2] - '0') + 1; }
		if(s >= 10) { passa1 = true; s = s -10;}
		else { passa1 = false; }
		soma[i+d3] = s + '0';
	}
	int j = 1;
	while(passa1 == true)
	{
		if(d3 - j >= 0)
		{
			s = (soma[d3 - j] - '0') + 1;
			if(s >= 10) { passa1 = true; s = s -10;}
			else { passa1 = false; }
			soma[d3 - j] = s + '0';
			j++;
		}
		else
		{
			soma = "1" + soma;
			passa1 = false;
		}
	}
	return inteiro(soma);
}
struct tInteiro sub(struct tInteiro i1, struct tInteiro i2)
{
	int d1, d2, s;
	std::string sub;
	char c;
	bool tira1 = false;
	int t = 0;
	int aux;
	if(i1.numero.length() >= i2.numero.length())
	{
		d1 = i1.numero.length() - i2.numero.length();
		d2 = 0;
		sub = i1.numero;
		for(int i = i2.numero.length()-1; i >= 0; i--)
		{
			if ((i1.numero[i+d1] - '0') < (i2.numero[i+d2] - '0')) { 
			    s = (i1.numero[i+d1] - '0') - (i2.numero[i+d2] - '0') + 10 - t;
			    tira1 = true;
			    t = 1; 
			}
			else if ((i1.numero[i+d1] - '0') == (i2.numero[i+d2] - '0'))
			{
				if(t == 1) {
				    s = (i1.numero[i+d1] - '0') - (i2.numero[i+d2] - '0') - t +10;
				    tira1 = true;
				    t = 1;
				}
				else {
				    s = (i1.numero[i+d1] - '0') - (i2.numero[i+d2] - '0') - t;
				    tira1 = false;
				    t = 0;
			    }
			}
			else
			{
			 	s = (i1.numero[i+d1] - '0') - (i2.numero[i+d2] - '0') - t;
				tira1 = false;
				t = 0;
			}
			c = (s + '0');
			sub[i+d1] = c;
		}
		int j = 1;
		while (tira1 == true)
		{
			if(d1 - j >= 0)
			{
				if ((sub[d1 - j] - '0') <= 0) { s = (sub[d1 - j] - '0') + 10 - t; tira1 = true; t = 1; }
				else
				{
				 	s = (sub[d1 - j] - '0') - t;
					tira1 = false;
					t = 0;
				}
				c = (s + '0');
				sub[d1 - j] = c;
				j++;
			}
			else
			{
				tira1 = false;
			}
		}
	}
	else
	{
		d1 = i2.numero.length() - i1.numero.length();
		d2 = 0;
		sub = i2.numero;
		for(int i = i1.numero.length()-1; i >= 0; i--)
		{
			if ((i2.numero[i+d1] - '0') < (i1.numero[i+d2] - '0')) { s = (i2.numero[i+d1] - '0') - (i1.numero[i+d2] - '0') + 10 - t; tira1 = true; t = 1; }
			else if ((i1.numero[i+d1] - '0') == (i2.numero[i+d2] - '0'))
			{
				if(t == 1) { s = (i2.numero[i+d1] - '0') - (i1.numero[i+d2] - '0') - t +10; tira1 = true; t = 1; }
				else { s = (i2.numero[i+d1] - '0') - (i1.numero[i+d2] - '0') - t; tira1 = false; t = 0; }
			}
			else
			{
			 	s = (i2.numero[i+d1] - '0') - (i1.numero[i+d2] - '0') - t;
				tira1 = false;
				t = 0;
			}
			c = (s + '0');
			sub[i+d1] = c;
		}
		int j = 1;
		while (tira1 == true)
		{
			if(d1 - j >= 0)
			{
				if ((sub[d1 - j] - '0') <= 0) { s = (sub[d1 - j] - '0') + 10 - t; tira1 = true; t = 1; }
				else
				{
				 	s = (sub[d1 - j] - '0') - t;
					tira1 = false;
					t = 0;
				}
				c = (s + '0');
				sub[d1 - j] = c;
				j++;
			}
			else
			{
				tira1 = false;
			}
		}
	}
	sub = rzero(sub);
	return inteiro(sub);
}
struct tInteiro mult(struct tInteiro i1, struct tInteiro i2)
{
	char c;
	int p = 0;
	int k = 0;
	struct tInteiro it;
	std::string mult = "";
	int m;
	bool passa1 = false;
	if(i1.numero == "0" || i2.numero == "0") return inteiro("0");
	else if(i1.numero == "1") return i2;
	else if(i1.numero == "1") return i1;
	if(i1.numero.length() >= i2.numero.length())
	{
		for(int i = i2.numero.length()-1; i >= 0; i--)
		{
			for(int j = i1.numero.length()-1; j >= 0; j--)
			{
				if (passa1 == false) m = (i1.numero[j] - '0') * (i2.numero[i] - '0');
				else { m = ((i1.numero[j] - '0') * (i2.numero[i] - '0')) + p; }
				if(m >= 10) { passa1 = true; p = passar(m); m = pegar1(m);}
				else { passa1 = false; p = 0; }
				c = (m + '0');
				mult = c + mult;
			}
		 if(passa1 == true)
			{
				c = (p + '0');
				mult = c + mult;
				passa1 = false;
				p = 0;
			}
			if(i == (i2.numero.length()-1))
			{		it = soma(inteiro(mult), inteiro("0")); }
			else { it = soma (it, inteiro(mult)); }
			k++;
			mult = qzero(k);
		}
	}
		else
		{
			for(int i = i1.numero.length()-1; i >= 0; i--)
			{
				for(int j = i2.numero.length()-1; j >= 0; j--)
				{
					if (passa1 == false) m = (i1.numero[i] - '0') * (i2.numero[j] - '0');
					else { m = ((i1.numero[i] - '0') * (i2.numero[j] - '0')) + p; }
					if(m >= 10) { passa1 = true; p = passar(m); m = pegar1(m);}
					else { passa1 = false; p = 0; }
					c = (m + '0');
					mult = c + mult;
				}
				if(passa1 == true)
	 			{
	 				c = (p + '0');
	 				mult = c + mult;
	 				passa1 = false;
	 				p = 0;
	 			}
				if(i == (i1.numero.length()-1))
				{		it = soma(inteiro(mult), inteiro("0")); }
				else { it = soma (it, inteiro(mult)); }
				k++;
				mult = qzero(k);
			}
		}
		return it;
	}

int pegar1 (int num)
{
	bool aux = true;
	while(aux == true)
	{
		num -= 10;

		if(num>= 10) aux = true;
		else aux = false;
	}
	return num;
}
int passar (int num)
{
	bool aux = true;
	int i = 0;
	while(aux == true)
	{
		num -= 10;

		if(num>= 10) aux = true;
		else aux = false;
		i++;
	}
	return i;
}
std::string qzero (int k)
{
	std::string zero = "";
	for(int i = 0; i < k; i++)
	{
		zero += "0";
	}
	return zero;
}
std::string rzero (std::string s)
{
	bool temzero = true;
	int i = 0;
	while(temzero)
	{
		if(s[i] == '0')
		{
			s.erase(0, 1);
		}
		else
		{
			temzero = false;
		}
	}
	return s;
}
