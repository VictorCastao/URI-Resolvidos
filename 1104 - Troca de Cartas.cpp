//Solução: colocar os valores em dois sets diferentes. Após, inserir as cartas de um set em outro e comparar seu tamanho atual com o antigo. Das duas diferenças, a menor delas será a resposta (pois uma deve dar à outra o mesmo número de cartas).

#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int main(){
	int cartas1, cartas2;
	while(true){
		scanf("%d %d", &cartas1, &cartas2);

		if (cartas1 == 0 and cartas2 == 0) break;

		set <int> Alice, Beatriz;
		int temp, i, j;

		for(i=0; i<cartas1; i++){
			scanf("%d", &temp);
			Alice.insert(temp);
		}

		for(j=0; j<cartas2; j++){
			scanf("%d", &temp);
			Beatriz.insert(temp);
		}

		int antigo1 = Alice.size();
		int antigo2 = Beatriz.size();

		for(auto it = Alice.begin(); it != Alice.end(); it++) Beatriz.insert(*it);

		for(auto it = Beatriz.begin(); it != Beatriz.end(); it++) Alice.insert(*it);

		int tamanho1 = Alice.size() - antigo1;
		int tamanho2 = Beatriz.size() - antigo2;

		printf("%d\n", min(tamanho1, tamanho2));
		

	}

	return 0;
}
