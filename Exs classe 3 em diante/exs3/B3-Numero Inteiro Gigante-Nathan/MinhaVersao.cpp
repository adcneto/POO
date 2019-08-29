#include <iostream>


struct tInteiro{

    std::string bigNum;
};


//Recebe uma cadeia de caracteres e retorna um inteiro gigante
struct tInteiro inteiro(std::string);

/*Recebe dois inteiros gigantes e retorna outro inteiro gigante 
  com a soma de ambos*/
struct tInteiro soma(struct tInteiro, struct tInteiro);

/*Recebe dois inteiros gigantes e retorna outro inteiro gigante 
  com a subtracao de ambos*/
struct tInteiro sub(struct tInteiro, struct tInteiro);

/*Recebe dois inteiros gigantes e retorna outro inteiro gigante 
  com o produto de ambos*/
struct tInteiro mult(struct tInteiro, struct tInteiro);

int tamanhoString(std::string);

int main(){

    std::string num_em_string1, num_em_string2;
    char operacao;

    while(std::cin >> num_em_string1 >> operacao >> num_em_string2){
    
        struct tInteiro big_num1, big_num2, resultado;
        
        big_num1 = inteiro(num_em_string1);
        big_num2 = inteiro(num_em_string2);
        
        if (operacao == '+'){
            resultado = soma(big_num1, big_num2);
        }
        else if(operacao == '-'){
        
            resultado = sub(big_num1, big_num2);
            
        }
        else if(operacao == '*'){
        
            resultado = mult(big_num1, big_num2);
            
        }
        std::cout << resultado.bigNum << std::endl;
        
    }
    
    std::cout << std::endl;

    return 0;
}

struct tInteiro inteiro(std::string string_recebida){
   struct tInteiro novo_big_num;
   novo_big_num.bigNum = string_recebida;
   return novo_big_num;
}


struct tInteiro soma(struct tInteiro big_num1, struct tInteiro big_num2){
    int i= big_num1.bigNum.length(), j = big_num2.bigNum.length();

    
    struct tInteiro resultado;
    
    std::string str_resultante;
    
    int n1, n2, carry=0, soma_digitos;

    for(;j>0 || i>0; j--, i--){
        j>0 ? (n2 = big_num2.bigNum[j-1] -48) : (n2= 0);
        i>0 ? (n1 = big_num1.bigNum[i-1] -48) : (n1=0);
        soma_digitos = (n2+n1+carry)%10;
        
        str_resultante = (char)(soma_digitos + 48) + str_resultante;
        carry = (n2+n1+carry)/10;;

    }
    
    if((j==0 && i==0) &&(carry==1)) 
        str_resultante = "1" + str_resultante;  
    
    while (str_resultante[0] == '0'){
        str_resultante.erase(0,1);
        
    } 

    
    
    
    resultado.bigNum = str_resultante;
    
    return resultado;

}

struct tInteiro sub(struct tInteiro big_num1, struct tInteiro big_num2){
    int i= big_num1.bigNum.length(), j = big_num2.bigNum.length();

    int maior
    struct tInteiro resultado;
    
    std::string str_resultante;
    
    int n1, n2, subtracao_digitos;

    for(;j>0 || i>0; j--, i--){
        j>0 ? (n2 = big_num2.bigNum[j-1] -48) : (n2= 0);
        i>0 ? (n1 = big_num1.bigNum[i-1] -48) : (n1=0);
        subtracao_digitos = (n2-n1)%10;
        
        str_resultante = (char)(subtracao_digitos + 48) + str_resultante;

    }
    
    while (str_resultante[0] == '0'){
        str_resultante.erase(0,1);
        
    } 
    
    resultado.bigNum = str_resultante;
    
    return resultado;
 
}

struct tInteiro mult(struct tInteiro big_num1, struct tInteiro big_num2){
    
    int i= big_num1.bigNum.length(), j = big_num2.bigNum.length();
    int tamanho_maximo = i+j;
    struct tInteiro resultado;

    return resultado;

}
