#include <iostream>
#include <cstdio>
#include <map>
#include <sstream>

using namespace std;

int main(){
	int palavras, teste;

	string temp;

	int temp2;
	
	while(cin >> palavras >> teste){

		map <string, int> cargo;

		for(int i=0; i<palavras; i++){
			cin >> temp >> temp2;
			cargo.insert(make_pair (temp, temp2));
		}

		cin.ignore();

		for(int j=0; j<teste; j++){
			long int soma = 0;
			string word;
			while(true){
				getline(cin, temp);
				if(temp == ".") break;
				istringstream frase(temp);
				while(frase >> word){
					if(cargo.find(word) != cargo.end()) soma += cargo[word];
				}
			}
			
			cout << soma << endl;
		}
	}
	return 0;
}

