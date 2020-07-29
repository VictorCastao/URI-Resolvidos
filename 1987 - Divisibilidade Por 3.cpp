#include <iostream>
#include <cstdio>


using namespace std;

int main(){
	int algarismos;
	string numero;
	while(cin >> algarismos >> numero){
		int soma=0;
		for(int i=0; i<algarismos; i++){
			soma += (int) numero[i] - '0';
		}
		if(soma%3 == 0) printf("%d sim\n", soma);
		else printf("%d nao\n", soma);
	}

	return 0;
}

