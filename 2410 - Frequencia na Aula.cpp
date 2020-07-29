#include <iostream>
#include <set>

using namespace std;

int main(){
	set <int> alunos;
	int registros, temp, i;
	cin >> registros;

	for(i=0; i<registros; i++){
		cin >> temp;
		alunos.insert(temp);
	}
	
	cout << alunos.size() << endl;

	return 0;
}

