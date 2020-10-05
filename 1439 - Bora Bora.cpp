#include <iostream>
#include <deque>
#include <queue>
#include <cstdio>
#include <map>
#include <stack>

using namespace std;

struct carta{
	int valor;
	char naipe;
	int peso;
};

int main(){
	int jogadores, inicial, monte, i, j;
	while(true){

		scanf("%d %d %d", &jogadores, &inicial, &monte);

		if(jogadores == 0 and inicial == 0 and monte == 0) break;

		//Estruturas necessárias
		deque <carta> jogo[jogadores+1];
		queue <carta> saque;
		stack <carta> descarte;
		int qtde[jogadores+1];
		int sentido = 1; //Exercício especifica que o sentido horário é o que inicia
		int vencedor;
		bool efeito = false;

		//Definir peso dos naipes (Lembrando que o peso de uma carta, em si, depende do valor e depois do naipe)
		map <char, int> conversao;
		conversao['C'] = 1;
		conversao['D'] = 2;
		conversao['H'] = 3;
		conversao['S'] = 4;	

		for(i=1; i<=jogadores; i++){
			qtde[i] = inicial;
		}

		carta temp, escolha;
		deque <carta>::iterator apagar;

		//Cartas jogadores
		for(i=1; i<=jogadores; i++){
			for(j=1; j<=inicial; j++){
				scanf("%d %c", &temp.valor, &temp.naipe);
				temp.peso = ((temp.valor-1) * 4) + conversao[temp.naipe]; //Ex: "1 S" tem peso 4 e "2 C" tem peso 5
				jogo[i].push_back(temp);
			}
		}

		//Carta de início
		scanf("%d %c", &temp.valor, &temp.naipe);
		temp.peso = ((temp.valor-1) * 4) + conversao[temp.naipe];
		descarte.push(temp);
		
		//Carta especial no começo		
		if(temp.valor == 1 or temp.valor == 7 or temp.valor == 11) efeito = true;
		if(temp.valor == 12) sentido*=-1;

		//Definir cartas a serem lidas ainda
		monte-=(jogadores*inicial);
		monte--;

		//Cartas monte
		for(i=1; i<=monte; i++){
			scanf("%d %c", &temp.valor, &temp.naipe);
			temp.peso = ((temp.valor-1) * 4) + conversao[temp.naipe];
			saque.push(temp);
		}

		//Jogo ocorrendo
		//OBS: Se efeito = false, a consequência da carta já foi aplicada. Além disso, diferente das cartas "1", "7" e "11", cuja consequência é aplicada diretamente no jogador do laço, o caso da dama inverte o sentido assim que o jogador da vez lança a carta. Fiz isso para evitar o erro de um mesmo jogador acabar jogando duas vezes seguidas.
		for(i=1; ;i+=sentido){
			//Corrigindo possíveis falhas
			if(i > jogadores) i = 1;
			if(i < 1) i=jogadores;

			//Caso Ás
			if(descarte.top().valor == 1 and efeito){
				jogo[i].push_back(saque.front());
				saque.pop();
				qtde[i]+=1;
				efeito = false;
				continue;
			}

			//Caso Sete
			if(descarte.top().valor == 7 and efeito){
				jogo[i].push_back(saque.front());
				saque.pop();
				jogo[i].push_back(saque.front());
				saque.pop();
				qtde[i]+=2;
				efeito = false;
				continue;
			}

			//Caso Valete
			if(descarte.top().valor == 11 and efeito){
				efeito = false;	
				continue;
			
			}
			//Escolher melhor carta para descartar
			escolha.peso = 0;
			for(auto it = jogo[i].begin(); it != jogo[i].end(); it++){
				if((*it).naipe == descarte.top().naipe or (*it).valor == descarte.top().valor){
					if((*it).peso > escolha.peso){
						escolha = *it;
						apagar = it;
					}
				}
			}

			//Tem carta para descartar
			if(escolha.peso != 0){
				descarte.push(escolha);
				jogo[i].erase(apagar);
				qtde[i]--;
				if(descarte.top().valor == 1 or descarte.top().valor == 7 or descarte.top().valor == 11) efeito = true;
				if(descarte.top().valor == 12) sentido*=-1; //Caso Dama
			}

			//Pesca do monte
			else{
				//Carta possível
				if(saque.front().valor == descarte.top().valor or saque.front().naipe == descarte.top().naipe){
					descarte.push(saque.front());
					saque.pop();
					if(descarte.top().valor == 1 or descarte.top().valor == 7 or descarte.top().valor == 11) efeito = true;
					if(descarte.top().valor == 12) sentido*=-1; //Caso Dama
				}

				//Ficar com a carta
				else{
					jogo[i].push_back(saque.front());
					saque.pop();
					qtde[i]++;
				}
			}

			//Jogador sem cartas vence
			if(qtde[i] == 0){
				vencedor = i;
				break;
			}
		}

		printf("%d\n", vencedor);
	}
	return 0;
}
