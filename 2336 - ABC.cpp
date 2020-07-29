#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	string exp;

	unsigned long long potencias[1000001];

	potencias[0] = 1;

	for(int k=1; k<1000001; k++){
		potencias[k] = (potencias[k-1] * 26) % 1000000007;
		potencias[k] %= 1000000007;
	}

	while (cin >> exp){
	
		int i,j;

		unsigned long long soma = 0;

		for(i=exp.size()-1, j=0; i>=0; i--,j++){
			unsigned long long pot = 1;
			soma += ((int) exp[i] - (int) 'A') * potencias[j];
			soma %= 1000000007;
		}

		cout << soma % 1000000007 << endl;
	}
	return 0;
}

