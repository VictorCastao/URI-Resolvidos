#include <iostream>
#include <cstdio>
#include <deque>
#include <queue>

using namespace std;

int main(){
	int operacoes;

	while(cin >> operacoes){
		deque <int> estrutura;
		int op, valor1, valor2;
		bool fila = true, pilha = true, prioridade = true;
		for(int i=0; i<operacoes; i++){
			scanf("%d %d", &valor1, &valor2);
			if(valor1 == 1) estrutura.push_back(valor2);
			else{
				int lugar=0;
				int maior=-1;
				int j;
				for(j=0; j<estrutura.size(); j++){
					if(estrutura[j] == valor2) lugar = j;
					if(estrutura[j] > maior) maior = estrutura[j];
				}

				if(valor2 != maior) prioridade = false;
				if(lugar != 0) fila = false;
				if(lugar != estrutura.size()-1) pilha = false;
				if(lugar == 0 and estrutura[0] != valor2){
					pilha = false;
					fila = false;
					prioridade = false;
				}
				else estrutura.erase(estrutura.begin()+lugar);
			}
		}

		if(!prioridade and !pilha and !fila) printf("impossible\n");
		else if(pilha and !prioridade and !fila) printf("stack\n");
		else if(!pilha and prioridade and !fila) printf("priority queue\n");
		else if(!pilha and !prioridade and fila) printf("queue\n");
		else printf("not sure\n");
	}

	return 0;
}
 
