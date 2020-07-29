#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

int main(){
	int linhas, colunas, i, j;
	while (scanf("%d %d", &linhas, &colunas) != EOF){
		int matriz[linhas][colunas];
		for(i=0; i<linhas; i++){
			for(j=0; j<colunas; j++){
				scanf("%d", &matriz[i][j]);
			}
		}

		int campo[linhas][colunas];
		
		for(i=0; i<linhas; i++){
			for(j=0; j<colunas; j++){
				int soma = 0;
				if(matriz[i][j]==1) soma = 9;
				else{
					if(j-1 >= 0 and matriz[i][j-1] == 1) soma++;
					if(j+1 < colunas and matriz[i][j+1] == 1) soma++;
					if(i-1 >= 0 and matriz[i-1][j] == 1) soma++;
					if(i+1 < linhas and matriz[i+1][j] == 1) soma++;
				}
				campo[i][j] = soma;
			}
		}

		for(i=0; i<linhas; i++){
			for(j=0; j<colunas; j++){
				printf("%d", campo[i][j]);
			}
			printf("\n");
		}
	}


	return 0;
}

