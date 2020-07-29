#include <iostream>

using namespace std;

int main(){
	int numero, passos = 1, posicao = 1;

	cin >> numero;

	while(posicao != 0){
		if(posicao >= numero/2) posicao = (posicao - (numero/2)) * 2;
		else posicao = (posicao * 2) + 1;
		passos++;
	}

	cout << passos << endl;

	return 0;
}

