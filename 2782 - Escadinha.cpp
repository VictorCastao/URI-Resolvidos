#include <iostream>

using namespace std;

int main(){
	int numeros;

	cin >> numeros;

	int seq[numeros];

	int diferenca_antiga, pivo, num_escada = 0;

	for(int j=0; j<numeros; j++){
		cin >> seq[j];
	}

	if(numeros == 1 or numeros == 2){
		cout << 1 << endl;
	}

	else{
		for(int i=0; i<numeros; i++){
			if (i==0){
				pivo = seq[i];
			}
			else if(i==1){
				diferenca_antiga = seq[i] - seq[i-1];
				pivo = seq[i];
				num_escada++;
			}
			else if(seq[i] - seq[i-1] == diferenca_antiga){
				pivo = seq[i];
			}
			else{
				pivo = seq[i-1];
				diferenca_antiga = seq[i] - seq[i-1];
				num_escada++;
			}
		
		}

		cout << num_escada << endl;

	}

	return 0;
}
