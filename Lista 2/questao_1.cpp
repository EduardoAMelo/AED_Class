#include <iostream>
#include <cmath>
#include <iomanip>
#define ROW 3
#define COLUMN 2
//defines feitos para settar tamanho padrao dos arrays

using namespace std;

//criacao dos pontos
class CartesianPoint {
    public: 
        double matrix[ROW][COLUMN]; // deixei publico para uma utilizacao especifica na subclasse
        void setMatrix(double arr[ROW][COLUMN]){// settando a matriz em matrix
            for(int a = 0; a < ROW; a++) {
		        for(int b = 0; b < COLUMN; b++) {
			        matrix[a][b] = arr[a][b];
		        }
	        }
        }
};

//calculo do perimetro
class TrianglePer : public CartesianPoint {
    double perimeter;

    public:
        void setPerimeter(){ //settando perimetro
            double per, x, y, z, holder;
            //setando os segmentos de reta ab, ac, bc
            //nao preciso me preocupar com numeros negativos por estar elevado a 2
            x = sqrt(pow((matrix[0][0] - matrix[1][0]), 2) + pow((matrix[0][1] - matrix[1][1]), 2) );
            y = sqrt(pow((matrix[0][0] - matrix[2][0]), 2) + pow((matrix[0][1] - matrix[2][1]), 2) );
            z = sqrt(pow((matrix[1][0] - matrix[2][0]), 2) + pow((matrix[1][1] - matrix[2][1]), 2) );
            per = x + y + z; //juncao de tudo
            perimeter = per;//settando em perimetro
        }

        double getPerimeter(){
            return perimeter;//retorno para cout na funcao main
        }



};

int main() {
    TrianglePer triangle;
    double matrix[ROW][COLUMN];

//insercao de inputs para criacao da matriz
    for(int a = 0; a < ROW; a++) {
        cout << "Insira os valores do ponto (" << a+1 << "): ";
		for(int b = 0; b < COLUMN; b++) {
			cin >> matrix [a][b];
		}
	}
    
    //chamada dos metodos das classes
    triangle.setMatrix(matrix);
    triangle.setPerimeter();
    cout << setprecision(2) << fixed // setprecision para valores melhores
         << triangle.getPerimeter() << endl;


    return 0;
}