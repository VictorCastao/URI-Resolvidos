#include <stdio.h>
int main() {
char nome;
double fixo, vendas, salario;
scanf("%s", &nome);
scanf("%lf", &fixo);
scanf("%lf", &vendas);
salario = fixo + (0.15 * vendas);
printf("TOTAL = R$ %.2lf\n", salario);
return 0;
}

