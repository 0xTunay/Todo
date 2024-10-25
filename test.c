#include <stdio.h>
#include <string.h>

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

int main() {
    char input[100];

    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Удаление символа новой строки

    toUpperCase(input); // Преобразуем строку в верхний регистр

    printf("Строка в верхнем регистре: %s\n", input);

    return 0;
}
