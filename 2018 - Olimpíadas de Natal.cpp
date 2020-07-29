#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <deque>

using namespace std;

struct QUADRO{
	string nome;
	int ouro = 0;
	int prata = 0;
	int bronze = 0;
};

bool ordem(QUADRO a, QUADRO b){
	if (a.ouro != b.ouro) return a.ouro > b.ouro;
	else if (a.prata != b.prata) return a.prata > b.prata;
	else if (a.bronze != b.bronze) return a.bronze > b.bronze;   
	else return a.nome < b.nome;

}

int main(){
	string primeiro, segundo, terceiro, modalidade;

	set <string> quadro;

	deque <QUADRO> tabela;

	QUADRO temp;

	while(getline(cin, modalidade)){
		getline(cin, primeiro);
		getline(cin, segundo);
		getline(cin, terceiro);
		if(quadro.find(primeiro) != quadro.end()){
			for(auto it = tabela.begin(); it != tabela.end(); it++){
				if(it->nome == primeiro){
					(it->ouro)++;
					break;
				}
			}
		}
		else{
			quadro.insert(primeiro);
			temp.nome = primeiro;
			temp.ouro = 1;
			temp.prata = 0;
			temp.bronze = 0;
			tabela.push_back(temp);			
		}

		if(quadro.find(segundo) != quadro.end()){
			for(auto it = tabela.begin(); it != tabela.end(); it++){
				if((it->nome) == segundo){
					(it->prata)++;
					break;
				}
			}
		}
		else{
			quadro.insert(segundo);
			temp.nome = segundo;
			temp.ouro = 0;
			temp.prata = 1;
			temp.bronze = 0;
			tabela.push_back(temp);			
		}
		
		if(quadro.find(terceiro) != quadro.end()){
			for(auto it = tabela.begin(); it != tabela.end(); it++){
				if((it->nome) == terceiro){
					(it->bronze)++;
					break;
				}
			}
		}
		else{
			quadro.insert(terceiro);
			temp.nome = terceiro;
			temp.ouro = 0;
			temp.prata = 0;
			temp.bronze = 1;
			tabela.push_back(temp);			
		}


	}
	

	sort(tabela.begin(), tabela.end(), ordem);

	printf("Quadro de Medalhas\n");

	for(auto it=tabela.begin(); it != tabela.end(); it++){
		cout << it->nome;
		printf(" %d %d %d\n", it->ouro, it->prata, it->bronze);
	}

	return 0;
}

