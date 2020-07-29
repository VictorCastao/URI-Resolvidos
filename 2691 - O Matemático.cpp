#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){

	long long n1, n2;
	int i, teste;
	char op;

	scanf("%d", &teste);

	for(int j=0; j<teste; j++){
		scanf("%lli%c%lli", &n1, &op, &n2);

		for(i=5; i<=10; i++){
			long long mult = n1*i, mult2 = n2*i;
			if(n1 != n2){
				cout << n1 << " x " << i << " = " << mult << " && " << n2 << " x " << i << " = " << mult2 << endl;
			}
			else{
				cout << n1 << " x " << i << " = " << mult << endl;
			}

		}
	}
	
	return 0;
}
