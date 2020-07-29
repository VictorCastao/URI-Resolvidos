#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct carro{
    int id;
    int tempo = 0;
};

bool comparar(carro a, carro b){
	return a.tempo < b.tempo;
}

int main(){
	int competidores, voltas, i, j, tempoaux;
	
	cin >> competidores >> voltas;
	
	deque <carro> lista;
	
	for(i=0; i<competidores; i++){
	    carro temp;
	    temp.id = i+1;
	    for(j=0; j<voltas; j++){
	        cin >> tempoaux;
	        temp.tempo += tempoaux;
	    }
	    lista.push_back(temp);
	}
	
	sort(lista.begin(), lista.end(), comparar);
	
	for(i=0; i<3; i++) cout << lista[i].id << endl;
	
	return 0;
}

