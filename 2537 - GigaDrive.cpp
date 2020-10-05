#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int BIT[1025][1025];

int soma(int x, int y){
	int result = 0, i, j;
	for(i = x; i > 0; i -= i & -i){
		for(j = y; j > 0; j -= j & -j){
			result+=BIT[i][j];
		}
	}
	return result;
}

void atualizar(int x, int y, int valor, int M, int M2){
	int i, j;
	for(i = x; i <= M; i += i & -i){
		for(j = y; j <= M2; j += j & -j){
			BIT[i][j] += valor;
		}
	}
}

int main(){
	int ordem, rodadas;
	while(scanf("%d %d", &ordem, &rodadas) != EOF){	
		int temp, i, j, M, M2;
		M = ceil(pow(2, log2(ordem))) + 1;
		M2 = ceil(pow(2, log2(ordem))) + 1;
		for(i=1; i<=ordem; i++){
			for(j=1; j<=ordem; j++){
				BIT[i][j] = 0;
			}
		}

		for(i=1; i<=ordem; i++){
			for(j=1; j<=ordem; j++){
				scanf("%d", &temp);
				if(temp == 1) atualizar(i, j, 1, M, M2);
			}
		}

		int operacoes, op, x1, x2, y1, y2;

		for(j=0; j<rodadas; j++){
			scanf("%d %d", &x1, &y1);
			atualizar(x1, y1, 1, M, M2);

			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			int resposta = soma(x2, y2) - soma(x2,y1-1) - soma(x1-1, y2) + soma(x1-1,y1-1);
			printf("%d\n", resposta);	
		}
	}
	return 0;
}
