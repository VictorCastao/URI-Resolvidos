#include <iostream>
#include <stdio.h>
#include <bitset>


using namespace std;

int main(){
	int numeros, maior;

	while(scanf("%d %d", &numeros, &maior) != EOF){
		int temp;
		int teste = 0;
		bitset <100000> seq;
		for(int i=0; i<numeros; i++){
			scanf("%d", &temp);
			if(temp <= maior and seq[temp-1] == 0){
				if (teste != 0) cout << " " << temp;
				else{
					cout << temp;
					teste = 1;
				}
				seq[temp-1] = 1;
			}
		}
		cout << endl;
		

	}

	return 0;
}

