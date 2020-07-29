#include <iostream>

using namespace std;

int main(){
	string nome;

	getline(cin, nome);
	
	int letras = 0;
	
	string nome1 = "ZELDA";

	string nome2 = "zelda";

	int marcador_letra = 0;

	for(int i=0; i<nome.size(); i++){
		if(nome[i] == nome1[marcador_letra] or nome[i] == nome2[marcador_letra]){
			letras++;
			marcador_letra++;
		}

		else{
			letras = 0;
			marcador_letra = 0;
		}

		if(letras == 5) break;
	}

	if (letras == 5) cout << "Link Bolado\n";

	else cout << "Link Tranquilo\n";

	return 0;
}
