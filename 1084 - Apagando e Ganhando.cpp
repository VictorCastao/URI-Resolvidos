#include <iostream>
#include <deque>

using namespace std;

int main(){
	int digitos, apagar;

	while(true){

		cin >> digitos >> apagar;

		if(digitos == 0 and apagar == 0) break;

		int apagados = 0;

		string numero;

		cin >> numero;

		deque <char> maior;

		for(int i=0; i<numero.size(); i++){
			if(apagados == apagar) maior.push_back(numero[i]);

			else if(maior.empty()) maior.push_back(numero[i]);

			else if(numero[i] <= maior.back()) maior.push_back(numero[i]);

			else if(numero[i] > maior.back()){
				while(!maior.empty() and numero[i] > maior.back() and apagar != apagados){
					maior.pop_back();
					apagados++;
				}
				maior.push_back(numero[i]);
			}
		}

		for(int j=0; j<maior.size() and j < digitos-apagar; j++){
			cout << maior[j];
		}

		cout << endl;
	}
	
	return 0;
}

