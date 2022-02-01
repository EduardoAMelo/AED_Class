#include <iostream>
#include <string>
#define SIZE 2
 
using namespace std;

class Agenda{
	string nome;
	int telefone;
	
	public:
		Agenda(){//valores iniciais
			nome = "";
			telefone = 0;
		}
		//sets do programa
		void setTelefone(int tel){
			telefone = tel;
		}
	
		void setNome(string name){
			nome = name;
		}
		//funcao print do programa
		void print(){
			cout << "Nome: " << nome << '\n'
				 << "Telefone: " << telefone << '\n' << endl;
		}
};


int main(){
	Agenda telefonica[SIZE];
	string name;
	int telefone;
	
	//loop para digitar o nome e telefone de SIZE contatos
	for (int i = 0; i < SIZE; i++) {
    	cout << "Digite o nome do contato(" << i+1 << "): ";
    	cin >> name;

    	cout << "Digite o numero do contato(" << i+1 << "): ";
    	cin >> telefone;
    	
    	telefonica[i].setNome(name);
    	telefonica[i].setTelefone(telefone);
	}
	//pro cout ficar bonito
	cout << '\n';

	//prints	
    for (int i = 0; i < SIZE; i++) {
    	telefonica[i].print();
	} 
	
	return 0;

}
