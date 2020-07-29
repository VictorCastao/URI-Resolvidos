#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
	int casos;

	scanf("%d", &casos);

	for(int i=0; i<casos; i++){

		int produtos;

		scanf("%d", &produtos);
		
		map <string, float> tabela;

		float preco;

		string produto;

		for(int j=0; j<produtos; j++){
			cin >> produto;
			scanf("%f", &preco);
			tabela[produto] = preco;
		}

		int quantidade;

		scanf("%d", &quantidade);

		float gasto = 0.0;

		for(int k=0; k<quantidade; k++){
			cin >> produto;
			scanf("%f", &preco);
			gasto += tabela[produto] * preco;
		}

		printf("R$ %.2f\n", gasto);
	}
	return 0;
}

