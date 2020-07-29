#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct reta{
	pair <int, int> p1, p2;
};

bool comparar(reta a, reta b){
	if(a.p2.second != b.p2.second) return a.p2.second < b.p2.second;
	else return a.p1.second < b.p1.second;
}

int main(){
	int retas, consultas;
	while(scanf("%d %d", &retas, &consultas) != EOF){
		reta lista[retas];
		reta temp;
		for(int i=0; i<retas; i++){
			scanf("%d %d %d %d", &temp.p1.first, &temp.p1.second, &temp.p2.first, &temp.p2.second);
			if(temp.p2.second >= temp.p1.second) lista[i] = temp;
			else{
				lista[i].p1 = temp.p2;
				lista[i].p2 = temp.p1;
			}
		}
		sort(lista, lista+retas, comparar);
		pair<int, int> coordenada;
		for(int j=0; j<consultas; j++){
			int valor, result = -1;
			bool reto = false, nenhum = true;
			scanf("%d", &valor);
			int ponteiro = 0;
			while(true){
				nenhum = true;
				while(ponteiro != retas){
					if((lista[ponteiro].p1.first <= valor and lista[ponteiro].p2.first >= valor) or (lista[ponteiro].p1.first >= valor and lista[ponteiro].p2.first <= valor)){
						nenhum = false;
						coordenada = lista[ponteiro].p2;
						if(lista[ponteiro].p2.second == lista[ponteiro].p1.second){
							reto = true;
							coordenada.first = valor;
						}
						else valor = coordenada.first;
						ponteiro++;
						break;
					}
					ponteiro++;
				}
				if(nenhum) break;
				else if(reto) break;
			}
			if(reto) printf("%d %d\n", coordenada.first, coordenada.second);
			else printf("%d\n", valor);
		}
	}
	return 0;
}
