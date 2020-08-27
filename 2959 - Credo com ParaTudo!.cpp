#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int bairros, conexoes, i, j, k, p1, p2, perguntas;

	scanf("%d %d %d", &bairros, &conexoes, &perguntas);

	int matriz[bairros+1][bairros+1];

	for(i=1; i<=bairros; i++){
		for(j=0; j<=bairros; j++){
			if(i==j) matriz[i][j] = 0;
			else matriz[i][j] = 10000000;
		}
	}

	for(i=0; i<conexoes; i++){
		scanf("%d %d", &p1, &p2);
		matriz[p1][p2] = min(matriz[p1][p2], 1);
		matriz[p2][p1] = matriz[p1][p2];
	}

	for(i=1; i<=bairros; i++){
		for(j=1; j<=bairros; j++){
			for(k=1; k<=bairros; k++){
				matriz[j][k] = min(matriz[j][k], matriz[j][i] + matriz[i][k]);
			}
		}
	}

	int a, b;

	for (i=0; i<perguntas; i++){
		scanf("%d %d", &a, &b);
		if (matriz[a][b] != 10000000) printf("Lets que lets\n");
		else printf("Deu ruim\n");

	}

	return 0;
}
