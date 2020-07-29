#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

deque <int> lista[50001];
int visitados[50001];

void busca_largura(int x){
	deque <int> fila;
	fila.push_back(x);
	while(!fila.empty()){
		int v = fila.front();
		fila.pop_front();
		if(visitados[v] == 1) continue;
		visitados[v] = 1;
		for(int i=0; i<lista[v].size(); i++){
			if(visitados[lista[v][i]]==0) fila.push_back(lista[v][i]);
		}
	}
}

 
int main(){
	int familias, linhas;
	scanf("%d %d", &familias, &linhas);
	int tipo1, tipo2;
	for(int i=0; i<linhas; i++){
		scanf("%d %d", &tipo1, &tipo2);
		lista[tipo1].push_back(tipo2);
		lista[tipo2].push_back(tipo1);
	}
	for(int i=1; i<=familias; i++){
		visitados[i] = 0;
	}
	int distintos = 0;
	for(int i=1; i<=familias; i++){
		if(visitados[i] == 0){
			distintos++;
			busca_largura(i);
		}

	}
	printf("%d\n", distintos);
	return 0;
}

