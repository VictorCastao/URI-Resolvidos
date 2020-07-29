#include <iostream>
#include <stack>
#include <vector> 
#include <algorithm>

using namespace std;

int main(){

	int casos_teste, j, i, p;

	string expressao;

	vector <char> operadores = {'+', '-', '*', '/', '^', '(', ')'};

	vector <char> peso1 = {'+', '-'};

	vector <char> peso2 = {'*', '/'};

	cin >> casos_teste;

	for(i=0; i<casos_teste; i++){
	
		cin >> expressao;

		string resultado = "";

		stack <char> pilha;

		for(j=0; j<expressao.size(); j++){
			if(expressao[j] == '('){
				pilha.push(expressao[j]);
				continue;
			}

			if(expressao[j] == ')'){
				while(pilha.top() != '('){
					resultado+=pilha.top();
					pilha.pop();
				}
				pilha.pop();
				continue;
			}				

			if(find(operadores.begin(), operadores.end(), expressao[j]) == operadores.end()){
				resultado+=expressao[j];
			}

			else{
				if (pilha.empty() or pilha.top() == '(' or (expressao[j] == '^' and pilha.top() != '^') or (find(peso2.begin(), peso2.end(), expressao[j]) != peso2.end() and find(peso1.begin(), peso1.end(), pilha.top()) != peso1.end()) ){

					pilha.push(expressao[j]);
				}

				else{
					while(true){
						if(pilha.empty()) break;
						if((pilha.top() == '^' and expressao[j] == '^') or
(pilha.top() == '^' and expressao[j] != '^') or				   
(find(peso2.begin(), peso2.end(), pilha.top()) != peso2.end() and find(peso2.begin(), peso2.end(), expressao[j]) != peso2.end()) or
(find(peso2.begin(), peso2.end(), pilha.top()) != peso2.end() and find(peso1.begin(), peso1.end(), expressao[j]) != peso1.end()) or
(find(peso1.begin(), peso1.end(), pilha.top()) != peso1.end() and find(peso1.begin(), peso1.end(), expressao[j]) != peso1.end())
									){
							resultado+=pilha.top();
							pilha.pop();
						}

						else break;
					}

					pilha.push(expressao[j]);

				/*fecha else*/}
			} 				
		}

		while (!pilha.empty()){
			resultado += pilha.top();
			pilha.pop();
		} 

		cout << resultado;
		cout << endl;

	}	
	return 0;
}

