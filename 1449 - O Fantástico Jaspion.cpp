#include <iostream>
#include <cstdio>
#include <sstream>
#include <map>
#include <deque>

using namespace std;

int main(){
	int testes;

	while(cin >> testes){
		for(int k=0; k<testes; k++){
		
			int i, j, qtde_palavras, versos;

			string verbete; 
			string traducao;

			scanf("%d %d", &qtde_palavras, &versos);

			map <string, string> dicionario;

			for(i=0; i<qtde_palavras; i++){
				cin >> verbete;
				cin.ignore();
				getline(cin, traducao);
				dicionario[verbete] = traducao;

			}

			deque <string> letra[versos];

			string frase;

			string palavra;

			for(j=0; j<versos; j++){
				//cin.ignore();
				getline(cin, frase);
				istringstream separador(frase);
				while(separador >> palavra){ 
					if(dicionario.find(palavra) == dicionario.end()) letra[j].push_back(palavra);
					else letra[j].push_back(dicionario[palavra]);
				}
			}

			for(i=0; i<versos; i++){
				auto it = letra[i].begin();
				while(it != letra[i].end()){
					if(it == letra[i].begin()) cout << *it;
					else cout << " " << *it;
					it++;
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	return 0;
}

