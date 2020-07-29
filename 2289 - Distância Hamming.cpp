#include <iostream>
#include <cstdio>

using namespace std;


int main(){
	unsigned long long num1, num2, exclusivo;
	
	while(true){

		int distancia = 0;

		cin >> num1 >> num2;

		if(num1 == 0 and num2 == 0) break;

		exclusivo = num1 ^ num2;

		while(exclusivo != 0){
			distancia++;
			exclusivo -= (exclusivo & -exclusivo);
		}

		printf("%d\n", distancia);
	}

	return 0;
}
 
