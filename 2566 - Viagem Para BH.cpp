#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>

using namespace std;
struct Comp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.first>b.first;
    }
};

int main(){
	int N, M;
	while(cin >> N >> M){
		int visitados_aviao[N+1], visitados_onibus[N+1];
		int minimo_aviao[N+1], minimo_onibus[N+1];
		deque <pair <int, int>> caminhos_aviao[N+1], caminhos_onibus[N+1];
		pair <int, int> atual;
		int origem, destino, meio, preco;
		priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> fila_aviao, fila_onibus;
		for(int i=0; i<M; i++){
			scanf("%d %d %d %d", &origem, &destino, &meio, &preco);
			if(meio == 1) caminhos_aviao[origem].push_back(make_pair(preco, destino));
			else caminhos_onibus[origem].push_back(make_pair(preco, destino));

		}

		for(int i=1; i<=N; i++){
			visitados_aviao[i] = 0;
			visitados_onibus[i] = 0;
			minimo_aviao[i] = 1000000000;
			minimo_onibus[i] = 1000000000;
		}
		minimo_aviao[1] = 0;
		minimo_onibus[1] = 0;
		fila_aviao.push(make_pair(0,1));
		fila_onibus.push(make_pair(0,1));
		int teste;
		while(true){
			teste = 0;
			while(!fila_aviao.empty()){
				atual = fila_aviao.top();
				fila_aviao.pop();
				if(visitados_aviao[atual.second] == 0){
					teste = 1;
					break;
				}
			}
			if(teste == 0) break;

			visitados_aviao[atual.second] = 1;
			
			int dist;

			for(int i=0; i<caminhos_aviao[atual.second].size(); i++){

				dist = atual.first + caminhos_aviao[atual.second][i].first;

				if(minimo_aviao[caminhos_aviao[atual.second][i].second] > dist){

					minimo_aviao[caminhos_aviao[atual.second][i].second] = dist;

					fila_aviao.push(make_pair(dist, caminhos_aviao[atual.second][i].second));

				}

			}
		}

		while(true){
			teste = 0;
			while(!fila_onibus.empty()){
				atual = fila_onibus.top();
				fila_onibus.pop();
				if(visitados_onibus[atual.second] == 0){
					teste = 1;
					break;
				}
			}
			if(teste == 0) break;

			visitados_onibus[atual.second] = 1;
			
			int dist;

			for(int i=0; i<caminhos_onibus[atual.second].size(); i++){

				dist = atual.first + caminhos_onibus[atual.second][i].first;

				if(minimo_onibus[caminhos_onibus[atual.second][i].second] > dist){

					minimo_onibus[caminhos_onibus[atual.second][i].second] = dist;

					fila_onibus.push(make_pair(dist, caminhos_onibus[atual.second][i].second));

				}

			}
		}

		int menor_aviao = minimo_aviao[N], menor_onibus = minimo_onibus[N];
		if(menor_aviao < menor_onibus) printf("%d\n", menor_aviao);
		else printf("%d\n", menor_onibus);









	}


	return 0;
}
