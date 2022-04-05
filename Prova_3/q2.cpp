#include <iostream>
#include <list>
#include <string>

using namespace std;


class Livros{// classe de livros
    string nome, autor, genero, bug;//declaração de variaveis
    int lancamento;

    public:
        void setbug(){//setters
          getline(cin, nome);
        }


        void setName(){
          cout << "Nome completo do livro: " ;
          getline(cin, nome);
        }


        void setAutor(){
            cout << "Nome completo do autor: " ;
            getline(cin, autor);
        }


         void setGenero(){
            cout << "Genero do livro: " ;
            getline(cin, genero);
        }


        void setLancamento(){
            cout << "Data do livro: ";
            cin >> lancamento;
        }

        void cadastra(){//funcao com this que faz todos os setters de uma vez
            cout << "cadastrando..." << endl;
            this->setbug();//aconteceu um bug bizarro onde o primeiro this e ignorado como eu tinha pouco tempo eu criei um this ignoravel
            this->setName();
            this->setAutor();
            this->setGenero();
            this->setLancamento();
        }


        string getName(){//getters
            return nome;
        }


        string getAutor(){
            return autor;
        }


        string getGenero(){
            return genero;
        }


        int getLancamento(){
            return lancamento;
        }



};

class Livraria{//classe que armazena todos os livros
    list <Livros> estante;//declaracao da lista
    int total = 0;//para nao sobrescrever

    public:
        void setLivros(Livros holder[], int n){//setando os livros na estante
            total += n;
            for(int i = 0; i < total; i++){
                estante.push_front(holder[i]);
            }
        } 


        void removeLivro(string titulo){//removendo os livros
            list<Livros>::iterator it = estante.begin();
            for(int i=0; i<estante.size(); i++){
            if(it->getName() == titulo){
                estante.erase(it);
                break;
                } 
            ++it;
            }
        }


        list<Livros>::iterator getLivro(int position){//get do iterator para o getNavigation inicializar
            list<Livros>::iterator it = estante.begin();
            advance(it, position);
            return it;
        }


        void getNavation(list<Livros>::iterator it){//navegador da estante
            int aux;
            cout << "\nLivro: " << it->getName() << endl;//mostrando pela primeira vez
            cout << "Autor: " << it->getAutor() << endl;
            cout << "Lancamento: " << it->getLancamento() << endl;
            cout << "Genero: " << it->getGenero() << endl;

            while(aux != 3){//loop para fazer a troca de proximo e anterior
                cout << "\n1- Anterior" << endl;
                cout << "2- Proximo" << endl;
                cout << "3- Sair" << endl;
                cin >> aux;

                switch (aux)
                {
                case 1:
                    --it;
                    cout << "\nLivro: " << it->getName() << endl;
                    cout << "Autor: " << it->getAutor() << endl;
                    cout << "Lancamento: " << it->getLancamento() << endl;
                    cout << "Genero: " << it->getGenero() << endl;
                    break;


                case 2:
                    ++it;
                    cout << "Livro: " << it->getName() << endl;
                    cout << "Autor: " << it->getAutor() << endl;
                    cout << "Lancamento: " << it->getLancamento() << endl;
                    cout << "Genero: " << it->getGenero() << endl;
                    break;


                case 3:
                break;
                }
            }
        }
};

int main(){
    Livros livros[100];//fiz como vetor para poder criar varios livros
    Livraria estante;//declaracao de tudo
    string titulo;
    list<Livros>::iterator it;
    int aux, size, i, position;
    //Menu de opções
    while(5){
        cout << "1- Cadastrar Livros" << endl;
        cout << "2- Remover Livros" << endl;
        cout << "3- Navegacao" << endl;
        cout << "4- Sair" << endl;
        cin >> aux;
        switch (aux)
        {
        case 1://inserindo livros
            cout << "Quantos livros deseja inserir: ";
            cin >> size;

            for(i = 0; i < size; i++){
                livros[i].cadastra();
            }
            estante.setLivros(livros, size);
            break;


        case 2://apagando livros
            cout << "Qual o titulo do livro: ";
            cin >> titulo;
            estante.removeLivro(titulo);
            break;


        case 3://navegando na estante
            cout << "Qual a posição inicial: ";
            cin >> position;
            it = estante.getLivro(position);
            estante.getNavation(it);

            break;


        case 4://fechando
            exit(4);
            break;
        }
    }

    system("pause");
    return 0;
}//nao dava tempo de codar pra evitar bugs ocasionados por usuario como navegar quando a estante ta vazia :(