#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <map>

using namespace std;

struct Comp{
    bool operator()(const pair<int, string>& a, const pair<int, string>& b){
        return a.first>b.first;
    }
};

int main(){
	int espacos, conexoes;
	scanf("%d %d", &espacos, &conexoes);
	map <string, deque <string>> caminhos_1, caminhos_2;
	map <string, int> visitados_1, visitados_2, minimo_1, minimo_2;
	string origem, destino;
	int pos1, pos2;
	deque <string> temp;
	for(int j=0; j<conexoes; j++){
		cin >> origem >> destino;
		temp = caminhos_1[origem];
		temp.push_back(destino);
		caminhos_1[origem] = temp;
		caminhos_2[origem] = temp;
		temp = caminhos_1[destino];
		temp.push_back(origem);
		caminhos_1[destino] = temp;
		caminhos_2[destino] = temp;
		visitados_1[origem] = 0;
		visitados_2[origem] = 0;
		visitados_1[destino] = 0;
		visitados_2[destino] = 0;
		minimo_1[origem] = 1000000000;
		minimo_2[origem] = 1000000000;
		minimo_1[destino] = 1000000000;
		minimo_2[destino] = 1000000000;
	}
	priority_queue<pair<int,string>, vector<pair<int,string>>, Comp> fila1, fila2;
	minimo_1["Entrada"] = 0;
	minimo_2["*"] = 0;
	fila1.push(make_pair(0,"Entrada"));
	fila2.push(make_pair(0,"*"));
	int teste;
	pair <int, string> atual;
	while(true){
			teste = 0;
			while(!fila1.empty()){
				atual = fila1.top();
				fila1.pop();
				if(visitados_1[atual.second] == 0){
					teste = 1;
					break;
				}
			}
			if(teste == 0 or atual.second == "*") break;

			visitados_1[atual.second] = 1;
			
			int dist;

			for(int i=0; i<caminhos_1[atual.second].size(); i++){

				dist = atual.first + 1;

				if(minimo_1[caminhos_1[atual.second][i]] > dist){

					minimo_1[caminhos_1[atual.second][i]] = dist;

					fila1.push(make_pair(dist, caminhos_1[atual.second][i]));

				}

			}
	}

	while(true){
			teste = 0;
			while(!fila2.empty()){
				atual = fila2.top();
				fila2.pop();
				if(visitados_2[atual.second] == 0){
					teste = 1;
					break;
				}
			}
			if(teste == 0 or atual.second == "Saida") break;

			visitados_2[atual.second] = 1;
			
			int dist;

			for(int i=0; i<caminhos_2[atual.second].size(); i++){

				dist = atual.first + 1;

				if(minimo_2[caminhos_2[atual.second][i]] > dist){

					minimo_2[caminhos_2[atual.second][i]] = dist;

					fila2.push(make_pair(dist, caminhos_2[atual.second][i]));

				}

			}
	}


	int caminho_menor = minimo_1["*"] + minimo_2["Saida"];

	printf("%d\n", caminho_menor);

	return 0;
}
