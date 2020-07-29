#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	double EV_1, EV_2, AT, D;
	while(true){
		scanf("%lf %lf %lf %lf", &EV_1, &EV_2, &AT, &D);
		if(EV_1 == 0 and EV_2 == 0 and AT == 0 and D == 0) break;
		double round_1 = ceil(EV_1 / D), round_2 = ceil(EV_2 / D);
		double resultado;
		if(AT == 3){
			resultado = (round_2 / (round_1 + round_2));
			resultado -= 1;
			resultado *= -100;
		}
		else{
			resultado = (1 - pow(AT / (6-AT), round_2) ) / (1 - pow((AT / (6-AT)), round_2 + round_1));
			resultado -= 1;
			resultado *= -100;
		}
		printf("%.1lf\n", resultado);
	}
	return 0;
}
