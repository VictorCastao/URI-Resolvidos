#include <iostream>
#include <set>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	multiset <double> precos;
	int mercados, gramas, i;
	double valor, temp;
	cin >> mercados;

	for(i=0; i<mercados; i++){
		cin >> valor >> gramas;
		temp = (double) (valor/gramas) * 1000.0;
		precos.insert(temp);
	}
	
	printf("%.2lf\n", *precos.begin());

	return 0;
}

