#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

double dist(pair<double, double> a, pair<double, double> b){
	double q1 = a.first-b.first, q2 = a.second-b.second;
	return sqrt(pow(q1,2) + pow(q2,2));
}

int membros[501], chefe[501];

struct estrada{
	int inicio, fim;
	double peso;
};

bool comp2(estrada a, estrada b){
	return a.peso < b.peso;
}

int busca(int v){
	if(chefe[v] == v) return v;
	else return chefe[v] = busca(chefe[v]);
}

pair<double, int> uniao(int a, int b, double peso){
	int chefe1 = busca(a), chefe2 = busca(b);
	if(chefe1 == chefe2) return make_pair(0.0,0);
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
	int pontos;
	while(scanf("%d", &pontos) != EOF){
		pair <double, int> resp;
		pair <double, double> leitura;
		deque <pair<double, double>> coordenadas;
		for(int i=0; i<pontos; i++){
			scanf("%lf %lf", &leitura.first, &leitura.second);
			coordenadas.push_back(leitura);
		}
		double soma_menor = 0;
		deque <estrada> fila_menor;
		estrada temp;
		for(int j=0; j<pontos-1; j++){
			for(int k=j+1; k<pontos; k++){
				temp.inicio = j+1;
				temp.fim = k+1;
				temp.peso = dist(coordenadas[j], coordenadas[k]);
				fila_menor.push_back(temp);
			}
			
		}
		for(int i=1; i<=pontos; i++){
			membros[i] = 1;
			chefe[i] = i;
		}
		sort(fila_menor.begin(), fila_menor.end(), comp2);
		for(int k=0; k<fila_menor.size(); k++){
			resp = uniao(fila_menor[k].inicio, fila_menor[k].fim, fila_menor[k].peso);
			soma_menor += resp.first;
			if(resp.second == pontos) break;
		}
		printf("%.2lf\n", soma_menor);
	}	
	return 0;
}

