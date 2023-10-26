/*A função ‘isuper’ é uma importante estrutura que nos permite verificar se uma letra é 
maiúscula. Devido a esta funcionalidade, podemos aplica-la em cenários como verificação de 
senha, de forma a assegurar que o usuário insira um caractere deste tipo.*/



# include <ctype.h> 
#include <stdio.h> 
int main() { 
 
 int contador = 0; 
 char senha[20]; 
 
 printf("Digite sua senha: "); 
 scanf("%s", senha); 
 for (int i = 0; senha[i] != '\0'; i++) { 
 if (isupper(senha[i])) { 
 printf("%c é uma letra maiúscula na senha.\n", senha[i]); 
 contador++; 
 } 
 } 
 
 if(contador > 0){ 
 printf("A senha é válida!"); 
 } else { 
 printf("A senha deve conter pelo menos um caracter maiúsculo."); 
 printf("A senha não é válida."); 
 } 
 return 0; 
}