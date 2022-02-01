#include <iostream>
#include <cmath>

using namespace std;

class Math{
	double c_sphere, a_sphere, la_cube, ta_cube, v_cube, raio, lateral;
	
	public:
	//sets de informações para calculos
		void setRaio(double r_circle){
			raio = r_circle;
			sphere();
		}
		
		
		void setLateral(double l_cube){
			lateral = l_cube;
			cube();
		}
		
		
	//função print	
		void print(){
			cout << "Circuferencia(comprimento): " << c_sphere << "pi" << '\n'
				 << "Circuferencia(area): " << a_sphere << "pi" << '\n'
				 << "Area lateral (cubo): " << la_cube << '\n'
				 << "Area total (cubo): " << ta_cube << '\n'
				 << "Volume cubo: " << v_cube << '\n' << endl;
		}
		
		
	private://calculos para esfera e cubo usando os valores setados no publico
		void sphere(){
			c_sphere = 2 * raio;
			a_sphere = pow(raio,2);
		}
	
		void cube(){
			la_cube = pow(lateral, 2);
			ta_cube = la_cube * 6;
			v_cube = pow(lateral, 3);
		}
};


int main(){
	Math counts;
	double raio, lateral;
	
	//interação com o usuario
	cout << "Digite raio do circulo: ";
	cin >> raio;
	cout << "Digite lado do cubo: ";
	cin >> lateral;
	
	counts.setRaio(raio);
	counts.setLateral(lateral);

	//print
	counts.print();
	
	
	return 0;
}
