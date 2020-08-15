/*
	O exercício foi solucionado através de conceitos relativos a geometria e ao Algoritmo de Kruskal.
	Inicialmente, as coordenadas das pessoas são lidas.
	Em seguida cria-se uma estrutura contendo 3 variáveis: início, fim e distância.
	Em seguida, para cada ponto, calcula-se a distância entre este e todos os demais, separadamente.
	Após, a identificação dos pontos de origem e destino, junto com a distância entre eles, é adicionada à estrutura, que é colocada em um vetor.
	Depois de todos os cálculos, o vetor é ordenado por ordem crescente da distância.
	Com esse vetor, realiza-se o Algoritmo de Kruskal até que se descubra a menor distância para conectar todos os pontos.  
*/
#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

double dist(pair<double, double> a, pair<double, double> b){
	double q1 = a.first-b.first, q2 = a.second-b.second;
	return sqrt(pow(q1,2) + pow(q2,2));
}

int membros[501], chefe[501];

struct conexao{
	int id1, id2;
	double distancia;
};

bool comp2(conexao a, conexao b){
	return a.distancia < b.distancia;
}

int busca(int v){
	if(chefe[v] == v) return v;
	else return chefe[v] = busca(chefe[v]);
}

pair<double, int> uniao(int a, int b, double distancia){
	int chefe1 = busca(a), chefe2 = busca(b);
	if(chefe1 == chefe2) return make_pair(0.0,0);
	else if(membros[chefe1] > membros[chefe2]){
		membros[chefe1] += membros[chefe2];
		chefe[chefe2] = chefe[chefe1];
		return make_pair(distancia, membros[chefe1]);
	}
	else{
		membros[chefe2] += membros[chefe1];
		chefe[chefe1] = chefe[chefe2];
		return make_pair(distancia, membros[chefe2]);
	}
}
 
int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int pontos;
		scanf("%d", &pontos);
		pair <double, int> resp;
		pair <double, double> leitura;
		deque <pair<double, double>> coordenadas;

		//Leitura das coordenadas
		for(int i=0; i<pontos; i++){
			scanf("%lf %lf", &leitura.first, &leitura.second);
			coordenadas.push_back(leitura);
		}

		double soma_menor = 0;
		deque <conexao> fila_menor;
		conexao temp;

		//Cálculos das distâncias
		for(int j=0; j<pontos-1; j++){
			for(int k=j+1; k<pontos; k++){
				temp.id1 = j+1;
				temp.id2 = k+1;
				temp.distancia = dist(coordenadas[j], coordenadas[k]);
				fila_menor.push_back(temp);
			}
		}

		//Inicializando vetores a serem utilizados
		for(int i=1; i<=pontos; i++){
			membros[i] = 1;
			chefe[i] = i;
		}

		//Ordenar distâncias em ordem crescente
		sort(fila_menor.begin(), fila_menor.end(), comp2);

		//Algoritmo de Kruskal
		for(int k=0; k<fila_menor.size(); k++){
			resp = uniao(fila_menor[k].id1, fila_menor[k].id2, fila_menor[k].distancia);
			soma_menor += resp.first;
			if(resp.second == pontos) break; //Critério de parada
		}

		printf("%.2lf\n", soma_menor/100); //Resposta
	}	
	return 0;
}

