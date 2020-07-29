#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdio>

using namespace std;
bool comparar(int a, int b){
	return a>b;
}

int main(){

	int notas, maiores;

	while(scanf("%d %d", &notas, &maiores) != EOF){
		int numeros[notas];

		for(int i=0; i<notas; i++){
			scanf("%d", &numeros[i]);
		}

		sort(numeros, numeros+notas, comparar);
	
		unsigned long long soma = 0;

		for(int j=0; j<maiores; j++){
			soma+=numeros[j];
		}

		printf("%llu\n", soma % (1000000000ull+7));

	}
	return 0;

}
