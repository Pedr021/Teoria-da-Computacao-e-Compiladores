
// Versão nao recursiva.

#include <stdio.h>
int f(int n) {
if (n % 2 == 0) {
return -n / 2;
} else {
return n / 2 + 1;
}
}
int main() {
int limite;
printf("Informe o limite: ");
scanf("%d", &limite);
for (int i = 0; i <= limite; i++) {
int result = f(i);
printf("[%d, %d], ", i, result);
}
printf("\n");
return 0;
}
—----