#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

int main(){
	char temp[100005];
	while (cin >> temp){
		char op =']';
		deque <char> texto;
		long int marcador=0;
		for(long int i=0; temp[i] != '\0'; i++){
			if(temp[i] == '[' or temp[i] == ']'){
				marcador=0;
				op = temp[i];
				continue;
			}
			else if(op == ']'){
				texto.push_back(temp[i]);
			}
			else if(op=='['){
				texto.insert(texto.begin()+marcador, temp[i]);
				marcador++;
			}
		}
		
		for(long int i=0; i<texto.size(); i++){
			printf("%c", texto[i]);
		}

		printf("\n");
	}


	return 0;
}

