#include <iostream>
#include <set>
#include <stdio.h>


using namespace std;

int main(){
	int pares;

	while(scanf("%d", &pares) != EOF){
		multiset <int> numeros;
		int a, b;		
		for(int i=0; i< pares; i++){
			cin >> a >> b;
			for(int j=a; j<=b; j++) numeros.insert(j);
		}
		int busca;
		cin >> busca;

		if(numeros.find(busca) == numeros.end()) cout << busca << " not found\n";

		else{
			int posicao1, posicao2;
			auto it = numeros.equal_range(busca);
			cout << busca << " found from " << distance (numeros.begin(), it.first) << " to " << distance (numeros.begin(), it.second) - 1 << endl;
		
		}
	}

	return 0;
}

