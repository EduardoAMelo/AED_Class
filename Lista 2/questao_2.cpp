#include <iostream>
#include <string>
#include <sstream>
#define ROW 1
#define COLUMN 3
#define FUNC 100
#define DERPART 10

using namespace std;

class Funcionario {
    public:
        string nome, data;
        double salario;

        //settar funcionarios
        void setFunc (int size){
            cout << "Digite nome, salario e data de admissao do funcionario (" << size <<"): ";
            cin >> nome >> salario >> data;
        }


};

class Departamento : public Funcionario {
    string name;
    int total_func_size;

    public:
        Funcionario all_func[FUNC];
        void setDepart(int size){//settar departamentos
            int func_size = 0;

            cout << "Nome do departamento(" << size + 1 << "): ";
            cin >> name;
            cout << "Numero de funcionarios: ";
            cin >> func_size;

            total_func_size += func_size;    

            
                for(int i = 0; i < func_size; i++){
                    all_func[i].setFunc(i);// loop para settagem inicial de funcionarios
                }
        }


        void setMore(){ // settar mais funcionarios
            int func_size;
            cout << "Numero de funcionarios: ";
            cin >> func_size;

            //loop para adicionar tudo
            for(int i = 0; i < func_size; i++){
                all_func[i + total_func_size].setFunc(i + total_func_size);
            }
            total_func_size += func_size; // para a contagem total de funcionarios no case 1

        }

        //para o cout do total de funcionarios
        int getFuncSize(){
            return total_func_size;
        }
};

class Empresa : public Departamento {
    string name, cnpj;
    int depart_size;

    public:
        Departamento todos[DERPART];
        void setEmpresa(string nome, string hold_cnpj, int depart){ //settando dados iniciais da empresa
            depart_size = depart;
            name = nome;
            cnpj = hold_cnpj;
            for(int i = 0; i < depart; i++){
                todos[i].setDepart(i);// loop para settar os departamentos iniciais
            }

        }


        void setMoreDep(int depart, int more){// settando mais departamentos
           for(int i = 0; i < more; i++){
                todos[i + depart - 1].setDepart(i + depart - 1);
            } 
            depart_size += more;
        }


        void setAumento(int escolha){//settando aumento de 10 porcento
            for(int i = 0; i < todos[escolha].getFuncSize(); i++){
                todos[escolha].all_func[i].salario += 0.1 * todos[escolha].all_func[i].salario;
            }
        }


        void coutEmpresa(int depart_size){ // cout de valores
            int size = 0;
            for(int i = 0; i < depart_size; i++){
                size += todos[i].getFuncSize();
            }

            cout << "Nome Empresa: " << name << '\n'
                 << "CNPJ: " << cnpj << '\n'
                 << "Numero de departamentos: " << depart_size << '\n'
                 << "Numero de funcionarios total: " << size << '\n';
        }


};

int main() {
    Empresa criador;
    string name, cnpj;
    int depart, escolha;

    cout << "Digite o nome, cnpj e numero de departamentos da empresa separados por espaco: ";
    cin >> name >> cnpj >> depart;

    criador.setEmpresa(name, cnpj, depart);

//menu
    cout << "'\n'1-Informações da empresa'\n'" 
         << "2-Adcionar mais departamentos'\n'" 
         << "3-Adicionar funcionarios a um departamento'\n'" 
         << "4- aumento 10 porcento'\n'"
         << "Escolha: ";

    cin >> escolha;
    cout << '\n';

    while(escolha < 5){
        
        switch (escolha)
        {
        case 1:
            criador.coutEmpresa(depart);//prints
            break;
        
        case 2://criação de novos departamentos
            cout << "Quantos departamentos deseja adicionar, ainda restam("
                << DERPART - depart << "): ";
            cin >> escolha;
            depart += escolha;//para aumentar o numero total para case 3
            criador.setMoreDep(depart, escolha);
            break;
        
        case 3://criação de novos funcionarios em departamentos específicos
            cout << "Qual departamento deseja adicionar, existem(" << depart << "): ";
            cin >> escolha;
            criador.todos[escolha].setMore();
            break;


        case 4:// aumentando salario
            cout << "Aumento de 10 porcento no salario de qual departamento, existem (" << depart << "): ";
            cin >> escolha;
            criador.setAumento(escolha);
            for(int i = 0; i < criador.todos[escolha].getFuncSize(); i++ )
                cout << criador.todos[escolha].all_func[i].salario << '\n';
            break;
        }



        cout << "\n1-Informações da empresa'\n'" //repetição ou não do loop sendo decidida
         << "2-Adcionar mais departamentos'\n'"
         << "3-Adicionar funcionarios a um departamento'\n'" 
         << "4- aumento 10 porcento'\n'"
         << "Escolha: ";
        cin >> escolha;
        cout << '\n';
    }
return 0;
}//nao sei como faz a transferencia