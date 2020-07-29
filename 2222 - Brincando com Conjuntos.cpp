#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

int main(){
	bitset <60> grupos[10000];

	bitset <60> aux; 

	int instancias, i, j, k, l, conjuntos, num_elementos, op, temp, tipo, num1, num2, resp;

	scanf("%d", &instancias);

	for(i=0; i<instancias; i++){
		scanf("%d", &conjuntos);

		for(j=0; j<conjuntos; j++){
			grupos[j].reset();

			scanf("%d", &num_elementos);
		
			for(k=0; k<num_elementos; k++){
				scanf("%d", &temp);
				grupos[j][temp-1] = 1;
			}
		}

		scanf("%d", &op);

		for(l=0; l<op; l++){
			scanf("%d %d %d", &tipo, &num1, &num2);

			if(tipo == 1){
				aux = grupos[num1-1] & grupos[num2-1];
				resp = aux.count();
				printf("%d\n", resp);
				
			}

			else if(tipo == 2){
				aux = grupos[num1-1] | grupos[num2-1];
				resp = aux.count();
				printf("%d\n", resp);			
			}
	
		}

	}
	return 0;
}

