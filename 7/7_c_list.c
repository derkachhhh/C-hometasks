#include "7_c_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Створення списку
c_list *create_list(size_t initial_capacity) {
    c_list *list = malloc(sizeof(c_list)); // Виділення пам’яті для структури списку
    if (!list) return NULL; // Перевірка на успішне виділення пам’яті
    list->items = malloc(initial_capacity * sizeof(void *)); // Виділення пам’яті для масиву елементів
    list->types = malloc(initial_capacity * sizeof(list_data_type)); // Виділення пам’яті для масиву типів
    list->size = 0; // Ініціалізація початкового розміру
    list->capacity = initial_capacity; // Ініціалізація початкової місткості
    return list;
}

// Додавання елемента
void append(c_list *list, void *item, list_data_type type) {
    if (list->size == list->capacity) { // Якщо список заповнений
        list->capacity *= 2; // Подвоюємо місткість
        list->items = realloc(list->items, list->capacity * sizeof(void *)); // Перевиділення пам’яті для елементів
        list->types = realloc(list->types, list->capacity * sizeof(list_data_type)); // Перевиділення пам’яті для типів
    }
    list->items[list->size] = item; // Додавання нового елемента
    list->types[list->size] = type; // Збереження типу нового елемента
    list->size++; // Збільшуємо розмір списку
}

// Видалення останнього елемента
void *pop(c_list *list) {
    if (list->size == 0) return NULL; // Якщо список порожній, повертаємо NULL
    list->size--; // Зменшуємо розмір списку
    return list->items[list->size]; // Повертаємо видалений елемент
}

// Виведення списку
void print_list(const c_list *list) {
    for (size_t i = 0; i < list->size; i++) { // Перебір усіх елементів списку
        switch (list->types[i]) { // Перевірка типу елемента
            case int_type:
                printf("%d ", *(int *)list->items[i]); // Виведення цілого числа
                break;
            case float_type:
                printf("%f ", *(float *)list->items[i]); // Виведення числа з плаваючою точкою
                break;
            case string_type:
                printf("%s ", (char *)list->items[i]); // Виведення рядка
                break;
        }
    }
    printf("\n"); // Перехід на новий рядок після виведення всіх елементів
}

// Сортування списку
void sort_list(c_list *list) {
    for (size_t i = 0; i < list->size - 1; i++) { // Зовнішній цикл: перебирає всі елементи.
        for (size_t j = 0; j < list->size - i - 1; j++) { // Внутрішній цикл: порівнює сусідні елементи 
            int swap = 0; // Змінна для перевірки, чи потрібен обмін

            // Сортування для `int`
            if (list->types[j] == int_type && list->types[j + 1] == int_type) {
                if (*(int *)list->items[j] > *(int *)list->items[j + 1]) {
                    swap = 1; // Потрібен обмін
                }
            }
            // Сортування для `float`
            else if (list->types[j] == float_type && list->types[j + 1] == float_type) {
                if (*(float *)list->items[j] > *(float *)list->items[j + 1]) {
                    swap = 1; // Потрібен обмін
                }
            }
            // Сортування для `string`
            else if (list->types[j] == string_type && list->types[j + 1] == string_type) {
                if (*(char *)list->items[j] > *(char *)list->items[j + 1]) {
                    swap = 1; // Потрібен обмін
                }
            }
            // Сортування між різними типами (ASCII першої літери для рядків)
            else if (list->types[j] == string_type || list->types[j + 1] == string_type) {
                char char1 = (list->types[j] == string_type) ? ((char *)list->items[j])[0] : 0;
                char char2 = (list->types[j + 1] == string_type) ? ((char *)list->items[j + 1])[0] : 0;
                if (char1 > char2) {
                    swap = 1; // Потрібен обмін
                }
            }

            // Виконати обмін, якщо потрібно
            if (swap) {
                // Обмін елементів
                void *temp_item = list->items[j];
                list->items[j] = list->items[j + 1];
                list->items[j + 1] = temp_item;

                // Обмін типів
                list_data_type temp_type = list->types[j];
                list->types[j] = list->types[j + 1];
                list->types[j + 1] = temp_type;
            }
        }
    }
}

// Звільнення пам'яті
void destroy_list(c_list *list) {
    free(list->items); // Звільнення пам’яті, виділеної для елементів
    free(list->types); // Звільнення пам’яті, виділеної для типів
    free(list); // Звільнення пам’яті для самої структури списку
}