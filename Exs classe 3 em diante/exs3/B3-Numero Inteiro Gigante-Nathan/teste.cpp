#include <iostream>



int main(){
    std::string big_num1, big_num2;
    std::cin >> big_num1 >> big_num2;
    
    int i= big_num1.length(), j = big_num2.length();


    std::string str_resultante;

    
    int n1, n2, carry=0, soma_digitos;
 
/*   
    do{
    
        n1 = big_num1[i-1] -48;
        n2 = big_num2[j-1] -48;
        
        soma_digitos = (n1+n2+carry)%10;
        str_resultante = (char)(soma_digitos + 48) + str_resultante;

        std::cout << str_resultante << std::endl;

        carry= (n1+n2+carry)/10;

        i--;
        j--;
       
    }while (j>0 && i>0);
*/    

 /*   
    for(;j>0; j--){
        n2 = big_num2[j-1] -48;
        soma_digitos = (n2+carry)%10;
        
        str_resultante = (char)(soma_digitos + 48) + str_resultante;
        carry = (n2+carry)/10;;

    }

    for (;i>0; i--){
        n1 = big_num1[i-1] -48;
        soma_digitos = (n1+carry)%10;
        
        str_resultante = (char)(soma_digitos + 48) + str_resultante;
        carry= (n1+carry)/10;;
    }
    
 */
 
    for(;j>0 || i>0; j--, i--){
        j>0 ? (n2 = big_num2[j-1] -48) : (n2= 0);
        i>0 ? (n1 = big_num1[i-1] -48) : (n1=0);
        soma_digitos = (n2+n1+carry)%10;
        
        str_resultante = (char)(soma_digitos + 48) + str_resultante;
        carry = (n2+n1+carry)/10;;

    }
    
    if((j==0 && i==0) &&(carry==1)) 
        str_resultante = "1" + str_resultante; 
    
    while (str_resultante[0] == '0'){
        str_resultante.erase(0,1);
        
    } 


    std::cout << str_resultante << std::endl;
    

    return 0;
    
    
}
