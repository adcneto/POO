#include <iostream>
//#include <stdexcept>

class ArrayOutOfBoundsException : public std ::runtime_error
{
    public : 
    ArrayOutOfBoundsException(): runtime_error("runtime error: indice fora dos limites do vetor.")
    {    }
};

void imprime(int indx, int* vec, int tam){
    if(indx < 0 || indx >= tam ){
            throw ArrayOutOfBoundsException();
        }
        else{
            std :: cout << vec[indx] << std :: endl;
        }

}

int main(){

    int tam, val, indx;

    std :: cin >> tam;
    int vec[tam];

    for(int i=0; i< tam ; i++){
        std :: cin >> val;
        vec[i] = val;

    }

    while(std :: cin >> indx){
        try{
            imprime(indx, vec, tam);     
        }
        catch(ArrayOutOfBoundsException e)
        {
            std :: cout << e.what() << std :: endl;
        }      
        
        
    }



    return 0;
}