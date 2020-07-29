#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack <char> expressao;
	string temp;
	int i, j, k, teste;
	cin >> teste;
	for(i=0; i<teste; i++){
		cin >> temp;
		for(j=0; j<temp.size(); j++){
			if(temp[j] == '(' or temp[j] == '[' or temp[j] == '{') expressao.push(temp[j]);

			else if((!expressao.empty()) and ((temp[j] == ')' and expressao.top() == '(') or (temp[j] == ']' and expressao.top() == '[') or (temp[j] == '}' and expressao.top() == '{'))) expressao.pop();

			else {
				expressao.push('{');
				break;
			}

		}
	
		if(expressao.empty()) cout << 'S' << endl;

		else{
			cout << 'N' << endl;
			for(;!expressao.empty();){
				expressao.pop();
			}
		}


	}

	return 0;
}

