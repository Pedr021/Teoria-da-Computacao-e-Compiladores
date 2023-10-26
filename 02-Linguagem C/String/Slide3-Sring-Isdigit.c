/*Função ‘isdigit’: 
A função ‘isdigit’ é responsável por verificar se uma determinada entrada contém apenas 
números, cenário que podemos aproveitá-lo para aplicá-lo em validações de números de 
telefones, cpf, cep e similares.*/




#include <stdio.h> 
#include <ctype.h> 
int main() { 
 
 char cep[8]; 
 printf("Digite o código postal (Apenas números): "); 
 scanf("%s", cep); 
 for (int i = 0; cep[i] != '\0'; i++) { 
 if (isdigit(cep[i])) { 
 printf("%c é um dígito no código postal.\n", cep[i]); 
 } else { 
 printf("\n%c não e um número.", cep[i]); 
 printf("\nEste CEP não é válido."); 
 break; 
 } 
 } 
 return 0; 
}