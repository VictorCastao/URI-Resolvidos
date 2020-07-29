#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct rena{
	string nome;
	int peso;
	int idade;
	double altura;
};

bool comparador(rena a, rena b){
	if(a.peso != b.peso) return a.peso>b.peso;
	else if(a.idade != b.idade) return a.idade<b.idade;
	else if(a.altura != b.altura) return a.altura<b.altura;
	else return a.nome<b.nome;
}

int main(){
	int casos, renas, treno;

	cin >> casos;

	for(int i=0; i<casos; i++){
		cin >> renas >> treno;

		vector <rena> lista;

		for(int j=0; j<renas; j++){
			rena aux;

			cin >> aux.nome >> aux.peso >> aux.idade >> aux.altura;

			lista.push_back(aux);

		}

		sort(lista.begin(), lista.end(), comparador);

		for(int k=0; k<treno; k++){
			if (k==0) cout << "CENARIO {" << i+1 << "}" << endl;
			cout << k+1 << " - " << lista[k].nome << endl;
		}
	}
	return 0;

}
