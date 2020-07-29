#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int membros[1001], chefe[1001];

struct estrada{
	int inicio, fim, peso;
};

bool comp(estrada a, estrada b){
	return a.peso > b.peso;
}

bool comp2(estrada a, estrada b){
	return a.peso < b.peso;
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
	int pontos = 0, ligacoes;
	pair <int, int> resp;
	scanf("%d", &ligacoes);
	int soma_menor = 0, soma_maior = 0;
	deque <estrada> fila_maior, fila_menor;
	estrada temp;
	for(int j=0; j<ligacoes; j++){
		scanf("%d %d %d", &temp.inicio, &temp.fim, &temp.peso);
		if(temp.inicio > pontos) pontos = temp.inicio;
		if(temp.fim > pontos) pontos = temp.fim;
		fila_maior.push_back(temp);
		fila_menor.push_back(temp);
	}
	for(int i=1; i<=pontos; i++){
		membros[i] = 1;
		chefe[i] = i;
	}
	sort(fila_maior.begin(), fila_maior.end(), comp);
	sort(fila_menor.begin(), fila_menor.end(), comp2);
	for(int k=0; k<fila_maior.size(); k++){
		resp = uniao(fila_maior[k].inicio, fila_maior[k].fim, fila_maior[k].peso);
		soma_maior += resp.first;
		if(resp.second == pontos) break;
	}
	for(int i=1; i<=pontos; i++){
		membros[i] = 1;
		chefe[i] = i;
	}
	for(int k=0; k<fila_menor.size(); k++){
		resp = uniao(fila_menor[k].inicio, fila_menor[k].fim, fila_menor[k].peso);
		soma_menor += resp.first;
		if(resp.second == pontos) break;
	}
	printf("%d\n%d\n", soma_maior, soma_menor);
	return 0;
}

