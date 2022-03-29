#include <iostream>
#include <string>

using namespace std;


void InsertionSort(string a[], int tam){//algorimto de sort
    int i, j;
    string aux;
    for(i = 0; i < tam; i++){
        j = i;
        while(j>0 && a[j-1] > a[j]){
            aux = a[j-1];
            a[j-1] = a[j];
            a[j] = aux;
            j--;
        }

    }
}

int main(){
    string a[5];//declaracoes
    int cont;
    for(cont = 0; cont < 5; cont++){
        cin >> a[cont];
    }//inserindo
    InsertionSort(a,5);//dando sort
    for(cont = 0; cont <5; cont++){
        cout << a[cont] << " ";//print
    }

    return 0;
}