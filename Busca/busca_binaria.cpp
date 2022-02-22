#include <iostream>
using namespace std;

int main(){
	int *A;
	int m, v, i, j, x, L, R, prov;	
	bool achou;

//-----------------------------------------------Preencher o vetor-----------------------------------------------------------------------
	cout << "selecione quanto numeros pretende colocar: \n";
	cin >> v;
	A = new int[v];
	
	for(i=0 ; i<v ; i++){
		cout << "digite o numero que pretende colocar na posicao " << i << ": \n";
		cin >> j; 	// o usu�rio vai preencher o vetor com os numeros que desejar
		A[i] = j;
	}
	cout << endl;
	
	for (i=0 ; i<v ; i++){			//processo de ordena��o para a execu��o da busca bin�ria
			for(j=1 ; j < (v-i) ; j++ ){
				if(A[i] > A[i + j]){
					prov = A[i+j];
					A[i+j] = A[i];
					A[i] = prov;
				}
			}
		}
	
//-----------------------------------------------Preencher o vetor-----------------------------------------------------------------------

//-----------------------------------------------Busca bin�ria---------------------------------------------------------------------------

	cout << "qual numero deseja procurar?:\n";
	cin>>x;

	L=0;
	R=v-1;
	achou = false;
	
	while((L<=R) && (achou==false)){
		
		if((R-L)%2 == 0){		//metodo para estabelecer m sempre entre L e R
			m=((R-L)/2) + L;
		}else{
			m =((R-L+1)/2) + L;
		}
		
		for(i=0 ; i<v ; i++){
		cout << "[ " << A[i] << " ]";
		
		if(i==L){
			cout<< "<-- L";
		}
		
		if(i==R){
			cout<< "<-- R";
		}
		
		if(i==m){
			cout<< "<-- m";
		}
		
		cout << endl;
		}
		
		system("PAUSE");
		
		if(A[m] == x){
			achou = true; // caso A[m] seja igual ao valor requisitado a perquisa acaba
		}
		if(A[m] < x){
			L = m+1;
		}
		if(A[m] > x){
			R = m-1;
		}
		
		
		for(i=0 ; i<v ; i++){
		cout << "[ " << A[i] << " ]";
		
		if(i==L){
			cout<< "<-- L";
		}
		
		if(i==R){
			cout<< "<-- R";
		}
		
		if(i==m){
			cout<< "<-- m";
		}
		
		cout << endl;
		}
		
		system("PAUSE");
		
	}


	
	if(achou==true){
		cout << "\no numero "<< x <<" foi encontrado";	//condi��o para caso o numero digitado for encontrado
	}
	if(achou==false){
		cout <<"\n" << x << " nao foi encontrado\n";	//condi��o para caso o numero digitado n�o for encontrado
	}


	return 0;
}