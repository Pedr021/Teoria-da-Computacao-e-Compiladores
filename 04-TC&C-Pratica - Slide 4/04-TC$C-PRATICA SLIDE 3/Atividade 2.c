#include <stdio.h>
int sucessor(int n) {
return n + 1;
}
int soma(int m, int n) {
if (n == 0) {
return m; // Caso base: m + 0 = m
} else {
return soma(sucessor(m), n - 1); // Passo recursivo: m + s(n) = s(m + n)
}
}
int main() {
int m, n;
printf("Informe o primeiro número: ");
scanf("%d", &m);
printf("Informe o segundo número: ");
scanf("%d", &n);
int resultado = soma(m, n);
printf("A soma de %d e %d é %d\n", m, n, resultado);
return 0;
}
