#include <iostream>
#include <deque>
#include <cstdio>

using namespace std;

int main(){
	int operacoes, i, numero, min;
	deque <int> pilha;
	char comando[5];
	scanf("%d", &operacoes);
	deque <int> :: iterator it;
	for(i=0; i<operacoes; i++){
		scanf("%s", &comando[0]);
		if(comando[1] == 'U'){
			scanf("%d", &numero);
			pilha.push_back(numero);
		}
		else if(comando[1] == 'O'){
			if(pilha.empty()) printf("EMPTY\n");
			else pilha.pop_back();
		}
		else if(comando[0] == 'M'){
			if(pilha.empty()) printf("EMPTY\n");
			else{
				min = pilha.front();	
				for(it = pilha.begin(); it != pilha.end(); it++){
					if(*it <= min) min = *it;
				}
				printf("%d\n", min);
			}
		}
	}
	return 0;
}
