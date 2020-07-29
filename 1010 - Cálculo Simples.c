#include <stdio.h>
int main() {
	int cod1, cod2, num1, num2;
	float vu1, vu2, total;
	scanf("%d %d %f", &cod1, &num1, &vu1);
	scanf("%d %d %f", &cod2, &num2, &vu2);
	total = (vu1 * num1) + (vu2 * num2);
	printf("VALOR A PAGAR: R$ %.2f\n", total);
	return 0;
}

