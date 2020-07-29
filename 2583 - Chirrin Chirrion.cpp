#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

int main(){
	string objeto, desejo;

	int teste, feitico;
	
	cin >> teste;

	for(int i=0; i<teste; i++){
		set <string> bau;
		cin >> feitico;

		for(int j=0; j<feitico; j++){
			cin >> objeto >> desejo;

			if(desejo == "chirrin") bau.insert(objeto);

			if(desejo == "chirrion") bau.erase(objeto);

		}

		cout << "TOTAL\n";

		for(auto k=bau.begin(); k!=bau.end(); k++){
			cout << *k << endl;
		}
	}

	return 0;
}

