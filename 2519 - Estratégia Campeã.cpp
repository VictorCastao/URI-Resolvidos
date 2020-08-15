/*	
	A resolução do exercício consiste na criação de uma BIT (Árvore de Indexação Binária) 2D.
	No começo, basta verificar onde há uma pessoa e somar 1 na BIT 2D.
	Na operação de mudança de posição, basta somar -1 no ponto de origem e 1 no ponto de destino (indicando na BIT 2D a mudança de lugar)
	Para saber quantas pessoas existem em um determinado intervalo, basta usar a fórmula para cálculo de soma da BIT 2D
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int BIT[1025][1025]; //BIT 2D com tamanho máximo (valor definido baseando-se no enunciado do exercício)

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
	int linhas, colunas;
	while(scanf("%d %d", &linhas, &colunas) != EOF){	
		int temp, i, j, M, M2;
		M = ceil(pow(2, log2(linhas))) + 1; //Cálculo do índice máximo das linhas da árvore (para evitar operações desnecessárias)
		M2 = ceil(pow(2, log2(colunas))) + 1; //Cálculo do índice máximo das colunas da árvore (para evitar operações desnecessárias)
		for(i=1; i<=linhas; i++){
			for(j=1; j<=colunas; j++){
				BIT[i][j] = 0;
			}
		}

		for(i=1; i<=linhas; i++){
			for(j=1; j<=colunas; j++){
				scanf("%d", &temp);
				if(temp == 1) atualizar(i, j, 1, M, M2); //Adicionar pessoa naquele ponto (somar 1 na BIT)
			}
		}

		int operacoes, op, x1, x2, y1, y2;

		scanf("%d", &operacoes);

		for(j=0; j<operacoes; j++){
			scanf("%d %d %d %d %d", &op, &x1, &y1, &x2, &y2);
			if(op == 0){
				atualizar(x1, y1, -1, M, M2);
				atualizar(x2, y2, 1, M, M2);
			}
			else{
				int resposta = soma(x2, y2) - soma(x2,y1-1) - soma(x1-1, y2) + soma(x1-1,y1-1); //Fórmula para obter soma da BIT 2D

				printf("%d\n", resposta);

			}
		}
	}
	return 0;
}
