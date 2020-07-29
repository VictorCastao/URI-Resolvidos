#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int x1, y1, x2, y2, cruzamentos = 0;

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	cruzamentos += abs(x2-x1) + abs(y2-y1);

	printf("%d\n", cruzamentos);

	return 0;
}
 
