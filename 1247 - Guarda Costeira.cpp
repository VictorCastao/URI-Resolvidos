#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	double distancia, vf, vg;

	while (scanf("%lf %lf %lf", &distancia, &vf, &vg) != EOF){
		double dist = pow(144.0 + (distancia * distancia), 0.5);
		if(dist / vg <= 12.0/vf) printf("S\n");
		else printf("N\n");
	}
	
	return 0;

}
