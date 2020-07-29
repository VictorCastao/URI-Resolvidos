#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
	int linha, coluna, inserir, temp;

	while(true){
		cin >> linha >> coluna >> inserir;
		if(linha == 0 and coluna == 0 and inserir == 0) break;
		deque <int> pilhas[coluna];
		deque <int> bloco;
		int livres = 0;
		for(int i=0; i<linha; i++){
			for(int j=0; j<coluna; j++){
				cin >> temp;
				if (temp != 0) pilhas[j].push_back(temp);
				else livres++;
			}
		}
	
		for(int k=0; k<inserir; k++){
			cin >> temp;
			bloco.push_back(temp);
		}

		int aux = inserir;		
	
		for(int i=coluna-2; i>=0; i--){
			while(!bloco.empty() and livres != 0 and pilhas[i].size() != pilhas[coluna-1].size()){
				pilhas[i].push_front(bloco.front());
				bloco.pop_front();
				livres--;
			}
		}

		for(int p=0; p<coluna-1; p++){
			while(pilhas[p].size() != pilhas[coluna-1].size()) pilhas[p].push_front(0);
		}

		for(int i=0; i<linha; i++){
			for(int j=0; j<coluna-1; j++){
				cout << pilhas[j][i] << " ";
			}
			cout << pilhas[coluna-1][i] << endl;
		}
	}
	return 0;
}

