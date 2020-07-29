#include <iostream>
#include <cstdio>

using namespace std;
int chefe[100001], peso[100001];

int procura_chefe(int banco){
	if(chefe[banco] == banco) return banco;
	else return chefe[banco] = procura_chefe(chefe[banco]);
}

void uniao(int b1, int b2){
	int digito1 = procura_chefe(b1);
	int digito2 = procura_chefe(b2);
	if(digito1 == digito2) return;
	else if(peso[digito1] > peso[digito2]) chefe[digito2] = digito1;
	else if(peso[digito2] > peso[digito1]) chefe[digito1] = digito2;
	else if(peso[digito1] == peso[digito2]){
		chefe[digito2] = digito1;
		peso[digito1]++;
	}
	return;
}

int main(){
	int numero_banco, numero_operacoes, i, j, banco1, banco2, consulta1, consulta2;
	char comando;
	cin >> numero_banco >> numero_operacoes;
	for(i=1; i<=numero_banco; i++){
		peso[i] = 1;
		chefe[i] = i;
	}
	for(j=0; j<numero_operacoes; j++){
		cin >> comando >> banco1 >> banco2;
		if(comando == 'F') uniao(banco1, banco2);
		else if(comando == 'C'){
			consulta1 = procura_chefe(banco1);
			consulta2 = procura_chefe(banco2);
			if(consulta1 == consulta2) cout << "S\n";
			else cout << "N\n";
		}
	}
	return 0;
}
