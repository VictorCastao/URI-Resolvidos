#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

int main(){
	string temp;
	while (cin >> temp){
		deque <char> expressao;
		int erro = 0;
		for(int j=0; j<temp.size(); j++){
			if (temp[j] != '(' and temp[j] != ')') continue;

			else if(temp[j] == '(') expressao.push_back(temp[j]);

			else if(temp[j] == ')' and !expressao.empty()){
				expressao.pop_back();
			}

			else erro = 1;
		}
		
		if(erro == 0 and expressao.empty()) printf("correct\n");

		else printf("incorrect\n");

		expressao.clear();
	}


	return 0;
}

