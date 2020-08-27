//SOLUCIONADO UTILIZANDO ALGORITMO DE DJIKSTRA. PORÉM, AO INVÉS DA COMPARAÇÃO SER COM BASE NA SOMA, ESTA FOI FEITA COM BASE NA MULTIPLICAÇÃO (POIS SE TRATAVA DE PROBABILIDADES). ALÉM DISSO, A FILA DE PRIORIDADE FOI ORDENADA, NESSE EXERCÍCIO, DE FORMA DECRESCENTE, E OS LOCAIS NÃO VISITADOS FORAM AJUSTADOS COM VALORES NEGATIVOS. ESSAS DUAS ALTERAÇÕES FORAM FEITAS PORQUE O EXERCÍCIO QUERIA DESCOBRIR A MAIOR PROBABILIDADE, EXIGINDO UMA ADAPTAÇÃO DO EXERCÍCIO ORIGINAL.

#include <iostream>
#include <cstdio>
#include <queue>
#include <deque>

using namespace std;

struct Comp{
    bool operator()(const pair<double, int>& a, const pair<double, int>& b){
        return a.first<b.first;
    }
};

int main(){
	int pontos, ruas, p1, p2;
	double chance;
	int i, j;
	pair <double, int> atual;
	while(true){
		scanf("%d", &pontos);
		if(pontos==0) break;
		scanf("%d", &ruas);
		double distancia[pontos+1];
		int visitados[pontos+1];
		deque <pair<double, int>> arestas[pontos+1];
		for(i=0; i<ruas; i++){
			scanf("%d %d %lf", &p1, &p2, &chance);
			arestas[p1].push_back(make_pair(chance/100.0, p2));
			arestas[p2].push_back(make_pair(chance/100.0, p1));
		}
		priority_queue< pair<double, int>, vector < pair <double, int> >, Comp > FILA; 
		for(i=1; i<=pontos; i++){
			distancia[i] = -1000000000.0;
			visitados[i] = 0;
		}
		
		distancia[1] = 1.0;
		FILA.push(make_pair(1.0,1));
		while(true){
			int fim = 0;
			while(!FILA.empty()){
				atual = FILA.top();
				FILA.pop();
				if(visitados[atual.second] == 0){
					fim = 1;
					break;
				}
			}
			if(fim == 0) break;
			for(i=0; i<arestas[atual.second].size(); i++){
				if(distancia[arestas[atual.second][i].second] < arestas[atual.second][i].first * atual.first){
					distancia[arestas[atual.second][i].second] = arestas[atual.second][i].first * atual.first;
					FILA.push(make_pair(distancia[arestas[atual.second][i].second], arestas[atual.second][i].second));
				}
			}
			visitados[atual.second] = 1;
		}

		double resposta = distancia[pontos];

		printf("%.6lf percent\n", resposta*100);
	}
	return 0;
}
