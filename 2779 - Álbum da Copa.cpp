#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	set <int> album;
	int numero_figurinhas, qtde_album, i, temp, restantes=0;
	cin >> qtde_album;
	cin >> numero_figurinhas;

	for(i=0; i<numero_figurinhas; i++){
		cin >> temp;
		album.insert(temp);
	}

	for(i=1; i<=qtde_album; i++){
		if(album.find(i) == album.end()) restantes++;
	}

	cout << restantes << endl;

	return 0;
}

