#include <iostream>
#include <bitset>
#include <queue>
#include <cstdio>


using namespace std;

struct Comp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.first>b.first;
    }
};

int main(){
	int cidades, estradas, atual, pedagio;
	int teste = 1;
	while(true){
		scanf("%d %d %d %d", &cidades, &estradas, &atual, &pedagio);
		if(cidades==0 and estradas==0 and atual==0 and pedagio==0) break;		
		bitset <51> visitados(0);
		deque <pair<int,int>> caminhos[cidades+1];
		int minimos[cidades+1];
		int p1, p2;
		priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> fila;
		for(int i=0; i<estradas; i++){
			scanf("%d %d", &p1, &p2);
			caminhos[p1].push_back(make_pair(1,p2));
			caminhos[p2].push_back(make_pair(1,p1));  
		}
		for(int i=1; i<=cidades; i++) minimos[i] = 10000;
		minimos[atual] = 0;
		fila.push(make_pair(0, atual));
		pair <int, int> temp;
		while(true){
			int b = 0;
			while(!fila.empty()){
				temp = fila.top();
				fila.pop();
				if(visitados[temp.second] == 0){
					b=1;
					break;
				}
			}
			if(b==0) break;
			visitados[temp.second] = 1;
			for(int j=0; j<caminhos[temp.second].size(); j++){
				if(minimos[caminhos[temp.second][j].second] > temp.first + 1){
					minimos[caminhos[temp.second][j].second] = temp.first + 1;
					fila.push(make_pair(temp.first+1, caminhos[temp.second][j].second));
				}
			}	
		}

		printf("Teste %d\n", teste);

		teste++;

		bool f=true;

		for(int k=1; k<=cidades; k++){
			if(minimos[k] <= pedagio and minimos[k] != 0){
				printf("%d ", k);
			} 
		}

		printf("\n\n");
	
	}

	return 0;
}

