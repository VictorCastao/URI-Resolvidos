#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>


using namespace std;

struct Comp{
    bool operator()(const pair<double, int>& a, const pair<double, int>& b){
        return a.first>b.first;
    }
};

double norma(pair <double, double> a, pair <double, double> b){
	return sqrt(pow(b.first-a.first, 2) + pow(b.second-a.second, 2));
}

int main(){
	int testes;
	scanf("%d", &testes);
	pair<double, double> temp;
	for(int i=0; i<testes; i++){
		int bolas;
		scanf("%d", &bolas);
		pair<double, double> branca;
		double dist;
		priority_queue<pair<double,int>, vector<pair<double,int>>, Comp> fila;
		for(int j=0; j<=bolas; j++){
			if(j==0) scanf("%lf %lf", &branca.first, &branca.second);
			else{
				scanf("%lf %lf", &temp.first, &temp.second);
				dist = norma(branca, temp);
				fila.push(make_pair(dist, j));
			}
		}
		printf("%d\n", fila.top().second);
	}
	return 0;
}
