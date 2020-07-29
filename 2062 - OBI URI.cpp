#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int main(){
	deque <string> palavras;
	int numero;
	cin >> numero;
	string temp;
	for(int i=0; i<numero; i++){
		cin >> temp;
		if(temp.size() == 3){
			if(temp[0] == 'U' and temp[1] == 'R') palavras.push_back("URI");
			else if(temp[0] == 'O' and temp[1] == 'B') palavras.push_back("OBI");
			else palavras.push_back(temp);
		}
		else palavras.push_back(temp);
	}

	for(int j=0; j<numero; j++){
		if(j==0) cout << palavras[j];
		else cout << " " << palavras[j];
	}

	cout << endl;

	return 0;
}

