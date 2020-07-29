#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
	return a>b;
}	
 
int main(){
	int numeros, i;
	scanf("%d", &numeros);
	int valores[numeros];
	int somatotal = 0;
	int somaparcial = 0;
	int qtde = 0;
	for(int i=0; i<numeros; i++){
		scanf("%d", &valores[i]);
		somatotal += valores[i];
	}
	sort(valores, valores+numeros, comp);
	for(i=0; i<numeros-2; i++){
		somaparcial += valores[i];
		if(somatotal - somaparcial > valores[i]){
			qtde = numeros - i;
			break;
		}
	}

	printf("%d\n", qtde);

	return 0;
}

