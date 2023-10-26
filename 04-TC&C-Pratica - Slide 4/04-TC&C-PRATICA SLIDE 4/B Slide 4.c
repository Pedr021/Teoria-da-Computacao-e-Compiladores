#include <stdio.h>
#include <string.h>

// Função para calcular o tamanho de uma string de forma recursiva
int recursive_length(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + recursive_length(str + 1);
}

// Função para inverter uma string de forma recursiva
void recursive_reverse(char *str, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    recursive_reverse(str, start + 1, end - 1);
}

int main() {
    char filename[] = "seuarquivo.txt";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    // Ler a string do arquivo
    char original_string[1000];
    fgets(original_string, sizeof(original_string), file);

    // Determinar o tamanho da string de forma recursiva
    int string_length = recursive_length(original_string);

    // Determinar o reverso da string de forma recursiva
    recursive_reverse(original_string, 0, string_length - 1);

    // Fechar o arquivo de leitura
    fclose(file);

    // Abrir o arquivo no modo de escrita
    file = fopen(filename, "a");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return 1;
    }

    // Armazenar o tamanho da string no arquivo original
    fprintf(file, "\nTamanho da string: %d", string_length);

    // Armazenar o reverso da string no arquivo original
    fprintf(file, "\nReverso da string: %s", original_string);

    // Fechar o arquivo de escrita
    fclose(file);

    printf("Tamanho da string: %d\n", string_length);
    printf("Reverso da string: %s\n", original_string);

    return 0;
}
