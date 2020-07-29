#include <iostream>
#include <deque> 
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
	int casos, i, j, k;

	while(scanf("%d", &casos) != EOF){
		deque <int> X;
		deque <int> Y;
		deque <int> Z;
		deque <string> NOMES;
		deque <string> ERRO;
		int num1, num2, num3;
		char op1;
		for(i=0; i<casos; i++){
			scanf("%d %d%c%d", &num1, &num2, &op1, &num3);
			X.push_back(num1);
			Y.push_back(num2);
			Z.push_back(num3);    
		}

		int expressao;
		string nome;
		char operador;
		
		for(j=0; j<casos; j++){
			cin >> nome;
			scanf("%d %c", &expressao, &operador);
			if(operador == '+' and X[expressao-1]+Y[expressao-1] == Z[expressao-1]) NOMES.push_back(nome);
			else if(operador == '-' and X[expressao-1]-Y[expressao-1] == Z[expressao-1]) NOMES.push_back(nome);
			else if(operador == '*' and X[expressao-1]*Y[expressao-1] == Z[expressao-1]) NOMES.push_back(nome);
			else if(operador == 'I' and X[expressao-1]+Y[expressao-1] != Z[expressao-1] and X[expressao-1]-Y[expressao-1] != Z[expressao-1] and X[expressao-1]*Y[expressao-1] != Z[expressao-1]) NOMES.push_back(nome);
			else ERRO.push_back(nome);
		}

		if(NOMES.size() == casos) cout << "You Shall All Pass!\n";
		else if(NOMES.empty()) cout << "None Shall Pass!\n";
		else{
			sort(ERRO.begin(), ERRO.end());
			for(k=0; k<ERRO.size(); k++){
				cout << ERRO[k];
				if(k == ERRO.size()-1) cout << endl;
				else cout << " ";
			}
		}
	}
	return 0;
}

