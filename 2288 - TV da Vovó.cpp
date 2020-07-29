#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int linhas, colunas, comando_vertical, comando_horizontal, temp1, temp2, horizontal, vertical, teste = 1;

	while(true){
		scanf("%d %d", &linhas, &colunas);
		if(linhas == 0 and colunas == 0) break;
		int matriz[linhas][colunas];
		for(int i=0; i<linhas; i++){
			for(int j=0; j<colunas; j++){
				scanf("%d", &matriz[i][j]);
			}
		}
		comando_vertical = 0;
		comando_horizontal = 0;
		while(true){
			scanf("%d %d", &temp1, &temp2);
			if(temp1 == 0 and temp2 == 0) break;
			comando_horizontal += temp1;
			comando_vertical += temp2;
		}
		printf("Teste %d\n", teste);
		teste++;
		for(int i=0; i<linhas; i++){
			vertical = i;
			vertical += (comando_vertical % linhas);
			if(vertical >= linhas) vertical -= linhas;
			else if(vertical < 0) vertical = linhas + vertical; 
			for(int j=0; j<colunas; j++){
				if(j!=0) printf(" ");
				horizontal = j;
				horizontal -= (comando_horizontal % colunas);
				if(horizontal >= colunas) horizontal -= colunas;
				else if(horizontal < 0) horizontal = colunas + horizontal;
				printf("%d", matriz[vertical][horizontal]);
 
			}
			printf("\n");
		}
		printf("\n"); 
	}
	return 0;
}

