#include <iostream>

using namespace std;

int buscaBinariaPosicao(int *itens, int valor, int inicio, int fim){
    int meio = inicio + (fim -inicio)/2;
    //int qtdSobrando = fim-inicio+1;
    int posicao = -1;
    
    if(fim>=inicio){
        if(itens[meio] > valor)
            posicao = buscaBinariaPosicao(itens,valor,inicio, meio-1);
            
        else if(itens[meio] < valor)
            posicao = buscaBinariaPosicao(itens,valor,meio+1, fim);
            
        else 
            posicao = meio;
    }

    if(posicao ==-1)  
        posicao = inicio;


    return posicao;
}

int main(){
    int *itens = new int[8], valor, posicao;
    
    for(int i=0; i<8; i++)
        cin >>itens[i];
    
        
    while(cin >> valor){
        posicao = buscaBinariaPosicao(itens,valor,0, 7);
        cout << "A posicao em que o elemento deve ser inserido eh a: "<<posicao<<endl;
    }
    

}
