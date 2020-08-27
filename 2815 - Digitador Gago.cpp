//Minha Solução: Ler a string e a cada palavra (verificada se o caracter anterior for ' ') verificar se as duas primeiras letras se repetem.

#include <iostream>

using namespace std;

int main(){
	string frase;
	getline(cin, frase);
	string resultado = "";
	bool espaco = true;
	for(int i=0; i<frase.size(); i++){
		if(espaco){
			if(i+3 < frase.size() and frase[i] == frase[i+2] and frase[i+1] == frase[i+3]){
				espaco = false;
				i++;
				continue;
			}
		}
		resultado+=frase[i];
		if(frase[i] == ' ') espaco = true;
		else espaco = false; 
	}
	cout << resultado << endl;

	return 0;
}
