#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double norma(pair <double, double> a, pair <double, double> b){
	return sqrt(pow(b.first-a.first, 2) + pow(b.second-a.second, 2));
}
 
int main(){
	double raio_desenho, raio_flor;
	pair <double, double> desenho, flor;
	while(cin >> raio_desenho >> desenho.first >> desenho.second >> raio_flor >> flor.first >> flor.second){
		double dist = norma(desenho, flor);
		dist += raio_flor;
		if(dist > raio_desenho) printf("MORTO\n");
		else printf("RICO\n");
	}
	return 0;
}

