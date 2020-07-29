#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int tentativas;

	while(true){

		cin >> tentativas;

		if(!cin) break;

		double tempos[tentativas];

		for(int i=0; i < tentativas; i++){
			cin >> tempos[i];
		}

		sort(tempos, tempos+tentativas);

		cout << tempos[0] << endl;

	}

	return 0;

}
