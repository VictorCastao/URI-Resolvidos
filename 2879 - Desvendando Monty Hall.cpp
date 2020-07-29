#include <iostream>

using namespace std;

int main(){
	int tentativas, porta, ganhou = 0;

	cin >> tentativas;

	for(int i=0; i<tentativas; i++){
		cin >> porta;
		if(porta == 1) continue;
		else ganhou++;
	}
	cout << ganhou << endl;

	return 0;
}
