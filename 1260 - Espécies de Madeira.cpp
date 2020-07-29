#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
	int casosteste;

	string temp;
	
	cin >> casosteste;

	cin.ignore();
	cin.ignore();
	
	for(int i=0; i<casosteste; i++){
		float soma = 0.0;
		map <string, int> arvores;
		while(true){
			getline(cin, temp);
			if(temp == "") break;
			else{
				if(arvores.find(temp) == arvores.end()){
					arvores.insert(make_pair (temp, 1));
					soma++;
				}
				else{
					arvores[temp]++;
					soma++;				
				}
			}
		}
		if(i != 0) cout << endl;
		for(auto it = arvores.begin(); it != arvores.end(); ++it){
			cout << it->first;
			printf(" %.4f\n", (it->second) * 100.0 / soma);
		}



	}

	return 0;
}

