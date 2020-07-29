#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int qtde;
	while(true){
		scanf("%d", &qtde);
		if(qtde == 0) break;
		int maria = 0, joao = 0, result;
		for(int i=0; i<qtde; i++){
			scanf("%d", &result);
			if (result == 0) maria++;
			else joao++;
		}
		printf("Mary won %d times and John won %d times\n", maria, joao);
	}
	return 0;
}
