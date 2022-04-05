#include <iostream>

using namespace std;


class Radio{//declaracao da classe
    int volume, canal;

    public:
        Radio(){//inicializando
            volume = 0;
            canal = 0;
        }

        void setVolume(int vol){//set volume inicial
            if(vol < 0)
                cout << "valor invalido";
            else
                volume = vol;
        }


        void setCanal(int channel){//set do canal inicial
            if(channel < 0)
                cout << "valor invalido";
            else
                canal = channel;
        }


        void aumentarVolume(){//aumentando o volume
            int holder;
            cout << "Quantos pontos deseja aumentar(" << volume << "): ";
            cin >> holder;

            volume += holder;
        }


        void abaixarVolume(){//abaixando o volume
            int holder;
            cout << "Quantos pontos deseja abaixar(" << volume << "): ";
            cin >> holder;

            if(holder > volume)
                cout << "valor invalido" << endl;
            else
                volume -= holder;
        }


        int getVolume(){//retornando volume
            return volume;
        }


        void mudarCanal(){//mudando de canal
            int holder;
            cout << "Para qual canal deseja ir (" << canal << "): ";
            cin >> holder;

            if(holder == canal)
                cout << "voce ja esta nesse canal" << endl;
            else
                canal = holder;
        }


        int getCanal(){
            return canal;
        }
};

int main(){
    Radio c1;//declaracoes
    c1.setVolume(100);
    c1.setCanal(10);
    int aux, canal = c1.getCanal(), volume = c1.getVolume();
    //Menu de opções
    while(5){//menu
        cout << "1- Aumentar o som" << endl;
        cout << "2- Diminuir o som" << endl;
        cout << "3- Exibir status do som" << endl;
        cout << "4- Mudar a sintonia da rádio (trocar canal)" << endl;
        cout << "5- Exibir status do canal" << endl;
        cout << "6- Sair" << endl;
        cin >> aux;
        switch (aux)
        {
        case 1:
            c1.aumentarVolume();//aumentando
            break;


        case 2:
            c1.abaixarVolume();//abaixando
            break;


        case 3:
            volume = c1.getVolume();//status volume
            cout << "Volume: " << volume << endl;
            break;


        case 4:
            c1.mudarCanal();//mudar canal
            break;


        case 5:
            canal = c1.getCanal();//status canal
            cout << "Canal: " << canal << endl;
            break;

            
        case 6://fechando
            exit(6);
            break;
        }
    }

    system("pause");
    return 0;
}