#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;

	cin >> a >> b;

	long long resposta = (a+b) * (b-a+1) / 2;

	cout << resposta << endl;

	return 0;
}
