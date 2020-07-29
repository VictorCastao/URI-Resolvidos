#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long mdc(long long a, long long b){
	if(b==0) return a;
	else return mdc(b, a%b);
}

 
int main(){
	long long a, b, c, d;
	scanf("%lli %lli %lli %lli", &a, &b, &c, &d);
	long long result = mdc(b,d);
	long long mmc = (b * d) / result;
	long long p1, p2;
	if(mmc > b) p1 = (mmc/b)*a;
	else p1 = a/(b/mmc);
	if(mmc > d) p2 = (mmc/d)*c;
	else p2 = c/(d/mmc);
	
	long long soma = p1 + p2;;
	result = mdc(soma, mmc);
	soma/=result;
	mmc/=result;
	printf("%lli %lli\n", soma, mmc);
	return 0;
}

