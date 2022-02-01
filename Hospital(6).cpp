#include <iostream>
#include <string>
#define SIZE 3

using namespace std;

class Blood{
	string name, blood_type;
	int tel, age;
	
	public:
		setPacient(int tel_c, int age_c, string name_c, string blood_c ){//set do paciente
			name = name_c;
			blood_type = blood_c;
			age = age_c;
			tel = tel_c;
		}
		
		 string getBlood() {//gets do programa
		 	return blood_type;
		 }
		 string getName() {
		 	return name;
		 }


};

int main(){
	Blood anchieta[SIZE];
	int tel, age;
	string name, blood_type, reciever, a;
	
	//loop para settar paciente
	for(int i = 0; i < SIZE; i++){
		cout << "nome, telefone, tipo saguineo e idade do paciente(" << i + 1 << "): ";
		cin >> name >> tel >> blood_type >> age;
		anchieta[i].setPacient(tel, age, name, blood_type);
	}
	
	//loop para localizar pacientes o-
	for(int i = 0; i < SIZE; i++){
		reciever = anchieta[i].getBlood();
		while(reciever == "o-"){
			reciever = anchieta[i].getName();
			cout << reciever  << endl;	
		}
	}
	
	return 0;
}
