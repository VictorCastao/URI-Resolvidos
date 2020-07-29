#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	string temp;
	pair <int, int> cavalo, pontos[8];
	int teste = 1;
	while(true){
		cin >> temp;
		if(temp[0] == '0') break;
		cavalo.first = (int) temp[0] - '0';
		cavalo.second = (int) temp[1] - 'a';
		for(int i=0; i<8; i++){
			cin >> temp;
			pontos[i].first = (int) temp[0] - '0';
			pontos[i].second = (int) temp[1] - 'a';
		}
		int possiveis = 0;
		if(cavalo.first+2 >= 1 and cavalo.first+2 <= 8 and cavalo.second-1 >= 0 and cavalo.second-1 <= 7 and find(pontos, pontos+8, make_pair(cavalo.first+3, cavalo.second)) ==  pontos+8 and find(pontos, pontos+8, make_pair(cavalo.first+3, cavalo.second-2)) == pontos+8) possiveis++;
		if(cavalo.first+2 >= 1 and cavalo.first+2 <= 8 and cavalo.second+1 >= 0 and cavalo.second+1 <= 7 and find(pontos, pontos+8, make_pair(cavalo.first+3, cavalo.second)) ==  pontos+8 and find(pontos, pontos+8, make_pair(cavalo.first+3, cavalo.second+2)) == pontos+8) possiveis++;
		if(cavalo.first+1 >= 1 and cavalo.first+1 <= 8 and cavalo.second-2 >= 0 and cavalo.second-2 <= 7 and find(pontos, pontos+8, make_pair(cavalo.first+2, cavalo.second-3)) ==  pontos+8 and find(pontos, pontos+8, make_pair(cavalo.first+2, cavalo.second-1)) == pontos+8) possiveis++;
		if(cavalo.first-1 >= 1 and cavalo.first-1 <= 8 and cavalo.second-2 >= 0 and cavalo.second-2 <= 7 and find(pontos, pontos+8, make_pair(cavalo.first, cavalo.second-3)) ==  pontos+8 and find(pontos, pontos+8, make_pair(cavalo.first, cavalo.second-1)) == pontos+8) possiveis++;
		if(cavalo.first-2 >= 1 and cavalo.first-2 <= 8 and cavalo.second-1 >= 0 and cavalo.second-1 <= 7 and find(pontos, pontos+8, make_pair(cavalo.first-1, cavalo.second-2)) ==  pontos+8 and find(pontos, pontos+8, make_pair(cavalo.first-1, cavalo.second)) == pontos+8) possiveis++;
		if(cavalo.first-2 >= 1 and cavalo.first-2 <= 8 and cavalo.second+1 >= 0 and cavalo.second+1 <= 7 and find(pontos, pontos+8, make_pair(cavalo.first-1, cavalo.second)) ==  pontos+8 and find(pontos, pontos+8, make_pair(cavalo.first-1, cavalo.second+2)) == pontos+8) possiveis++;
		if(cavalo.first-1 >= 1 and cavalo.first-1 <= 8 and cavalo.second+2 >= 0 and cavalo.second+2 <= 7 and find(pontos, pontos+8, make_pair(cavalo.first, cavalo.second+1)) ==  pontos+8 and find(pontos, pontos+8, make_pair(cavalo.first, cavalo.second+3)) == pontos+8) possiveis++;
		if(cavalo.first+1 >= 1 and cavalo.first+1 <= 8 and cavalo.second+2 >= 0 and cavalo.second+2 <= 7 and find(pontos, pontos+8, make_pair(cavalo.first+2, cavalo.second+1)) ==  pontos+8 and find(pontos, pontos+8, make_pair(cavalo.first+2, cavalo.second+3)) == pontos+8) possiveis++;

		printf("Caso de Teste #%d: %d movimento(s).\n", teste, possiveis);
		teste++;
	}
	return 0;
}
