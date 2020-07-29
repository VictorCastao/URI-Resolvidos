#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

int main(){
	int N, K, M, horario, antihorario, contagem_horario, contagem_antihorario;

	bitset <20> numeros(0);

	while(true){
		scanf("%d %d %d", &N, &K, &M);

		numeros.reset();

		if(N==0 and K==0 and M==0) break;

		for(int i=N; i<20; i++){
			numeros[i] = 1;
		}

		horario = 0;

		antihorario = N-1;

		while(numeros.count() != 20){
			while(numeros[horario] != 0){
				horario++;
				if(horario == N) horario = 0;
			}

			while(numeros[antihorario] != 0){
				antihorario--;
				if(antihorario == -1) antihorario = N-1;
			}

			contagem_horario = 0;

			contagem_antihorario = 0;

			while(true){
				if(numeros[horario] == 0) contagem_horario++;
				if (contagem_horario == K) break;
				horario++;
				if(horario == N) horario = 0;
			}

			while(true){
				if(numeros[antihorario] == 0) contagem_antihorario++;
				if (contagem_antihorario == M) break;
				antihorario--;
				if(antihorario == -1) antihorario = N-1;
			}

			if(horario == antihorario){
				if(horario+1 >= 10) printf(" %d", horario+1);
				else printf("  %d", horario+1);
			}

			else{
				if(horario+1 >= 10) printf(" %d", horario+1);
				else printf("  %d", horario+1);

				if(antihorario+1 >= 10) printf(" %d", antihorario+1);
				else printf("  %d", antihorario+1);
			}

			numeros[horario] = 1;
		
			numeros[antihorario] = 1;

			if(numeros.count() != 20) printf(",");

		}

		printf("\n");
	}



	return 0;
}

