if(contador =! 0){
                for(int i = 0; i < contador; i++){
                    cout <<"Usuario(" << i << "): " << contas[i].getName;
                }
                cout << "selecione o usuario pelo ID: ";
                cin >> id;

                cout << "O saldo e: " << contas[id].getObterSaldo;
            }
            else
                cout << "nao existem clientes!!";
            break;