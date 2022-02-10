#include <iostream>
#include <string>
#define ARRSIZE 20

using namespace std;

class Pessoa{
    string nome;
    int idade, altura;

    public:
        void cadastrarPessoa(){//settar pessoa
            cout << "Digite nome, idade e altura, separados por espaco: ";
            cin >> nome >> idade >> altura;
        }

        void deletarPessoa(){//deletar pessoa
            nome = "";
            idade = NULL;
            altura = NULL;
        }


        void listarPessoas(){//listar pessoa
            cout << "Nome:" << nome
                 << "\nIdade: " << idade
                 << "\nAltura: " << altura << endl;
        }

        string getPessoa(){//get pessoa
            return nome;
        }
};


int main(){
    Pessoa total[ARRSIZE];
    int aux, contador, id;
    contador = 0;
    //Menu de opções
    while(4){
        cout << "1- Cadastrar" << endl;
        cout << "2- Listar" << endl;
        cout << "3- Deletar " << endl;
        cout << "4- Sair" << endl;
        cin >> aux;
        switch (aux)
        {
        case 1://cadrasto
            total[contador].cadastrarPessoa();
            contador++;
            break;


        case 2://listar
            for(int i = 0; i < contador; i++){
                total[i].listarPessoas();
                cout << '\n';
            }
            break;


        case 3://deletar
                for(int i = 0; i < contador; i++){
                        cout <<"Pessoa(" << i << "): " << total[i].getPessoa() << endl;
                    }
                    cout << "selecione o usuario pelo ID: ";
                    cin >> id;

                    total[id].deletarPessoa();
            break;


        case 4://sair
            exit(4);
            break;
        }
    }

    system("pause");
    return 0;
}