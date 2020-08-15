/*
	Inicialmente, lê-se 2 strings relativas ao nome e sobrenome
	Após, com um for percorrendo as 2 strings, somar à string de resposta duas letras da primeira string e mais duas letras da segunda string, fazendo isso até que as strings sejam percorridas por completo.
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int casos;
	scanf("%d", &casos);
	for(int i=0; i<casos; i++){
		string nome = "";
		string l1, l2;
		if(i == 0) cin.ignore();
		getline(cin, l1);
		getline(cin, l2);
		for(int j=0; j<l1.size(); j+=2){
			nome+=l1[j];
			nome+=l1[j+1];
			nome+=l2[j];
			if(j+1 < l2.size()) nome+=l2[j+1];	
		}
		cout << nome << endl;
	}
	return 0;

}
