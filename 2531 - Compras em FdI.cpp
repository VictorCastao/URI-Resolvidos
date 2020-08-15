//A resolução consiste numa árvore de segmentos que armazena em seus nós um par de inteiro. O primeiro valor corresponde ao menor valor até aquele nó, enquanto o segundo valor corresponde ao maior valor. Com isso, ao fazer a consulta, basta obter o valor absoluto da subtração desses dois elementos, obtendo, assim, a maior diferença entre os valores de determinado intervalo.

#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

pair<int,int> Arvore[300000];

pair<int, int> Construir_Arvore(int vetor[], int no, int inicio, int fim){
	if(inicio == fim){
		Arvore[no].first = vetor[inicio];
		Arvore[no].second = vetor[inicio];		
		return Arvore[no];
	}
	
	int meio = (inicio+fim) / 2;

	pair<int,int> esquerda = Construir_Arvore(vetor, (no*2) + 1, inicio, meio);

	pair<int,int> direita = Construir_Arvore(vetor, (no*2) + 2, meio+1, fim);

	Arvore[no].first = min(esquerda.first, direita.first);
	Arvore[no].second = max(esquerda.second, direita.second);
	
	return Arvore[no];
}

pair<int, int> Atualizar(int no, int indice, int valor, int inicio, int fim){
	if(inicio == fim and inicio == indice){
		Arvore[no].first = valor;
		Arvore[no].second = valor;
		return Arvore[no];
	}
	else if(inicio == fim) return Arvore[no];

	int meio = (inicio + fim) / 2;

	if(indice >= inicio and indice <= meio) Atualizar((no*2)+1, indice, valor, inicio, meio);
	else Atualizar((no*2)+2, indice, valor, meio+1, fim);

	Arvore[no].first = min(Arvore[(no*2)+1].first, Arvore[(no*2)+2].first);
	Arvore[no].second = max(Arvore[(no*2)+1].second, Arvore[(no*2)+2].second);

	return Arvore[no];	
}

pair<int,int> Consulta(int no, int ponto1, int ponto2, int inicio, int fim){
	if(ponto1 > fim or ponto2 < inicio) return make_pair(1000000,-1000000);

	if(ponto1 <= inicio and ponto2 >= fim) return Arvore[no];

	int meio = (inicio + fim) / 2;
	pair<int,int> esquerda = Consulta((no*2) + 1, ponto1, ponto2, inicio, meio);
	pair<int,int> direita = Consulta((no*2) + 2, ponto1, ponto2, meio+1, fim);

	return make_pair(min(esquerda.first, direita.first), max(esquerda.second, direita.second));
} 



int main(){
	int qtde, temp, operacoes, p1, p2, comando;

	while(scanf("%d", &qtde) != EOF){

		int valores[qtde];

		for(int i=0; i<qtde; i++){
			scanf("%d", &temp);
			valores[i] = temp;

		}

		Construir_Arvore(valores, 0, 0, qtde-1);

		scanf("%d", &operacoes);

		for(int i=0; i<operacoes; i++){
			scanf("%d %d %d", &comando, &p1, &p2);

			if(comando == 1){
				Atualizar(0, p1-1, p2, 0, qtde-1);
			}
			else if(comando == 2){
				pair<int,int> resp = Consulta(0,p1-1,p2-1,0,qtde-1);
				printf("%d\n", abs(resp.second - resp.first));
			}
		}
	}

	return 0;

}
