#include <iostream>


class Ponto{
	private:
		float x, y;
	public:
		Ponto();
		Ponto(float, float);
		float getX() const;
		float getY() const;
		void setX(float);
		void setY(float);

};



class Bola{
	private:
		float peso, diametro;
		Ponto posicao;
	public:
		static float gravidade;
		Bola();
                Bola(Ponto, float, float);
		Bola(float, float);
		static void FormatoBolaDoQuico();
                float getPeso() const;
                float getDiametro() const;
		float getGravidade();
		Ponto getPosicao() const;
                void setPosicao(Ponto);
		void setPeso(float);
		void setDiametro(float);
};

Ponto::Ponto(){ }

Ponto::Ponto(float x, float y){
	this->setX(x);
	this->setY(y);
}

float Ponto::getX()const{
	return this->x;
}

float Ponto::getY()const{
	return this->y;
}

void Ponto::setX(float x){
	this->x = x;
}

void Ponto::setY(float y){
	this->y = y;
}



float Bola::gravidade = 10.0f;

Bola::Bola(){ }

Bola::Bola(float peso, float diametro){
	this->setPeso(peso);
	this->setDiametro(diametro);
	this->setPosicao(Ponto(0,0));
}

Bola::Bola(Ponto posicao, float peso, float diametro){
        this->setPeso(peso);
        this->setDiametro(diametro);
        this->setPosicao(posicao);
}

float Bola::getPeso() const{
	return this->peso;
}

float Bola::getDiametro() const{
	return this->diametro;
}

Ponto Bola::getPosicao() const{
	return this->posicao;
}

float Bola::getGravidade(){
	return this->gravidade;
}

void Bola::setPosicao(Ponto posicao){
	this->posicao = posicao;
}

void Bola::setPeso(float peso){
	this->peso = peso;
}

void Bola::setDiametro(float diametro){
	this->diametro = diametro;
}

void Bola::FormatoBolaDoQuico(){
	std::cout << "A BOLA DO QUICO É QUADRADA!!! KKKK"<<std::endl;
}


int main(){
	Bola jabulani(230, 45), brazuca(Ponto(12.32f, 21.43f), 225, 48);
	std::cout << "Jabulani ";
	std::cout << "Gravidade: " << jabulani.getGravidade() << std::endl;
	std::cout << "Brazuca ";
	std::cout << "Gravidade: " << brazuca.getGravidade() << std::endl;
	jabulani.gravidade = 15;
	std::cout << "Jabulani ";
	std::cout << "Gravidade: " << jabulani.getGravidade() << std::endl;
	std::cout << "Brazuca";
	std::cout << "Gravidade:" << brazuca.getGravidade() << std::endl;
	Bola::FormatoBolaDoQuico();
	
	return 0;

}
