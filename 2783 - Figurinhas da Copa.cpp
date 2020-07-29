#include <iostream>
#include <set>

using namespace std;

int main(){
	set <int> figurinhas;

	int espacos, carimbadas, compradas, temp, i;

	cin >> espacos >> carimbadas >> compradas;

	for(i=0; i<carimbadas; i++){
		cin >> temp;
		figurinhas.insert(temp);
	}

	for(i=0; i<compradas; i++){
		cin >> temp;
		if(figurinhas.find(temp) != figurinhas.end()){
			figurinhas.erase(temp);
			carimbadas--;
		}
	}
	
	cout << carimbadas << endl;

	return 0;
}

