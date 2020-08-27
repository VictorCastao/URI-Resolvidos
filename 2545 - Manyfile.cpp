//PROBLEMA SOLUCIONADO COM ORDENAÇÃO TOPOLÓGICA. ENTRETANTO, O VETOR QUE CONTÉM AS TAREFAS A SEREM EXECUTADAS CONTÉM, TAMBÉM, O TEMPO EM QUE ELAS ACABAM DE SER EXECUTADAS. COM ISSO, BASTA VERIFICAR O TEMPO DA ÚLTIMA TAREFA E DESCOBRIR QUAL O TEMPO TOTAL PARA TUDO SER EXECUTADO.

#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int main(){
	int tarefas;
	while(scanf("%d", &tarefas) != EOF){
		int grau[tarefas+1];
		deque <pair<int,int>> ordem;
		deque <pair<int,int>> execucao;
		deque <int> ligacoes[tarefas+1];
		int a, b, i;

		for(i=1; i<=tarefas; i++) grau[i] = 0;

		for(i=1; i<=tarefas; i++){
			scanf("%d", &a);
			for(int j=0; j<a; j++){
				scanf("%d", &b);
				grau[i]++;
				ligacoes[b].push_back(i);
			}
		}

		for(i=1; i<=tarefas; i++) if(grau[i] == 0) ordem.push_back(make_pair(i,1));

		int k=0;

		while(k < ordem.size()){
			execucao.push_back(ordem[k]);
			for(i=0; i<ligacoes[ordem[k].first].size(); i++){
				grau[ligacoes[ordem[k].first][i]] --;
				if(grau[ligacoes[ordem[k].first][i]] == 0){
					ordem.push_back(make_pair(ligacoes[ordem[k].first][i],ordem[k].second+1));
				}
			}
			k++;
		}

		if(execucao.size() != tarefas) printf("-1\n");

		else{
			printf("%d\n", execucao[tarefas-1].second);
			//for(int i=0; i<execucao.size(); i++) printf("%d %d\n", execucao[i].first, execucao[i].second);

		}
	}
	return 0;
}
