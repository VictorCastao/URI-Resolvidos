#include <iostream>
#include <bitset>
#include <queue>
#include <cstdio>
#include <deque>


using namespace std;

struct ponto{
	int peso, x, y;
};

struct Comp{
    bool operator()(const ponto& a, const ponto& b){
        return a.peso>b.peso;
    }
};

int main(){
	int linhas, colunas, resp;
	int xh, yh, xe, ye;
	scanf("%d %d", &linhas, &colunas);
	string M[linhas];
	string tempor;
	for(int i=0; i<linhas; i++){
		cin >> tempor;
		M[i] = tempor;
		for(int j=0; j<M[i].size(); j++){
			if(M[i][j] == 'H'){
				xh = i;
				yh = j;
			}
			else if(M[i][j] == 'E'){
				xe = i;
				ye = j;
			}
		}
	}

	bitset <500> visitado [500];
	for(int i=0; i<500; i++){
		for(int j=0; j<500; j++){
			visitado[i][j] = 0;
		}
	}
	int matriz[linhas][colunas];
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			matriz[i][j] = 1000000000;
		}
	}
	matriz[xh][yh] = 0;
	ponto temp;
	temp.peso = 0;
	temp.x = xh;
	temp.y = yh;
	priority_queue<ponto, vector<ponto>, Comp> fila;
	fila.push(temp);
	
	while(true){
		int f = -1;
		while(!fila.empty()){
			temp = fila.top();
			fila.pop();
			if(visitado[temp.x][temp.y]==0){
				f = 1;
				break;
			}
		}
		if(f==-1 or (temp.x == xe and temp.y == ye)) break;
		ponto temp2;
		visitado[temp.x][temp.y] = 1;

		if(temp.x>0 and M[temp.x-1][temp.y] != '#'){
			int p;
			if(M[temp.x-1][temp.y] == '.' or M[temp.x-1][temp.y] == 'E') p = 0;
			else p = (int) M[temp.x-1][temp.y] - (int) '0';
			if(temp.peso + p < matriz[temp.x-1][temp.y]){
				matriz[temp.x-1][temp.y] = temp.peso + p;
				temp2.peso = matriz[temp.x-1][temp.y];
				temp2.x = temp.x-1;
				temp2.y = temp.y;
				fila.push(temp2);
			}
		}
		//x<ordem-1
		if(temp.x<linhas-1 and M[temp.x+1][temp.y] != '#'){
			int p;
			if(M[temp.x+1][temp.y] == '.' or M[temp.x+1][temp.y] == 'E') p = 0;
			else p = (int) M[temp.x+1][temp.y] - (int) '0';
			if(temp.peso + p < matriz[temp.x+1][temp.y]){
				matriz[temp.x+1][temp.y] = temp.peso + p;
				temp2.peso = matriz[temp.x+1][temp.y];
				temp2.x = temp.x+1;
				temp2.y = temp.y;
				fila.push(temp2);
			}
		}
		//y>0
		if(temp.y>0 and M[temp.x][temp.y-1] != '#'){
			int p;
			if(M[temp.x][temp.y-1] == '.' or M[temp.x][temp.y-1] == 'E') p = 0;
			else p = (int) M[temp.x][temp.y-1] - (int) '0';
			if(temp.peso + p < matriz[temp.x][temp.y-1]){
				matriz[temp.x][temp.y-1] = temp.peso + p;
				temp2.peso = matriz[temp.x][temp.y-1];
				temp2.x = temp.x;
				temp2.y = temp.y-1;
				fila.push(temp2);
			}
		}
		//y<ordem-1
		if(temp.y<colunas-1 and M[temp.x][temp.y+1] != '#'){
			int p;
			if(M[temp.x][temp.y+1] == '.' or M[temp.x][temp.y+1] == 'E') p = 0;
			else p = (int) M[temp.x][temp.y+1] - (int) '0';
			if(temp.peso + p < matriz[temp.x][temp.y+1]){
				matriz[temp.x][temp.y+1] = temp.peso + p;
				temp2.peso = matriz[temp.x][temp.y+1];
				temp2.x = temp.x;
				temp2.y = temp.y+1;
				fila.push(temp2);
			}
		}

	}

	resp = matriz[xe][ye];

	if(resp == 1000000000) printf("ARTSKJID\n");

	else printf("%d\n", resp);

	return 0;
}

