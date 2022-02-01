#include <iostream>
#include <string>
#define SIZE 2

using namespace std;

class Garage{
	string nome, marca, cor, placa;
	int telefone;
	
	public:
		Garage(){//valores iniciais
			nome = "";
			marca = "";
			cor = "";
			telefone = 0;
			placa = "";
		}
		
	//Settar strings
		void setUser(string name, int tel){
			nome = name;
			telefone = tel;
		}
		void setCarro(string brand, string color, string plate){
			marca = brand;
			cor = color;
			placa = plate;
		}
	
	//Print do resultado
		void print(){
			cout << "Nome: " << nome << '\n'
				 << "Telefone: " << telefone << '\n'
				 << "Marca: " << marca << '\n'
				 << "Cor: " << cor << '\n'
				 << "Placa: " << placa << '\n' << endl;
		}		
		
};

int main(){
	Garage Zeca[SIZE];
	string name, brand, color, plate ;
	int tel;
	
	//settar motorista
	for (int i = 0; i < SIZE; i++) {
    	cout << "Digite o nome do motorista(" << i+1 << "): ";
    	cin >> name;

    	cout << "Digite o telefone do motorista(" << i+1 << "): ";
    	cin >> tel;
    	
    	cout << "Digite a marca do veiculo do motorista (" << i+1 << "): ";
    	cin >> brand;
    	
    	cout << "Digite a placa e a cor do motorista(" << i+1 << "): ";
    	cin >> plate >> color;

    	Zeca[i].setUser(name, tel);
    	Zeca[i].setCarro(brand, color, plate);
	}
		cout << '\n';
	
	//prints 
	for (int i = 0; i < SIZE; i++) {
    	Zeca[i].print();
	} 
	
		
	return 0;	
}
