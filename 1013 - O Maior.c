#include <stdio.h>
#include <stdlib.h>
int main() {
int a, b, c, absolab, absolc, maiorab, maiortodos;
scanf("%d %d %d", &a, &b, &c);
absolab = abs(a-b);
maiorab = (a+b+absolab)/2;
absolc = abs(maiorab-c);
maiortodos = (maiorab+c+absolc)/2;
printf("%d eh o maior\n", maiortodos);
return 0;
}

