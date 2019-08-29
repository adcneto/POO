
#include <iostream>

class Lista
{
	private:
			int *itens;
			int quantidade;
			int tamanho;
	public:
			Lista(int);
			~Lista();
			void setQuantidade(int);
			void setTamanho(int);
			void setItens(int, int);
			int getQuantidade();
			int getTamanho();
			int getItens(int);
			void inserir(int);
			int remover(int);
			void mostrar();
			bool isVazia();
			bool isCheia();
};

Lista::Lista(int tamanho)
{
	this->setTamanho(tamanho);
	this->setQuantidade(0);
	this->itens = new int[this->getTamanho()];
}

Lista::~Lista()
{
	delete this->itens;
}

void Lista::setQuantidade(int quantidade)
{
	this->quantidade = quantidade;
}

void Lista::setTamanho(int tamanho)
{
	this->tamanho = tamanho;
}

void Lista::setItens(int item, int posicao)
{
	this->itens[posicao] = item;
}

int Lista::getQuantidade()
{
	return this->quantidade;
}

int Lista::getTamanho()
{
	return this->tamanho;
}

int Lista::getItens(int posicao)
{
	return this->itens[posicao];
}

void Lista::inserir(int item)
{
	int posicao, proximo;
	bool achei;
	if(!this->isCheia())
	{
		achei = false;
		posicao = 0;
		while(posicao < this->getQuantidade() && !achei)
		{
			if(this->getItens(posicao) >= item)
			{
				achei = true;
				if(this->getItens(posicao) == item)
				{
					return;
				}
			}
			else
			{
				posicao++;
			}
		}
		if(achei)
		{
			for(proximo = this->getQuantidade(); proximo > posicao; proximo--)
			{
				this->setItens(this->getItens(proximo-1), proximo);
			}
		}
		this->setItens(item, posicao);
		this->setQuantidade(this->getQuantidade() + 1);
	}
}

int Lista::remover(int item)
{
	int posicao, proximo;
	bool achei;
	if(!this->isVazia())
	{
		for(achei = false, posicao = 0; posicao <  this->getQuantidade() && !achei;)
		{
			if(this->getItens(posicao) == item)
			{
				achei = true;
			}
			else
			{
				posicao++;
			}
		}
		if(achei)
		{
			for(proximo = posicao + 1; proximo < this->getQuantidade(); proximo++)
			{
				this->setItens(this->getItens(proximo), proximo-1);
			}
			this->setQuantidade(this->getQuantidade() - 1);
		}
	}
}

void Lista::mostrar()
{
	int i;
	for(i = 0; i < this->getQuantidade(); i++)
	{
		std::cout << this->getItens(i) << std::endl;
	}
}

bool Lista::isVazia()
{
	return this->getQuantidade() == 0;
}

bool Lista::isCheia()
{
	return this->getQuantidade() == this->getTamanho();
}

int main()
{
	Lista *lista;
	int q, i, chave;
	char operacao;
	
	std::cin >> q;
	lista = new Lista(q);
	for(i = 0; i < q; i++)
	{
		std::cin >> operacao >> chave;
		if(operacao == 'I')
		{
			lista->inserir(chave);
		}
		else
		{
			lista->remover(chave);
		}
	}
	lista->mostrar();
	delete lista;
	return 0;
}



