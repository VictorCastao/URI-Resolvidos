#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int qtde;
	cin >> qtde;
	for(int i=0; i<qtde; i++){
		long double lado;
		double pi = 2*acos(0.0);
		cin >> lado;
		long double apotema = (lado/2) / tan (pi * 36 / 180);
		long double area = 5 * lado * apotema / 2;
		printf("%.3Lf\n", area);
	}


	return 0;
}
