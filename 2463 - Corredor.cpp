#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;

	cin >> num;

	int valores[num];

	for(int i=0; i<num; i++) cin >> valores[i];

	int maior = 0, resposta = 0;

	for(int i=0; i<num; i++){
		maior = max(0, maior+valores[i]);

		resposta = max(resposta, maior);
	}

	cout << resposta << endl;	

	return 0;
}
