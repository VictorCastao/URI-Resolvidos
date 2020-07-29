#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int membros[5001], chefe[5001];

struct estrada{
	int inicio, fim, peso, tipo;
};

bool comp(estrada a, estrada b){
	if(a.tipo != b.tipo) return a.tipo < b.tipo;
	else return a.peso < b.peso;
}

int busca(int v){
	if(chefe[v] == v) return v;
	else return chefe[v] = busca(chefe[v]);
}

pair<int, int> uniao(int a, int b, int peso){
	int chefe1 = busca(a), chefe2 = busca(b);
	if(chefe1 == chefe2) return make_pair(0,0);
	else if(membros[chefe1] > membros[chefe2]){
		membros[chefe1] += membros[chefe2];
		chefe[chefe2] = chefe[chefe1];
		return make_pair(peso, membros[chefe1]);
	}
	else{
		membros[chefe2] += membros[chefe1];
		chefe[chefe1] = chefe[chefe2];
		return make_pair(peso, membros[chefe2]);
	}
}
 
int main(){
	int soma, cidades, rodovias, ferrovias;
	pair <int, int> resp;
	scanf("%d %d %d", &cidades, &ferrovias, &rodovias);
	soma = 0;
	deque <estrada> fila;
	estrada temp;
	for(int i=0; i<=cidades; i++){
		membros[i] = 1;
		chefe[i] = i;
	}
	for(int j=0; j<ferrovias; j++){
		scanf("%d %d %d", &temp.inicio, &temp.fim, &temp.peso);
		temp.tipo = 1;
		fila.push_back(temp);
	}
	for(int j=0; j<rodovias; j++){
		scanf("%d %d %d", &temp.inicio, &temp.fim, &temp.peso);
		temp.tipo = 2;
		fila.push_back(temp);
	}
	sort(fila.begin(), fila.end(), comp);
	for(int k=0; k<fila.size(); k++){
		resp = uniao(fila[k].inicio, fila[k].fim, fila[k].peso);
		soma += resp.first;
		if(resp.second == cidades) break;
	}
	printf("%d\n", soma);
	return 0;
}

