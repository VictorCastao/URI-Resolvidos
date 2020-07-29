#include <iostream>

using namespace std;

int main(){
	int feijao[4], posicao;
	for (int i=0; i<4; i++){
		cin >> feijao[i];
		
		if(feijao[i] == 1) posicao = i+1;
	}

	cout << posicao << endl;

	return 0;

}
