#include <stdio.h>
#include <stdlib.h>
int main() {
int km;
float combustivel;
double consumo;
scanf("%d", &km);
scanf("%f", &combustivel);
consumo = km / combustivel;
printf("%.3lf km/l\n", consumo);
return 0;
}

