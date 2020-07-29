#include <iostream>
#include <cstdio>
#include <map>
#include <sstream>

using namespace std;

int main(){
	string dig1, dig2;
	
	while(true){
		cin >> dig1 >> dig2;
		if(dig1 == "0" and dig2 == "0") break;
		int moveu = 0;
		int carry = 0;
		int soma;
		for(int i=dig1.size()-1, j=dig2.size()-1; i>=0 and j>=0; i--, j--){
			soma = (int) dig1[i] - '0' + (int) dig2[j] - '0';
			if(moveu == 1) soma++;
			if(soma >= 10){
				carry++;
				moveu = 1;
			}
			else moveu = 0;
		}

		if(dig1.size() > dig2.size()){
			for(int k=dig1.size()-dig2.size()-1; k>=0; k--){
				soma = (int) dig1[k] - '0';
				if(moveu == 1) soma++;
				if(soma >= 10){
					carry++;
					moveu = 1;
				}
				else break;
			}
		}
		else if(dig1.size() < dig2.size()){
			for(int k=dig2.size()-dig1.size()-1; k>=0; k--){
				soma = (int) dig2[k] - '0';
				if(moveu == 1) soma++;
				if(soma >= 10){
					carry++;
					moveu = 1;
				}
				else break;
			}
		}

		if(carry == 0) printf("No carry operation.\n");
		else if(carry == 1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n", carry);

	}
	return 0;
}

