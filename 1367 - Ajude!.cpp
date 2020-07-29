#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int submissoes;
	while(true){
		scanf("%d", &submissoes);
		if(submissoes == 0) break;
		int problemas[26], tempo;
		int resolvidos = 0, total = 0;
		char id;
		string resultado;
		for(int i=0; i<26; i++) problemas[i] = 0;
		for(int i=0; i<submissoes; i++){
			cin >> id >> tempo >> resultado;
			problemas[(int) id - (int) 'A']++;
			if(resultado == "correct"){
				resolvidos++;
				total+=tempo;
				total+=(problemas[(int) id - (int) 'A'] - 1) * 20;
			}
		}
		printf("%d %d\n", resolvidos, total);
	}
	return 0;
}
