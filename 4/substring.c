#include <stdio.h>
#include <string.h>

#define MAX_LEN 500

// Функція для пошуку підрядка в тексті
void find_substring(const char *text, const char *substring) {
    int text_len = strlen(text); // Довжина тексту
    int substring_len = strlen(substring); // Довжина підрядка
    int found = -1;

    for (int i = 0; i <= text_len - substring_len; i++) {
        int j;
        for (j = 0; j < substring_len; j++) {
            if (text[i + j] != substring[j]) {
                break;
            }
        }
        if (j == substring_len) { // Якщо підрядок знайдений
            found = i;
            break;
        }
    }

    // Виведення результату пошуку
    if (found != -1) {
        printf("Підрядок знайдено на індексі: %d\n", found);
    } else {
        printf("Підрядок не знайдено.\n");
    }
}

int main() {
    char text[MAX_LEN], substring[MAX_LEN];

    // Ввід тексту
    printf("Введіть текст: ");
    fgets(text, MAX_LEN, stdin);
    text[strcspn(text, "\n")] = '\0'; // Видалення символу нового рядка

    // Ввід підрядка
    printf("Введіть підрядок для пошуку: ");
    fgets(substring, MAX_LEN, stdin);
    substring[strcspn(substring, "\n")] = '\0'; // Видалення символу нового рядка

    // Пошук підрядка
    find_substring(text, substring);

    return 0;
}
