#include <iostream>

using namespace std;
bool comparar(int a, int b){
	return a>b;
}

int main(){

	int n1, n2, resultado, casos, qtde, correto;

	char op, op2;

	cin >> casos;

	for(int i=0; i<casos; i++){
		cin >> n1 >> op >> n2 >> op2 >> resultado;

		if(op == '+') correto = n1+n2;
		else if(op == '-') correto = n1-n2;
		else correto = n1*n2;

		qtde = resultado - correto;

		if(qtde<0) qtde *= -1;

		cout << "E";

		for(int j=0; j<qtde; j++){
			cout << 'r';
		}

		cout << "ou!\n";

	}
	
	return 0;
}
