#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int busca_largura(int x, deque <int> lista[], int visitados[]){
	deque <int> fila;
	int numero = 0;
	fila.push_back(x);
	while(!fila.empty()){
		int v = fila.front();
		fila.pop_front();
		if(visitados[v] == 1) continue;
		visitados[v] = 1;
		numero++;
		for(int i=0; i<lista[v].size(); i++){
			if(visitados[lista[v][i]]==0) fila.push_back(lista[v][i]);
		}
	}

	return numero;
}

 
int main(){
	int totais, linhas;
	while(scanf("%d %d", &totais, &linhas) != EOF){
		deque <int> componentes[totais+1];
		int visitas[totais+1], tipo1, tipo2;
		for(int i=0; i<linhas; i++){
			scanf("%d %d", &tipo1, &tipo2);
			componentes[tipo1].push_back(tipo2);
			componentes[tipo2].push_back(tipo1);
			visitas[tipo1] = 0;
			visitas[tipo2] = 0;
		}
		int pesquisa;
		scanf("%d", &pesquisa);
		int resultado = busca_largura(pesquisa, componentes, visitas);
		printf("%d\n", resultado);
	}
	return 0;
}

