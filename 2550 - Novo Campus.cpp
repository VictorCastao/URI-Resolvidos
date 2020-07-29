#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int membros[200001], chefe[200001];

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
	int pontos, ligacoes;
	while(scanf("%d %d", &pontos, &ligacoes) != EOF){
		bool teste = false;
		pair <int, int> resp;
		int soma_menor = 0;
		deque <estrada> fila_menor;
		estrada temp;
		for(int j=0; j<ligacoes; j++){
			scanf("%d %d %d", &temp.inicio, &temp.fim, &temp.peso);
			if(temp.inicio > pontos) pontos = temp.inicio;
			if(temp.fim > pontos) pontos = temp.fim;
			fila_menor.push_back(temp);
		}
		for(int i=1; i<=pontos; i++){
			membros[i] = 1;
			chefe[i] = i;
		}
		sort(fila_menor.begin(), fila_menor.end(), comp2);
		for(int k=0; k<fila_menor.size(); k++){
			resp = uniao(fila_menor[k].inicio, fila_menor[k].fim, fila_menor[k].peso);
			soma_menor += resp.first;
			if(resp.second == pontos){ 
				teste = true;					
				break;
			}
		}
		if(teste) printf("%d\n", soma_menor);
		else printf("impossivel\n");
	}	
	return 0;
}

