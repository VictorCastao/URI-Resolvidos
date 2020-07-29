#include <iostream>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int main(){
	int programas, versoes, i, temp_prog, temp_ver;

	scanf("%d %d", &programas, &versoes);

	map <int, int> apps;

	set <int> atualizado;	

	for(i=0; i<programas; i++){
		scanf("%d %d", &temp_prog, &temp_ver);

		apps[temp_prog] = temp_ver;

	}

	for(i=0; i<versoes; i++){
		scanf("%d %d", &temp_prog, &temp_ver);

		if(apps.find(temp_prog) != apps.end() and apps[temp_prog] < temp_ver){

			apps[temp_prog] = temp_ver;

			atualizado.insert(temp_prog);
		}

		else if(apps.find(temp_prog) == apps.end()){ 
			apps[temp_prog] = temp_ver;
			atualizado.insert(temp_prog);
		}

	}

	for(auto it = atualizado.begin(); it != atualizado.end(); ++it){
		printf("%d %d\n", *it, apps[*it]);
	}
	
	return 0;
}

