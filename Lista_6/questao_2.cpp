#include <iostream>
#include <stdio.h>
#include <string>
//codigo incompleto
using namespace std;

void Quick(string &vetor, int inicio, int fim){
    int i, j;
    i = inicio;
    j = fim;
    int pivo = vetor[(inicio + fim) / 2];
    // cout << pivo;

    while(i <= j){
        while(vetor[i] < pivo){
            i++; 
        }
        while(vetor[j] > pivo){
            j--; 
        }
        if(i <=j){
            swap(vetor[i], vetor[j]);
            i++;
            j--;
        }
    };

    if(inicio < j){
        Quick(vetor, inicio, j);
    }
    if(i < fim){
        Quick(vetor, i, fim);
    }

}

int main(){
    string a = "edcba";
    cout << a << endl;
    Quick(a, 0, a.length()- 1);
    cout << a;
    

    return 0;
}
