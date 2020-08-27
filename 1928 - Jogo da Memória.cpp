//Para a resolução do exercício implementei um algoritmo de LCA presente no site NEPS Academy, utilizando, também, um vetor que armazena os ídices dos pares corretos de cartas (para fornecer qual distância deveria ser calculada)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

#define ML 20
#define MN 50500


deque <int> vizinhos[MN];
int nivel[MN];
int pai[MN];
int ancestral[MN][ML];
vector <int> pares[MN]; 

void dfs(int valor){
	for(int k=0; k<vizinhos[valor].size(); k++){
		int j = vizinhos[valor][k];
		if(nivel[j] == -1){
			pai[j] = valor;
			nivel[j] = nivel[valor] + 1;
			dfs(j);
		}
	}
}

int LCA(int p1, int p2){
	if(nivel[p1] < nivel[p2]) swap(p1, p2);

	for(int i=ML-1; i>=0; i--){
		if(nivel[p1] - (1<<i) >= nivel[p2]) p1 = ancestral[p1][i];
	}

	if(p1 == p2) return p1;

	for(int j=ML-1; j>=0; j--){
		if(ancestral[p1][j] != -1 and ancestral[p1][j] != ancestral[p2][j]){
			p1 = ancestral[p1][j];
			p2 = ancestral[p2][j];
		}
	}

	return pai[p1];
}



int main(){
	int a,b,n;
	scanf("%d", &n);
	for(int p=1; p<=n; p++){
		scanf("%d", &a);
		pares[a].push_back(p);
	}

	for(int p=1; p<n; p++){
		scanf("%d %d", &a, &b);
		vizinhos[a].push_back(b);
		vizinhos[b].push_back(a);

	}

	for(int i=0; i<MN; i++){
		pai[i] = nivel[i] = -1;
		for(int j=0; j<ML; j++){
			ancestral[i][j] = -1;
		}
	}

	nivel[1] = 0;
	dfs(1);

	for(int i=1; i<=n; i++) ancestral[i][0] = pai[i];

	for(int j=1; j<ML; j++){
		for(int i=1; i<=n; i++){
			ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
		}
	}

	long long resposta = 0;

	for(long long i=1; i<=(n/2); i++){
		//printf("%d %d\n", pares[i][0], pares[i][1]);
		resposta += (long long) (nivel[ pares[i][0] ] + nivel[ pares[i][1] ] - 2 * nivel[LCA(pares[i][0], pares[i][1])]);
	}

	printf("%lli\n", resposta);

	return 0;
}
