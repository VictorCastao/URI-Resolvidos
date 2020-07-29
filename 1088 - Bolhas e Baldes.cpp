#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int merge(vector <int> &v){
	if(v.size() == 1) return 0;
	int inversoes = 0;
	vector <int> metade1, metade2;
	for(int i=0; i<v.size()/2; i++){
		metade1.push_back(v[i]);
	}
	for(int i=v.size()/2; i<v.size(); i++){
		metade2.push_back(v[i]);
	}
	inversoes += merge(metade1);
	inversoes += merge(metade2);
	int tam1 = metade1.size(), tam2 = metade2.size(), pos1 = 0, pos2 = 0;
	for(int j=0; j<v.size(); j++){
		if(pos1 == tam1){
			v[j] = metade2[pos2];
			pos2++;
		}
		else if(pos2 == tam2){
			v[j] = metade1[pos1];
			pos1++;
		}
		else if(metade1[pos1] < metade2[pos2]){
			v[j] = metade1[pos1];
			pos1++;
		}
		else if(metade1[pos1] > metade2[pos2]){
			v[j] = metade2[pos2];
			pos2++;
			inversoes += tam1 - pos1;
		}
	}
	return inversoes;
}

int main(){
	int qtde, temp;
	while(true){
		scanf("%d", &qtde);
		if(qtde == 0) break;
		vector <int> valores;
		for(int i=0; i<qtde; i++){
			scanf("%d", &temp);
			valores.push_back(temp);
		}
		int pessoa = 0;
		pessoa = merge(valores);
		if(pessoa % 2 == 0) printf("Carlos\n");
		else printf("Marcelo\n");
	}
	return 0;
}
