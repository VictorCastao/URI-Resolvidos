#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int testes, tempx, tempy, divisax, divisay;
	while(true){
		scanf("%d", &testes);
		if(testes == 0) break;
		scanf("%d %d", &divisax, &divisay);
		for(int i=0; i<testes; i++){
			scanf("%d %d", &tempx, &tempy);
			if(tempx == divisax or tempy == divisay) printf("divisa\n");
			else if(tempx > divisax and tempy > divisay) printf("NE\n");
			else if(tempx > divisax and tempy < divisay) printf("SE\n");
			else if(tempx < divisax and tempy > divisay) printf("NO\n");
			else if(tempx < divisax and tempy < divisay) printf("SO\n");
		}
	}
	return 0;
}
