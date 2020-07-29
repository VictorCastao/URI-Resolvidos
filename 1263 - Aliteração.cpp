#include <iostream>

using namespace std;


int main(){

	string T;
	char marcador;
	int aliteracao = 0;

	while(true){

		aliteracao = 0;

		getline(cin, T);

		int dif = (int) 'a' - (int) 'A';

		if(!cin) break;

		for (int i=0; i<T.size(); i++){
			if(T[i] >= 'A' and T[i] <= 'Z') T[i] = (char) T[i] + dif;
		}

		char antigo = '0';

		for (int i=0; i<T.size(); i++){
			if(i==0){
				marcador = T[i];
				continue;
			}

			if(T[i] == ' '){
				i++;
				if (T[i] == marcador and T[i] != antigo){
					aliteracao++;
					antigo = marcador;
				}
				if (T[i] == antigo and T[i] != marcador){
					antigo = marcador;
				}
				marcador = T[i];
			}
		}

		cout << aliteracao << endl;

	}

	return 0;

}
