#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int comp(int a, int b){
	return a>b;
}

int main(){
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	int numeros[n];
	for(int i=0; i<n; i++){
		scanf("%d", &numeros[i]);
	}
	sort(numeros, numeros+n, comp);
	int contador = k;
	int pos = k;
	while(numeros[pos] == numeros[k-1] and pos < n){
		pos++;
		contador++;
	}
	printf("%d\n", contador);
	return 0;
}
