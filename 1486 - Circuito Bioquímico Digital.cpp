#include <iostream>
#include <cstdio>

using namespace std;
 
int main(){
	int linha, coluna, peso, temp, resp;
	while(true){
		resp = 0;
		scanf("%d %d %d", &coluna, &linha, &peso);
		if(coluna == 0 and linha == 0 and peso == 0) break;
		int palito[coluna];
		for(int i=0; i<coluna; i++) palito[i] = 0;
		for(int i=0; i<linha; i++){
			for(int j=0; j<coluna; j++){
				scanf("%d", &temp);
				if(temp == 1) palito[j]++;
				else{
					if(palito[j] >= peso) resp++;
					palito[j] = 0;
				}
			}
		}
		for(int k=0; k<coluna; k++) if(palito[k] >= peso) resp++;
		printf("%d\n", resp);
	}
	return 0;
}

