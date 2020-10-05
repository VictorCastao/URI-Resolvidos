#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int sapatos, numero, resp;
	char lado;
	pair<int, int> estoque[61];
	pair<int, int> padrao = make_pair(0,0);

	while (scanf("%d", &sapatos) != EOF){
		for(int i=30; i<=60; i++) estoque[i] = padrao;
		for(int j=0; j<sapatos; j++){
			scanf("%d %c", &numero, &lado);
			if(lado == 'D') estoque[numero].second++;
			else estoque[numero].first++;
		}
		resp = 0;
		for(int k=30; k<=60; k++) resp += min(estoque[k].first, estoque[k].second);
		printf("%d\n", resp);
	}
	
	return 0;

}
