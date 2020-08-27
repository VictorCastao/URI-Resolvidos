// SOLUCIONADO UTILIZANDO O ALGORITMO DE FLOYD-WARSHAL. PARA ISSO, AO INVÉS DAS CASAS SEREM REFERNCIADAS TRADICIONALMENTE (DE A1 ATÉ H8), ELAS FORAM TRANSFORMADAS EM NÚMEROS DE 1 A 64. COM ISSO, UMA MATRIZ 64 X 64 INFORMAVA AS DISTANCIAS DE TODAS AS CASAS PARA TODAS AS CASAS (CONSIDERANDO O MOVIMENTO DO CAVALO) APÓS RODAR O ALGORITMO, PERMITINDO A OBTENÇÃO DA RESPOSTA.

#include <iostream>
#include <cstdio>
#include <queue>
#include <deque>
#include <map>

using namespace std;

struct dist{
	string nome;
	int d;
};

int main(){
	int x, y;
	int matriz[65][65];
	for(int i=1; i<=64; i++){
		for(int j=1; j<=64; j++){
			matriz[i][j] = 10000000;
		}
	}
	for(int i=1; i<=8; i++){
		for(int j=1; j<=8; j++){
			if(i+2 >= 1 and i+2 <=8 and j+1 >= 1 and j+1 <= 8){
				matriz[(i-1)*8 + j][(i+2-1)*8 + j + 1] = 1;
				matriz[(i+2-1)*8 + j + 1][(i-1)*8 + j] = 1;
			}
			if(i+2 >= 1 and i+2 <=8 and j-1 >= 1 and j-1 <= 8){
				matriz[(i-1)*8 + j][(i+2-1)*8 + j - 1] = 1;
				matriz[(i+2-1)*8 + j - 1][(i-1)*8 + j] = 1;
			}
			if(i+1 >= 1 and i+1 <=8 and j-2 >= 1 and j-2 <= 8){
				matriz[(i-1)*8 + j][(i+1-1)*8 + j - 2] = 1;
				matriz[(i+1-1)*8 + j - 2][(i-1)*8 + j] = 1;
			}
			if(i+1 >= 1 and i+1 <=8 and j+2 >= 1 and j+2 <= 8){
				x = (i-1) * 8 + j;
				y = (i+1-1) * 8 + j + 2;
				matriz[x][y] = 1;
				matriz[y][x] = 1;
			}
			if(i-1 >= 1 and i-1 <=8 and j-2 >= 1 and j-2 <= 8){
				x = (i-1) * 8 + j;
				y = (i-1-1) * 8 + j - 2;
				matriz[x][y] = 1;
				matriz[y][x] = 1;
			}
			if(i-1 >= 1 and i-1 <=8 and j+2 >= 1 and j+2 <= 8){
				x = (i-1) * 8 + j;
				y = (i-1-1) * 8 + j + 2;
				matriz[x][y] = 1;
				matriz[y][x] = 1;
			}
			if(i-2 >= 1 and i-2 <=8 and j-1 >= 1 and j-1 <= 8){
				x = (i-1) * 8 + j;
				y = (i-2-1) * 8 + j - 1;
				matriz[x][y] = 1;
				matriz[y][x] = 1;
			}
			if(i-2 >= 1 and i-2 <=8 and j+1 >= 1 and j+1 <= 8){
				x = (i-1) * 8 + j;
				y = (i-2-1) * 8 + j + 1;
				matriz[x][y] = 1;
				matriz[y][x] = 1;
			}
		}
	}

	for(int k = 1;k <= 64;k++)
    		for(int i = 1;i <= 64;i++)
        		for(int j = 1;j <= 64;j++)
	       			matriz[i][j] = min(matriz[i][j], matriz[i][k] + matriz[k][j]);

	string p1, p2;

	while(cin >> p1 >> p2){
		int valor1 = ((int) p1[0] - (int) 'a') * 8 + ((int) p1[1] - (int) '0');
		int valor2 = ((int) p2[0] - (int) 'a') * 8 + ((int) p2[1] - (int) '0');
		cout << "To get from " << p1 << " to " << p2 << " takes " << matriz[valor1][valor2] << " knight moves.\n";
	}
	return 0;
}
