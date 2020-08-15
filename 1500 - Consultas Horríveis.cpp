// Problema típico de "lazy propagation", que foi solucionado utilizando desse mesmo conceito.

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long Construir(long long arvore[], long long vetor[], long long lazy[], long long no, long long inicio, long long fim){

	if(inicio == fim){
		arvore[no] = vetor[inicio];
		lazy[no] = 0;
		return arvore[no];
	}
	
	long long metade = (inicio+fim) / 2;
	long long esquerda = Construir(arvore, vetor, lazy, (no*2) + 1, inicio, metade);
	long long direita = Construir(arvore, vetor, lazy, (no*2) + 2, metade+1, fim);

	arvore[no] = esquerda + direita;
	lazy[no] = 0;

	return arvore[no];
}

void Atualizar(long long arvore[], long long lazy[], long long no, long long inicio, long long fim, long long p1, long long p2, long long valor){

	long long meio = (inicio+fim) / 2;
	long long esquerda = (no*2) + 1;
	long long direita = (no*2) + 2;

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

long long Consultar(long long arvore[], long long lazy[], long long no, long long inicio, long long fim, long long p1, long long p2){

	long long meio = (inicio+fim) / 2;
	long long esquerda = (no*2)+1;
	long long direita = (no*2)+2;

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

	long long soma1 = Consultar(arvore, lazy, esquerda, inicio, meio, p1, p2);
	long long soma2 = Consultar(arvore, lazy, direita, meio+1, fim, p1, p2);

	return soma1 + soma2;

}

int main(){

	int qtde, operacoes, casos;

	scanf("%d", &casos);

	for(int l=0; l<casos; l++){

		scanf("%d %d", &qtde, &operacoes);

		int tamanho = (pow(2, ceil(log2 (qtde))) * 2) - 1;

		long long vetor[qtde], lazy[tamanho], arvore[tamanho], i, j, A, B, K, O, resposta;

		for(i=0; i<qtde; i++){
			vetor[i] = 0;
		}

		Construir(arvore, vetor, lazy, 0, 0, qtde-1);

		for(j=0; j<operacoes; j++){
			scanf("%lli", &O);
			
			if(O == 0){
				scanf("%lli %lli %lli", &A, &B, &K);

				Atualizar(arvore, lazy, 0, 0, qtde-1, A-1, B-1, K);
			}

			else if(O == 1){
				scanf("%lli %lli", &A, &B);

				resposta = Consultar(arvore, lazy, 0, 0, qtde-1, A-1, B-1);

				printf("%lli\n", resposta);
			}
		}
	}
	return 0;
}
