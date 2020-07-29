#include <iostream>

using namespace std;

int main(){
	int L, C, l1, l2;

	cin >> L;

	cin >> C;

	l2 = ((L-1) * 2) + ((C-1) * 2);

	l1 = (L*C) + ((L-1) * (C-1));

	cout << l1 << endl;

	cout << l2 << endl;

	return 0;
}
