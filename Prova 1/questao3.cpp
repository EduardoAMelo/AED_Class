#include <iostream>
#include <string>
#define ARRSIZE 40

using namespace std;

class Aluno(){
    double prova1, prova2, prova3, projeto;

    public:
        double lista1, lista2, lista3, lista4;
        string nome, curso;
        int matricula;

        void cadastrarAluno(){//cadastro

           cout << "Digite nome, curso e matricula, separados por espaco: ";
            cin >> nome >> curso >> matricula;            
        }

        void listarAluno(){//listar
            cout << "Nome:" << nome
                 << "\nCurso: " << curso
                 << "\nAltura: " << matricula << endl;
        }
}


int main(){
    Aluno teste[ARRSIZE];
    int aux, contador;

    contador = 0
    //Menu de opções
    while(4){
        cout << "1- Cadastrar aluno:" << endl;
        cout << "2- Listar alunos" << endl;
        cout << "3- Media do aluno" << endl;
        cout << "4- sair" << endl;
        cin >> aux;
        switch (aux)
        {
        case 1:
            teste[contador].;
            contador++;
            break;


        case 2:
            /* code */
            break;


        case 3:
            /* code */
            break;


        case 4:
            /* code */
            break;

            
        case 5:
            exit(5);
            break;
        }
    }

    system("pause");
    return 0;
}