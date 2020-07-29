#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	if(a == b) printf("%d\n", a);
	else printf("%d\n", max(a,b));
	return 0;
}
