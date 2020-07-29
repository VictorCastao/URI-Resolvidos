#include <iostream>
#include <cstdio>
#include <deque>
#include <queue>

using namespace std;


int main(){
	int numeros;

	priority_queue <int> impares;

	priority_queue <int, vector<int>, greater<int>> pares;

	cin >> numeros;

	int temp;

	for(int i=0; i<numeros; i++){
		scanf("%d", &temp);
		if(temp % 2 == 0) pares.push(temp);
		else impares.push(temp);
	}

	while(!pares.empty()){
		printf("%d\n", pares.top());
		pares.pop();
	}

	while(!impares.empty()){
		printf("%d\n", impares.top());
		impares.pop();
	}

	return 0;
}
 
