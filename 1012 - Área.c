#include <stdio.h>
int main() {
double a, b, c;
scanf("%lf %lf %lf", &a, &b, &c);
double pi = 3.14159;
double areatriangulo = a * c / 2;
double areacirculo = pi * c * c;
double areatrapezio = (a + b) * c / 2;
double areaquadrado = b * b;
double arearetangulo = a * b;
printf("TRIANGULO: %.3lf\n", areatriangulo);
printf("CIRCULO: %.3lf\n", areacirculo);
printf("TRAPEZIO: %.3lf\n", areatrapezio);
printf("QUADRADO: %.3lf\n", areaquadrado);
printf("RETANGULO: %.3lf\n", arearetangulo);
return 0;
}

