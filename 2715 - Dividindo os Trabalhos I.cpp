#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){

	int trabalhos, i;

	while(scanf("%d", &trabalhos) != EOF){
		int numeros[trabalhos];
		long long somatotal=0;
		for(i=0; i<trabalhos; i++){
			scanf("%d", &numeros[i]);
			somatotal += numeros[i];
		}
		
		long long soma=0, diferenca = somatotal;
		
		for(i=0; i<trabalhos; i++){
			soma+=numeros[i];

			somatotal-=numeros[i];

			if(abs(soma-somatotal) < abs(diferenca)) diferenca = abs(soma-somatotal);

		}

		cout << diferenca << endl;

	}
	
	return 0;
}
