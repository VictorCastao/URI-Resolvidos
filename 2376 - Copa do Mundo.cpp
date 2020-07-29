#include <iostream>
#include <vector>

using namespace std;

int main(){
	string equipes = "ABCDEFGHIJKLMNOP";
	int i, a, b;
	vector <char> quartas;
	vector <char> semi;
	vector <char> fim;
	for(i=0; i<16; i+=2){
		cin >> a >> b;
		if(a>b) quartas.push_back(equipes[i]);
		else quartas.push_back(equipes[i+1]);
	}

	for(i=0; i<8; i+=2){
		cin >> a >> b;
		if(a>b) semi.push_back(quartas[i]);
		else semi.push_back(quartas[i+1]);
	}

	for(i=0; i<4; i+=2){
		cin >> a >> b;
		if(a>b) fim.push_back(semi[i]);
		else fim.push_back(semi[i+1]);
	}

	cin >> a >> b;

	if(a>b) cout << fim[0] << endl;

	else cout << fim[1] << endl;

	return 0;
}

