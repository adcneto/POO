#include <iostream>

struct tData{

	int dia;
	int mes;
	int ano;

};

//typedef struct tAluno tAluno;
struct tAluno{
	std::string nome;
	std::string matricula;
	struct tData dtNascimento;
	float notas[3];	

};

void mergeSort(struct tAluno*, int, int);

void merge(struct tAluno*, int, int, int);

int main(){
	int n;
	std::cin >> n;
	struct tAluno *vetAlu = new tAluno[n];
	
	for (int i=0; i<n; i++){
		std::cin >> vetAlu[i].nome;
		//std::cin >> vetAlu[i].matricula;
		std::cin >> vetAlu[i].dtNascimento.dia;
		std::cin >> vetAlu[i].dtNascimento.mes;
		std::cin >> vetAlu[i].dtNascimento.ano;
		std::cin >> vetAlu[i].notas[0];
		std::cin >> vetAlu[i].notas[1];
		std::cin >> vetAlu[i].notas[2];	
		
	}
	
	mergeSort(vetAlu, 0, n-1);
	
	

	for (int i=n-1; i>=0; i--){
        std::cout << "\nnome: " <<vetAlu[i].nome;
		std::cout << ' ' << vetAlu[i].dtNascimento.dia;
		std::cout << '/' <<vetAlu[i].dtNascimento.mes;
        std::cout << '/' <<vetAlu[i].dtNascimento.ano << std::endl;
		std::cout << "nota1: " << vetAlu[i].notas[0] << ' ';
		std::cout << "nota2: " << vetAlu[i].notas[1] << ' ';
		std::cout << "nota3: " << vetAlu[i].notas[2] << std::endl;
		std::cout << "media: " << (vetAlu[i].notas[2] + vetAlu[i].notas[1] + vetAlu[i].notas[2])/3.f << std::endl;
        std::cout << "------------------------------------"<< std::endl;
    }
   
    delete[] vetAlu;
  
    

	
	return 0;

}


void mergeSort(struct tAluno *vetAlu, int lo, int hi){
    if(hi>lo){
        int mid = lo + (hi-lo)/2;
        mergeSort(vetAlu,lo, mid);
        mergeSort(vetAlu, mid+1, hi);
        merge(vetAlu, lo, mid, hi);

    }
}


void merge(struct tAluno *vetAlu, int lo, int mid, int hi){
    int i= lo, j=mid+1, k=0;
    tAluno  aux[hi-lo +1];
    while(i<=mid && j<=hi){
        float media_i = (vetAlu[i].notas[2]+vetAlu[i].notas[1]+vetAlu[i].notas[2])/3.f;
        float media_j = (vetAlu[j].notas[2]+vetAlu[j].notas[1]+vetAlu[j].notas[2])/3.f;
        if(media_i < media_j)
            aux[k++] = vetAlu[i++];
        else
             aux[k++] = vetAlu[j++];
    }
    
    for(;i<=mid; i++) aux[k++] = vetAlu[i];
    for(;j<=hi; j++) aux[k++] = vetAlu[j];
    
    for(i=lo, k=0; i<=hi; i++) vetAlu[i]=aux[k++];

}
