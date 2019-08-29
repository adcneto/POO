#include <iostream>
#include <stdexcept>



class DivException : public std::runtime_error{
    public:
        DivException():runtime_error("Nao eh possivel dividir por zero!"){ }
};

float DivisaoFloats(float a, float b) throw(DivException) {
    if(b==0){
        throw DivException();
    }
    else{
        return a/b;
    }
    
}


int main(){
    float a, b;
    std::cin >> a >> b;
    try{
        
        std::cout << "O resultado eh: " << DivisaoFloats(a,b) <<std::endl;
    }
    catch(DivException e){
        std::cout << e.what() << std::endl;
        //std::cerr << e.what() << std::endl;
    }

    return 0;
}

