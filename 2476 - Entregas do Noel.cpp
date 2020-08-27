#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>

using namespace std;

#define MAXL    20
#define MAXN 100500
int n;
int par[MAXN];
int pai[MAXN], nivel[MAXN], ancestral[MAXN][MAXL];
vector <int> lista[MAXN];

void DFS(int u){
	for(int i = 0; i < (int)lista[u].size(); i++){
		int v = lista[u][i];
		if(nivel[v] == -1){
			pai[v] = u;
			nivel[v] = nivel[u] + 1;
			DFS(v);
		}
	}
}

void Ancestral(int N){
	for(int i = 0; i < MAXN; i++) pai[i] = nivel[i] = -1;

	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXL; j++) ancestral[i][j] = -1;
	
	nivel[1] = 0;
	DFS(1);

	for(int i = 1; i <= N; i++) ancestral[i][0] = pai[i];

	for(int j = 1; j < MAXL; j++)
		for(int i = 1; i <= N; i++)
			if(ancestral[i][j-1] != -1) ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
}

int LCA(int u,int v){
	if(nivel[u] < nivel[v]) swap(u, v);

	for(int i = MAXL-1; i >= 0; i--)
		if(nivel[u] - (1<<i) >= nivel[v]) u = ancestral[u][i];
	
	if(u == v)return u;

	for(int i = MAXL-1; i >= 0; i--)
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}

	return ancestral[u][0];
}

int main(){
	int perguntas;
	cin >> n >> perguntas;
	deque <string> presentes;
	string temp;
	presentes.push_back("Não usado");
	cin.ignore();
	for(int i=0; i<n; i++){
		cin >> temp;
		presentes.push_back(temp);
	} 

	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		lista[a].push_back(b);
		lista[b].push_back(a);
	}

	Ancestral(n);

	for(int i=0; i<perguntas; i++){
		int a, b;
		cin >> a >> b;
		set <string> dist;

		//PARA CADA PERGUNTA, CALCULO O LCA		

		int val = LCA(a,b); 

		//PARA CADA ITEM DO PAR, VOU PERCORRENDO SEUS ANCESTRAIS ATÉ CHEGAR NO LCA. PARA CADA ANCESTRAL, ADICIONO O PRESENTE CORREPONDENTE EM UM SET E, AO FINAL, SEU TAMANHO SERÁ IGUAL AO NÚMERO DE PRESENTES DISTINTOS (RESPOSTA DO EXERCÍCIO).

		dist.insert(presentes[a]);
		dist.insert(presentes[b]);
		for(int k=a; k!=val;){
			k = pai[k];
			dist.insert(presentes[k]);
		}
		for(int k=b; k!=val;){
			k = pai[k];
			dist.insert(presentes[k]);
		}
		int v = dist.size();
		printf("%d\n", v);
	}
	
	return 0;
}


