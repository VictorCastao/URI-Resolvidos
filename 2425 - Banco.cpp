#include <iostream>
#include <cstdio>
#include <set>
#include <deque>
#include <queue>

using namespace std;

struct cliente{
	int chegada;
	int tempo;
};


int main(){
	int caixas, pessoas;

	scanf("%d %d", &caixas, &pessoas);

	cliente temp;

	deque <cliente> fila;

	int i, momento, resposta = 0, novahora;

	priority_queue <int, vector<int>, greater<int>> atendimento;

	bool visitado;

	for(i=0; i<pessoas; i++){
		scanf("%d %d", &temp.chegada, &temp.tempo);
		if(i<caixas) atendimento.push(temp.tempo + temp.chegada);
		else fila.push_back(temp);
	}

	while(!fila.empty()){
		if(atendimento.top() < fila.front().chegada){
			atendimento.pop();
			atendimento.push(fila.front().chegada + fila.front().tempo);
			fila.pop_front();
		}
		else{
			if(atendimento.top() - fila.front().chegada > 20) resposta++;
			novahora = atendimento.top() + fila.front().tempo;
			atendimento.pop();
			fila.pop_front();
			atendimento.push(novahora);
		}
	}

	printf("%d\n", resposta);

	return 0;
}
 
