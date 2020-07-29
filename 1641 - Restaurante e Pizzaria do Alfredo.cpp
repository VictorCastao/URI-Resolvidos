#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

 
int main(){
	double raio, largura, altura;
	int teste = 1;
	while(true){
		scanf("%lf", &raio);
		if(raio == 0) break;
		scanf("%lf %lf", &largura, &altura);
		double diagonal = sqrt(pow(largura,2) + pow(altura,2));
		if(diagonal <= raio * 2) printf("Pizza %d fits on the table.\n", teste);
		else printf("Pizza %d does not fit on the table.\n", teste);
		teste++;
	}
	return 0;
}

