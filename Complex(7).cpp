#include <iostream>
#include <complex>
#include <cmath>
#define SIZE 2

using namespace std;

class Complex{
	double soma[SIZE], sub[SIZE], mult[SIZE], div[SIZE];
	
	public:
		//logica soma
		void sum(double re_1, double re_2, double im_1, double im_2){
			re_1 += re_2;//real
			for(int i = 0; i < SIZE; i++){// loop feito apenas para separar parte imaginaria da real no array
				soma[i] = re_1;
				re_1 = im_1 + im_2;//imaginario
			}
			if(soma[1] < 0)
				cout << soma[0] << soma[1] << "i" << endl;
			else
				cout << soma[0] << " + " << soma[1] << "i" << endl;
		}
		
		//logica subtra��o
		void subt(double re_1, double re_2, double im_1, double im_2){
			re_2 *= -1;//corretor do resultado
			im_2 *= -1;
			re_1 += re_2; //real
			for(int i = 0; i < SIZE; i++){// loop feito apenas para separar parte imaginaria da real no array
				sub[i] = re_1;
				re_1 = im_1 + im_2; //imaginario
			}
			if(sub[1] < 0)
				cout << sub[0] << sub[1] << "i" << endl;
			else
				cout << sub[0] << " + " << sub[1] << "i" << endl;	
		}
		
		//logica multiplicacao
		void multi(double a, double c, double b, double d){
			double holder = (a*c - b*d);//real
			for(int i = 0; i < SIZE; i++){// loop feito apenas para separar parte imaginaria da real no array
				mult[i] = holder;
				holder = (a*d + b*c);//imaginario
			}
			if(mult[1] < 0)
				cout << mult[0] << mult[1] << "i" << endl;
			else
				cout << mult[0] << " + " << mult[1] << "i" << endl;
			
		}
		
		//logica divisao
		void division(double a, double c, double b, double d){
            double holder;
            if(c == 0){//logica quando o divisor e imaginario puro
                holder = (b*d / pow(d,2));//real
                for(int i = 0; i < SIZE; i++){// loop feito apenas para separar parte imaginaria da real no array
                    div[i] = holder;
                    holder = (a*d / pow(d,2));//imaginario
                }
            }
            else{//logica funcional para todo o resto
                holder = ((a*c + b*d) / (pow(c,2) + pow(d,2)));//real
                for(int i = 0; i < SIZE; i++){// loop feito apenas para separar parte imaginaria da real no array
                    div[i] = holder;
                    holder = ((b*c - a*d) / (pow(c,2) + pow(d,2)));//imaginario
                }
            }
			if(div[1] < 0)//corretor do cout caso parte imaginaria seja negativa
				cout << div[0] << div[1] << "i" << endl;
			else//corretor cout imaginario positivo
				cout << div[0] << " + " << div[1] << "i" << endl;
			 
		}

/*
Nao tinha certeza sobre o tipo de retorno 
"pois so conheco o trigonometrico do fundamental" entao
utilizei o retorno da biblioteca "cmath" com a "complex"
 */
        void poten(double re_1, double im_1){
            cout << std::complex<double>(re_1, im_1) * std::complex<double>(re_1, im_1) << endl;
        }
        
        void raizs(double re_1, double im_1){
            cout << sqrt(std::complex<double>(re_1, im_1))<< endl;
        }
        
};


int main(){
	Complex complexos;
    int escolha;
	double re_1, re_2, im_1, im_2;

//primeira escolha	
	cout << "Escolha o tipo de conta a fazer:\n" 
         << "1-Soma\n" << "2-Subtracao\n" << "3-Multiplicacao\n" 
         << "4-Divisao\n" << "5-Potencia\n" << "6-Raiz\n" << "Digite: ";
	cin >> escolha;

    while(escolha < 0 | escolha > 6){
        cout << "valor invalido, insira outro: ";
        cin >> escolha;
    }

//loop para utilizar o programa varias vezes
    while((escolha > 0) && (escolha <= 6)){
        switch (escolha)
        {
        case 1:
            cout << "Numeros complexos (reais 1 e 2) e (imaginarios 1 e 2): ";
            cin >> re_1 >> re_2 >> im_1 >> im_2;
            complexos.sum(re_1, re_2, im_1, im_2);
            break;
        case 2:
            cout << "Numeros complexos (reais 1 e 2) e (imaginarios 1 e 2): ";
            cin >> re_1 >> re_2 >> im_1 >> im_2;
            complexos.subt(re_1, re_2, im_1, im_2);
            break;
        case 3:
            cout << "Numeros complexos (reais 1 e 2) e (imaginarios 1 e 2): ";
            cin >> re_1 >> re_2 >> im_1 >> im_2;
            complexos.multi(re_1, re_2, im_1, im_2);
            break;
        case 4:
            cout << "Numeros complexos (reais 1 e 2) e (imaginarios 1 e 2): ";
            cin >> re_1 >> re_2 >> im_1 >> im_2;
            complexos.division(re_1, re_2, im_1, im_2);
            break;
        case 5:
            cout << "Numero complexo: ";
            cin >> re_1 >> im_1;
            complexos.poten(re_1, im_1);
            break;
        case 6:
            cout << "Numero complexo: ";
            cin >> re_1 >> im_1;
            complexos.raizs(re_1, im_1);
            break;
        }
        //nao coloquei o default pois o switch nunca vai ter um valor fora do previsto
        //condicao de repeticao do loop sendo decidida pelo usuario
        cout << "Escolha o tipo de conta a fazer:\n" 
             << "1-Soma\n" << "2-Subtracao\n" << "3-Multiplicacao\n" 
             << "4-Divisao\n" << "5-Potencia\n" << "6-Raiz\n" << "7-Sair\n" << "Digite: ";
	    cin >> escolha;
    }
    
    return 0;

}
