#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int linhas, colunas, costas=0, i, j;

	string mapa;

	scanf("%d %d", &linhas, &colunas);
	
	string matriz[linhas];

	for(i=0; i<linhas; i++){
		cin >> mapa;
		matriz[i] = mapa;
	}	

	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			if(matriz[i][j] == '.') continue;
			else{
				if(i==0 or j==0 or i==linhas-1 or j==colunas-1){
					costas++;
					continue;
				}
				else if(i>0 and matriz[i-1][j] == '.'){
					costas++;
					continue;
				}
				else if(i<linhas-1 and matriz[i+1][j] == '.'){
					costas++;
					continue;
				}
				else if(j>0 and matriz[i][j-1] == '.'){
					costas++;
					continue;
				}
				else if(j<colunas-1 and matriz[i][j+1] == '.'){
					costas++;
					continue;
				}
			}
		}
	}

	printf("%d\n", costas);

	return 0;
}
 
