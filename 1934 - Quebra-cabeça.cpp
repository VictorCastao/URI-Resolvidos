#include <iostream>
#include <set>
#include <map>
#include <cstdio>

using namespace std;

int main(){
	int linhas, colunas;
	scanf("%d %d", &linhas, &colunas);
	string matriz[linhas][colunas];
	set <string> distintos;  //Verificar quantas incógnitas
	map <string, int> descobertos; //Verfificar descobertos
	int valor_linha[linhas], valor_coluna[colunas];
	//Ler valores
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			cin >> matriz[i][j];
			distintos.insert(matriz[i][j]);
		}
		cin >> valor_linha[i];
	}
	for(int k=0; k<colunas; k++) cin >> valor_coluna[k];
	//Loop para descobrir elementos
	while(descobertos.size() < distintos.size()){
		//Percorrer linhas
		for(int l=0; l<linhas; l++){
			map<string, int> nao_descoberto;
			int soma = 0;
			for(int m=0; m<colunas; m++){
				if(descobertos.find(matriz[l][m]) == descobertos.end()) nao_descoberto[matriz[l][m]]++; //Valor não descoberto
				else soma+=descobertos[matriz[l][m]]; // Valor já descoberto
			}
			//Se só tiver 1 incógnita, descobrir o valor e adicioná-la
			if(nao_descoberto.size() == 1){
				int result = valor_linha[l] - soma;
				pair<string, int> novo = *nao_descoberto.begin();
				descobertos[novo.first] = result / novo.second;
			}
		}
		//Percorrer colunas
		for(int m=0; m<colunas; m++){
			map<string, int> nao_descoberto2;
			int soma2 = 0;
			for(int l=0; l<linhas; l++){
				if(descobertos.find(matriz[l][m]) == descobertos.end()) nao_descoberto2[matriz[l][m]]++; //Valor já descoberto
				else soma2+=descobertos[matriz[l][m]]; // Valor não descoberto
			}
			//Se só tiver 1 incógnita, descobrir o valor e adicioná-la
			if(nao_descoberto2.size() == 1){
				int result2 = valor_coluna[m] - soma2;
				pair<string, int> novo2 = *nao_descoberto2.begin();
				descobertos[novo2.first] = result2 / novo2.second;
			}
		}
	}
	//Imprimir valores em ordem alfabética
	for(auto it = descobertos.begin(); it != descobertos.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
