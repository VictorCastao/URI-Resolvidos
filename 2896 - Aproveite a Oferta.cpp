#include <iostream>

using namespace std;

int main(){
	int tentativas, comprou, troca, ficou;

	cin >> tentativas;

	for(int i=0; i<tentativas; i++){
		cin >> comprou >> troca;
		ficou = (comprou % troca) + (int) comprou / troca;
		cout << ficou << endl;
	}
	return 0;
}
