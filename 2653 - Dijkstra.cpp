#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

int main(){
	string joia;
	set <string> bau;
	while(cin >> joia){
		bau.insert(joia);
	}

	cout << bau.size() << endl;
	return 0;
}

