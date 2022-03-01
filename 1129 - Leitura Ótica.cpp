#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int questoes, marcado, correto, media;
	char texto[5];
	texto[0] = 'A';
	texto[1] = 'B';
	texto[2] = 'C';
	texto[3] = 'D';
	texto[4] = 'E';
	while(true){
		scanf("%d", &questoes);
		if(questoes == 0) break;
		for(int i=0; i<questoes; i++){
			marcado = 5;
			correto = 0;
			for(int j=0; j<5; j++){
				scanf("%d", &media);
				if(media <= 127){
					correto++;
					marcado = j;
				}
			}
			if(correto == 1){
				printf("%c\n", texto[marcado]);
			}
			else{
				printf("*\n");
			}
		}		
	}
}
