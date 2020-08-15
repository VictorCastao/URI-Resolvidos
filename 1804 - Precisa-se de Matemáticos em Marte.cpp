/*
	A resolução do exercício basea-se no conteúdo de "Lazy Propagation".
	No início, os valores dos nós são dados de acordo com os números informados, e o vetor "lazy" inicia zerado.
	Ao atualizar os nós, a única adaptação feita é que, agora, ao invés da soma, o que se deve fazer é uma subtração correspondente ao número de pessoas no bug (já que eles foram abduzidos).
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int Construir(int arvore[], int vetor[], int lazy[], int no, int inicio, int fim){

	if(inicio == fim){
		arvore[no] = vetor[inicio];
		lazy[no] = 0;
		return arvore[no];
	}
	
	int metade = (inicio+fim) / 2;
	int esquerda = Construir(arvore, vetor, lazy, (no*2) + 1, inicio, metade);
	int direita = Construir(arvore, vetor, lazy, (no*2) + 2, metade+1, fim);

	arvore[no] = esquerda + direita;
	lazy[no] = 0;

	return arvore[no];
}

void Atualizar(int arvore[], int lazy[], int no, int inicio, int fim, int p1, int p2, int valor){

	int meio = (inicio+fim) / 2;
	int esquerda = (no*2) + 1;
	int direita = (no*2) + 2;

	if(lazy[no] != 0){
		arvore[no] += lazy[no] * (fim-inicio+1);

		if(inicio != fim){
			lazy[esquerda] += lazy[no];
			lazy[direita] += lazy[no];
		}

		lazy[no] = 0;
	}

	if(inicio > fim or inicio > p2 or fim < p1) return;

	if(p1 <= inicio and p2 >= fim){
		arvore[no] += valor * (fim-inicio+1);
		
		if(inicio != fim){
			lazy[esquerda] += valor;
			lazy[direita] += valor;
		}
	}
	
	else{
		Atualizar(arvore, lazy, esquerda, inicio, meio, p1, p2, valor);
		Atualizar(arvore, lazy, direita, meio+1, fim, p1, p2, valor);
		arvore[no] = arvore[esquerda] + arvore[direita];
	}
}

int Consultar(int arvore[], int lazy[], int no, int inicio, int fim, int p1, int p2){

	int meio = (inicio+fim) / 2;
	int esquerda = (no*2)+1;
	int direita = (no*2)+2;

	if(lazy[no] != 0){
		arvore[no] += lazy[no] * (fim-inicio+1);

		if(inicio != fim){
			lazy[esquerda] += lazy[no];
			lazy[direita] += lazy[no];
		}

		lazy[no] = 0;
	}

	if(inicio > fim or p1 > fim or p2 < inicio) return 0;

	if(p1 <= inicio and p2 >= fim) return arvore[no];

	int soma1 = Consultar(arvore, lazy, esquerda, inicio, meio, p1, p2);
	int soma2 = Consultar(arvore, lazy, direita, meio+1, fim, p1, p2);

	return soma1 + soma2;

}

int main(){

	int qtde;

	scanf("%d", &qtde);

	int tamanho = (pow(2, ceil(log2 (qtde))) * 2) - 1; //Cálculo do número máximo de nós da árvore e do vetor "lazy"

	int vetor[qtde], lazy[tamanho], arvore[tamanho], i, j, resposta, num;

	for(i=0; i<qtde; i++){
		scanf("%d", &vetor[i]);
	}

	Construir(arvore, vetor, lazy, 0, 0, qtde-1);

	char op;

	while(scanf("%c", &op) != EOF){
		
		if(op == 'a'){
			scanf("%d", &num);

			Atualizar(arvore, lazy, 0, 0, qtde-1, num-1, num-1, -vetor[num-1]);
		}

		else if(op == '?'){
			scanf("%d", &num);

			resposta = Consultar(arvore, lazy, 0, 0, qtde-1, 0, num-2);

			printf("%d\n", resposta);
		}
	}
	return 0;
}
