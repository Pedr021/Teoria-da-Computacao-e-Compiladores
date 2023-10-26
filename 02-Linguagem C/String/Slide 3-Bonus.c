/*Podemos usar todo conteúdo aprendido acima para fazer uma validação melhor da senha, 
verificando se ela tem letras maiúsculas e minúsculas, todos os caracteres são alfanuméricos, e 
que tenha número também. 
 
*/ 


#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
int TestarSenha(char senha[]) { 
 
 int temLetra = 0; 
 int temDigito = 0; 
 int temMaiuscula = 0; 
 int temMinuscula = 0; 
 for (int i = 0; senha[i] != '\0'; i++) { 
 if (isalpha(senha[i])) { 
 temLetra = 1; 
 if (isupper(senha[i])) { 
 temMaiuscula = 1; 
 } else if (islower(senha[i])) { 
 temMinuscula = 1; 
 } 
 } else if (isdigit(senha[i])) { 
 temDigito = 1; 
 } 
 } 
 if (temLetra && temDigito && temMaiuscula && temMinuscula && (strlen(senha) >= 8)) { 
 return 1; // A senha é válida 
 } else { 
 return 0; // A senha não é válida 
 } 
 
 
} 
int main() { 
 char senha[50]; 
 printf("Insira uma senha: "); 
 scanf("%s", senha); 
 if (TestarSenha(senha) == 1) { 
 printf("Senha válida!\n"); 
 } else { 
 printf("Senha inválida. A senha deve conter pelo menos 8 caracteres, incluindo pelo 
menos uma letra maiúscula, uma letra minúscula e um dígito.\n"); 
 } 
 return 0; 
}