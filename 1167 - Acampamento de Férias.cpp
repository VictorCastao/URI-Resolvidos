#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

struct pessoa{
	string nome;
	int ficha;
	int visitado = 0;
};


int main(){
	int criancas;
	
	while(true){

		scanf("%d", &criancas);

		if(criancas == 0) break;
		
		deque <pessoa> circulo;

		int sentido = 0;

		int cont = 0;

		pessoa temppessoa;

		for(int i=0; i<criancas; i++){
			cin >> temppessoa.nome;
			scanf("%d", &temppessoa.ficha);
			circulo.push_back(temppessoa);
		}

		int contagem=circulo[0].ficha;
		int pessoa = 0;
		bool comeco = true;
		int apagados=0, marcador=0, i, j;
		while(apagados != criancas-1){

			marcador = 0;
			if(contagem%2==0) sentido = -1;
			else sentido = 1;
			for(int i=pessoa; ;i+=sentido){
				if(comeco){
					comeco = false;
					continue;
				}
				if(i==-1) i=criancas-1;
				else if(i==criancas) i=0;
				if(circulo[i].visitado == 0) marcador++;
				if(marcador == contagem){
					pessoa = i;
					circulo[i].visitado = 1;
					contagem = circulo[i].ficha;
					break;
				} 
			}
			apagados++;
		}
		pessoa=0;
		while(circulo[pessoa].visitado == 1) pessoa++;
		printf("Vencedor(a): ");
		cout << circulo[pessoa].nome << endl;
	}

	return 0;
}
 
