#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef ssize_t
typedef long ssize_t;  // Якщо немає ssize_t, визначаємо його
#endif

ssize_t custom_getline(char **lineptr, size_t *n, const char *source) {
    if (!source) {
        return -1;  // Якщо source дорівнює NULL, повертаємо помилку
    }

    size_t len = strlen(source);
    
    // Якщо lineptr або *lineptr дорівнює NULL, виділяємо пам'ять
    if (lineptr == NULL || (lineptr && *lineptr == NULL)) {
        *lineptr = malloc(len + 1);  // Виділяємо пам'ять для рядка + нульовий символ
        if (*lineptr == NULL) {
            return -1;  // Якщо пам'ять не вдалося виділити
        }
        *n = len + 1;  // Встановлюємо розмір
    } else if (*n < len + 1) {  // Якщо наявний буфер занадто малий
        char *temp = realloc(*lineptr, len + 1);
        if (temp == NULL) {
            return -1;  // Якщо не вдалося перевиділити пам'ять
        }
        *lineptr = temp;
        *n = len + 1;  // Оновлюємо розмір
    }

    // Копіюємо рядок з source в *lineptr
    strcpy(*lineptr, source);

    return len;  // Повертаємо кількість прочитаних символів
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    // Тест 1: Звичайний рядок
    const char *test_str1 = "Hello, world!";
    nread = custom_getline(&line, &len, test_str1);
    assert(nread == strlen(test_str1));  // Перевіряємо кількість прочитаних символів
    assert(strcmp(line, test_str1) == 0);  // Перевіряємо правильність копіювання рядка
    printf("Test 1 passed\n");

    // Тест 2: Пустий рядок
    const char *test_str2 = "";
    nread = custom_getline(&line, &len, test_str2);
    assert(nread == 0);  // Пустий рядок має повернути 0
    assert(strcmp(line, test_str2) == 0);  // Перевіряємо правильність копіювання пустого рядка
    printf("Test 2 passed\n");

    // Тест 3: NULL як джерело
    nread = custom_getline(&line, &len, NULL);
    assert(nread == -1);  // Якщо source дорівнює NULL, повертається -1
    printf("Test 3 passed\n");

    // Вивільняємо пам'ять
    free(line);

    return 0;
}
