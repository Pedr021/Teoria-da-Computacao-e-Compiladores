/*Nesta questão devemos construir um algoritmo recursivo para o cálculo de um expoente. Para 
isso, o usuário deve inserir o valor da base e do expoente e devemos fazer a conta de forma 
recursiva 
 
*/ 

#include <stdio.h> 
int Exponencial(int base, int expoente) { 
 if (expoente == 0) { 
 return 1; 
 } 
 else if (expoente == 1) { 
 return base; 
 } 
 else { 
 return base * Exponencial(base, expoente - 1); 
 } 
} 
int main() { 
 
 int base; 
 int expoente; 
 printf("Digite a base: "); 
 scanf("%d", &base); 
 printf("Digite o expoente: "); 
 scanf("%d", &expoente); 
 int resultado = Exponencial(base, expoente); 
 printf("%d^%d = %d\n", base, expoente, resultado); 
 return 0; 
} 
