//O exercício foi solucionado utilizando o conceito de Ordenação Topológica

#include <iostream>
#include <cstdio>
#include <set>
#include <deque>

using namespace std;

int main(){
	int tarefas, dependencias;
	scanf("%d %d", &tarefas, &dependencias);
	int grau[tarefas];
	int visitado[tarefas];
	set <int> ordem;
	deque <int> execucao;
	deque <int> ligacoes[tarefas];
	int a, b, i;

	for(i=0; i<tarefas; i++) grau[i] = visitado[i] = 0;

	for(i=0; i<dependencias; i++){
		scanf("%d %d", &a, &b);
		grau[b]++;
		ligacoes[a].push_back(b);
	}

	for(i=0; i<tarefas; i++) if(grau[i] == 0) ordem.insert(i);

	while(! ordem.empty()){
		auto it = ordem.begin();
		execucao.push_back(*it);
		if(visitado[*it] != 1){
			for(i=0; i<ligacoes[*it].size(); i++){
				grau[ligacoes[*it][i]] --;
				if(grau[ligacoes[*it][i]] == 0 and visitado[ligacoes[*it][i]] == 0) ordem.insert(ligacoes[*it][i]);
			}
		}
		visitado[*it] = 1;
		ordem.erase(*it);
	}

	if(execucao.size() != tarefas) printf("*\n");

	else{
		for(i=0; i<tarefas; i++) printf("%d\n", execucao[i]);
	}

	return 0;
}
