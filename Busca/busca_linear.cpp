#include <iostream>
using namespace std;

void preencher(int v[]){
    v[0]=14;
    v[1]=12;
    v[2]=11;
    v[3]=16;
    v[4]=19;
    v[5]=17;
}

int main(){
  int v[6];
  int n,i;
  bool achou;

  preencher(v);
  achou = false;
  cout << "Numero: ";
  cin >> n;

  for (i = 0; i<6; i++){

      if(v[i] == n){
          achou = true;
      }
  }

  if(achou){
      cout << "\n O numero" << n << "foi encontrado" << endl;
  }else {
      cout << "\n O numero " << n << " não foi encontrado" << endl;
  }

return 0;


}