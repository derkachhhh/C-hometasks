#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

ssize_t getline(char **lineptr, size_t *n, const char *source); 
// Приймає: вказівник на буфер, розмір буфера, вхідний рядок для зчитування.
// Повертає кількість символів, зчитаних з `source`

int main() {
    char *line = NULL;   // Вказівник на буфер для зчитаного рядка (спочатку не ініціалізований).
    size_t len = 0;      // Початковий розмір буфера (0, бо він ще не виділений).
    ssize_t nread;       // Змінна для збереження кількості зчитаних символів.

    // Тестовий випадок 1: звичайне введення рядка
    const char *test_str1 = "Привіт:)"; // Тестовий рядок
    nread = getline(&line, &len, test_str1); // Виклик функції getline для зчитування рядка
    assert(nread == strlen(test_str1)); // Перевірка, чи кількість зчитаних символів відповідає довжині вхідного рядка
    assert(strcmp(line, test_str1) == 0); // Перевірка, чи зчитаний рядок збігається з вхідним
    printf("Тест 1 пройдено\n"); // Повідомлення про успішне проходження тесту

    // Тестовий випадок 2: вхід порожнього рядка
    const char *test_str2 = ""; // Порожній рядок
    nread = getline(&line, &len, test_str2); // Виклик функції getline
    assert(nread == 0); // Перевірка, чи зчитано 0 символів
    assert(strcmp(line, test_str2) == 0); // Перевірка, чи зчитаний рядок збігається з вхідним
    printf("Тест 2 пройдено\n"); // Повідомлення про успішне проходження тесту

    // Тестовий випадок 3: вхід довгого рядка
    const char *test_str3 = "Це дуже довгий рядок для тестування custom_getline функції."; 
    nread = getline(&line, &len, test_str3); // Виклик функції getline для довгого рядка
    assert(nread == strlen(test_str3)); // Перевірка, чи кількість зчитаних символів відповідає довжині вхідного рядка
    assert(strcmp(line, test_str3) == 0); // Перевірка, чи зчитаний рядок збігається з вхідним
    printf("Тест 3 пройдено\n"); // Повідомлення про успішне проходження тесту

    // Звільнення пам'яті
    free(line); // Звільняємо пам’ять, виділену для буфера

    return 0; // Завершення програми
}
