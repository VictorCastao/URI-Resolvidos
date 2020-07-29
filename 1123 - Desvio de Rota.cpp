#include <iostream>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>

using namespace std;

struct Comp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.first>b.first;
    }
};

int main(){
	int cidades, estradas, cidades_rota, cidade_concerto;

	while(true){
		scanf("%d %d %d %d", &cidades, &estradas, &cidades_rota, &cidade_concerto);
		if(cidades==0 and estradas==0 and cidades_rota==0 and cidade_concerto==0) break;
		int p1, p2, tarifa;
		bitset <250> visitados(0);
		deque < pair<int, int> > caminhos[cidades];
		for(int i=0; i<estradas; i++){
			scanf("%d %d %d", &p1, &p2, &tarifa);
			if(p1 >= cidades_rota or (p1 < cidades_rota and p2 == p1+1)) caminhos[p1].push_back(make_pair(tarifa, p2));
			if(p2 >= cidades_rota or (p2 < cidades_rota and p1 == p2+1)) caminhos[p2].push_back(make_pair(tarifa, p1));
		}
		int menor_caminho[cidades];
		for(int j=0; j<cidades; j++){
			menor_caminho[j] = 1000000;
		}
		menor_caminho[cidade_concerto] = 0;
		pair <int, int> atual;
		priority_queue < pair <int, int>, vector < pair<int, int> >, Comp > fila;
		fila.push(make_pair(0, cidade_concerto));
		int teste;
		int somas[cidades];
		somas[0] = 0;
		for(int k=1; k<cidades; k++){
			for(int l=0; l<caminhos[k].size(); l++){
				if(caminhos[k][l].second == k-1){
					somas[k] = somas[k-1] + caminhos[k][l].first;
					break;
				}
			}
		}
		while(true){
			teste = 0;
			while(!fila.empty()){
				atual = fila.top();
				fila.pop();
				if(visitados[atual.second] == 0){
					teste = 1;
					break;
				}
			}
			if(teste == 0 or atual.second == cidades_rota-1) break;

			visitados[atual.second] = 1;
			
			int dist;

			for(int i=0; i<caminhos[atual.second].size(); i++){

				dist = atual.first + caminhos[atual.second][i].first;

				if(menor_caminho[caminhos[atual.second][i].second] > dist){

					menor_caminho[caminhos[atual.second][i].second] = dist;

					fila.push(make_pair(dist, caminhos[atual.second][i].second));

				}

			}
		}

		
		
		printf("%d\n", menor_caminho[cidades_rota-1]);
	}

	return 0;
}
