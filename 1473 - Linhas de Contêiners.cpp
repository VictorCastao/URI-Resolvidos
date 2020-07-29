#include <iostream>
#include <deque>
#include <cstdio>

using namespace std;

int main()
{
    int linhas, colunas, i, j, temp, temp2;
    while(scanf("%d %d", &linhas, &colunas) != EOF){
	bool result = true;
	int trocas = 0, temptroca;
        int matriz[linhas][colunas];
        deque <int> fileira_1, coluna_fim;
        for(i=0;i<linhas;i++){
            for(j=0;j<colunas;j++){
                scanf("%d", &matriz[i][j]);
                if(matriz[i][j] == 1) temp = i;
		if(matriz[i][j] % colunas == 0) temp2 = j;
		if(j>0 and i>0){
			if(matriz[i-1][j] - matriz[i-1][j-1] != matriz[i][j] - matriz[i][j-1]) result = false;
		}
            }
        }
	if(result){
		for(i=0;i<colunas;i++){
			fileira_1.push_back(matriz[temp][i]);
			if(matriz[temp][i] > colunas){
				result = false;
				break;
			}
		}
	}
	if(result){
		for(i=0;i<linhas;i++){
			coluna_fim.push_back(matriz[i][temp2]);
			if(matriz[i][temp2] % colunas != 0){
				result = false;
				break;
			}
		}
	}
	if(result){
		for(i=0;i<colunas;i++){
			if(fileira_1[i] == i+1) continue;
			else{
				trocas++;
				temptroca = fileira_1[i];
				fileira_1[i] = fileira_1[temptroca-1];
				fileira_1[temptroca-1] = temptroca;
				i--;
			}
		}

		for(i=0;i<linhas;i++){
			if(coluna_fim[i] / colunas == i+1) continue;
			else{
				trocas++;
				temptroca = coluna_fim[i];
				coluna_fim[i] = coluna_fim[(temptroca/colunas)-1];
				coluna_fim[(temptroca/colunas)-1] = temptroca;
				i--;
			}
		}
	}
	if(result) printf("%d\n", trocas);
	else printf("*\n");
    } 
    return 0;
}
