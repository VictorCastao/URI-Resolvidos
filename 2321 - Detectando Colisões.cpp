#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int x0, y0, x1, y1, x2, y2, x3, y3;

	scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

	scanf("%d %d %d %d", &x2, &y2, &x3, &y3);

	bool resp = false;

	if(x0 >= x2 and x0 <= x3 and y0 >= y2 and y0 <= y3) resp = true;
	else if((x1 >= x2 and x1 <= x3) and y1 >= y2 and y1 <= y3) resp = true;
	else if(x2 >= x0 and x2 <= x1 and y2 >= y0 and y2 <= y1) resp = true;
	else if(x3 >= x0 and x3 <= x1 and y3 >= y0 and y3 <= y1) resp = true;
	else if(x0 >= x2 and x0 <= x3 and y1 >= y2 and y1 <= y3) resp = true;
	else if((x1 >= x2 and x1 <= x3) and y0 >= y2 and y0 <= y3) resp = true;
	else if(x2 >= x0 and x2 <= x1 and y3 >= y0 and y3 <= y1) resp = true;
	else if(x3 >= x0 and x3 <= x1 and y2 >= y0 and y2 <= y1) resp = true;
	else if(x3 >= x0 and x3 <= x1 and y2 >= y0 and y2 <= y1) resp = true;
	else if(x0 >= x2 and x1 <= x3 and y0 <= y2 and y1 >= y3) resp = true; 
	else if(x0 <= x2 and x1 >= x3 and y0 >= y2 and y1 <= y3) resp = true; 

	if(resp) printf("1\n");
	else printf("0\n");

	return 0;
}
 
