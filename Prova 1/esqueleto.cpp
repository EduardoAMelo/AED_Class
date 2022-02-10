#include <iostream>

using namespace std;


int main(){
    int aux;
    //Menu de opções
    while(5){
        cout << "1- item 1" << endl;
        cout << "2- item 2" << endl;
        cout << "3- item 3" << endl;
        cout << "4- item 4" << endl;
        cout << "5- Sair" << endl;
        cin >> aux;
        switch (aux)
        {
        case 1:
            /* code */
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