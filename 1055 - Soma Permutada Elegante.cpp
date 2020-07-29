#include <iostream>
#include <deque>
#include <stdlib.h>

using namespace std;

int main(){

	int casos_teste, elementos, temp, i, j, k;

	cin >> casos_teste;

	for(i=0; i<casos_teste; i++){
	
		cin >> elementos;

		deque <int> numeros;

		deque <int> maior_dif;

		int diferenca = 0, maior_esq = -1, maior_dir = -1, num_esq, num_dir, pos_esq, pos_dir;

		for(k=0; k<elementos; k++){

		cin >> temp;

		numeros.push_back(temp);
		
		}

		maior_dif.push_back(*max_element(numeros.begin(), numeros.end()));

		numeros.erase(max_element(numeros.begin(),numeros.end()));

		while(!numeros.empty()){
			for(j=0; j<numeros.size(); j++){
				if(abs(numeros[j]-maior_dif.front()) > maior_esq){
					pos_esq = j;
					num_esq = numeros[j];
					maior_esq = abs(numeros[j] - maior_dif.front());
				}

				if(abs(numeros[j]-maior_dif.back()) > maior_dir){
					pos_dir = j;
					num_dir = numeros[j];
					maior_dir = abs(numeros[j] - maior_dif.back());
				}

			}

			if(maior_dir > maior_esq){
				diferenca += maior_dir;
				maior_dif.push_back(num_dir);
				numeros.erase(numeros.begin()+pos_dir);
			}

			else{
				diferenca += maior_esq;
				maior_dif.push_front(num_esq);
				numeros.erase(numeros.begin()+pos_esq);
			}
			
			maior_esq = -1;
			maior_dir = -1;
		}

		cout << "Case " << i+1 << ": " << diferenca << endl;

		diferenca = 0;
	}

	return 0;
}

