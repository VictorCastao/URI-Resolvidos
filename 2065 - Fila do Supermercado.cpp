#include <iostream>
#include <cstdio>
#include <deque>
#include <queue>

using namespace std;

struct caixa{
	int id;
	int momento;
};

struct compare{
	bool operator()(const caixa & a, const caixa & b){
		if(a.momento != b.momento) return a.momento > b.momento;
		else return a.id > b.id;
	}
};

int main(){
	priority_queue <caixa, vector<caixa>, compare> atendimento;
	deque <int> lista;
	deque <int> tempo;
	caixa temporario;
	int caixas, pessoas, temp, i, j;
	scanf("%d %d", &caixas, &pessoas);
	for(i=0; i<caixas; i++){
		scanf("%d", &temp);
		tempo.push_back(temp);
	}
	for(i=0; i<pessoas; i++){
		scanf("%d", &temp);
		if(i<caixas){
			temporario.id = i;
			temporario.momento = tempo[i] * temp;
			atendimento.push(temporario);
		}
		else lista.push_back(temp);
	}

	while(!lista.empty()){
		temporario.id = atendimento.top().id;
		temporario.momento = atendimento.top().momento + (tempo[atendimento.top().id] * lista[0]);
		atendimento.pop();
		atendimento.push(temporario);
		lista.pop_front();
	}

	int total;

	while(!atendimento.empty()){
		total = atendimento.top().momento;
		atendimento.pop();
	}

	printf("%d\n", total);

	return 0;
}
 
