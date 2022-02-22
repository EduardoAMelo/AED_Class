#include <iostream>
using namespace std;

void preencher(int v[]){
    v[0]=14;
    v[1]=12;
    v[2]=11;
    v[3]=16;
    v[4]=19;
}

int main(){
  int v[6];
  int n,i, sentinela;
  bool achou;

  preencher(v);
  achou = false;
  cout << "Numero: ";
  cin >> n;

  sentinela = n;
    v[5] = sentinela;
  for (i = 0; v[i] != sentinela; i++){

      if(i!=5 && v[i]==n){
          achou = true;
      }
  }

  if(achou){
      cout << "\n O numero" << n << "foi encontrado" << endl;
  }else {
      cout << "\n O numero " << n << " nao foi encontrado" << endl;
  }

return 0;


}