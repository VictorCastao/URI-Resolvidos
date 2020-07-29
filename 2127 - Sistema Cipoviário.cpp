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
	int pontos, ligacoes, soma, teste = 1;
	pair <int, int> resp;
	while(cin >> pontos >> ligacoes){
		soma = 0;
		deque <estrada> fila;
		estrada temp;
		for(int i=1; i<=pontos; i++){
			membros[i] = 1;
			chefe[i] = i;
		}
		for(int j=0; j<ligacoes; j++){
			scanf("%d %d %d", &temp.inicio, &temp.fim, &temp.peso);
			fila.push_back(temp);
		}
		sort(fila.begin(), fila.end(), comp);
		for(int k=0; k<fila.size(); k++){
			resp = uniao(fila[k].inicio, fila[k].fim, fila[k].peso);
			soma += resp.first;
			if(resp.second == pontos) break;
		}
		printf("Instancia %d\n%d\n\n", teste, soma);
		teste++;
	}
	return 0;
}

