#include <iostream>
#include <string>
#define ARRSIZE 100

using namespace std;

class ContaCorrente{
    double saldo, quantia;

    public:
        string name, cpf;
        void cadastrarCliente(){
            string name_input, cpf_input;

            cout << "Digite nome e CPF, separados por espaço: ";
            cin >> name_input >> cpf_input;
            name = name_input;
            cpf = cpf_input;
            saldo = 0;
            quantia = 0;
        }


        void setDepositar(double quantia){
            saldo += quantia;
        }


        void Sacar(){//vai subtrair o valor de saldo, para testar olhe getObterSaldo
           double saque_input;
           string cpf_input;
           saque_input = 0;
           cout << "valor do saque: ";
           cin >> saque_input;
            cout << "Qual o cpf do usuario: ";
                cin >> cpf_input;

                if(cpf == cpf_input){
                    saldo -= (saque_input + (saque_input * 0.05));
                }
                else
                    cout << "CPF ERRADO!!";      
        }


        double getObterSaldo(){
            return saldo;
        }

        string getName(){
            return name;
        }

        string getCPF(){
            return cpf;
        }
};


int main(){
    ContaCorrente contas[ARRSIZE];
    int contador, aux;
    string cpf;
    int id;
    double quantia;

    contador = 0;
    //Menu de opções
    while(5){
        cout << "1- Cadastrar cliente" << endl;
        cout << "2- Depositar" << endl;
        cout << "3- Sacar" << endl;
        cout << "4- Obter saldo" << endl;
        cout << "5- Sair" << endl;
        cin >> aux;
        switch (aux)
        {
        case 1:
            contas[contador].cadastrarCliente();
            contador++;
            break;


        case 2:

            if(contador =! 0){
                for(int i = 0; i < contador; i++){
                    cout <<"Usuario(" << i << "): " << contas[i].getName() << endl;
                }
                cout << "selecione o usuario pelo ID: ";
                cin >> id;
                cout << "Qual o cpf do usuario: ";
                cin >> cpf;

                if(cpf == contas[id].getCPF()){
                    cout << "Quantia: ";
                    cin >> quantia;
                    contas[id].setDepositar(quantia);
                }
                else
                    cout << "CPF ERRADO!!";

            }
            else
                cout << "nao existem clientes!!";
            break;


        case 3:
            if(contador =! 0){
                for(int i = 0; i < contador; i++){
                    cout <<"Usuario(" << i << "): " << contas[i].getName() << endl;
                }
                cout << "selecione o usuario pelo ID: ";
                cin >> id;

                contas[id].Sacar();
            }
            else
                cout << "nao existem clientes!!";
            break;


        case 4:
            if(contador =! 0){
                for(int i = 0; i < contador; i++){
                    cout <<"Usuario(" << i << "): " << contas[i].getName() << endl;
                }
                cout << "selecione o usuario pelo ID: ";
                cin >> id;

                cout << "O saldo e: " << contas[id].getObterSaldo() << endl;
            }
            else
                cout << "nao existem clientes!!";
            break;

            
        case 5:
            exit(5);
            break;
        }
    }

    system("pause");
    return 0;
}