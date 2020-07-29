#include <iostream>
#include <deque>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct camiseta{
	string nome;
	string cor;
	char tamanho;
};


bool comparar(camiseta A, camiseta B){
	if(A.cor != B.cor) return A.cor < B.cor;
	else if (A.tamanho != B.tamanho){
		return A.tamanho > B.tamanho;
	}
	else return A.nome < B.nome;
}

int main(){
	int linhas, teste=0;

	while(true){
		cin >> linhas;

		if(linhas == 0) break;
		
		if(teste == 0) teste=1;
		else cout << endl;

		deque <camiseta> pessoas;

		for(int i=0; i<linhas; i++){
			camiseta temp;
			cin.ignore();
			getline(cin, temp.nome);
			cin >> temp.cor >> temp.tamanho;
			pessoas.push_back(temp);
		}

		sort(pessoas.begin(), pessoas.end(), comparar);

		for(int j=0; j<pessoas.size(); j++){
			cout << pessoas[j].cor << " " << pessoas[j].tamanho << " " << pessoas[j].nome << endl; 

		}

	}
	return 0;
}

