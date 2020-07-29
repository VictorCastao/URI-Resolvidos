#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int qtde;
	while(true){
		scanf("%d", &qtde);
		if(qtde == 0) break;
		int valores[qtde];
		for(int i=0; i<qtde; i++){
			scanf("%d", &valores[i]);
		}
		char op;
		if(valores[qtde-1] > valores[0]) op = 'D';
		else op = 'C';
		int picos = 0;
		for(int j=1; j<qtde; j++){
			if(valores[j] > valores[j-1] and op == 'D') picos++;
			else if(valores[j] < valores[j-1] and op == 'C') picos++;
			if(valores[j] > valores[j-1]) op = 'C';
			else op = 'D'; 
		}
		if(valores[0] > valores[qtde-1] and op == 'D') picos++;
		else if(valores[0] < valores[qtde-1] and op == 'C') picos++;
		printf("%d\n", picos);
		
	}
	return 0;
}
