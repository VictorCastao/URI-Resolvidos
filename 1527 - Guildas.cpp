#include <iostream>
#include <cstdio>

using namespace std;

int pontos[100005], chefe[100005], peso[100005];

int buscar_chefe(int valor){
	if(chefe[valor] == valor) return valor;
	else return chefe[valor] = buscar_chefe(chefe[valor]);
}

void uniao(int set1, int set2){
	set1 = buscar_chefe(set1);
	set2 = buscar_chefe(set2);
	if(set1 == set2) return;
	else if(peso[set1] > peso[set2]){
		chefe[set2] = set1;
		pontos[set1] += pontos[set2];
	}
	else if(peso[set2] > peso[set1]){
		chefe[set1] = set2;
		pontos[set2] += pontos[set1];
	}
	else if(peso[set1] == peso[set2]){
		chefe[set2] = set1;
		pontos[set1] += pontos[set2];
		peso[set1]++;
	}
}

int main(){
	int jogadores, operacoes, ponto, op, guilda1, guilda2, pt_guilda1, pt_guilda2, temp1, temp2;
	
	while(true){

		cin >> jogadores >> operacoes;

		if(jogadores == 0 and operacoes == 0) break;

		int vitorias = 0;

		for(int i=1; i<=jogadores; i++){
			scanf("%d", &ponto);
			chefe[i] = i;
			peso[i] = 1;
			pontos[i] = ponto;
		}

		for(int j=0; j<operacoes; j++){
			scanf("%d %d %d", &op, &guilda1, &guilda2);
			if(op == 1) uniao(guilda1, guilda2);
			else if(op == 2){
				temp1 = buscar_chefe(guilda1);
				temp2 = buscar_chefe(guilda2);
				int rafael = buscar_chefe(1);
				pt_guilda1 = pontos[temp1];
				pt_guilda2 = pontos[temp2];
				if(pt_guilda1 > pt_guilda2 and rafael == temp1) vitorias++;
				else if(pt_guilda2 > pt_guilda1 and rafael == temp2) vitorias++;
			}
		}

		printf("%d\n", vitorias);
	}
	return 0;
}

