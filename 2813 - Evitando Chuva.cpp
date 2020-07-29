#include <iostream>

using namespace std;

int main(){
	string previsao_casa, previsao_trabalho;

	int qtde_casa = 0, qtde_trabalho = 0, dias, tem_casa = 0, tem_trabalho = 0;
	
	string chuva = "chuva";

	string sol = "sol";

	cin >> dias;

	for(int i=0; i<dias; i++){
		cin >> previsao_casa >> previsao_trabalho;

		if (previsao_casa == chuva and tem_casa == 0){
			qtde_casa++;
			tem_trabalho++;
		}
	
		if (previsao_casa == chuva and tem_casa > 0){
			tem_casa--;
			tem_trabalho++;
		}

		if (previsao_trabalho == chuva and tem_trabalho == 0){
			qtde_trabalho++;
			tem_casa++;
		}

		if (previsao_trabalho == chuva and tem_trabalho > 0){
			tem_casa++;
			tem_trabalho--;
		}
	}

	cout << qtde_casa << " " << qtde_trabalho << endl;

	return 0;
}
