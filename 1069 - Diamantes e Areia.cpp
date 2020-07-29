#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		deque <char> expressao;
		int diamantes = 0;
		string temp;
		cin >> temp;
		for(int j=0; j<temp.size(); j++){
			if(temp[j] == '<') expressao.push_back(temp[j]);

			else if(temp[j] == '>' and !expressao.empty()){
				expressao.pop_back();
				diamantes++;
			}
		}
		
		printf("%d\n", diamantes);
	}

	return 0;
}

