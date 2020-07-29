#include <iostream>
#include <cstdio>
#include <deque>
#include <queue>

using namespace std;

struct atendente{
	int id;
	int duracao;
};

struct comparar{
	bool operator()(const atendente& a, const atendente& b){
		if(a.duracao != b.duracao) return a.duracao > b.duracao;
		else return a.id > b.id;
	}
};

int main(){
	int funcionarios, ligacoes, i, j;

	scanf("%d %d", &funcionarios, &ligacoes);

	int ligacoes_feitas[funcionarios], templig;

	for(i=0; i<funcionarios; i++){
		ligacoes_feitas[i] = 0;
	}
	
	atendente temp, troca;

	deque <int> lista;

	int tempo;

	int momento = 0;

	deque <atendente> transicao;

	priority_queue <atendente, vector<atendente>, comparar> trabalho;

	for(i=0; i<ligacoes; i++){
		scanf("%d", &templig);
		lista.push_back(templig);
	}

	for(i=0; i<funcionarios and !lista.empty(); i++){
		temp.id = i;
		ligacoes_feitas[i]++;
		temp.duracao = lista[0];
		lista.pop_front();
		trabalho.push(temp);
	}

	while(!lista.empty()){
		temp.id = trabalho.top().id;
		temp.duracao = trabalho.top().duracao + lista.front();
		lista.pop_front();
		trabalho.pop();
		trabalho.push(temp);
		ligacoes_feitas[temp.id]++;
	}

	for(j=0; j<funcionarios; j++){
		printf("%d %d\n", j+1, ligacoes_feitas[j]);
	}

	return 0;
}
 
