#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	long long n, i;
	bool resp = false;
	cin >> n;
	for(i = 2; i*i <= n; i++){
		if(n % i == 0){
			resp = true;
			break;
		}
	}

	if(resp) printf("S\n");

	else printf("N\n");

	return 0;
}

