#include <stdio.h>
#include <stddef.h>

int recursive_length(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + recursive_length(str + 1);
}

int main() {
    char filename[] = "seuarquivo.txt";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para leitura.\n");
        return 1;
    }

    // Ler a string do arquivo
    char original_string[1000];
    fgets(original_string, sizeof(original_string), file);

    // Fechar o arquivo de leitura
    fclose(file);

    // Determinar o tamanho da string de forma recursiva
    int string_length = recursive_length(original_string);

    // Abrir o arquivo no modo de escrita
    file = fopen(filename, "a");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return 1;
    }

    // Armazenar o tamanho da string no arquivo original
    fprintf(file, "\nTamanho da string: %d", string_length);

    // Fechar o arquivo de escrita
    fclose(file);

    printf("Tamanho da string: %d\n", string_length);

    return 0;
}
