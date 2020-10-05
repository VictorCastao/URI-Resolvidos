#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int qtde;

	cin >> qtde;

	int inimigo[qtde], nosso[qtde];

	for(int i=0; i<qtde; i++) cin >> inimigo[i];

	for(int j=0; j<qtde; j++) cin >> nosso[j];

	sort(inimigo, inimigo+qtde);
	sort(nosso, nosso+qtde);

	int vitorias = 0;
	
	int pos = 0;

	for(int k=0; k<qtde; k++){
		if(nosso[pos] > inimigo[k]) vitorias++;
		else{
			pos++;
			while(pos < qtde){
				if(nosso[pos] > inimigo[k]){
					vitorias++;
					break;
				}
				pos++;
			}
		}
		pos++;
    	if(pos >= qtde) break;
	}

	cout << vitorias << endl;

	return 0;
}
