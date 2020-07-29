#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>

using namespace std;

struct dist{
	int d, p, ped;
};

struct Comp{
    bool operator()(const dist& a, const dist& b){
        return a.d>b.d;
    }
};

int main(){
	int cidades, estradas;
	scanf("%d %d", &cidades, &estradas);
	int visitados[cidades+1][2];
	int minimo[cidades+1][2];
	deque <pair<int,int>> caminhos[cidades+1];
	dist atual;
	int origem, destino, preco;
	priority_queue<dist, vector<dist>, Comp> fila;
	for(int i=0; i<estradas; i++){
		scanf("%d %d %d", &origem, &destino, &preco);
		caminhos[origem].push_back(make_pair(preco, destino));
		caminhos[destino].push_back(make_pair(preco, origem));
	}

	for(int i=1; i<=cidades; i++){
		visitados[i][0] = 0;
		visitados[i][1] = 0;
		minimo[i][0] = 1000000000;
		minimo[i][1] = 1000000000;
	}
	minimo[1][0] = 0;
	dist temp;
	temp.d = 0;
	temp.p = 1;
	temp.ped = 0;
	fila.push(temp);
	int teste;
	while(true){
		teste = 0;
		while(!fila.empty()){
			atual = fila.top();
			fila.pop();
			if(visitados[atual.p][atual.ped % 2] == 0 ){
				teste = 1;
				break;
			}
		}
		if(teste == 0 or (atual.p == cidades and atual.ped % 2 == 0)) break;

		visitados[atual.p][atual.ped % 2] = 1;
		
		int dista,num;

		if(atual.ped % 2 == 0) num = 1;
		else num = 0;

		for(int i=0; i<caminhos[atual.p].size(); i++){

			dista = atual.d + caminhos[atual.p][i].first;

			if(minimo[caminhos[atual.p][i].second][num] > dista){

				minimo[caminhos[atual.p][i].second][num] = dista;

				temp.d = dista;
				temp.p = caminhos[atual.p][i].second;
				temp.ped = atual.ped + 1;

				fila.push(temp);

			}

		}
	}

	int resp = minimo[cidades][0];

	if (resp != 1000000000) printf("%d\n", minimo[cidades][0]);
	else printf("-1\n");


	return 0;
}
