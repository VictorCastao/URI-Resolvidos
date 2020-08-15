#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

char Arvore[300000];

char Construir_Arvore(char vetor[], int no, int inicio, int fim){
	if(inicio == fim){
		Arvore[no] = vetor[inicio];	
		return vetor[inicio];
	}
	
	int meio = (inicio+fim) / 2;

	char esquerda = Construir_Arvore(vetor, (no*2) + 1, inicio, meio);

	char direita = Construir_Arvore(vetor, (no*2) + 2, meio+1, fim);

	if(direita == '0' or esquerda == '0') Arvore[no] = '0';
	else if(direita == esquerda) Arvore[no] = '+';
	else Arvore[no] = '-';
	
	return Arvore[no];
}

char Atualizar(int no, int indice, char valor, int inicio, int fim){
	if(inicio == fim){
		Arvore[no] = valor;
		return valor;
	}

	int meio = (inicio + fim) / 2;

	if(indice >= inicio and indice <= meio) Atualizar((no*2)+1, indice, valor, inicio, meio);
	else Atualizar((no*2)+2, indice, valor, meio+1, fim);

	if(Arvore[(no*2)+1] == '0' or Arvore[(no*2)+2] == '0') Arvore[no] = '0';
	else if (Arvore[(no*2)+1] == Arvore[(no*2)+2]) Arvore[no] = '+';
	else Arvore[no] = '-';

	return Arvore[no];	
}

char Consulta(int no, int ponto1, int ponto2, int inicio, int fim){
	if(ponto1 > fim or ponto2 < inicio) return '+';

	if(ponto1 <= inicio and ponto2 >= fim) return Arvore[no];

	int meio = (inicio + fim) / 2;
	char esquerda = Consulta((no*2) + 1, ponto1, ponto2, inicio, meio);
	char direita = Consulta((no*2) + 2, ponto1, ponto2, meio+1, fim);

	if(direita == '0' or esquerda == '0') return '0';
	else if(direita == esquerda) return '+';
	else return '-';
} 



int main(){
	int qtde, temp, operacoes, p1, p2;
	char comando, sinal;

	while(scanf("%d %d", &qtde, &operacoes) != EOF){

		char valores[qtde];

		for(int i=0; i<qtde; i++){
			scanf("%d", &temp);

			if(temp == 0) valores[i] = '0';
			else if(temp > 0) valores[i] = '+';
			else valores[i] = '-'; 

		}

		Construir_Arvore(valores, 0, 0, qtde-1);

		deque <char> respostas;

		for(int i=0; i<operacoes; i++){
			scanf(" %c %d %d", &comando, &p1, &p2);

			if(comando == 'C'){

				if(p2 == 0) sinal = '0';
				else if(p2 > 0) sinal = '+';
				else sinal = '-';

				Atualizar(0, p1-1, sinal, 0, qtde-1);

			}

			else if(comando == 'P'){

				char op = Consulta(0, p1-1, p2-1, 0, qtde-1);
				respostas.push_back(op);

			}
		}

		for(int i=0; i<respostas.size(); i++){
			printf("%c", respostas[i]);
		}

		printf("\n");

	}

	return 0;

}
