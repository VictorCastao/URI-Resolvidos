#include <iostream>
#include <cstdio>
#include <deque>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	int lista = 1;
	int presentes;
	string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while(cin >> presentes){
		deque <char> codigo;
		deque <int> numeros;
		for(int i=0; i<26; i++){
			numeros.push_back(i+1);
			codigo.push_back('A' + i);
		}
		cin.ignore();
		string temp;
		deque <char> objetos[presentes];
		int num;
		for(int k=0; k<presentes; k++){
			getline(cin, temp);
			istringstream frase(temp);
			while(frase >> num){
				if(num == 27) objetos[k].push_back(' ');
				else{
					objetos[k].push_back(codigo[numeros[num-1]-1]);
					char troca = objetos[k].back();
					int trocanum = numeros[num-1];
					codigo.push_back(troca);
					numeros.push_back(trocanum);
					auto it1 = codigo.begin();
					auto it2 = numeros.begin();
					while(*it1 != troca) it1++;
					while(*it2 != trocanum) it2++;
					codigo.erase(it1);
					numeros.erase(it2);
				}
			}
		}
		multiset <string> resp;
		if(lista != 1) printf("\n");
		printf("LISTA #%d:\n", lista);
		lista++;
		for(int l=0; l<presentes; l++){
			string t = "";
			for(auto it = objetos[l].begin(); it != objetos[l].end(); ++it) t += *it;
			resp.insert(t);
		}

		for(auto m = resp.begin(); m != resp.end(); ++m) cout << *m << endl;







	}
	return 0;
}

