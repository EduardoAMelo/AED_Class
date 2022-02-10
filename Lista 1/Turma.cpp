#include <iostream>
#include <string>
#define SIZE 2

using namespace std;

class Alunos{
	string nome, curso;
	int matricula, nota, faltas;
	
	public:
		Alunos(){//valores iniciais
			nome = " ";
			curso = " ";
			matricula = 0;
			faltas = 0;
			nota = 0;
		}
		
	//Settar strings
		void setName(string nam){
			nome = nam;
		}
		void setMat(int mat){
			matricula = mat;
		}
		void setCur(string cur){
			curso = cur;
		}
		void setResultado(int fal, int nta){
			nota = nta;
			faltas = fal;
		}
	
	//Print do resultado
		void print(){
			cout << "Aluno: " << nome << '\n'
				 << "Matricula: " << matricula << '\n'
				 << "Nota: " << nota << '\n'
				 << "Faltas: " << faltas << '\n'
				 << "Curso: " << curso << '\n' << endl;
		}		
		
};

int main(){
	Alunos turma[SIZE];
	string name, curso;
	int matricula, nota, faltas;
	
	//loop para settar alunos
	for (int i = 0; i < SIZE; i++) {
    	cout << "Digite o nome do aluno(" << i+1 << "): ";
    	cin >> name;

    	cout << "Digite a matricula do aluno(" << i+1 << "): ";
    	cin >> matricula;
    	
    	cout << "Digite o curso do aluno (" << i+1 << "): ";
    	cin >> curso;
    	
    	cout << "Digite as faltas e a nota do aluno (" << i+1 << "): ";
    	cin >> faltas >> nota;

    	turma[i].setName(name);
    	turma[i].setMat(matricula);
    	turma[i].setCur(curso);
    	turma[i].setResultado(faltas, nota);
	}
		cout << '\n';
	
	//loop para print dos alunos
	for (int i = 0; i < SIZE; i++) {
    	turma[i].print();
	} 
	
		
	return 0;	
}
